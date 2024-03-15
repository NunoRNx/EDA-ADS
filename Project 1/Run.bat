cd C:\Users\Nuno\OneDrive\Documentos\GitHub\EDA-ADS\Project 1

del output\main.o
del output\funcoes.o
del output\halg.o
del output\main.exe
<<<<<<< Updated upstream
del output\biblioteca.lib
del output\halg.lib

gcc -c lib.c -o output\lib.o
gcc -c HungAlgorithm.c -o output\halg.o

gcc -shared -o output\biblioteca.lib output\lib.o
gcc -shared -o output\halg.lib output\halg.o

gcc -c main.c -o output\main.o

gcc -o output\main.exe output\main.o -Loutput -lhalg -lbiblioteca


cd output

main.exe

pause
=======
del output\biblioteca.dll
del output\halg.dll
>>>>>>> Stashed changes
