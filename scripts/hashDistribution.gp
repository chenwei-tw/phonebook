reset
set xlabel 'bucket no'
set ylabel 'number'
set style fill solid
set title 'hash table distribution'
set term png enhanced font 'Verdana,12'
set output 'hashdist.png'

plot 'hash_output.txt'
