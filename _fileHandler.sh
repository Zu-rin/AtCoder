#!/bin/zsh

source ./.venv/bin/activate
python _fileHandler.py
deactivate

if [ -f a.out ]; then
    echo "Start removing a.out"
    rm a.out
fi
echo "Done."