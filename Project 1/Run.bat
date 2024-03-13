del output\lib.o
del output\main.o
del output\main.exe

gcc -c lib.c -o output/lib.o
pause
gcc -c HungAlgorithm.c -o output/halg.o

gcc -shared -o output/biblioteca.dll output/lib.o
gcc -shared -o output/halg.dll output/halg.o

gcc -c main.c -o output/main.o

gcc -o output/main.exe output/main.o -Loutput -lhalg -lbiblioteca


cd output

main.exe

pause