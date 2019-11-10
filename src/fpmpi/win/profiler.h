#ifndef PROFILER_H_INCLUDED
#define PROFILER_H_INCLUDED

/* DO NOT EDIT profiler.h - this is created from profiler.h.in by configure */

#include <stdio.h>
#include <sys/types.h>
#include <string.h>

/* Global defs & variables */

/* The number of different message sizes to use */
#define NBINS 29

/* Maximum desired output line width */
#define MAX_LINE_WIDTH 120

/* typedefs */

#ifndef HAVE_INT32_T
typedef  int32_t;  /* \@INT32\@ determined by configure */
#endif

/* In more recent MPI versions, C sized types (e.g., uint8_t) are available. */
#if SIZEOF_LONG_LONG >= 8
typedef long long msgsize_t;
#define MSGSIZE_T MPI_LONG_LONG
#else
/* Use doubles for the message size if we don't have an 8-byte long long */
typedef double msgsize_t;
#define MSGSIZE_T MPI_DOUBLE
#endif

/* Prototypes for visible routines */
void fpmpiOutputPartnerTopology( int32_t [], FILE *, int );
void fpmpiOutputDetailedPartners( int32_t [], FILE *, int );
void fpmpiOutputDetailedDataVol( FILE *, int );

void fpmpi_getrange_int_single(int, int *, int *, int *, int *, int *);
void fpmpi_getrange_double_single(double, double *, int *, 
				  double *, int *, double *);
#if SIZEOF_LONG_LONG >= 8
void fpmpi_getrange_msgsize_single(msgsize_t, msgsize_t *, 
     				    int *, msgsize_t *, 
				    int *, msgsize_t *);
#else
#define fpmpi_getrange_msgsize_single fpmpi_getrange_double_single
#endif
void fpmpi_Output_TestWait( FILE *, int, int );
void fpmpi_Output_DupSplit( FILE *, int);

FILE *OutputOpenFile( int );
void OutputProgramDescription( FILE *, int, int );
void OutputResourceUsage( FILE *, int, int  );
void OutputCommunicationData( FILE *, int, int );
void OutputPartners( FILE *, int );
void OutputHeader( FILE *, int );
void OutputTail( FILE *, int );
void fpmpiInitPerformanceCounters( void );
void fpmpiOutputPerformanceCounters( FILE * , int, int );


/*
 * The following structure contains the information that we give
 * in a "general" report about the resource usage by a program.
 */
/* Bits for the fields in ProgramResourceUsage */
#define FPMPI_PRU_USER_TIME 0x1
#define FPMPI_PRU_SYS_TIME  0x2
#define FPMPI_PRU_MINOR_PAGE_FAULTS 0x4
#define FPMPI_PRU_MAJOR_PAGE_FAULTS 0x8
#define FPMPI_PRU_RSS 0x10
typedef struct {
  double   userTime, systemTime;
  unsigned int minorPageFaults,
               majorPageFaults,
               residentSetSize;
  unsigned int validFields;           /* bits are set for each valid field
					 above */
} ProgramResourceUsage;
int fpmpi_GetResourceUsage( ProgramResourceUsage *, int );


/* We also define a structure that may be used for routines that
   do not communicate data (they may include delays, so we include a
   synctime field) */
typedef struct {
    double time, synctime;
    int    calls;
    int    success;   /* For calls like test or iprobe, whether flag==true */
} NoCommData;

typedef struct {
    const char *name;
    int        hasSyncTime;
    NoCommData *data;
    double      totalTime, totalSync;
    int         totalCalls, totalSuccess;
    double      maxTime, maxSync;
    int         maxTimeLoc, maxSyncLoc, maxCalls, maxCallsLoc,
	maxSuccess, maxSuccessLoc;
} CallBasicData;
void fpmpi_TestWaitInit( CallBasicData [] );
void fpmpi_TestWaitSavePhase(NoCommData *, int);
void fpmpi_TestWaitRestorePhase(NoCommData *, int);

/*
 * Definitions for the data that is collected.
 *
 * The hierarchy of structures is:
 *
 * For each class of routine (e.g., point-to-point, collective) there
 * is an array of structures:
 *   array of { routine-name, pointer-to-raw-data, pointer-to-summary-data }
 * A null routine name designates end-of-list.
 *
 * Each pointer to raw data contains information on each routine,
 * separated in the bins by message size.  Additional information on
 * process partners and on synchronization (collective) or wait (blocking
 * point-to-point) operations may also be collected.
 *
 * These arrays are used to simplify the reporting of results; the
 * output routine loop over them (also by class) to compute things like
 * total point-to-point communication volume.
 */
typedef struct {
    double    time;     /* sum of time */
    double    synctime; /* sum of synchronization or wait time, if relevant */
    msgsize_t size;     /* sum of exact size */
    int       calls;    /* Number of calls */
} CommBinData;

/* This struct combines all of the data about the use of a routine - both
    the communication (CommBinData) and the partners (topology) */
typedef struct {
    CommBinData  b[NBINS];     /* One bin for each range of message size */
    int32_t      partners[MAX_PROCBY32];
                               /* partners is a bit vector to keep track of
		                  with which processes this one has been in
				  communication.  Pt2pt only */
    msgsize_t    *sizeToPartner;  /* Total message volume to partner.
				     Allocated if feature enabled; pt2pt only.
				   */
} CommData;

/* This structure contains all of the information about the use of a routine,
   including the routine's name, communication data, and memory used to
   create the output */
typedef struct {
    const char *name;               /* Name of routine */
    int         hasSyncTime;
    CommData    *data;              /* Raw data (for this process).
				       Pointer used to simplify definition;
				       access in routines is directly to the
				       data to which this points */
    CommData    sumData,            /* Aggregated data (valid on process 0 */
 	        maxData, minData;   /* only) */
    double      totalTime, totalSync,
                minTime, maxTime, maxSync;
    int         totalCalls,
	        minCalls, maxCalls;
    msgsize_t   totalSize, maxSize; /* TotalSize is the aggregate size over all
				       processes.  maxSize is the maximum sent
				       or received by any one process */
    int         maxTimeLoc, maxCallsLoc, maxSizeLoc, maxSyncLoc;
                                    /* Rank of process with the maxTime etc. */
    /* partner data */
    int         totalPartners, maxPartners, maxPartnersLoc,
	        minPartners, minPartnersLoc;
} CallData;

typedef struct commCounterPhase {
    char       *name;         /* Name for this phase */
    CommData   *comm_data;    /* Array for saving comm data */
    NoCommData *nocomm_data;  /* Ditto for nocomm data */
} commCounterPhase;

#define SAVE_COUNTER(_rd,_name) {				\
    memcpy(_rd+_name##_idx,&_name##_data,sizeof(CommData));	\
    memset(&_name##_data,0,sizeof(CommData));}
#define SAVE_COUNTER_BASIC(_rd,_name) {				\
    memcpy(_rd+_name##_idx,&_name##_data,sizeof(NoCommData));	\
    memset(&_name##_data,0,sizeof(NoCommData));}
#define RESTORE_COUNTER(_rd,_name) {					\
	memcpy(&_name##_data,_rd+_name##_idx,sizeof(CommData));}
#define RESTORE_COUNTER_BASIC(_rd,_name) {				\
	memcpy(&_name##_data,_rd+_name##_idx,sizeof(NoCommData));}

#define SAVE_COUNTER_BASIC_IDX(_rd,_name,_idx) {			\
    memcpy(_rd+(_idx),&_name##_data,sizeof(NoCommData)); \
    memset(&_name##_data,0,sizeof(NoCommData));}
#define RESTORE_COUNTER_BASIC_IDX(_rd,_name,_idx) {			\
    memcpy(&_name##_data,_rd+(_idx),sizeof(NoCommData));}

#endif
