#!/bin/sh

R_HOME=`Rscript -e 'cat(R.home()[1])'`
JSS_BST=${R_HOME}/share/texmf/bibtex/bst/jss.bst
JSS_CLS=${R_HOME}/share/texmf/tex/latex/jss.cls

rm *.aux *.bbl *.blg *.log *.out *.toc *.bst *.cls
cp ${JSS_BST} ./
cp ${JSS_CLS} ./

pdflatex pbdPROF-guide.Rnw
bibtex pbdPROF-guide
pdflatex pbdPROF-guide.Rnw
pdflatex pbdPROF-guide.Rnw
pdflatex pbdPROF-guide.Rnw
Rscript -e "tools::compactPDF('.', gs_quality='ebook')"
rm *.aux *.bbl *.blg *.log *.out *.toc *.bst *.cls

mv -f *.pdf ../inst/doc/
cp -f *.Rnw ../inst/doc/
