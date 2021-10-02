#!/bin/bash
./gen
mode=0
a="a.bin"
b="b.bin"
c="out.bin"
cr="cntrl.bin"
tmp="tmp.bin"
tim="tim.bin"
while [[ $mode < 6 ]]
do
index=0
while [[ $index < 9 ]]
do
./sspp $a $b $c $mode >> $tmp 
./cntrl $cr $c
let "index=index+1"
done
./tim $tmp $tim $mode
echo > $tmp
let "mode=mode+1"
done
gnuplot pl
echo "График в файле mul.png"
