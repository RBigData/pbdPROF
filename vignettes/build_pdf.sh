#!/bin/sh

rm *.aux *.bbl *.blg *.log *.out *.toc
pdflatex pbdPROF-guide.Rnw
bibtex pbdPROF-guide
pdflatex pbdPROF-guide.Rnw
pdflatex pbdPROF-guide.Rnw
Rscript -e "tools::compactPDF('.', gs_quality='ebook')"
rm *.aux *.bbl *.blg *.log *.out *.toc *.dvi

mv -f *.pdf ../inst/doc/
cp -f *.Rnw ../inst/doc/
