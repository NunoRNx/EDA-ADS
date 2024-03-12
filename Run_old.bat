cd C:\Users\epere\OneDrive\Documentos\.IPCA\Ongoing\Est Dados Avançadas\Project\Source

del output\lib.o
del output\main.o
del output\main.exe

gcc -c lib.c -o output\lib.o
gcc -c main.c -o output\main.o
gcc output\main.o output\lib.o -o output\main

cd output
cls
main.exe

pause