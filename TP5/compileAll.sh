flex scanner.l
bison parser.y
gcc -Wall *.c -o compilador -lfl
./compilador < ../TP4/entradaok.txt
