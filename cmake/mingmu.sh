#!/bin/sh

BIN="bin/mingmu"
if [ -f $BIN ]; then
    exec $BIN "$@"
else
    echo "Mingmu not build, read INSTALL first"
fi
