set terminal png size 500,500
set output 'mul.png'
set xtics ("ijk" 0, "ikj" 1, "kij" 2, "jik" 3, "jki" 4, "kji" 5)
plot "tim.bin" with linespoints
