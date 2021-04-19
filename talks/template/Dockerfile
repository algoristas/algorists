FROM pandoc/ubuntu-latex
RUN tlmgr update --self && tlmgr update -all
RUN tlmgr install \
        adjustbox algorithm2e algorithmicx collectbox doublestroke \
        environ eulervm ifoddpage relsize tcolorbox
COPY . .
RUN mv beamer /opt/texlive/texdir/texmf-dist/tex/latex/beamer \
    && chmod -R 644 /opt/texlive/texdir/texmf-dist/tex/latex/beamer \
    && texhash

RUN pandoc example.md -o example.pdf \
    --lua-filter algorithm.lua \
    --listings \
    --include-in-header=preamble.tex \
    --syntax-definition=algorithm.xml \
    --to=beamer

RUN pandoc example.md -o example.html \
    --mathjax \
    --standalone \
    --css=algorists.css \
    --listings \
    --syntax-definition=algorithm.xml \
    --to=slidy

ENTRYPOINT [ "bash" ]