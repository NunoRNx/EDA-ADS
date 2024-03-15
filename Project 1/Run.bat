cd Project 1

del output\main.o
del output\funcoes.o
del output\halg.o
del output\main.exe
del output\biblioteca.dll
del output\halg.dll

cls

gcc -w -c funcoes.c -o output\funcoes.o
gcc -w -shared -o output\biblioteca.dll output\funcoes.o

gcc -w -c HungAlgorithm.c -o output\halg.o
gcc -w -shared -o output\halg.dll output\halg.o -Loutput -lbiblioteca

gcc -w -c main.c -o output\main.o
gcc -w -o output\main.exe output\main.o -Loutput -lhalg -lbiblioteca

cd output

cls

main.exe

pause
