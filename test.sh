#!/bin/bash

./gen
./$1 a.bin b.bin out.bin 0
echo "c"
./cntrl cntrl.bin out.bin
./$1 a.bin b.bin out.bin 1
./cntrl cntrl.bin out.bin
./$1 a.bin b.bin out.bin 2
./cntrl cntrl.bin out.bin
./$1 a.bin b.bin out.bin 3
./cntrl cntrl.bin out.bin
./$1 a.bin b.bin out.bin 4
./cntrl cntrl.bin out.bin
./$1 a.bin b.bin out.bin 5
./cntrl cntrl.bin out.bin
