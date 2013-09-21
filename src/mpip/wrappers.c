/* /home/g/Documents/pbd/mpiP-3.3/wrappers.c */
/* DO NOT EDIT -- AUTOMATICALLY GENERATED! */
/* Timestamp: 19 September 2013 18:27  */
/* Location: G posix */
/* Creator: root  */


#include "mpiPi.h"
#include "symbols.h"
#include "mpiPi_def.h"




/* --------------- MPI_Accumulate --------------- */

static int mpiPif_MPI_Accumulate( jmp_buf * base_jbuf, void  *origin_addr, int  * origin_count, MPI_Datatype  * origin_datatype, int  * target_rank, MPI_Aint  * target_disp, int  * target_count, MPI_Datatype  * target_datatype, MPI_Op  * op, MPI_Win  * win){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Accumulate( origin_addr,  * origin_count,  * origin_datatype,  * target_rank,  * target_disp,  * target_count,  * target_datatype,  * op,  * win);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

PMPI_Type_size(*target_datatype, &tsize);
rmaSize = (double)(tsize * *target_count);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Accumulate");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Accumulate, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Accumulate */



extern int MPI_Accumulate ( void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Op op, MPI_Win win )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Accumulate( &jbuf, origin_addr,  & origin_count,  & origin_datatype,  & target_rank,  & target_disp,  & target_count,  & target_datatype,  & op,  & win );

return rc;
} /* MPI_Accumulate */


extern void F77_MPI_ACCUMULATE(void  *origin_addr, int  * origin_count, MPI_Fint  * origin_datatype, int  * target_rank, MPI_Aint  * target_disp, int  * target_count, MPI_Fint  * target_datatype, MPI_Fint  * op, MPI_Win  * win , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_origin_datatype;
MPI_Datatype c_target_datatype;
MPI_Op c_op;

c_origin_datatype = MPI_Type_f2c(*origin_datatype);
c_target_datatype = MPI_Type_f2c(*target_datatype);
c_op = MPI_Op_f2c(*op);

rc = mpiPif_MPI_Accumulate( &jbuf, origin_addr, origin_count, &c_origin_datatype, target_rank, target_disp, target_count, &c_target_datatype, &c_op, win );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_accumulate */



/* --------------- MPI_Allgather --------------- */

static int mpiPif_MPI_Allgather( jmp_buf * base_jbuf, void  *sendbuf, int  * sendcount, MPI_Datatype  * sendtype, void  *recvbuf, int  * recvcount, MPI_Datatype  * recvtype, MPI_Comm  * comm){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Allgather( sendbuf,  * sendcount,  * sendtype, recvbuf,  * recvcount,  * recvtype,  * comm);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( *sendtype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*sendtype, &tsize);
messSize = (double)(tsize * *sendcount);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Allgather");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Allgather, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Allgather */



extern int MPI_Allgather ( void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Allgather( &jbuf, sendbuf,  & sendcount,  & sendtype, recvbuf,  & recvcount,  & recvtype,  & comm );

return rc;
} /* MPI_Allgather */


extern void F77_MPI_ALLGATHER(void  *sendbuf, int  * sendcount, MPI_Fint  * sendtype, void  *recvbuf, int  * recvcount, MPI_Fint  * recvtype, MPI_Fint  * comm , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_sendtype;
MPI_Datatype c_recvtype;
MPI_Comm c_comm;

c_sendtype = MPI_Type_f2c(*sendtype);
c_recvtype = MPI_Type_f2c(*recvtype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Allgather( &jbuf, sendbuf, sendcount, &c_sendtype, recvbuf, recvcount, &c_recvtype, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_allgather */



/* --------------- MPI_Allgatherv --------------- */

static int mpiPif_MPI_Allgatherv( jmp_buf * base_jbuf, void  *sendbuf, int  * sendcount, MPI_Datatype  * sendtype, void  *recvbuf, int  *recvcounts, int  *displs, MPI_Datatype  * recvtype, MPI_Comm  * comm){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Allgatherv( sendbuf,  * sendcount,  * sendtype, recvbuf, recvcounts, displs,  * recvtype,  * comm);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( *sendtype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*sendtype, &tsize);
messSize = (double)(tsize * *sendcount);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Allgatherv");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Allgatherv, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Allgatherv */



extern int MPI_Allgatherv ( void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int *recvcounts, int *displs, MPI_Datatype recvtype, MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Allgatherv( &jbuf, sendbuf,  & sendcount,  & sendtype, recvbuf, recvcounts, displs,  & recvtype,  & comm );

return rc;
} /* MPI_Allgatherv */


extern void F77_MPI_ALLGATHERV(void  *sendbuf, int  * sendcount, MPI_Fint  * sendtype, void  *recvbuf, int  *recvcounts, int  *displs, MPI_Fint  * recvtype, MPI_Fint  * comm , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_sendtype;
MPI_Datatype c_recvtype;
MPI_Comm c_comm;

c_sendtype = MPI_Type_f2c(*sendtype);
c_recvtype = MPI_Type_f2c(*recvtype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Allgatherv( &jbuf, sendbuf, sendcount, &c_sendtype, recvbuf, recvcounts, displs, &c_recvtype, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_allgatherv */



/* --------------- MPI_Allreduce --------------- */

static int mpiPif_MPI_Allreduce( jmp_buf * base_jbuf, void  *sendbuf, void  *recvbuf, int  * count, MPI_Datatype  * datatype, MPI_Op  * op, MPI_Comm  * comm){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Allreduce( sendbuf, recvbuf,  * count,  * datatype,  * op,  * comm);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( *datatype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*datatype, &tsize);
messSize = (double)(tsize * *count);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Allreduce");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Allreduce, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Allreduce */



extern int MPI_Allreduce ( void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Allreduce( &jbuf, sendbuf, recvbuf,  & count,  & datatype,  & op,  & comm );

return rc;
} /* MPI_Allreduce */


extern void F77_MPI_ALLREDUCE(void  *sendbuf, void  *recvbuf, int  * count, MPI_Fint  * datatype, MPI_Fint  * op, MPI_Fint  * comm , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Op c_op;
MPI_Comm c_comm;

c_datatype = MPI_Type_f2c(*datatype);
c_op = MPI_Op_f2c(*op);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Allreduce( &jbuf, sendbuf, recvbuf, count, &c_datatype, &c_op, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_allreduce */



/* --------------- MPI_Alltoall --------------- */

static int mpiPif_MPI_Alltoall( jmp_buf * base_jbuf, void  *sendbuf, int  * sendcount, MPI_Datatype  * sendtype, void  *recvbuf, int  * recvcnt, MPI_Datatype  * recvtype, MPI_Comm  * comm){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Alltoall( sendbuf,  * sendcount,  * sendtype, recvbuf,  * recvcnt,  * recvtype,  * comm);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( *sendtype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*sendtype, &tsize);
messSize = (double)(tsize * *sendcount);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Alltoall");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Alltoall, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Alltoall */



extern int MPI_Alltoall ( void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcnt, MPI_Datatype recvtype, MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Alltoall( &jbuf, sendbuf,  & sendcount,  & sendtype, recvbuf,  & recvcnt,  & recvtype,  & comm );

return rc;
} /* MPI_Alltoall */


extern void F77_MPI_ALLTOALL(void  *sendbuf, int  * sendcount, MPI_Fint  * sendtype, void  *recvbuf, int  * recvcnt, MPI_Fint  * recvtype, MPI_Fint  * comm , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_sendtype;
MPI_Datatype c_recvtype;
MPI_Comm c_comm;

c_sendtype = MPI_Type_f2c(*sendtype);
c_recvtype = MPI_Type_f2c(*recvtype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Alltoall( &jbuf, sendbuf, sendcount, &c_sendtype, recvbuf, recvcnt, &c_recvtype, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_alltoall */



/* --------------- MPI_Alltoallv --------------- */

static int mpiPif_MPI_Alltoallv( jmp_buf * base_jbuf, void  *sendbuf, int  *sendcnts, int  *sdispls, MPI_Datatype  * sendtype, void  *recvbuf, int  *recvcnts, int  *rdispls, MPI_Datatype  * recvtype, MPI_Comm  * comm){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Alltoallv( sendbuf, sendcnts, sdispls,  * sendtype, recvbuf, recvcnts, rdispls,  * recvtype,  * comm);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Alltoallv");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Alltoallv, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Alltoallv */



extern int MPI_Alltoallv ( void *sendbuf, int *sendcnts, int *sdispls, MPI_Datatype sendtype, void *recvbuf, int *recvcnts, int *rdispls, MPI_Datatype recvtype, MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Alltoallv( &jbuf, sendbuf, sendcnts, sdispls,  & sendtype, recvbuf, recvcnts, rdispls,  & recvtype,  & comm );

return rc;
} /* MPI_Alltoallv */


extern void F77_MPI_ALLTOALLV(void  *sendbuf, int  *sendcnts, int  *sdispls, MPI_Fint  * sendtype, void  *recvbuf, int  *recvcnts, int  *rdispls, MPI_Fint  * recvtype, MPI_Fint  * comm , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_sendtype;
MPI_Datatype c_recvtype;
MPI_Comm c_comm;

c_sendtype = MPI_Type_f2c(*sendtype);
c_recvtype = MPI_Type_f2c(*recvtype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Alltoallv( &jbuf, sendbuf, sendcnts, sdispls, &c_sendtype, recvbuf, recvcnts, rdispls, &c_recvtype, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_alltoallv */



/* --------------- MPI_Attr_delete --------------- */

static int mpiPif_MPI_Attr_delete( jmp_buf * base_jbuf, MPI_Comm  * comm, int  * keyval){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Attr_delete(  * comm,  * keyval);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Attr_delete");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Attr_delete, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Attr_delete */



extern int MPI_Attr_delete ( MPI_Comm comm, int keyval )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Attr_delete( &jbuf,  & comm,  & keyval );

return rc;
} /* MPI_Attr_delete */


extern void F77_MPI_ATTR_DELETE(MPI_Fint  * comm, int  * keyval , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Attr_delete( &jbuf, &c_comm, keyval );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_attr_delete */



/* --------------- MPI_Attr_get --------------- */

static int mpiPif_MPI_Attr_get( jmp_buf * base_jbuf, MPI_Comm  * comm, int  * keyval, void  *attr_value, int  *flag){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Attr_get(  * comm,  * keyval, attr_value, flag);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Attr_get");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Attr_get, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Attr_get */



extern int MPI_Attr_get ( MPI_Comm comm, int keyval, void *attr_value, int *flag )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Attr_get( &jbuf,  & comm,  & keyval, attr_value, flag );

return rc;
} /* MPI_Attr_get */


extern void F77_MPI_ATTR_GET(MPI_Fint  * comm, int  * keyval, void  *attr_value, int  *flag , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Attr_get( &jbuf, &c_comm, keyval, attr_value, flag );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_attr_get */



/* --------------- MPI_Attr_put --------------- */

static int mpiPif_MPI_Attr_put( jmp_buf * base_jbuf, MPI_Comm  * comm, int  * keyval, void  *attr_value){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Attr_put(  * comm,  * keyval, attr_value);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Attr_put");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Attr_put, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Attr_put */



extern int MPI_Attr_put ( MPI_Comm comm, int keyval, void *attr_value )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Attr_put( &jbuf,  & comm,  & keyval, attr_value );

return rc;
} /* MPI_Attr_put */


extern void F77_MPI_ATTR_PUT(MPI_Fint  * comm, int  * keyval, void  *attr_value , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Attr_put( &jbuf, &c_comm, keyval, attr_value );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_attr_put */



/* --------------- MPI_Barrier --------------- */

static int mpiPif_MPI_Barrier( jmp_buf * base_jbuf, MPI_Comm  * comm){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Barrier(  * comm);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Barrier");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Barrier, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Barrier */



extern int MPI_Barrier ( MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Barrier( &jbuf,  & comm );

return rc;
} /* MPI_Barrier */


extern void F77_MPI_BARRIER(MPI_Fint  * comm , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Barrier( &jbuf, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_barrier */



/* --------------- MPI_Bcast --------------- */

static int mpiPif_MPI_Bcast( jmp_buf * base_jbuf, void  *buffer, int  * count, MPI_Datatype  * datatype, int  * root, MPI_Comm  * comm){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Bcast( buffer,  * count,  * datatype,  * root,  * comm);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( *datatype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*datatype, &tsize);
messSize = (double)(tsize * *count);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Bcast");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Bcast, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Bcast */



extern int MPI_Bcast ( void *buffer, int count, MPI_Datatype datatype, int root, MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Bcast( &jbuf, buffer,  & count,  & datatype,  & root,  & comm );

return rc;
} /* MPI_Bcast */


extern void F77_MPI_BCAST(void  *buffer, int  * count, MPI_Fint  * datatype, int  * root, MPI_Fint  * comm , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Bcast( &jbuf, buffer, count, &c_datatype, root, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_bcast */



/* --------------- MPI_Bsend --------------- */

static int mpiPif_MPI_Bsend( jmp_buf * base_jbuf, void  *buf, int  * count, MPI_Datatype  * datatype, int  * dest, int  * tag, MPI_Comm  * comm){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Bsend( buf,  * count,  * datatype,  * dest,  * tag,  * comm);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( *datatype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*datatype, &tsize);
messSize = (double)(tsize * *count);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Bsend");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Bsend, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Bsend */



extern int MPI_Bsend ( void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Bsend( &jbuf, buf,  & count,  & datatype,  & dest,  & tag,  & comm );

return rc;
} /* MPI_Bsend */


extern void F77_MPI_BSEND(void  *buf, int  * count, MPI_Fint  * datatype, int  * dest, int  * tag, MPI_Fint  * comm , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Bsend( &jbuf, buf, count, &c_datatype, dest, tag, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_bsend */



/* --------------- MPI_Bsend_init --------------- */

static int mpiPif_MPI_Bsend_init( jmp_buf * base_jbuf, void  *buf, int  * count, MPI_Datatype  * datatype, int  * dest, int  * tag, MPI_Comm  * comm, MPI_Request  *request){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Bsend_init( buf,  * count,  * datatype,  * dest,  * tag,  * comm, request);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Bsend_init");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Bsend_init, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Bsend_init */



extern int MPI_Bsend_init ( void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Bsend_init( &jbuf, buf,  & count,  & datatype,  & dest,  & tag,  & comm, request );

return rc;
} /* MPI_Bsend_init */


extern void F77_MPI_BSEND_INIT(void  *buf, int  * count, MPI_Fint  * datatype, int  * dest, int  * tag, MPI_Fint  * comm, MPI_Fint  *request , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;
MPI_Request c_request;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Bsend_init( &jbuf, buf, count, &c_datatype, dest, tag, &c_comm, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_bsend_init */



/* --------------- MPI_Buffer_attach --------------- */

static int mpiPif_MPI_Buffer_attach( jmp_buf * base_jbuf, void  *buffer, int  * size){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Buffer_attach( buffer,  * size);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Buffer_attach");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Buffer_attach, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Buffer_attach */



extern int MPI_Buffer_attach ( void *buffer, int size )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Buffer_attach( &jbuf, buffer,  & size );

return rc;
} /* MPI_Buffer_attach */


extern void F77_MPI_BUFFER_ATTACH(void  *buffer, int  * size , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;


rc = mpiPif_MPI_Buffer_attach( &jbuf, buffer, size );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_buffer_attach */



/* --------------- MPI_Buffer_detach --------------- */

static int mpiPif_MPI_Buffer_detach( jmp_buf * base_jbuf, void  *bufferptr, int  *size){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Buffer_detach( bufferptr, size);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Buffer_detach");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Buffer_detach, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Buffer_detach */



extern int MPI_Buffer_detach ( void *bufferptr, int *size )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Buffer_detach( &jbuf, bufferptr, size );

return rc;
} /* MPI_Buffer_detach */


extern void F77_MPI_BUFFER_DETACH(void  *bufferptr, int  *size , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;


rc = mpiPif_MPI_Buffer_detach( &jbuf, bufferptr, size );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_buffer_detach */



/* --------------- MPI_Cancel --------------- */

static int mpiPif_MPI_Cancel( jmp_buf * base_jbuf, MPI_Request  *request){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Cancel( request);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Cancel");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Cancel, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Cancel */



extern int MPI_Cancel ( MPI_Request *request )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Cancel( &jbuf, request );

return rc;
} /* MPI_Cancel */


extern void F77_MPI_CANCEL(MPI_Fint  *request , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Request c_request;

c_request = MPI_Request_f2c(*request);

rc = mpiPif_MPI_Cancel( &jbuf, &c_request );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_cancel */



/* --------------- MPI_Cart_coords --------------- */

static int mpiPif_MPI_Cart_coords( jmp_buf * base_jbuf, MPI_Comm  * comm, int  * rank, int  * maxdims, int  *coords){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Cart_coords(  * comm,  * rank,  * maxdims, coords);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Cart_coords");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Cart_coords, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Cart_coords */



extern int MPI_Cart_coords ( MPI_Comm comm, int rank, int maxdims, int *coords )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Cart_coords( &jbuf,  & comm,  & rank,  & maxdims, coords );

return rc;
} /* MPI_Cart_coords */


extern void F77_MPI_CART_COORDS(MPI_Fint  * comm, int  * rank, int  * maxdims, int  *coords , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Cart_coords( &jbuf, &c_comm, rank, maxdims, coords );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_cart_coords */



/* --------------- MPI_Cart_create --------------- */

static int mpiPif_MPI_Cart_create( jmp_buf * base_jbuf, MPI_Comm  * comm_old, int  * ndims, int  *dims, int  *periods, int  * reorder, MPI_Comm  *comm_cart){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Cart_create(  * comm_old,  * ndims, dims, periods,  * reorder, comm_cart);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Cart_create");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Cart_create, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Cart_create */



extern int MPI_Cart_create ( MPI_Comm comm_old, int ndims, int *dims, int *periods, int reorder, MPI_Comm *comm_cart )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Cart_create( &jbuf,  & comm_old,  & ndims, dims, periods,  & reorder, comm_cart );

return rc;
} /* MPI_Cart_create */


extern void F77_MPI_CART_CREATE(MPI_Fint  * comm_old, int  * ndims, int  *dims, int  *periods, int  * reorder, MPI_Fint  *comm_cart , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Comm c_comm_old;
MPI_Comm c_comm_cart;

c_comm_old = MPI_Comm_f2c(*comm_old);

rc = mpiPif_MPI_Cart_create( &jbuf, &c_comm_old, ndims, dims, periods, reorder, &c_comm_cart );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*comm_cart = MPI_Comm_c2f(c_comm_cart);
}
return;
} /* mpi_cart_create */



/* --------------- MPI_Cart_get --------------- */

static int mpiPif_MPI_Cart_get( jmp_buf * base_jbuf, MPI_Comm  * comm, int  * maxdims, int  *dims, int  *periods, int  *coords){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Cart_get(  * comm,  * maxdims, dims, periods, coords);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Cart_get");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Cart_get, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Cart_get */



extern int MPI_Cart_get ( MPI_Comm comm, int maxdims, int *dims, int *periods, int *coords )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Cart_get( &jbuf,  & comm,  & maxdims, dims, periods, coords );

return rc;
} /* MPI_Cart_get */


extern void F77_MPI_CART_GET(MPI_Fint  * comm, int  * maxdims, int  *dims, int  *periods, int  *coords , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Cart_get( &jbuf, &c_comm, maxdims, dims, periods, coords );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_cart_get */



/* --------------- MPI_Cart_map --------------- */

static int mpiPif_MPI_Cart_map( jmp_buf * base_jbuf, MPI_Comm  * comm_old, int  * ndims, int  *dims, int  *periods, int  *newrank){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Cart_map(  * comm_old,  * ndims, dims, periods, newrank);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Cart_map");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Cart_map, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Cart_map */



extern int MPI_Cart_map ( MPI_Comm comm_old, int ndims, int *dims, int *periods, int *newrank )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Cart_map( &jbuf,  & comm_old,  & ndims, dims, periods, newrank );

return rc;
} /* MPI_Cart_map */


extern void F77_MPI_CART_MAP(MPI_Fint  * comm_old, int  * ndims, int  *dims, int  *periods, int  *newrank , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Comm c_comm_old;

c_comm_old = MPI_Comm_f2c(*comm_old);

rc = mpiPif_MPI_Cart_map( &jbuf, &c_comm_old, ndims, dims, periods, newrank );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_cart_map */



/* --------------- MPI_Cart_rank --------------- */

static int mpiPif_MPI_Cart_rank( jmp_buf * base_jbuf, MPI_Comm  * comm, int  *coords, int  *rank){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Cart_rank(  * comm, coords, rank);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Cart_rank");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Cart_rank, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Cart_rank */



extern int MPI_Cart_rank ( MPI_Comm comm, int *coords, int *rank )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Cart_rank( &jbuf,  & comm, coords, rank );

return rc;
} /* MPI_Cart_rank */


extern void F77_MPI_CART_RANK(MPI_Fint  * comm, int  *coords, int  *rank , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Cart_rank( &jbuf, &c_comm, coords, rank );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_cart_rank */



/* --------------- MPI_Cart_shift --------------- */

static int mpiPif_MPI_Cart_shift( jmp_buf * base_jbuf, MPI_Comm  * comm, int  * direction, int  * displ, int  *source, int  *dest){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Cart_shift(  * comm,  * direction,  * displ, source, dest);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Cart_shift");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Cart_shift, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Cart_shift */



extern int MPI_Cart_shift ( MPI_Comm comm, int direction, int displ, int *source, int *dest )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Cart_shift( &jbuf,  & comm,  & direction,  & displ, source, dest );

return rc;
} /* MPI_Cart_shift */


extern void F77_MPI_CART_SHIFT(MPI_Fint  * comm, int  * direction, int  * displ, int  *source, int  *dest , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Cart_shift( &jbuf, &c_comm, direction, displ, source, dest );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_cart_shift */



/* --------------- MPI_Cart_sub --------------- */

static int mpiPif_MPI_Cart_sub( jmp_buf * base_jbuf, MPI_Comm  * comm, int  *remain_dims, MPI_Comm  *comm_new){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Cart_sub(  * comm, remain_dims, comm_new);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Cart_sub");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Cart_sub, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Cart_sub */



extern int MPI_Cart_sub ( MPI_Comm comm, int *remain_dims, MPI_Comm *comm_new )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Cart_sub( &jbuf,  & comm, remain_dims, comm_new );

return rc;
} /* MPI_Cart_sub */


extern void F77_MPI_CART_SUB(MPI_Fint  * comm, int  *remain_dims, MPI_Fint  *comm_new , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;
MPI_Comm c_comm_new;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Cart_sub( &jbuf, &c_comm, remain_dims, &c_comm_new );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*comm_new = MPI_Comm_c2f(c_comm_new);
}
return;
} /* mpi_cart_sub */



/* --------------- MPI_Cartdim_get --------------- */

static int mpiPif_MPI_Cartdim_get( jmp_buf * base_jbuf, MPI_Comm  * comm, int  *ndims){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Cartdim_get(  * comm, ndims);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Cartdim_get");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Cartdim_get, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Cartdim_get */



extern int MPI_Cartdim_get ( MPI_Comm comm, int *ndims )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Cartdim_get( &jbuf,  & comm, ndims );

return rc;
} /* MPI_Cartdim_get */


extern void F77_MPI_CARTDIM_GET(MPI_Fint  * comm, int  *ndims , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Cartdim_get( &jbuf, &c_comm, ndims );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_cartdim_get */



/* --------------- MPI_Comm_create --------------- */

static int mpiPif_MPI_Comm_create( jmp_buf * base_jbuf, MPI_Comm  * comm, MPI_Group  * group, MPI_Comm  *comm_out){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Comm_create(  * comm,  * group, comm_out);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Comm_create");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Comm_create, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Comm_create */



extern int MPI_Comm_create ( MPI_Comm comm, MPI_Group group, MPI_Comm *comm_out )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Comm_create( &jbuf,  & comm,  & group, comm_out );

return rc;
} /* MPI_Comm_create */


extern void F77_MPI_COMM_CREATE(MPI_Fint  * comm, MPI_Fint  * group, MPI_Fint  *comm_out , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;
MPI_Group c_group;
MPI_Comm c_comm_out;

c_comm = MPI_Comm_f2c(*comm);
c_group = MPI_Group_f2c(*group);

rc = mpiPif_MPI_Comm_create( &jbuf, &c_comm, &c_group, &c_comm_out );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*comm_out = MPI_Comm_c2f(c_comm_out);
}
return;
} /* mpi_comm_create */



/* --------------- MPI_Comm_dup --------------- */

static int mpiPif_MPI_Comm_dup( jmp_buf * base_jbuf, MPI_Comm  * comm, MPI_Comm  *comm_out){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Comm_dup(  * comm, comm_out);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Comm_dup");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Comm_dup, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Comm_dup */



extern int MPI_Comm_dup ( MPI_Comm comm, MPI_Comm *comm_out )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Comm_dup( &jbuf,  & comm, comm_out );

return rc;
} /* MPI_Comm_dup */


extern void F77_MPI_COMM_DUP(MPI_Fint  * comm, MPI_Fint  *comm_out , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;
MPI_Comm c_comm_out;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Comm_dup( &jbuf, &c_comm, &c_comm_out );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*comm_out = MPI_Comm_c2f(c_comm_out);
}
return;
} /* mpi_comm_dup */



/* --------------- MPI_Comm_free --------------- */

static int mpiPif_MPI_Comm_free( jmp_buf * base_jbuf, MPI_Comm  *commp){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Comm_free( commp);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Comm_free");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Comm_free, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Comm_free */



extern int MPI_Comm_free ( MPI_Comm *commp )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Comm_free( &jbuf, commp );

return rc;
} /* MPI_Comm_free */


extern void F77_MPI_COMM_FREE(MPI_Fint  *commp , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Comm c_commp;

c_commp = MPI_Comm_f2c(*commp);

rc = mpiPif_MPI_Comm_free( &jbuf, &c_commp );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*commp = MPI_Comm_c2f(c_commp);
}
return;
} /* mpi_comm_free */



/* --------------- MPI_Comm_group --------------- */

static int mpiPif_MPI_Comm_group( jmp_buf * base_jbuf, MPI_Comm  * comm, MPI_Group  *group){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Comm_group(  * comm, group);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Comm_group");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Comm_group, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Comm_group */



extern int MPI_Comm_group ( MPI_Comm comm, MPI_Group *group )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Comm_group( &jbuf,  & comm, group );

return rc;
} /* MPI_Comm_group */


extern void F77_MPI_COMM_GROUP(MPI_Fint  * comm, MPI_Fint  *group , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;
MPI_Group c_group;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Comm_group( &jbuf, &c_comm, &c_group );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*group = MPI_Group_c2f(c_group);
}
return;
} /* mpi_comm_group */



/* --------------- MPI_Comm_remote_group --------------- */

static int mpiPif_MPI_Comm_remote_group( jmp_buf * base_jbuf, MPI_Comm  * comm, MPI_Group  *group){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Comm_remote_group(  * comm, group);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Comm_remote_group");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Comm_remote_group, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Comm_remote_group */



extern int MPI_Comm_remote_group ( MPI_Comm comm, MPI_Group *group )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Comm_remote_group( &jbuf,  & comm, group );

return rc;
} /* MPI_Comm_remote_group */


extern void F77_MPI_COMM_REMOTE_GROUP(MPI_Fint  * comm, MPI_Fint  *group , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;
MPI_Group c_group;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Comm_remote_group( &jbuf, &c_comm, &c_group );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*group = MPI_Group_c2f(c_group);
}
return;
} /* mpi_comm_remote_group */



/* --------------- MPI_Comm_remote_size --------------- */

static int mpiPif_MPI_Comm_remote_size( jmp_buf * base_jbuf, MPI_Comm  * comm, int  *size){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Comm_remote_size(  * comm, size);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Comm_remote_size");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Comm_remote_size, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Comm_remote_size */



extern int MPI_Comm_remote_size ( MPI_Comm comm, int *size )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Comm_remote_size( &jbuf,  & comm, size );

return rc;
} /* MPI_Comm_remote_size */


extern void F77_MPI_COMM_REMOTE_SIZE(MPI_Fint  * comm, int  *size , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Comm_remote_size( &jbuf, &c_comm, size );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_comm_remote_size */



/* --------------- MPI_Comm_split --------------- */

static int mpiPif_MPI_Comm_split( jmp_buf * base_jbuf, MPI_Comm  * comm, int  * color, int  * key, MPI_Comm  *comm_out){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Comm_split(  * comm,  * color,  * key, comm_out);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Comm_split");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Comm_split, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Comm_split */



extern int MPI_Comm_split ( MPI_Comm comm, int color, int key, MPI_Comm *comm_out )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Comm_split( &jbuf,  & comm,  & color,  & key, comm_out );

return rc;
} /* MPI_Comm_split */


extern void F77_MPI_COMM_SPLIT(MPI_Fint  * comm, int  * color, int  * key, MPI_Fint  *comm_out , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;
MPI_Comm c_comm_out;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Comm_split( &jbuf, &c_comm, color, key, &c_comm_out );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*comm_out = MPI_Comm_c2f(c_comm_out);
}
return;
} /* mpi_comm_split */



/* --------------- MPI_Comm_test_inter --------------- */

static int mpiPif_MPI_Comm_test_inter( jmp_buf * base_jbuf, MPI_Comm  * comm, int  *flag){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Comm_test_inter(  * comm, flag);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Comm_test_inter");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Comm_test_inter, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Comm_test_inter */



extern int MPI_Comm_test_inter ( MPI_Comm comm, int *flag )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Comm_test_inter( &jbuf,  & comm, flag );

return rc;
} /* MPI_Comm_test_inter */


extern void F77_MPI_COMM_TEST_INTER(MPI_Fint  * comm, int  *flag , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Comm_test_inter( &jbuf, &c_comm, flag );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_comm_test_inter */



/* --------------- MPI_Dims_create --------------- */

static int mpiPif_MPI_Dims_create( jmp_buf * base_jbuf, int  * nnodes, int  * ndims, int  *dims){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Dims_create(  * nnodes,  * ndims, dims);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Dims_create");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Dims_create, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Dims_create */



extern int MPI_Dims_create ( int nnodes, int ndims, int *dims )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Dims_create( &jbuf,  & nnodes,  & ndims, dims );

return rc;
} /* MPI_Dims_create */


extern void F77_MPI_DIMS_CREATE(int  * nnodes, int  * ndims, int  *dims , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;


rc = mpiPif_MPI_Dims_create( &jbuf, nnodes, ndims, dims );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_dims_create */



/* --------------- MPI_Error_class --------------- */

static int mpiPif_MPI_Error_class( jmp_buf * base_jbuf, int  * errorcode, int  *errorclass){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Error_class(  * errorcode, errorclass);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Error_class");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Error_class, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Error_class */



extern int MPI_Error_class ( int errorcode, int *errorclass )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Error_class( &jbuf,  & errorcode, errorclass );

return rc;
} /* MPI_Error_class */


extern void F77_MPI_ERROR_CLASS(int  * errorcode, int  *errorclass , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;


rc = mpiPif_MPI_Error_class( &jbuf, errorcode, errorclass );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_error_class */



/* --------------- MPI_File_close --------------- */

static int mpiPif_MPI_File_close( jmp_buf * base_jbuf, MPI_File  *fh){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_File_close( fh);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_File_close");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_File_close, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_File_close */



extern int MPI_File_close (MPI_File *fh)
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_File_close( &jbuf, fh );

return rc;
} /* MPI_File_close */


extern void F77_MPI_FILE_CLOSE(MPI_Fint  *fh , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_File c_fh;

c_fh = MPI_File_f2c(*fh);

rc = mpiPif_MPI_File_close( &jbuf, &c_fh );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*fh = MPI_File_c2f(c_fh);
}
return;
} /* mpi_file_close */



/* --------------- MPI_File_open --------------- */

static int mpiPif_MPI_File_open( jmp_buf * base_jbuf, MPI_Comm  * comm, char  *filename, int  * amode, MPI_Info  * info, MPI_File  *fh){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_File_open(  * comm, filename,  * amode,  * info, fh);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_File_open");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_File_open, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_File_open */



extern int MPI_File_open (MPI_Comm comm, char *filename, int amode, MPI_Info info, MPI_File *fh)
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_File_open( &jbuf,  & comm, filename,  & amode,  & info, fh );

return rc;
} /* MPI_File_open */


extern void F77_MPI_FILE_OPEN(MPI_Fint  * comm, char  *filename, int  * amode, MPI_Fint  * info, MPI_Fint  *fh , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;
MPI_Info c_info;
MPI_File c_fh;

c_comm = MPI_Comm_f2c(*comm);
c_info = MPI_Info_f2c(*info);

rc = mpiPif_MPI_File_open( &jbuf, &c_comm, filename, amode, &c_info, &c_fh );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*fh = MPI_File_c2f(c_fh);
}
return;
} /* mpi_file_open */



/* --------------- MPI_File_preallocate --------------- */

static int mpiPif_MPI_File_preallocate( jmp_buf * base_jbuf, MPI_File  * fh, MPI_Offset  * size){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_File_preallocate(  * fh,  * size);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_File_preallocate");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_File_preallocate, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_File_preallocate */



extern int MPI_File_preallocate (MPI_File fh, MPI_Offset size)
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_File_preallocate( &jbuf,  & fh,  & size );

return rc;
} /* MPI_File_preallocate */


extern void F77_MPI_FILE_PREALLOCATE(MPI_Fint  * fh, MPI_Offset  * size , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_File c_fh;

c_fh = MPI_File_f2c(*fh);

rc = mpiPif_MPI_File_preallocate( &jbuf, &c_fh, size );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_file_preallocate */



/* --------------- MPI_File_read --------------- */

static int mpiPif_MPI_File_read( jmp_buf * base_jbuf, MPI_File  * fh, void  *buf, int  * count, MPI_Datatype  * datatype, MPI_Status  *status){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_File_read(  * fh, buf,  * count,  * datatype, status);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

PMPI_Type_size(*datatype, &tsize);
ioSize = (double)(tsize * *count);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_File_read");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_File_read, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_File_read */



extern int MPI_File_read (MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_File_read( &jbuf,  & fh, buf,  & count,  & datatype, status );

return rc;
} /* MPI_File_read */


extern void F77_MPI_FILE_READ(MPI_Fint  * fh, void  *buf, int  * count, MPI_Fint  * datatype, MPI_Status  *status , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_File c_fh;
MPI_Datatype c_datatype;

c_fh = MPI_File_f2c(*fh);
c_datatype = MPI_Type_f2c(*datatype);

rc = mpiPif_MPI_File_read( &jbuf, &c_fh, buf, count, &c_datatype, status );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_file_read */



/* --------------- MPI_File_read_all --------------- */

static int mpiPif_MPI_File_read_all( jmp_buf * base_jbuf, MPI_File  * fh, void  *buf, int  * count, MPI_Datatype  * datatype, MPI_Status  *status){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_File_read_all(  * fh, buf,  * count,  * datatype, status);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

PMPI_Type_size(*datatype, &tsize);
ioSize = (double)(tsize * *count);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_File_read_all");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_File_read_all, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_File_read_all */



extern int MPI_File_read_all (MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_File_read_all( &jbuf,  & fh, buf,  & count,  & datatype, status );

return rc;
} /* MPI_File_read_all */


extern void F77_MPI_FILE_READ_ALL(MPI_Fint  * fh, void  *buf, int  * count, MPI_Fint  * datatype, MPI_Status  *status , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_File c_fh;
MPI_Datatype c_datatype;

c_fh = MPI_File_f2c(*fh);
c_datatype = MPI_Type_f2c(*datatype);

rc = mpiPif_MPI_File_read_all( &jbuf, &c_fh, buf, count, &c_datatype, status );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_file_read_all */



/* --------------- MPI_File_read_at --------------- */

static int mpiPif_MPI_File_read_at( jmp_buf * base_jbuf, MPI_File  * fh, MPI_Offset  * offset, void  *buf, int  * count, MPI_Datatype  * datatype, MPI_Status  *status){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_File_read_at(  * fh,  * offset, buf,  * count,  * datatype, status);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

PMPI_Type_size(*datatype, &tsize);
ioSize = (double)(tsize * *count);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_File_read_at");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_File_read_at, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_File_read_at */



extern int MPI_File_read_at (MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_File_read_at( &jbuf,  & fh,  & offset, buf,  & count,  & datatype, status );

return rc;
} /* MPI_File_read_at */


extern void F77_MPI_FILE_READ_AT(MPI_Fint  * fh, MPI_Offset  * offset, void  *buf, int  * count, MPI_Fint  * datatype, MPI_Status  *status , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_File c_fh;
MPI_Datatype c_datatype;

c_fh = MPI_File_f2c(*fh);
c_datatype = MPI_Type_f2c(*datatype);

rc = mpiPif_MPI_File_read_at( &jbuf, &c_fh, offset, buf, count, &c_datatype, status );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_file_read_at */



/* --------------- MPI_File_seek --------------- */

static int mpiPif_MPI_File_seek( jmp_buf * base_jbuf, MPI_File  * fh, MPI_Offset  * offset, int  * whence){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_File_seek(  * fh,  * offset,  * whence);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_File_seek");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_File_seek, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_File_seek */



extern int MPI_File_seek (MPI_File fh, MPI_Offset offset, int whence)
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_File_seek( &jbuf,  & fh,  & offset,  & whence );

return rc;
} /* MPI_File_seek */


extern void F77_MPI_FILE_SEEK(MPI_Fint  * fh, MPI_Offset  * offset, int  * whence , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_File c_fh;

c_fh = MPI_File_f2c(*fh);

rc = mpiPif_MPI_File_seek( &jbuf, &c_fh, offset, whence );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_file_seek */



/* --------------- MPI_File_set_view --------------- */

static int mpiPif_MPI_File_set_view( jmp_buf * base_jbuf, MPI_File  * fh, MPI_Offset  * disp, MPI_Datatype  * etype, MPI_Datatype  * filetype, char  *datarep, MPI_Info  * info){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_File_set_view(  * fh,  * disp,  * etype,  * filetype, datarep,  * info);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_File_set_view");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_File_set_view, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_File_set_view */



extern int MPI_File_set_view (MPI_File fh, MPI_Offset disp, MPI_Datatype etype, MPI_Datatype filetype, char *datarep, MPI_Info info)
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_File_set_view( &jbuf,  & fh,  & disp,  & etype,  & filetype, datarep,  & info );

return rc;
} /* MPI_File_set_view */


extern void F77_MPI_FILE_SET_VIEW(MPI_Fint  * fh, MPI_Offset  * disp, MPI_Fint  * etype, MPI_Fint  * filetype, char  *datarep, MPI_Fint  * info , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_File c_fh;
MPI_Datatype c_etype;
MPI_Datatype c_filetype;
MPI_Info c_info;

c_fh = MPI_File_f2c(*fh);
c_etype = MPI_Type_f2c(*etype);
c_filetype = MPI_Type_f2c(*filetype);
c_info = MPI_Info_f2c(*info);

rc = mpiPif_MPI_File_set_view( &jbuf, &c_fh, disp, &c_etype, &c_filetype, datarep, &c_info );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_file_set_view */



/* --------------- MPI_File_write --------------- */

static int mpiPif_MPI_File_write( jmp_buf * base_jbuf, MPI_File  * fh, void  *buf, int  * count, MPI_Datatype  * datatype, MPI_Status  *status){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_File_write(  * fh, buf,  * count,  * datatype, status);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

PMPI_Type_size(*datatype, &tsize);
ioSize = (double)(tsize * *count);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_File_write");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_File_write, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_File_write */



extern int MPI_File_write (MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_File_write( &jbuf,  & fh, buf,  & count,  & datatype, status );

return rc;
} /* MPI_File_write */


extern void F77_MPI_FILE_WRITE(MPI_Fint  * fh, void  *buf, int  * count, MPI_Fint  * datatype, MPI_Status  *status , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_File c_fh;
MPI_Datatype c_datatype;

c_fh = MPI_File_f2c(*fh);
c_datatype = MPI_Type_f2c(*datatype);

rc = mpiPif_MPI_File_write( &jbuf, &c_fh, buf, count, &c_datatype, status );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_file_write */



/* --------------- MPI_File_write_all --------------- */

static int mpiPif_MPI_File_write_all( jmp_buf * base_jbuf, MPI_File  * fh, void  *buf, int  * count, MPI_Datatype  * datatype, MPI_Status  *status){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_File_write_all(  * fh, buf,  * count,  * datatype, status);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

PMPI_Type_size(*datatype, &tsize);
ioSize = (double)(tsize * *count);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_File_write_all");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_File_write_all, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_File_write_all */



extern int MPI_File_write_all (MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_File_write_all( &jbuf,  & fh, buf,  & count,  & datatype, status );

return rc;
} /* MPI_File_write_all */


extern void F77_MPI_FILE_WRITE_ALL(MPI_Fint  * fh, void  *buf, int  * count, MPI_Fint  * datatype, MPI_Status  *status , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_File c_fh;
MPI_Datatype c_datatype;

c_fh = MPI_File_f2c(*fh);
c_datatype = MPI_Type_f2c(*datatype);

rc = mpiPif_MPI_File_write_all( &jbuf, &c_fh, buf, count, &c_datatype, status );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_file_write_all */



/* --------------- MPI_File_write_at --------------- */

static int mpiPif_MPI_File_write_at( jmp_buf * base_jbuf, MPI_File  * fh, MPI_Offset  * offset, void  *buf, int  * count, MPI_Datatype  * datatype, MPI_Status  *status){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_File_write_at(  * fh,  * offset, buf,  * count,  * datatype, status);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

PMPI_Type_size(*datatype, &tsize);
ioSize = (double)(tsize * *count);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_File_write_at");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_File_write_at, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_File_write_at */



extern int MPI_File_write_at (MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype, MPI_Status *status)
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_File_write_at( &jbuf,  & fh,  & offset, buf,  & count,  & datatype, status );

return rc;
} /* MPI_File_write_at */


extern void F77_MPI_FILE_WRITE_AT(MPI_Fint  * fh, MPI_Offset  * offset, void  *buf, int  * count, MPI_Fint  * datatype, MPI_Status  *status , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_File c_fh;
MPI_Datatype c_datatype;

c_fh = MPI_File_f2c(*fh);
c_datatype = MPI_Type_f2c(*datatype);

rc = mpiPif_MPI_File_write_at( &jbuf, &c_fh, offset, buf, count, &c_datatype, status );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_file_write_at */



/* --------------- MPI_Gather --------------- */

static int mpiPif_MPI_Gather( jmp_buf * base_jbuf, void  *sendbuf, int  * sendcnt, MPI_Datatype  * sendtype, void  *recvbuf, int  * recvcount, MPI_Datatype  * recvtype, int  * root, MPI_Comm  * comm){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Gather( sendbuf,  * sendcnt,  * sendtype, recvbuf,  * recvcount,  * recvtype,  * root,  * comm);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( *sendtype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*sendtype, &tsize);
messSize = (double)(tsize * *sendcnt);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Gather");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Gather, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Gather */



extern int MPI_Gather ( void *sendbuf, int sendcnt, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, int root, MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Gather( &jbuf, sendbuf,  & sendcnt,  & sendtype, recvbuf,  & recvcount,  & recvtype,  & root,  & comm );

return rc;
} /* MPI_Gather */


extern void F77_MPI_GATHER(void  *sendbuf, int  * sendcnt, MPI_Fint  * sendtype, void  *recvbuf, int  * recvcount, MPI_Fint  * recvtype, int  * root, MPI_Fint  * comm , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_sendtype;
MPI_Datatype c_recvtype;
MPI_Comm c_comm;

c_sendtype = MPI_Type_f2c(*sendtype);
c_recvtype = MPI_Type_f2c(*recvtype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Gather( &jbuf, sendbuf, sendcnt, &c_sendtype, recvbuf, recvcount, &c_recvtype, root, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_gather */



/* --------------- MPI_Gatherv --------------- */

static int mpiPif_MPI_Gatherv( jmp_buf * base_jbuf, void  *sendbuf, int  * sendcnt, MPI_Datatype  * sendtype, void  *recvbuf, int  *recvcnts, int  *displs, MPI_Datatype  * recvtype, int  * root, MPI_Comm  * comm){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Gatherv( sendbuf,  * sendcnt,  * sendtype, recvbuf, recvcnts, displs,  * recvtype,  * root,  * comm);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( *sendtype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*sendtype, &tsize);
messSize = (double)(tsize * *sendcnt);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Gatherv");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Gatherv, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Gatherv */



extern int MPI_Gatherv ( void *sendbuf, int sendcnt, MPI_Datatype sendtype, void *recvbuf, int *recvcnts, int *displs, MPI_Datatype recvtype, int root, MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Gatherv( &jbuf, sendbuf,  & sendcnt,  & sendtype, recvbuf, recvcnts, displs,  & recvtype,  & root,  & comm );

return rc;
} /* MPI_Gatherv */


extern void F77_MPI_GATHERV(void  *sendbuf, int  * sendcnt, MPI_Fint  * sendtype, void  *recvbuf, int  *recvcnts, int  *displs, MPI_Fint  * recvtype, int  * root, MPI_Fint  * comm , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_sendtype;
MPI_Datatype c_recvtype;
MPI_Comm c_comm;

c_sendtype = MPI_Type_f2c(*sendtype);
c_recvtype = MPI_Type_f2c(*recvtype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Gatherv( &jbuf, sendbuf, sendcnt, &c_sendtype, recvbuf, recvcnts, displs, &c_recvtype, root, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_gatherv */



/* --------------- MPI_Get --------------- */

static int mpiPif_MPI_Get( jmp_buf * base_jbuf, void  *origin_addr, int  * origin_count, MPI_Datatype  * origin_datatype, int  * target_rank, MPI_Aint  * target_disp, int  * target_count, MPI_Datatype  * target_datatype, MPI_Win  * win){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Get( origin_addr,  * origin_count,  * origin_datatype,  * target_rank,  * target_disp,  * target_count,  * target_datatype,  * win);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

PMPI_Type_size(*origin_datatype, &tsize);
rmaSize = (double)(tsize * *origin_count);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Get");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Get, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Get */



extern int MPI_Get ( void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win win )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Get( &jbuf, origin_addr,  & origin_count,  & origin_datatype,  & target_rank,  & target_disp,  & target_count,  & target_datatype,  & win );

return rc;
} /* MPI_Get */


extern void F77_MPI_GET(void  *origin_addr, int  * origin_count, MPI_Fint  * origin_datatype, int  * target_rank, MPI_Aint  * target_disp, int  * target_count, MPI_Fint  * target_datatype, MPI_Win  * win , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_origin_datatype;
MPI_Datatype c_target_datatype;

c_origin_datatype = MPI_Type_f2c(*origin_datatype);
c_target_datatype = MPI_Type_f2c(*target_datatype);

rc = mpiPif_MPI_Get( &jbuf, origin_addr, origin_count, &c_origin_datatype, target_rank, target_disp, target_count, &c_target_datatype, win );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_get */



/* --------------- MPI_Graph_create --------------- */

static int mpiPif_MPI_Graph_create( jmp_buf * base_jbuf, MPI_Comm  * comm_old, int  * nnodes, int  *index, int  *edges, int  * reorder, MPI_Comm  *comm_graph){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Graph_create(  * comm_old,  * nnodes, index, edges,  * reorder, comm_graph);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Graph_create");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Graph_create, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Graph_create */



extern int MPI_Graph_create ( MPI_Comm comm_old, int nnodes, int *index, int *edges, int reorder, MPI_Comm *comm_graph )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Graph_create( &jbuf,  & comm_old,  & nnodes, index, edges,  & reorder, comm_graph );

return rc;
} /* MPI_Graph_create */


extern void F77_MPI_GRAPH_CREATE(MPI_Fint  * comm_old, int  * nnodes, int  *index, int  *edges, int  * reorder, MPI_Fint  *comm_graph , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Comm c_comm_old;
MPI_Comm c_comm_graph;

c_comm_old = MPI_Comm_f2c(*comm_old);

rc = mpiPif_MPI_Graph_create( &jbuf, &c_comm_old, nnodes, index, edges, reorder, &c_comm_graph );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*comm_graph = MPI_Comm_c2f(c_comm_graph);
}
return;
} /* mpi_graph_create */



/* --------------- MPI_Graph_get --------------- */

static int mpiPif_MPI_Graph_get( jmp_buf * base_jbuf, MPI_Comm  * comm, int  * maxindex, int  * maxedges, int  *index, int  *edges){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Graph_get(  * comm,  * maxindex,  * maxedges, index, edges);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Graph_get");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Graph_get, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Graph_get */



extern int MPI_Graph_get ( MPI_Comm comm, int maxindex, int maxedges, int *index, int *edges )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Graph_get( &jbuf,  & comm,  & maxindex,  & maxedges, index, edges );

return rc;
} /* MPI_Graph_get */


extern void F77_MPI_GRAPH_GET(MPI_Fint  * comm, int  * maxindex, int  * maxedges, int  *index, int  *edges , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Graph_get( &jbuf, &c_comm, maxindex, maxedges, index, edges );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_graph_get */



/* --------------- MPI_Graph_map --------------- */

static int mpiPif_MPI_Graph_map( jmp_buf * base_jbuf, MPI_Comm  * comm_old, int  * nnodes, int  *index, int  *edges, int  *newrank){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Graph_map(  * comm_old,  * nnodes, index, edges, newrank);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Graph_map");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Graph_map, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Graph_map */



extern int MPI_Graph_map ( MPI_Comm comm_old, int nnodes, int *index, int *edges, int *newrank )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Graph_map( &jbuf,  & comm_old,  & nnodes, index, edges, newrank );

return rc;
} /* MPI_Graph_map */


extern void F77_MPI_GRAPH_MAP(MPI_Fint  * comm_old, int  * nnodes, int  *index, int  *edges, int  *newrank , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Comm c_comm_old;

c_comm_old = MPI_Comm_f2c(*comm_old);

rc = mpiPif_MPI_Graph_map( &jbuf, &c_comm_old, nnodes, index, edges, newrank );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_graph_map */



/* --------------- MPI_Graph_neighbors --------------- */

static int mpiPif_MPI_Graph_neighbors( jmp_buf * base_jbuf, MPI_Comm  * comm, int  * rank, int  * maxneighbors, int  *neighbors){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Graph_neighbors(  * comm,  * rank,  * maxneighbors, neighbors);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Graph_neighbors");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Graph_neighbors, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Graph_neighbors */



extern int MPI_Graph_neighbors ( MPI_Comm comm, int rank, int maxneighbors, int *neighbors )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Graph_neighbors( &jbuf,  & comm,  & rank,  & maxneighbors, neighbors );

return rc;
} /* MPI_Graph_neighbors */


extern void F77_MPI_GRAPH_NEIGHBORS(MPI_Fint  * comm, int  * rank, int  * maxneighbors, int  *neighbors , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Graph_neighbors( &jbuf, &c_comm, rank, maxneighbors, neighbors );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_graph_neighbors */



/* --------------- MPI_Graph_neighbors_count --------------- */

static int mpiPif_MPI_Graph_neighbors_count( jmp_buf * base_jbuf, MPI_Comm  * comm, int  * rank, int  *nneighbors){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Graph_neighbors_count(  * comm,  * rank, nneighbors);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Graph_neighbors_count");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Graph_neighbors_count, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Graph_neighbors_count */



extern int MPI_Graph_neighbors_count ( MPI_Comm comm, int rank, int *nneighbors )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Graph_neighbors_count( &jbuf,  & comm,  & rank, nneighbors );

return rc;
} /* MPI_Graph_neighbors_count */


extern void F77_MPI_GRAPH_NEIGHBORS_COUNT(MPI_Fint  * comm, int  * rank, int  *nneighbors , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Graph_neighbors_count( &jbuf, &c_comm, rank, nneighbors );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_graph_neighbors_count */



/* --------------- MPI_Graphdims_get --------------- */

static int mpiPif_MPI_Graphdims_get( jmp_buf * base_jbuf, MPI_Comm  * comm, int  *nnodes, int  *nedges){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Graphdims_get(  * comm, nnodes, nedges);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Graphdims_get");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Graphdims_get, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Graphdims_get */



extern int MPI_Graphdims_get ( MPI_Comm comm, int *nnodes, int *nedges )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Graphdims_get( &jbuf,  & comm, nnodes, nedges );

return rc;
} /* MPI_Graphdims_get */


extern void F77_MPI_GRAPHDIMS_GET(MPI_Fint  * comm, int  *nnodes, int  *nedges , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Graphdims_get( &jbuf, &c_comm, nnodes, nedges );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_graphdims_get */



/* --------------- MPI_Group_compare --------------- */

static int mpiPif_MPI_Group_compare( jmp_buf * base_jbuf, MPI_Group  * group1, MPI_Group  * group2, int  *result){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Group_compare(  * group1,  * group2, result);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Group_compare");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Group_compare, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Group_compare */



extern int MPI_Group_compare ( MPI_Group group1, MPI_Group group2, int *result )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Group_compare( &jbuf,  & group1,  & group2, result );

return rc;
} /* MPI_Group_compare */


extern void F77_MPI_GROUP_COMPARE(MPI_Fint  * group1, MPI_Fint  * group2, int  *result , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Group c_group1;
MPI_Group c_group2;

c_group1 = MPI_Group_f2c(*group1);
c_group2 = MPI_Group_f2c(*group2);

rc = mpiPif_MPI_Group_compare( &jbuf, &c_group1, &c_group2, result );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_group_compare */



/* --------------- MPI_Group_difference --------------- */

static int mpiPif_MPI_Group_difference( jmp_buf * base_jbuf, MPI_Group  * group1, MPI_Group  * group2, MPI_Group  *group_out){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Group_difference(  * group1,  * group2, group_out);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Group_difference");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Group_difference, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Group_difference */



extern int MPI_Group_difference ( MPI_Group group1, MPI_Group group2, MPI_Group *group_out )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Group_difference( &jbuf,  & group1,  & group2, group_out );

return rc;
} /* MPI_Group_difference */


extern void F77_MPI_GROUP_DIFFERENCE(MPI_Fint  * group1, MPI_Fint  * group2, MPI_Fint  *group_out , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Group c_group1;
MPI_Group c_group2;
MPI_Group c_group_out;

c_group1 = MPI_Group_f2c(*group1);
c_group2 = MPI_Group_f2c(*group2);

rc = mpiPif_MPI_Group_difference( &jbuf, &c_group1, &c_group2, &c_group_out );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*group_out = MPI_Group_c2f(c_group_out);
}
return;
} /* mpi_group_difference */



/* --------------- MPI_Group_excl --------------- */

static int mpiPif_MPI_Group_excl( jmp_buf * base_jbuf, MPI_Group  * group, int  * n, int  *ranks, MPI_Group  *newgroup){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Group_excl(  * group,  * n, ranks, newgroup);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Group_excl");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Group_excl, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Group_excl */



extern int MPI_Group_excl ( MPI_Group group, int n, int *ranks, MPI_Group *newgroup )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Group_excl( &jbuf,  & group,  & n, ranks, newgroup );

return rc;
} /* MPI_Group_excl */


extern void F77_MPI_GROUP_EXCL(MPI_Fint  * group, int  * n, int  *ranks, MPI_Fint  *newgroup , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Group c_group;
MPI_Group c_newgroup;

c_group = MPI_Group_f2c(*group);

rc = mpiPif_MPI_Group_excl( &jbuf, &c_group, n, ranks, &c_newgroup );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*newgroup = MPI_Group_c2f(c_newgroup);
}
return;
} /* mpi_group_excl */



/* --------------- MPI_Group_free --------------- */

static int mpiPif_MPI_Group_free( jmp_buf * base_jbuf, MPI_Group  *group){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Group_free( group);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Group_free");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Group_free, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Group_free */



extern int MPI_Group_free ( MPI_Group *group )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Group_free( &jbuf, group );

return rc;
} /* MPI_Group_free */


extern void F77_MPI_GROUP_FREE(MPI_Fint  *group , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Group c_group;

c_group = MPI_Group_f2c(*group);

rc = mpiPif_MPI_Group_free( &jbuf, &c_group );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*group = MPI_Group_c2f(c_group);
}
return;
} /* mpi_group_free */



/* --------------- MPI_Group_incl --------------- */

static int mpiPif_MPI_Group_incl( jmp_buf * base_jbuf, MPI_Group  * group, int  * n, int  *ranks, MPI_Group  *group_out){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Group_incl(  * group,  * n, ranks, group_out);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Group_incl");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Group_incl, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Group_incl */



extern int MPI_Group_incl ( MPI_Group group, int n, int *ranks, MPI_Group *group_out )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Group_incl( &jbuf,  & group,  & n, ranks, group_out );

return rc;
} /* MPI_Group_incl */


extern void F77_MPI_GROUP_INCL(MPI_Fint  * group, int  * n, int  *ranks, MPI_Fint  *group_out , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Group c_group;
MPI_Group c_group_out;

c_group = MPI_Group_f2c(*group);

rc = mpiPif_MPI_Group_incl( &jbuf, &c_group, n, ranks, &c_group_out );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*group_out = MPI_Group_c2f(c_group_out);
}
return;
} /* mpi_group_incl */



/* --------------- MPI_Group_intersection --------------- */

static int mpiPif_MPI_Group_intersection( jmp_buf * base_jbuf, MPI_Group  * group1, MPI_Group  * group2, MPI_Group  *group_out){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Group_intersection(  * group1,  * group2, group_out);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Group_intersection");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Group_intersection, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Group_intersection */



extern int MPI_Group_intersection ( MPI_Group group1, MPI_Group group2, MPI_Group *group_out )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Group_intersection( &jbuf,  & group1,  & group2, group_out );

return rc;
} /* MPI_Group_intersection */


extern void F77_MPI_GROUP_INTERSECTION(MPI_Fint  * group1, MPI_Fint  * group2, MPI_Fint  *group_out , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Group c_group1;
MPI_Group c_group2;
MPI_Group c_group_out;

c_group1 = MPI_Group_f2c(*group1);
c_group2 = MPI_Group_f2c(*group2);

rc = mpiPif_MPI_Group_intersection( &jbuf, &c_group1, &c_group2, &c_group_out );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*group_out = MPI_Group_c2f(c_group_out);
}
return;
} /* mpi_group_intersection */



/* --------------- MPI_Group_translate_ranks --------------- */

static int mpiPif_MPI_Group_translate_ranks( jmp_buf * base_jbuf, MPI_Group  * group_a, int  * n, int  *ranks_a, MPI_Group  * group_b, int  *ranks_b){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Group_translate_ranks(  * group_a,  * n, ranks_a,  * group_b, ranks_b);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Group_translate_ranks");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Group_translate_ranks, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Group_translate_ranks */



extern int MPI_Group_translate_ranks ( MPI_Group group_a, int n, int *ranks_a, MPI_Group group_b, int *ranks_b )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Group_translate_ranks( &jbuf,  & group_a,  & n, ranks_a,  & group_b, ranks_b );

return rc;
} /* MPI_Group_translate_ranks */


extern void F77_MPI_GROUP_TRANSLATE_RANKS(MPI_Fint  * group_a, int  * n, int  *ranks_a, MPI_Fint  * group_b, int  *ranks_b , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Group c_group_a;
MPI_Group c_group_b;

c_group_a = MPI_Group_f2c(*group_a);
c_group_b = MPI_Group_f2c(*group_b);

rc = mpiPif_MPI_Group_translate_ranks( &jbuf, &c_group_a, n, ranks_a, &c_group_b, ranks_b );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_group_translate_ranks */



/* --------------- MPI_Group_union --------------- */

static int mpiPif_MPI_Group_union( jmp_buf * base_jbuf, MPI_Group  * group1, MPI_Group  * group2, MPI_Group  *group_out){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Group_union(  * group1,  * group2, group_out);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Group_union");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Group_union, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Group_union */



extern int MPI_Group_union ( MPI_Group group1, MPI_Group group2, MPI_Group *group_out )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Group_union( &jbuf,  & group1,  & group2, group_out );

return rc;
} /* MPI_Group_union */


extern void F77_MPI_GROUP_UNION(MPI_Fint  * group1, MPI_Fint  * group2, MPI_Fint  *group_out , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Group c_group1;
MPI_Group c_group2;
MPI_Group c_group_out;

c_group1 = MPI_Group_f2c(*group1);
c_group2 = MPI_Group_f2c(*group2);

rc = mpiPif_MPI_Group_union( &jbuf, &c_group1, &c_group2, &c_group_out );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*group_out = MPI_Group_c2f(c_group_out);
}
return;
} /* mpi_group_union */



/* --------------- MPI_Ibsend --------------- */

static int mpiPif_MPI_Ibsend( jmp_buf * base_jbuf, void  *buf, int  * count, MPI_Datatype  * datatype, int  * dest, int  * tag, MPI_Comm  * comm, MPI_Request  *request){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Ibsend( buf,  * count,  * datatype,  * dest,  * tag,  * comm, request);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( *datatype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*datatype, &tsize);
messSize = (double)(tsize * *count);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Ibsend");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Ibsend, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Ibsend */



extern int MPI_Ibsend ( void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Ibsend( &jbuf, buf,  & count,  & datatype,  & dest,  & tag,  & comm, request );

return rc;
} /* MPI_Ibsend */


extern void F77_MPI_IBSEND(void  *buf, int  * count, MPI_Fint  * datatype, int  * dest, int  * tag, MPI_Fint  * comm, MPI_Fint  *request , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;
MPI_Request c_request;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Ibsend( &jbuf, buf, count, &c_datatype, dest, tag, &c_comm, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_ibsend */



/* --------------- MPI_Intercomm_create --------------- */

static int mpiPif_MPI_Intercomm_create( jmp_buf * base_jbuf, MPI_Comm  * local_comm, int  * local_leader, MPI_Comm  * peer_comm, int  * remote_leader, int  * tag, MPI_Comm  *comm_out){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Intercomm_create(  * local_comm,  * local_leader,  * peer_comm,  * remote_leader,  * tag, comm_out);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Intercomm_create");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Intercomm_create, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Intercomm_create */



extern int MPI_Intercomm_create ( MPI_Comm local_comm, int local_leader, MPI_Comm peer_comm, int remote_leader, int tag, MPI_Comm *comm_out )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Intercomm_create( &jbuf,  & local_comm,  & local_leader,  & peer_comm,  & remote_leader,  & tag, comm_out );

return rc;
} /* MPI_Intercomm_create */


extern void F77_MPI_INTERCOMM_CREATE(MPI_Fint  * local_comm, int  * local_leader, MPI_Fint  * peer_comm, int  * remote_leader, int  * tag, MPI_Fint  *comm_out , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Comm c_local_comm;
MPI_Comm c_peer_comm;
MPI_Comm c_comm_out;

c_local_comm = MPI_Comm_f2c(*local_comm);
c_peer_comm = MPI_Comm_f2c(*peer_comm);

rc = mpiPif_MPI_Intercomm_create( &jbuf, &c_local_comm, local_leader, &c_peer_comm, remote_leader, tag, &c_comm_out );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*comm_out = MPI_Comm_c2f(c_comm_out);
}
return;
} /* mpi_intercomm_create */



/* --------------- MPI_Intercomm_merge --------------- */

static int mpiPif_MPI_Intercomm_merge( jmp_buf * base_jbuf, MPI_Comm  * comm, int  * high, MPI_Comm  *comm_out){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Intercomm_merge(  * comm,  * high, comm_out);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Intercomm_merge");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Intercomm_merge, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Intercomm_merge */



extern int MPI_Intercomm_merge ( MPI_Comm comm, int high, MPI_Comm *comm_out )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Intercomm_merge( &jbuf,  & comm,  & high, comm_out );

return rc;
} /* MPI_Intercomm_merge */


extern void F77_MPI_INTERCOMM_MERGE(MPI_Fint  * comm, int  * high, MPI_Fint  *comm_out , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;
MPI_Comm c_comm_out;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Intercomm_merge( &jbuf, &c_comm, high, &c_comm_out );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*comm_out = MPI_Comm_c2f(c_comm_out);
}
return;
} /* mpi_intercomm_merge */



/* --------------- MPI_Iprobe --------------- */

static int mpiPif_MPI_Iprobe( jmp_buf * base_jbuf, int  * source, int  * tag, MPI_Comm  * comm, int  *flag, MPI_Status  *status){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Iprobe(  * source,  * tag,  * comm, flag, status);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Iprobe");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Iprobe, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Iprobe */



extern int MPI_Iprobe ( int source, int tag, MPI_Comm comm, int *flag, MPI_Status *status )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Iprobe( &jbuf,  & source,  & tag,  & comm, flag, status );

return rc;
} /* MPI_Iprobe */


extern void F77_MPI_IPROBE(int  * source, int  * tag, MPI_Fint  * comm, int  *flag, MPI_Status  *status , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Iprobe( &jbuf, source, tag, &c_comm, flag, status );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_iprobe */



/* --------------- MPI_Irecv --------------- */

static int mpiPif_MPI_Irecv( jmp_buf * base_jbuf, void  *buf, int  * count, MPI_Datatype  * datatype, int  * source, int  * tag, MPI_Comm  * comm, MPI_Request  *request){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Irecv( buf,  * count,  * datatype,  * source,  * tag,  * comm, request);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Irecv");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Irecv, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Irecv */



extern int MPI_Irecv ( void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request *request )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Irecv( &jbuf, buf,  & count,  & datatype,  & source,  & tag,  & comm, request );

return rc;
} /* MPI_Irecv */


extern void F77_MPI_IRECV(void  *buf, int  * count, MPI_Fint  * datatype, int  * source, int  * tag, MPI_Fint  * comm, MPI_Fint  *request , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;
MPI_Request c_request;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Irecv( &jbuf, buf, count, &c_datatype, source, tag, &c_comm, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_irecv */



/* --------------- MPI_Irsend --------------- */

static int mpiPif_MPI_Irsend( jmp_buf * base_jbuf, void  *buf, int  * count, MPI_Datatype  * datatype, int  * dest, int  * tag, MPI_Comm  * comm, MPI_Request  *request){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Irsend( buf,  * count,  * datatype,  * dest,  * tag,  * comm, request);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( *datatype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*datatype, &tsize);
messSize = (double)(tsize * *count);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Irsend");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Irsend, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Irsend */



extern int MPI_Irsend ( void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Irsend( &jbuf, buf,  & count,  & datatype,  & dest,  & tag,  & comm, request );

return rc;
} /* MPI_Irsend */


extern void F77_MPI_IRSEND(void  *buf, int  * count, MPI_Fint  * datatype, int  * dest, int  * tag, MPI_Fint  * comm, MPI_Fint  *request , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;
MPI_Request c_request;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Irsend( &jbuf, buf, count, &c_datatype, dest, tag, &c_comm, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_irsend */



/* --------------- MPI_Isend --------------- */

static int mpiPif_MPI_Isend( jmp_buf * base_jbuf, void  *buf, int  * count, MPI_Datatype  * datatype, int  * dest, int  * tag, MPI_Comm  * comm, MPI_Request  *request){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Isend( buf,  * count,  * datatype,  * dest,  * tag,  * comm, request);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( *datatype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*datatype, &tsize);
messSize = (double)(tsize * *count);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Isend");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Isend, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Isend */



extern int MPI_Isend ( void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Isend( &jbuf, buf,  & count,  & datatype,  & dest,  & tag,  & comm, request );

return rc;
} /* MPI_Isend */


extern void F77_MPI_ISEND(void  *buf, int  * count, MPI_Fint  * datatype, int  * dest, int  * tag, MPI_Fint  * comm, MPI_Fint  *request , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;
MPI_Request c_request;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Isend( &jbuf, buf, count, &c_datatype, dest, tag, &c_comm, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_isend */



/* --------------- MPI_Issend --------------- */

static int mpiPif_MPI_Issend( jmp_buf * base_jbuf, void  *buf, int  * count, MPI_Datatype  * datatype, int  * dest, int  * tag, MPI_Comm  * comm, MPI_Request  *request){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Issend( buf,  * count,  * datatype,  * dest,  * tag,  * comm, request);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( *datatype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*datatype, &tsize);
messSize = (double)(tsize * *count);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Issend");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Issend, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Issend */



extern int MPI_Issend ( void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Issend( &jbuf, buf,  & count,  & datatype,  & dest,  & tag,  & comm, request );

return rc;
} /* MPI_Issend */


extern void F77_MPI_ISSEND(void  *buf, int  * count, MPI_Fint  * datatype, int  * dest, int  * tag, MPI_Fint  * comm, MPI_Fint  *request , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;
MPI_Request c_request;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Issend( &jbuf, buf, count, &c_datatype, dest, tag, &c_comm, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_issend */



/* --------------- MPI_Keyval_create --------------- */

static int mpiPif_MPI_Keyval_create( jmp_buf * base_jbuf, MPI_Copy_function  *copy_fn, MPI_Delete_function  *delete_fn, int  *keyval, void  *extra_state){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Keyval_create( copy_fn, delete_fn, keyval, extra_state);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Keyval_create");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Keyval_create, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Keyval_create */



extern int MPI_Keyval_create ( MPI_Copy_function *copy_fn, MPI_Delete_function *delete_fn, int *keyval, void *extra_state )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Keyval_create( &jbuf, copy_fn, delete_fn, keyval, extra_state );

return rc;
} /* MPI_Keyval_create */


extern void F77_MPI_KEYVAL_CREATE(MPI_Copy_function  *copy_fn, MPI_Delete_function  *delete_fn, int  *keyval, void  *extra_state , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;


rc = mpiPif_MPI_Keyval_create( &jbuf, copy_fn, delete_fn, keyval, extra_state );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_keyval_create */



/* --------------- MPI_Keyval_free --------------- */

static int mpiPif_MPI_Keyval_free( jmp_buf * base_jbuf, int  *keyval){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Keyval_free( keyval);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Keyval_free");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Keyval_free, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Keyval_free */



extern int MPI_Keyval_free ( int *keyval )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Keyval_free( &jbuf, keyval );

return rc;
} /* MPI_Keyval_free */


extern void F77_MPI_KEYVAL_FREE(int  *keyval , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;


rc = mpiPif_MPI_Keyval_free( &jbuf, keyval );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_keyval_free */



/* --------------- MPI_Pack --------------- */

static int mpiPif_MPI_Pack( jmp_buf * base_jbuf, void  *inbuf, int  * incount, MPI_Datatype  * datatype, void  *outbuf, int  * count, int  *position, MPI_Comm  * comm){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Pack( inbuf,  * incount,  * datatype, outbuf,  * count, position,  * comm);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Pack");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Pack, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Pack */



extern int MPI_Pack ( void *inbuf, int incount, MPI_Datatype datatype, void *outbuf, int count, int *position, MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Pack( &jbuf, inbuf,  & incount,  & datatype, outbuf,  & count, position,  & comm );

return rc;
} /* MPI_Pack */


extern void F77_MPI_PACK(void  *inbuf, int  * incount, MPI_Fint  * datatype, void  *outbuf, int  * count, int  *position, MPI_Fint  * comm , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Pack( &jbuf, inbuf, incount, &c_datatype, outbuf, count, position, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_pack */



/* --------------- MPI_Probe --------------- */

static int mpiPif_MPI_Probe( jmp_buf * base_jbuf, int  * source, int  * tag, MPI_Comm  * comm, MPI_Status  *status){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Probe(  * source,  * tag,  * comm, status);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Probe");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Probe, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Probe */



extern int MPI_Probe ( int source, int tag, MPI_Comm comm, MPI_Status *status )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Probe( &jbuf,  & source,  & tag,  & comm, status );

return rc;
} /* MPI_Probe */


extern void F77_MPI_PROBE(int  * source, int  * tag, MPI_Fint  * comm, MPI_Status  *status , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Probe( &jbuf, source, tag, &c_comm, status );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_probe */



/* --------------- MPI_Put --------------- */

static int mpiPif_MPI_Put( jmp_buf * base_jbuf, void  *origin_addr, int  * origin_count, MPI_Datatype  * origin_datatype, int  * target_rank, MPI_Aint  * target_disp, int  * target_count, MPI_Datatype  * target_datatype, MPI_Win  * win){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Put( origin_addr,  * origin_count,  * origin_datatype,  * target_rank,  * target_disp,  * target_count,  * target_datatype,  * win);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

PMPI_Type_size(*origin_datatype, &tsize);
rmaSize = (double)(tsize * *origin_count);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Put");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Put, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Put */



extern int MPI_Put ( void *origin_addr, int origin_count, MPI_Datatype origin_datatype, int target_rank, MPI_Aint target_disp, int target_count, MPI_Datatype target_datatype, MPI_Win win )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Put( &jbuf, origin_addr,  & origin_count,  & origin_datatype,  & target_rank,  & target_disp,  & target_count,  & target_datatype,  & win );

return rc;
} /* MPI_Put */


extern void F77_MPI_PUT(void  *origin_addr, int  * origin_count, MPI_Fint  * origin_datatype, int  * target_rank, MPI_Aint  * target_disp, int  * target_count, MPI_Fint  * target_datatype, MPI_Win  * win , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_origin_datatype;
MPI_Datatype c_target_datatype;

c_origin_datatype = MPI_Type_f2c(*origin_datatype);
c_target_datatype = MPI_Type_f2c(*target_datatype);

rc = mpiPif_MPI_Put( &jbuf, origin_addr, origin_count, &c_origin_datatype, target_rank, target_disp, target_count, &c_target_datatype, win );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_put */



/* --------------- MPI_Recv --------------- */

static int mpiPif_MPI_Recv( jmp_buf * base_jbuf, void  *buf, int  * count, MPI_Datatype  * datatype, int  * source, int  * tag, MPI_Comm  * comm, MPI_Status  *status){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Recv( buf,  * count,  * datatype,  * source,  * tag,  * comm, status);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Recv");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Recv, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Recv */



extern int MPI_Recv ( void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status *status )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Recv( &jbuf, buf,  & count,  & datatype,  & source,  & tag,  & comm, status );

return rc;
} /* MPI_Recv */


extern void F77_MPI_RECV(void  *buf, int  * count, MPI_Fint  * datatype, int  * source, int  * tag, MPI_Fint  * comm, MPI_Status  *status , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Recv( &jbuf, buf, count, &c_datatype, source, tag, &c_comm, status );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_recv */



/* --------------- MPI_Recv_init --------------- */

static int mpiPif_MPI_Recv_init( jmp_buf * base_jbuf, void  *buf, int  * count, MPI_Datatype  * datatype, int  * source, int  * tag, MPI_Comm  * comm, MPI_Request  *request){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Recv_init( buf,  * count,  * datatype,  * source,  * tag,  * comm, request);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Recv_init");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Recv_init, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Recv_init */



extern int MPI_Recv_init ( void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request *request )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Recv_init( &jbuf, buf,  & count,  & datatype,  & source,  & tag,  & comm, request );

return rc;
} /* MPI_Recv_init */


extern void F77_MPI_RECV_INIT(void  *buf, int  * count, MPI_Fint  * datatype, int  * source, int  * tag, MPI_Fint  * comm, MPI_Fint  *request , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;
MPI_Request c_request;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Recv_init( &jbuf, buf, count, &c_datatype, source, tag, &c_comm, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_recv_init */



/* --------------- MPI_Reduce --------------- */

static int mpiPif_MPI_Reduce( jmp_buf * base_jbuf, void  *sendbuf, void  *recvbuf, int  * count, MPI_Datatype  * datatype, MPI_Op  * op, int  * root, MPI_Comm  * comm){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Reduce( sendbuf, recvbuf,  * count,  * datatype,  * op,  * root,  * comm);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( *datatype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*datatype, &tsize);
messSize = (double)(tsize * *count);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Reduce");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Reduce, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Reduce */



extern int MPI_Reduce ( void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Reduce( &jbuf, sendbuf, recvbuf,  & count,  & datatype,  & op,  & root,  & comm );

return rc;
} /* MPI_Reduce */


extern void F77_MPI_REDUCE(void  *sendbuf, void  *recvbuf, int  * count, MPI_Fint  * datatype, MPI_Fint  * op, int  * root, MPI_Fint  * comm , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Op c_op;
MPI_Comm c_comm;

c_datatype = MPI_Type_f2c(*datatype);
c_op = MPI_Op_f2c(*op);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Reduce( &jbuf, sendbuf, recvbuf, count, &c_datatype, &c_op, root, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_reduce */



/* --------------- MPI_Reduce_scatter --------------- */

static int mpiPif_MPI_Reduce_scatter( jmp_buf * base_jbuf, void  *sendbuf, void  *recvbuf, int  *recvcnts, MPI_Datatype  * datatype, MPI_Op  * op, MPI_Comm  * comm){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Reduce_scatter( sendbuf, recvbuf, recvcnts,  * datatype,  * op,  * comm);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Reduce_scatter");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Reduce_scatter, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Reduce_scatter */



extern int MPI_Reduce_scatter ( void *sendbuf, void *recvbuf, int *recvcnts, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Reduce_scatter( &jbuf, sendbuf, recvbuf, recvcnts,  & datatype,  & op,  & comm );

return rc;
} /* MPI_Reduce_scatter */


extern void F77_MPI_REDUCE_SCATTER(void  *sendbuf, void  *recvbuf, int  *recvcnts, MPI_Fint  * datatype, MPI_Fint  * op, MPI_Fint  * comm , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Op c_op;
MPI_Comm c_comm;

c_datatype = MPI_Type_f2c(*datatype);
c_op = MPI_Op_f2c(*op);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Reduce_scatter( &jbuf, sendbuf, recvbuf, recvcnts, &c_datatype, &c_op, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_reduce_scatter */



/* --------------- MPI_Request_free --------------- */

static int mpiPif_MPI_Request_free( jmp_buf * base_jbuf, MPI_Request  *request){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Request_free( request);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Request_free");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Request_free, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Request_free */



extern int MPI_Request_free ( MPI_Request *request )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Request_free( &jbuf, request );

return rc;
} /* MPI_Request_free */


extern void F77_MPI_REQUEST_FREE(MPI_Fint  *request , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Request c_request;

c_request = MPI_Request_f2c(*request);

rc = mpiPif_MPI_Request_free( &jbuf, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_request_free */



/* --------------- MPI_Rsend --------------- */

static int mpiPif_MPI_Rsend( jmp_buf * base_jbuf, void  *buf, int  * count, MPI_Datatype  * datatype, int  * dest, int  * tag, MPI_Comm  * comm){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Rsend( buf,  * count,  * datatype,  * dest,  * tag,  * comm);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( *datatype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*datatype, &tsize);
messSize = (double)(tsize * *count);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Rsend");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Rsend, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Rsend */



extern int MPI_Rsend ( void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Rsend( &jbuf, buf,  & count,  & datatype,  & dest,  & tag,  & comm );

return rc;
} /* MPI_Rsend */


extern void F77_MPI_RSEND(void  *buf, int  * count, MPI_Fint  * datatype, int  * dest, int  * tag, MPI_Fint  * comm , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Rsend( &jbuf, buf, count, &c_datatype, dest, tag, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_rsend */



/* --------------- MPI_Rsend_init --------------- */

static int mpiPif_MPI_Rsend_init( jmp_buf * base_jbuf, void  *buf, int  * count, MPI_Datatype  * datatype, int  * dest, int  * tag, MPI_Comm  * comm, MPI_Request  *request){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Rsend_init( buf,  * count,  * datatype,  * dest,  * tag,  * comm, request);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Rsend_init");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Rsend_init, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Rsend_init */



extern int MPI_Rsend_init ( void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Rsend_init( &jbuf, buf,  & count,  & datatype,  & dest,  & tag,  & comm, request );

return rc;
} /* MPI_Rsend_init */


extern void F77_MPI_RSEND_INIT(void  *buf, int  * count, MPI_Fint  * datatype, int  * dest, int  * tag, MPI_Fint  * comm, MPI_Fint  *request , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;
MPI_Request c_request;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Rsend_init( &jbuf, buf, count, &c_datatype, dest, tag, &c_comm, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_rsend_init */



/* --------------- MPI_Scan --------------- */

static int mpiPif_MPI_Scan( jmp_buf * base_jbuf, void  *sendbuf, void  *recvbuf, int  * count, MPI_Datatype  * datatype, MPI_Op  * op, MPI_Comm  * comm){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Scan( sendbuf, recvbuf,  * count,  * datatype,  * op,  * comm);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( *datatype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*datatype, &tsize);
messSize = (double)(tsize * *count);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Scan");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Scan, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Scan */



extern int MPI_Scan ( void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Scan( &jbuf, sendbuf, recvbuf,  & count,  & datatype,  & op,  & comm );

return rc;
} /* MPI_Scan */


extern void F77_MPI_SCAN(void  *sendbuf, void  *recvbuf, int  * count, MPI_Fint  * datatype, MPI_Fint  * op, MPI_Fint  * comm , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Op c_op;
MPI_Comm c_comm;

c_datatype = MPI_Type_f2c(*datatype);
c_op = MPI_Op_f2c(*op);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Scan( &jbuf, sendbuf, recvbuf, count, &c_datatype, &c_op, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_scan */



/* --------------- MPI_Scatter --------------- */

static int mpiPif_MPI_Scatter( jmp_buf * base_jbuf, void  *sendbuf, int  * sendcnt, MPI_Datatype  * sendtype, void  *recvbuf, int  * recvcnt, MPI_Datatype  * recvtype, int  * root, MPI_Comm  * comm){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Scatter( sendbuf,  * sendcnt,  * sendtype, recvbuf,  * recvcnt,  * recvtype,  * root,  * comm);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( *sendtype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*sendtype, &tsize);
messSize = (double)(tsize * *sendcnt);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Scatter");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Scatter, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Scatter */



extern int MPI_Scatter ( void *sendbuf, int sendcnt, MPI_Datatype sendtype, void *recvbuf, int recvcnt, MPI_Datatype recvtype, int root, MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Scatter( &jbuf, sendbuf,  & sendcnt,  & sendtype, recvbuf,  & recvcnt,  & recvtype,  & root,  & comm );

return rc;
} /* MPI_Scatter */


extern void F77_MPI_SCATTER(void  *sendbuf, int  * sendcnt, MPI_Fint  * sendtype, void  *recvbuf, int  * recvcnt, MPI_Fint  * recvtype, int  * root, MPI_Fint  * comm , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_sendtype;
MPI_Datatype c_recvtype;
MPI_Comm c_comm;

c_sendtype = MPI_Type_f2c(*sendtype);
c_recvtype = MPI_Type_f2c(*recvtype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Scatter( &jbuf, sendbuf, sendcnt, &c_sendtype, recvbuf, recvcnt, &c_recvtype, root, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_scatter */



/* --------------- MPI_Scatterv --------------- */

static int mpiPif_MPI_Scatterv( jmp_buf * base_jbuf, void  *sendbuf, int  *sendcnts, int  *displs, MPI_Datatype  * sendtype, void  *recvbuf, int  * recvcnt, MPI_Datatype  * recvtype, int  * root, MPI_Comm  * comm){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Scatterv( sendbuf, sendcnts, displs,  * sendtype, recvbuf,  * recvcnt,  * recvtype,  * root,  * comm);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Scatterv");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Scatterv, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Scatterv */



extern int MPI_Scatterv ( void *sendbuf, int *sendcnts, int *displs, MPI_Datatype sendtype, void *recvbuf, int recvcnt, MPI_Datatype recvtype, int root, MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Scatterv( &jbuf, sendbuf, sendcnts, displs,  & sendtype, recvbuf,  & recvcnt,  & recvtype,  & root,  & comm );

return rc;
} /* MPI_Scatterv */


extern void F77_MPI_SCATTERV(void  *sendbuf, int  *sendcnts, int  *displs, MPI_Fint  * sendtype, void  *recvbuf, int  * recvcnt, MPI_Fint  * recvtype, int  * root, MPI_Fint  * comm , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_sendtype;
MPI_Datatype c_recvtype;
MPI_Comm c_comm;

c_sendtype = MPI_Type_f2c(*sendtype);
c_recvtype = MPI_Type_f2c(*recvtype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Scatterv( &jbuf, sendbuf, sendcnts, displs, &c_sendtype, recvbuf, recvcnt, &c_recvtype, root, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_scatterv */



/* --------------- MPI_Send --------------- */

static int mpiPif_MPI_Send( jmp_buf * base_jbuf, void  *buf, int  * count, MPI_Datatype  * datatype, int  * dest, int  * tag, MPI_Comm  * comm){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Send( buf,  * count,  * datatype,  * dest,  * tag,  * comm);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( *datatype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*datatype, &tsize);
messSize = (double)(tsize * *count);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Send");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Send, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Send */



extern int MPI_Send ( void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Send( &jbuf, buf,  & count,  & datatype,  & dest,  & tag,  & comm );

return rc;
} /* MPI_Send */


extern void F77_MPI_SEND(void  *buf, int  * count, MPI_Fint  * datatype, int  * dest, int  * tag, MPI_Fint  * comm , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Send( &jbuf, buf, count, &c_datatype, dest, tag, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_send */



/* --------------- MPI_Send_init --------------- */

static int mpiPif_MPI_Send_init( jmp_buf * base_jbuf, void  *buf, int  * count, MPI_Datatype  * datatype, int  * dest, int  * tag, MPI_Comm  * comm, MPI_Request  *request){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Send_init( buf,  * count,  * datatype,  * dest,  * tag,  * comm, request);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Send_init");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Send_init, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Send_init */



extern int MPI_Send_init ( void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Send_init( &jbuf, buf,  & count,  & datatype,  & dest,  & tag,  & comm, request );

return rc;
} /* MPI_Send_init */


extern void F77_MPI_SEND_INIT(void  *buf, int  * count, MPI_Fint  * datatype, int  * dest, int  * tag, MPI_Fint  * comm, MPI_Fint  *request , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;
MPI_Request c_request;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Send_init( &jbuf, buf, count, &c_datatype, dest, tag, &c_comm, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_send_init */



/* --------------- MPI_Sendrecv --------------- */

static int mpiPif_MPI_Sendrecv( jmp_buf * base_jbuf, void  *sendbuf, int  * sendcount, MPI_Datatype  * sendtype, int  * dest, int  * sendtag, void  *recvbuf, int  * recvcount, MPI_Datatype  * recvtype, int  * source, int  * recvtag, MPI_Comm  * comm, MPI_Status  *status){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Sendrecv( sendbuf,  * sendcount,  * sendtype,  * dest,  * sendtag, recvbuf,  * recvcount,  * recvtype,  * source,  * recvtag,  * comm, status);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( *sendtype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*sendtype, &tsize);
messSize = (double)(tsize * *sendcount);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Sendrecv");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Sendrecv, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Sendrecv */



extern int MPI_Sendrecv ( void *sendbuf, int sendcount, MPI_Datatype sendtype, int dest, int sendtag, void *recvbuf, int recvcount, MPI_Datatype recvtype, int source, int recvtag, MPI_Comm comm, MPI_Status *status )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Sendrecv( &jbuf, sendbuf,  & sendcount,  & sendtype,  & dest,  & sendtag, recvbuf,  & recvcount,  & recvtype,  & source,  & recvtag,  & comm, status );

return rc;
} /* MPI_Sendrecv */


extern void F77_MPI_SENDRECV(void  *sendbuf, int  * sendcount, MPI_Fint  * sendtype, int  * dest, int  * sendtag, void  *recvbuf, int  * recvcount, MPI_Fint  * recvtype, int  * source, int  * recvtag, MPI_Fint  * comm, MPI_Status  *status , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_sendtype;
MPI_Datatype c_recvtype;
MPI_Comm c_comm;

c_sendtype = MPI_Type_f2c(*sendtype);
c_recvtype = MPI_Type_f2c(*recvtype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Sendrecv( &jbuf, sendbuf, sendcount, &c_sendtype, dest, sendtag, recvbuf, recvcount, &c_recvtype, source, recvtag, &c_comm, status );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_sendrecv */



/* --------------- MPI_Sendrecv_replace --------------- */

static int mpiPif_MPI_Sendrecv_replace( jmp_buf * base_jbuf, void  *buf, int  * count, MPI_Datatype  * datatype, int  * dest, int  * sendtag, int  * source, int  * recvtag, MPI_Comm  * comm, MPI_Status  *status){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Sendrecv_replace( buf,  * count,  * datatype,  * dest,  * sendtag,  * source,  * recvtag,  * comm, status);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( *datatype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*datatype, &tsize);
messSize = (double)(tsize * *count);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Sendrecv_replace");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Sendrecv_replace, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Sendrecv_replace */



extern int MPI_Sendrecv_replace ( void *buf, int count, MPI_Datatype datatype, int dest, int sendtag, int source, int recvtag, MPI_Comm comm, MPI_Status *status )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Sendrecv_replace( &jbuf, buf,  & count,  & datatype,  & dest,  & sendtag,  & source,  & recvtag,  & comm, status );

return rc;
} /* MPI_Sendrecv_replace */


extern void F77_MPI_SENDRECV_REPLACE(void  *buf, int  * count, MPI_Fint  * datatype, int  * dest, int  * sendtag, int  * source, int  * recvtag, MPI_Fint  * comm, MPI_Status  *status , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Sendrecv_replace( &jbuf, buf, count, &c_datatype, dest, sendtag, source, recvtag, &c_comm, status );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_sendrecv_replace */



/* --------------- MPI_Ssend --------------- */

static int mpiPif_MPI_Ssend( jmp_buf * base_jbuf, void  *buf, int  * count, MPI_Datatype  * datatype, int  * dest, int  * tag, MPI_Comm  * comm){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Ssend( buf,  * count,  * datatype,  * dest,  * tag,  * comm);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( *datatype != MPI_DATATYPE_NULL ) { PMPI_Type_size(*datatype, &tsize);
messSize = (double)(tsize * *count);}
else { mpiPi_msg_warn("MPI_DATATYPE_NULL encountered.  MPI_IN_PLACE not supported.\n");
mpiPi_msg_warn("Values for %s may be invalid for rank %d.\n", &(__func__)[7], mpiPi.rank);}

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Ssend");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Ssend, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Ssend */



extern int MPI_Ssend ( void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Ssend( &jbuf, buf,  & count,  & datatype,  & dest,  & tag,  & comm );

return rc;
} /* MPI_Ssend */


extern void F77_MPI_SSEND(void  *buf, int  * count, MPI_Fint  * datatype, int  * dest, int  * tag, MPI_Fint  * comm , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Ssend( &jbuf, buf, count, &c_datatype, dest, tag, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_ssend */



/* --------------- MPI_Ssend_init --------------- */

static int mpiPif_MPI_Ssend_init( jmp_buf * base_jbuf, void  *buf, int  * count, MPI_Datatype  * datatype, int  * dest, int  * tag, MPI_Comm  * comm, MPI_Request  *request){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Ssend_init( buf,  * count,  * datatype,  * dest,  * tag,  * comm, request);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Ssend_init");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Ssend_init, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Ssend_init */



extern int MPI_Ssend_init ( void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Ssend_init( &jbuf, buf,  & count,  & datatype,  & dest,  & tag,  & comm, request );

return rc;
} /* MPI_Ssend_init */


extern void F77_MPI_SSEND_INIT(void  *buf, int  * count, MPI_Fint  * datatype, int  * dest, int  * tag, MPI_Fint  * comm, MPI_Fint  *request , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;
MPI_Request c_request;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Ssend_init( &jbuf, buf, count, &c_datatype, dest, tag, &c_comm, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_ssend_init */



/* --------------- MPI_Start --------------- */

static int mpiPif_MPI_Start( jmp_buf * base_jbuf, MPI_Request  *request){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Start( request);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Start");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Start, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Start */



extern int MPI_Start ( MPI_Request *request )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Start( &jbuf, request );

return rc;
} /* MPI_Start */


extern void F77_MPI_START(MPI_Fint  *request , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Request c_request;

c_request = MPI_Request_f2c(*request);

rc = mpiPif_MPI_Start( &jbuf, &c_request );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_start */



/* --------------- MPI_Startall --------------- */

static int mpiPif_MPI_Startall( jmp_buf * base_jbuf, int  * count, MPI_Request  *array_of_requests){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Startall(  * count, array_of_requests);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Startall");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Startall, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Startall */



extern int MPI_Startall ( int count, MPI_Request *array_of_requests )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Startall( &jbuf,  & count, array_of_requests );

return rc;
} /* MPI_Startall */


extern void F77_MPI_STARTALL(int  * count, MPI_Fint  *array_of_requests , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Request *c_array_of_requests;

c_array_of_requests = (MPI_Request*)malloc(sizeof(MPI_Request)*(*count));
if ( c_array_of_requests == NULL ) mpiPi_abort("Failed to allocate memory in MPI_Startall");
{
  int i; 
  for (i = 0; i < *count; i++) { 
    c_array_of_requests[i] = MPI_Request_f2c(array_of_requests[i]);
  }
}

rc = mpiPif_MPI_Startall( &jbuf, count, c_array_of_requests );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
{
  int i; 
  for (i = 0; i < *count; i++) { 
    array_of_requests[i] = MPI_Request_c2f(c_array_of_requests[i]);
  }
}
}
free(c_array_of_requests);
return;
} /* mpi_startall */



/* --------------- MPI_Test --------------- */

static int mpiPif_MPI_Test( jmp_buf * base_jbuf, MPI_Request  *request, int  *flag, MPI_Status  *status){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Test( request, flag, status);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Test");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Test, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Test */



extern int MPI_Test ( MPI_Request *request, int *flag, MPI_Status *status )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Test( &jbuf, request, flag, status );

return rc;
} /* MPI_Test */


extern void F77_MPI_TEST(MPI_Fint  *request, int  *flag, MPI_Status  *status , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Request c_request;

c_request = MPI_Request_f2c(*request);

rc = mpiPif_MPI_Test( &jbuf, &c_request, flag, status );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_test */



/* --------------- MPI_Testall --------------- */

static int mpiPif_MPI_Testall( jmp_buf * base_jbuf, int  * count, MPI_Request  *array_of_requests, int  *flag, MPI_Status  *array_of_statuses){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Testall(  * count, array_of_requests, flag, array_of_statuses);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Testall");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Testall, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Testall */



extern int MPI_Testall ( int count, MPI_Request *array_of_requests, int *flag, MPI_Status *array_of_statuses )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Testall( &jbuf,  & count, array_of_requests, flag, array_of_statuses );

return rc;
} /* MPI_Testall */


extern void F77_MPI_TESTALL(int  * count, MPI_Fint  *array_of_requests, int  *flag, MPI_Status  *array_of_statuses , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Request *c_array_of_requests;

c_array_of_requests = (MPI_Request*)malloc(sizeof(MPI_Request)*(*count));
if ( c_array_of_requests == NULL ) mpiPi_abort("Failed to allocate memory in MPI_Testall");
{
  int i; 
  for (i = 0; i < *count; i++) { 
    c_array_of_requests[i] = MPI_Request_f2c(array_of_requests[i]);
  }
}

rc = mpiPif_MPI_Testall( &jbuf, count, c_array_of_requests, flag, array_of_statuses );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
{
  int i; 
  for (i = 0; i < *count; i++) { 
    array_of_requests[i] = MPI_Request_c2f(c_array_of_requests[i]);
  }
}
}
free(c_array_of_requests);
return;
} /* mpi_testall */



/* --------------- MPI_Testany --------------- */

static int mpiPif_MPI_Testany( jmp_buf * base_jbuf, int  * count, MPI_Request  *array_of_requests, int  *index, int  *flag, MPI_Status  *status){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Testany(  * count, array_of_requests, index, flag, status);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Testany");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Testany, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Testany */



extern int MPI_Testany ( int count, MPI_Request *array_of_requests, int *index, int *flag, MPI_Status *status )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Testany( &jbuf,  & count, array_of_requests, index, flag, status );

return rc;
} /* MPI_Testany */


extern void F77_MPI_TESTANY(int  * count, MPI_Fint  *array_of_requests, int  *index, int  *flag, MPI_Status  *status , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Request *c_array_of_requests;

c_array_of_requests = (MPI_Request*)malloc(sizeof(MPI_Request)*(*count));
if ( c_array_of_requests == NULL ) mpiPi_abort("Failed to allocate memory in MPI_Testany");
{
  int i; 
  for (i = 0; i < *count; i++) { 
    c_array_of_requests[i] = MPI_Request_f2c(array_of_requests[i]);
  }
}

rc = mpiPif_MPI_Testany( &jbuf, count, c_array_of_requests, index, flag, status );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
array_of_requests[*index] = MPI_Request_c2f(c_array_of_requests[*index]);
if ( *index >= 0 ) (*index)++;
}
free(c_array_of_requests);
return;
} /* mpi_testany */



/* --------------- MPI_Testsome --------------- */

static int mpiPif_MPI_Testsome( jmp_buf * base_jbuf, int  * incount, MPI_Request  *array_of_requests, int  *count, int  *array_of_indices, MPI_Status  *array_of_statuses){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Testsome(  * incount, array_of_requests, count, array_of_indices, array_of_statuses);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Testsome");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Testsome, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Testsome */



extern int MPI_Testsome ( int incount, MPI_Request *array_of_requests, int *count, int *array_of_indices, MPI_Status *array_of_statuses )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Testsome( &jbuf,  & incount, array_of_requests, count, array_of_indices, array_of_statuses );

return rc;
} /* MPI_Testsome */


extern void F77_MPI_TESTSOME(int  * incount, MPI_Fint  *array_of_requests, int  *count, int  *array_of_indices, MPI_Status  *array_of_statuses , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Request *c_array_of_requests;

c_array_of_requests = (MPI_Request*)malloc(sizeof(MPI_Request)*(*incount));
if ( c_array_of_requests == NULL ) mpiPi_abort("Failed to allocate memory in MPI_Testsome");
{
  int i; 
  for (i = 0; i < *incount; i++) { 
    c_array_of_requests[i] = MPI_Request_f2c(array_of_requests[i]);
  }
}

rc = mpiPif_MPI_Testsome( &jbuf, incount, c_array_of_requests, count, array_of_indices, array_of_statuses );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
{
  int i; 
  for (i = 0; i < *incount; i++) { 
    array_of_requests[i] = MPI_Request_c2f(c_array_of_requests[i]);
  }
}
{ int i; for ( i = 0; i < *count; i++)  array_of_indices[i]++;}
}
free(c_array_of_requests);
return;
} /* mpi_testsome */



/* --------------- MPI_Topo_test --------------- */

static int mpiPif_MPI_Topo_test( jmp_buf * base_jbuf, MPI_Comm  * comm, int  *top_type){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Topo_test(  * comm, top_type);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Topo_test");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Topo_test, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Topo_test */



extern int MPI_Topo_test ( MPI_Comm comm, int *top_type )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Topo_test( &jbuf,  & comm, top_type );

return rc;
} /* MPI_Topo_test */


extern void F77_MPI_TOPO_TEST(MPI_Fint  * comm, int  *top_type , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Comm c_comm;

c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Topo_test( &jbuf, &c_comm, top_type );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_topo_test */



/* --------------- MPI_Type_commit --------------- */

static int mpiPif_MPI_Type_commit( jmp_buf * base_jbuf, MPI_Datatype  *datatype){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Type_commit( datatype);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Type_commit");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Type_commit, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Type_commit */



extern int MPI_Type_commit ( MPI_Datatype *datatype )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Type_commit( &jbuf, datatype );

return rc;
} /* MPI_Type_commit */


extern void F77_MPI_TYPE_COMMIT(MPI_Fint  *datatype , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;

c_datatype = MPI_Type_f2c(*datatype);

rc = mpiPif_MPI_Type_commit( &jbuf, &c_datatype );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*datatype = MPI_Type_c2f(c_datatype);
}
return;
} /* mpi_type_commit */



/* --------------- MPI_Type_free --------------- */

static int mpiPif_MPI_Type_free( jmp_buf * base_jbuf, MPI_Datatype  *datatype){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Type_free( datatype);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Type_free");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Type_free, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Type_free */



extern int MPI_Type_free ( MPI_Datatype *datatype )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Type_free( &jbuf, datatype );

return rc;
} /* MPI_Type_free */


extern void F77_MPI_TYPE_FREE(MPI_Fint  *datatype , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;

c_datatype = MPI_Type_f2c(*datatype);

rc = mpiPif_MPI_Type_free( &jbuf, &c_datatype );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*datatype = MPI_Type_c2f(c_datatype);
}
return;
} /* mpi_type_free */



/* --------------- MPI_Type_get_contents --------------- */

static int mpiPif_MPI_Type_get_contents( jmp_buf * base_jbuf, MPI_Datatype  * datatype, int  * max_integers, int  * max_addresses, int  * max_datatypes, int  *array_of_integers, MPI_Aint  *array_of_addresses, MPI_Datatype  *array_of_datatypes){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Type_get_contents(  * datatype,  * max_integers,  * max_addresses,  * max_datatypes, array_of_integers, array_of_addresses, array_of_datatypes);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Type_get_contents");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Type_get_contents, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Type_get_contents */



extern int MPI_Type_get_contents ( MPI_Datatype datatype, int max_integers, int max_addresses, int max_datatypes, int *array_of_integers, MPI_Aint *array_of_addresses, MPI_Datatype *array_of_datatypes )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Type_get_contents( &jbuf,  & datatype,  & max_integers,  & max_addresses,  & max_datatypes, array_of_integers, array_of_addresses, array_of_datatypes );

return rc;
} /* MPI_Type_get_contents */


extern void F77_MPI_TYPE_GET_CONTENTS(MPI_Fint  * datatype, int  * max_integers, int  * max_addresses, int  * max_datatypes, int  *array_of_integers, MPI_Aint  *array_of_addresses, MPI_Fint  *array_of_datatypes , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Datatype *c_array_of_datatypes;

c_array_of_datatypes = (MPI_Datatype*)malloc(sizeof(MPI_Datatype)*(*max_integers));
if ( c_array_of_datatypes == NULL ) mpiPi_abort("Failed to allocate memory in MPI_Type_get_contents");
c_datatype = MPI_Type_f2c(*datatype);

rc = mpiPif_MPI_Type_get_contents( &jbuf, &c_datatype, max_integers, max_addresses, max_datatypes, array_of_integers, array_of_addresses, c_array_of_datatypes );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
{
  int i; 
  for (i = 0; i < *max_integers; i++) { 
    array_of_datatypes[i] = MPI_Type_c2f(c_array_of_datatypes[i]);
  }
}
}
free(c_array_of_datatypes);
return;
} /* mpi_type_get_contents */



/* --------------- MPI_Type_get_envelope --------------- */

static int mpiPif_MPI_Type_get_envelope( jmp_buf * base_jbuf, MPI_Datatype  * datatype, int  *num_integers, int  *num_addresses, int  *num_datatypes, int  *combiner){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Type_get_envelope(  * datatype, num_integers, num_addresses, num_datatypes, combiner);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Type_get_envelope");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Type_get_envelope, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Type_get_envelope */



extern int MPI_Type_get_envelope ( MPI_Datatype datatype, int *num_integers, int *num_addresses, int *num_datatypes, int *combiner )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Type_get_envelope( &jbuf,  & datatype, num_integers, num_addresses, num_datatypes, combiner );

return rc;
} /* MPI_Type_get_envelope */


extern void F77_MPI_TYPE_GET_ENVELOPE(MPI_Fint  * datatype, int  *num_integers, int  *num_addresses, int  *num_datatypes, int  *combiner , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;

c_datatype = MPI_Type_f2c(*datatype);

rc = mpiPif_MPI_Type_get_envelope( &jbuf, &c_datatype, num_integers, num_addresses, num_datatypes, combiner );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_type_get_envelope */



/* --------------- MPI_Unpack --------------- */

static int mpiPif_MPI_Unpack( jmp_buf * base_jbuf, void  *inbuf, int  * insize, int  *position, void  *outbuf, int  * count, MPI_Datatype  * datatype, MPI_Comm  * comm){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Unpack( inbuf,  * insize, position, outbuf,  * count,  * datatype,  * comm);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Unpack");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Unpack, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Unpack */



extern int MPI_Unpack ( void *inbuf, int insize, int *position, void *outbuf, int count, MPI_Datatype datatype, MPI_Comm comm )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Unpack( &jbuf, inbuf,  & insize, position, outbuf,  & count,  & datatype,  & comm );

return rc;
} /* MPI_Unpack */


extern void F77_MPI_UNPACK(void  *inbuf, int  * insize, int  *position, void  *outbuf, int  * count, MPI_Fint  * datatype, MPI_Fint  * comm , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Datatype c_datatype;
MPI_Comm c_comm;

c_datatype = MPI_Type_f2c(*datatype);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Unpack( &jbuf, inbuf, insize, position, outbuf, count, &c_datatype, &c_comm );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_unpack */



/* --------------- MPI_Wait --------------- */

static int mpiPif_MPI_Wait( jmp_buf * base_jbuf, MPI_Request  *request, MPI_Status  *status){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Wait( request, status);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Wait");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Wait, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Wait */



extern int MPI_Wait ( MPI_Request *request, MPI_Status *status )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Wait( &jbuf, request, status );

return rc;
} /* MPI_Wait */


extern void F77_MPI_WAIT(MPI_Fint  *request, MPI_Status  *status , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Request c_request;

c_request = MPI_Request_f2c(*request);

rc = mpiPif_MPI_Wait( &jbuf, &c_request, status );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
*request = MPI_Request_c2f(c_request);
}
return;
} /* mpi_wait */



/* --------------- MPI_Waitall --------------- */

static int mpiPif_MPI_Waitall( jmp_buf * base_jbuf, int  * count, MPI_Request  *array_of_requests, MPI_Status  *array_of_statuses){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Waitall(  * count, array_of_requests, array_of_statuses);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Waitall");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Waitall, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Waitall */



extern int MPI_Waitall ( int count, MPI_Request *array_of_requests, MPI_Status *array_of_statuses )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Waitall( &jbuf,  & count, array_of_requests, array_of_statuses );

return rc;
} /* MPI_Waitall */


extern void F77_MPI_WAITALL(int  * count, MPI_Fint  *array_of_requests, MPI_Status  *array_of_statuses , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Request *c_array_of_requests;

c_array_of_requests = (MPI_Request*)malloc(sizeof(MPI_Request)*(*count));
if ( c_array_of_requests == NULL ) mpiPi_abort("Failed to allocate memory in MPI_Waitall");
{
  int i; 
  for (i = 0; i < *count; i++) { 
    c_array_of_requests[i] = MPI_Request_f2c(array_of_requests[i]);
  }
}

rc = mpiPif_MPI_Waitall( &jbuf, count, c_array_of_requests, array_of_statuses );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
{
  int i; 
  for (i = 0; i < *count; i++) { 
    array_of_requests[i] = MPI_Request_c2f(c_array_of_requests[i]);
  }
}
}
free(c_array_of_requests);
return;
} /* mpi_waitall */



/* --------------- MPI_Waitany --------------- */

static int mpiPif_MPI_Waitany( jmp_buf * base_jbuf, int  * count, MPI_Request  *array_of_requests, int  *index, MPI_Status  *status){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Waitany(  * count, array_of_requests, index, status);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Waitany");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Waitany, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Waitany */



extern int MPI_Waitany ( int count, MPI_Request *array_of_requests, int *index, MPI_Status *status )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Waitany( &jbuf,  & count, array_of_requests, index, status );

return rc;
} /* MPI_Waitany */


extern void F77_MPI_WAITANY(int  * count, MPI_Fint  *array_of_requests, int  *index, MPI_Status  *status , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Request *c_array_of_requests;

c_array_of_requests = (MPI_Request*)malloc(sizeof(MPI_Request)*(*count));
if ( c_array_of_requests == NULL ) mpiPi_abort("Failed to allocate memory in MPI_Waitany");
{
  int i; 
  for (i = 0; i < *count; i++) { 
    c_array_of_requests[i] = MPI_Request_f2c(array_of_requests[i]);
  }
}

rc = mpiPif_MPI_Waitany( &jbuf, count, c_array_of_requests, index, status );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
array_of_requests[*index] = MPI_Request_c2f(c_array_of_requests[*index]);
if ( *index >= 0 ) (*index)++;
}
free(c_array_of_requests);
return;
} /* mpi_waitany */



/* --------------- MPI_Waitsome --------------- */

static int mpiPif_MPI_Waitsome( jmp_buf * base_jbuf, int  * incount, MPI_Request  *array_of_requests, int  *count, int  *array_of_indices, MPI_Status  *array_of_statuses){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Waitsome(  * incount, array_of_requests, count, array_of_indices, array_of_statuses);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Waitsome");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Waitsome, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Waitsome */



extern int MPI_Waitsome ( int incount, MPI_Request *array_of_requests, int *count, int *array_of_indices, MPI_Status *array_of_statuses )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Waitsome( &jbuf,  & incount, array_of_requests, count, array_of_indices, array_of_statuses );

return rc;
} /* MPI_Waitsome */


extern void F77_MPI_WAITSOME(int  * incount, MPI_Fint  *array_of_requests, int  *count, int  *array_of_indices, MPI_Status  *array_of_statuses , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Request *c_array_of_requests;

c_array_of_requests = (MPI_Request*)malloc(sizeof(MPI_Request)*(*incount));
if ( c_array_of_requests == NULL ) mpiPi_abort("Failed to allocate memory in MPI_Waitsome");
{
  int i; 
  for (i = 0; i < *incount; i++) { 
    c_array_of_requests[i] = MPI_Request_f2c(array_of_requests[i]);
  }
}

rc = mpiPif_MPI_Waitsome( &jbuf, incount, c_array_of_requests, count, array_of_indices, array_of_statuses );

*ierr = (MPI_Fint)rc;
if ( rc == MPI_SUCCESS ) { 
{
  int i; 
  for (i = 0; i < *incount; i++) { 
    array_of_requests[i] = MPI_Request_c2f(c_array_of_requests[i]);
  }
}
{ int i; for ( i = 0; i < *count; i++)  array_of_indices[i]++;}
}
free(c_array_of_requests);
return;
} /* mpi_waitsome */



/* --------------- MPI_Win_complete --------------- */

static int mpiPif_MPI_Win_complete( jmp_buf * base_jbuf, MPI_Win  * win){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Win_complete(  * win);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Win_complete");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Win_complete, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Win_complete */



extern int MPI_Win_complete ( MPI_Win win )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Win_complete( &jbuf,  & win );

return rc;
} /* MPI_Win_complete */


extern void F77_MPI_WIN_COMPLETE(MPI_Win  * win , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;


rc = mpiPif_MPI_Win_complete( &jbuf, win );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_win_complete */



/* --------------- MPI_Win_create --------------- */

static int mpiPif_MPI_Win_create( jmp_buf * base_jbuf, void  *base, MPI_Aint  * size, int  * disp_unit, MPI_Info  * info, MPI_Comm  * comm, MPI_Win  *win){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Win_create( base,  * size,  * disp_unit,  * info,  * comm, win);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Win_create");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Win_create, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Win_create */



extern int MPI_Win_create ( void *base, MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm, MPI_Win *win )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Win_create( &jbuf, base,  & size,  & disp_unit,  & info,  & comm, win );

return rc;
} /* MPI_Win_create */


extern void F77_MPI_WIN_CREATE(void  *base, MPI_Aint  * size, int  * disp_unit, MPI_Fint  * info, MPI_Fint  * comm, MPI_Win  *win , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Info c_info;
MPI_Comm c_comm;

c_info = MPI_Info_f2c(*info);
c_comm = MPI_Comm_f2c(*comm);

rc = mpiPif_MPI_Win_create( &jbuf, base, size, disp_unit, &c_info, &c_comm, win );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_win_create */



/* --------------- MPI_Win_fence --------------- */

static int mpiPif_MPI_Win_fence( jmp_buf * base_jbuf, int  * assert, MPI_Win  * win){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Win_fence(  * assert,  * win);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Win_fence");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Win_fence, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Win_fence */



extern int MPI_Win_fence ( int assert, MPI_Win win )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Win_fence( &jbuf,  & assert,  & win );

return rc;
} /* MPI_Win_fence */


extern void F77_MPI_WIN_FENCE(int  * assert, MPI_Win  * win , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;


rc = mpiPif_MPI_Win_fence( &jbuf, assert, win );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_win_fence */



/* --------------- MPI_Win_free --------------- */

static int mpiPif_MPI_Win_free( jmp_buf * base_jbuf, MPI_Win  *win){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Win_free( win);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Win_free");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Win_free, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Win_free */



extern int MPI_Win_free ( MPI_Win *win )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Win_free( &jbuf, win );

return rc;
} /* MPI_Win_free */


extern void F77_MPI_WIN_FREE(MPI_Win  *win , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;


rc = mpiPif_MPI_Win_free( &jbuf, win );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_win_free */



/* --------------- MPI_Win_get_group --------------- */

static int mpiPif_MPI_Win_get_group( jmp_buf * base_jbuf, MPI_Win  * win, MPI_Group  *group){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Win_get_group(  * win, group);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Win_get_group");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Win_get_group, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Win_get_group */



extern int MPI_Win_get_group ( MPI_Win win, MPI_Group *group )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Win_get_group( &jbuf,  & win, group );

return rc;
} /* MPI_Win_get_group */


extern void F77_MPI_WIN_GET_GROUP(MPI_Win  * win, MPI_Fint  *group , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Group c_group;

c_group = MPI_Group_f2c(*group);

rc = mpiPif_MPI_Win_get_group( &jbuf, win, &c_group );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_win_get_group */



/* --------------- MPI_Win_lock --------------- */

static int mpiPif_MPI_Win_lock( jmp_buf * base_jbuf, int  * lock_type, int  * rank, int  * assert, MPI_Win  * win){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Win_lock(  * lock_type,  * rank,  * assert,  * win);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Win_lock");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Win_lock, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Win_lock */



extern int MPI_Win_lock ( int lock_type, int rank, int assert, MPI_Win win )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Win_lock( &jbuf,  & lock_type,  & rank,  & assert,  & win );

return rc;
} /* MPI_Win_lock */


extern void F77_MPI_WIN_LOCK(int  * lock_type, int  * rank, int  * assert, MPI_Win  * win , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;


rc = mpiPif_MPI_Win_lock( &jbuf, lock_type, rank, assert, win );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_win_lock */



/* --------------- MPI_Win_post --------------- */

static int mpiPif_MPI_Win_post( jmp_buf * base_jbuf, MPI_Group  * group, int  * assert, MPI_Win  * win){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Win_post(  * group,  * assert,  * win);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Win_post");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Win_post, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Win_post */



extern int MPI_Win_post ( MPI_Group group, int assert, MPI_Win win )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Win_post( &jbuf,  & group,  & assert,  & win );

return rc;
} /* MPI_Win_post */


extern void F77_MPI_WIN_POST(MPI_Fint  * group, int  * assert, MPI_Win  * win , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Group c_group;

c_group = MPI_Group_f2c(*group);

rc = mpiPif_MPI_Win_post( &jbuf, &c_group, assert, win );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_win_post */



/* --------------- MPI_Win_start --------------- */

static int mpiPif_MPI_Win_start( jmp_buf * base_jbuf, MPI_Group  * group, int  * assert, MPI_Win  * win){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Win_start(  * group,  * assert,  * win);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Win_start");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Win_start, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Win_start */



extern int MPI_Win_start ( MPI_Group group, int assert, MPI_Win win )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Win_start( &jbuf,  & group,  & assert,  & win );

return rc;
} /* MPI_Win_start */


extern void F77_MPI_WIN_START(MPI_Fint  * group, int  * assert, MPI_Win  * win , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;
MPI_Group c_group;

c_group = MPI_Group_f2c(*group);

rc = mpiPif_MPI_Win_start( &jbuf, &c_group, assert, win );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_win_start */



/* --------------- MPI_Win_test --------------- */

static int mpiPif_MPI_Win_test( jmp_buf * base_jbuf, MPI_Win  * win, int  *flag){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Win_test(  * win, flag);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Win_test");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Win_test, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Win_test */



extern int MPI_Win_test ( MPI_Win win, int *flag)
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Win_test( &jbuf,  & win, flag );

return rc;
} /* MPI_Win_test */


extern void F77_MPI_WIN_TEST(MPI_Win  * win, int  *flag , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;


rc = mpiPif_MPI_Win_test( &jbuf, win, flag );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_win_test */



/* --------------- MPI_Win_unlock --------------- */

static int mpiPif_MPI_Win_unlock( jmp_buf * base_jbuf, int  * rank, MPI_Win  * win){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Win_unlock(  * rank,  * win);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Win_unlock");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Win_unlock, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Win_unlock */



extern int MPI_Win_unlock ( int rank, MPI_Win win )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Win_unlock( &jbuf,  & rank,  & win );

return rc;
} /* MPI_Win_unlock */


extern void F77_MPI_WIN_UNLOCK(int  * rank, MPI_Win  * win , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;


rc = mpiPif_MPI_Win_unlock( &jbuf, rank, win );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_win_unlock */



/* --------------- MPI_Win_wait --------------- */

static int mpiPif_MPI_Win_wait( jmp_buf * base_jbuf, MPI_Win  * win){int rc, enabledState; double dur; int tsize; double messSize = 0.; double ioSize = 0.; double rmaSize =0.;
mpiPi_TIME start, end;
void *call_stack[MPIP_CALLSITE_STACK_DEPTH_MAX] = { NULL };

if (mpiPi.enabled) {
mpiPi_GETTIME (&start);
mpiPi_RecordTraceBack((*base_jbuf), call_stack, MPIP_CALLSITE_STACK_DEPTH);
}

enabledState = mpiPi.enabled;
mpiPi.enabled = 0;

rc = PMPI_Win_wait(  * win);

mpiPi.enabled = enabledState;
if (mpiPi.enabled) {

mpiPi_GETTIME (&end);
dur = mpiPi_GETTIMEDIFF (&end, &start);

if ( dur < 0 )
  mpiPi_msg_warn("Rank %5d : Negative time difference : %11.9f in %s\n", mpiPi.rank, dur, "MPI_Win_wait");
else
  mpiPi_update_callsite_stats(mpiPi_MPI_Win_wait, mpiPi.rank, call_stack, dur, (double)messSize,(double)ioSize,(double)rmaSize);
}

return rc;
} /* MPI_Win_wait */



extern int MPI_Win_wait ( MPI_Win win )
{
int rc;
jmp_buf jbuf;

rc = mpiPif_MPI_Win_wait( &jbuf,  & win );

return rc;
} /* MPI_Win_wait */


extern void F77_MPI_WIN_WAIT(MPI_Win  * win , MPI_Fint *ierr){
int rc;
jmp_buf jbuf;


rc = mpiPif_MPI_Win_wait( &jbuf, win );

*ierr = (MPI_Fint)rc;
return;
} /* mpi_win_wait */


/* eof */
