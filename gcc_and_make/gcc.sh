#!/bin/bash

set -x

ROOT_DIR=`dirname $0`
ROOT_DIR=`cd $ROOT_DIR/; pwd`

rm -f $ROOT_DIR/hello.i
rm -f $ROOT_DIR/hello.s
rm -f $ROOT_DIR/hello.o
rm -f $ROOT_DIR/hello

gcc -E hello.c -o hello.i
gcc -S hello.i -o hello.s
gcc -c hello.s -o hello.o
gcc    hello.o -o hello

$ROOT_DIR/hello

