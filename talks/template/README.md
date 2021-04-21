This directory contains the new Markdown template with support for LaTeX.

It can be use it with `pandoc` CLI to generate either a PDF or an HTML. For instance, following command generates a beamer presentation in PDF:
```bash
pandoc example.md -o example.pdf \
    --lua-filter algorithm.lua \
    --listings \
    --include-in-header=preamble.tex \
    --syntax-definition=algorithm.xml \
    --to=beamer
```

To generate HTML slides use:
```bash
pandoc example.md -o example.html \
    --mathjax \
    --standalone \
    --css=algorists.css \
    --listings \
    --syntax-definition=algorithm.xml \
    --to=slidy
```

There is also a Dockerfile to create a docker container, so the command above can be tested easier without the need of installing `pandoc`, `texlive` and any required LaTeX package. This container can be created and run using the following commands:
```bash
docker build -t algorists .
docker run -it algorists
```
It's also possible mount a volume with your local files:
```bash
docker run -it -v //c/Users/ulises/Documents/algorists/talks/my-tech-talk:/data algorists
```
