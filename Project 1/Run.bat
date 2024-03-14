cd Project 1

del output\lib.o
del output\main.o
del output\main.exe
del output\biblioteca.lib
del output\halg.lib

gcc -c funcoes.c -o output\funcoes.o
gcc -c HungAlgorithm.c -o output\halg.o

gcc -shared -o output\biblioteca.dll output\funcoes.o
gcc -shared -o output\halg.dll output\halg.o

gcc -c main.c -o output\main.o

gcc -o output\main.exe output\main.o -Loutput -lhalg -lbiblioteca

cd output

main.exe

pause