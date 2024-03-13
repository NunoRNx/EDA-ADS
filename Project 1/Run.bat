cd Project 1

del output\lib.o
del output\main.o
del output\main.exe
del output\biblioteca.lib
del output\halg.lib

gcc -c lib.c -o output\lib.o
gcc -c HungAlgorithm.c -o output\halg.o

gcc -shared -o output\biblioteca.lib output\lib.o
gcc -shared -o output\halg.lib output\halg.o

gcc -c main.c -o output\main.o

gcc -o output\main.exe output\main.o -Loutput -lhalg -lbiblioteca

cd output
cls
main.exe

pause