#!/bin/bash
pwd
name="3_Planeta_Vector_PEFRL"
VAR=0.05

g++ -std=c++17  $name.cpp -o $name.x

./$name.x > $name.txt

cat <<EOF> $name.gp

set term pdf
set output "$name.pdf"
set xlabel "x"
set ylabel "y"
set grid
#set xrange[-5:11]
#set yrange[-5:11]
set size ratio -1

#set xtics 11 
#set ytics 0.1
#set mxtics 4
#set mytics 2
#set logscale x 2
#set grid mxtics mytics ls 101
#set grid mxtics mytics
#set key center right box
#unset key

plot "$name.txt" u 2:3 title "Movimiento-Planetario" w lp ps 0.01 lt rgb "blue" pointtype 7 lw 0.8
EOF

gnuplot $name.gp

xreader $name.pdf &
