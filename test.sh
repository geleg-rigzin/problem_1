#!/bin/bash

./gen
./$1 a.bin b.bin out.bin 0
echo "cекунд"
./cntrl cntrl.bin out.bin
./$1 a.bin b.bin out.bin 1
echo "cекунд"
./cntrl cntrl.bin out.bin
./$1 a.bin b.bin out.bin 2
echo "cекунд"
./cntrl cntrl.bin out.bin
./$1 a.bin b.bin out.bin 3
echo "cекунд"
./cntrl cntrl.bin out.bin
./$1 a.bin b.bin out.bin 4
echo "cекунд"
./cntrl cntrl.bin out.bin
./$1 a.bin b.bin out.bin 5
echo "cекунд"
./cntrl cntrl.bin out.bin
