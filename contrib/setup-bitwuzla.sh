#!/bin/bash
set -e

BITWUZLA_VERSION=06bca95621ce618e4958151fba61b13dd4805ba5
DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" >/dev/null 2>&1 && pwd)"
DEPS="$(dirname "$DIR")/deps"

mkdir -p $DEPS

if [ ! -d "$DEPS/bitwuzla" ]; then
    cd $DEPS
    git clone https://github.com/bitwuzla/bitwuzla.git
    cd bitwuzla
    git checkout -f $BITWUZLA_VERSION
    ./configure.py --prefix $DEPS/install
    cd build
    meson compile
    meson install
else
    echo "$DEPS/bitwuzla already exists. If you want to rebuild, please remove it manually."
fi
