/**
 * @file header.h
 * @author honun
 * @brief ficheiro de organização
 * @version 0.2
 * @date 2024-03-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>

/**
 * @brief Estrutura da Matriz.
 * @param x valor inteiro presente no nó da matriz.
 * @param proxl parametro que guarda o endereço da proxima linha.
 * @param proxc parametro que guarda o endereço da proxima coluna.
 */
typedef struct Matrix {
    int x;
    struct Matrix *proxl;
    struct Matrix *proxc;
} Matrix;

/**
 * @brief Declaração de todas as funções.
 */
Matrix* fmalloc(Matrix* pline, Matrix* pcol);
Matrix* ler(const char* filename, int* r);
void lerErro(int r, const char* filename);
Matrix* removeLine(Matrix* inicio, int linha);
Matrix* removeColumn(Matrix* inicio, int coluna);
Matrix* addLine(Matrix* inicio, int linha, bool* r);
Matrix* addColumn(Matrix* inicio, int coluna,  bool* r);
void printMatrix(Matrix* inicio);
bool replaceValue(Matrix* inicio, int linha, int coluna, int value);

bool hungAlgorithm(Matrix* hini,Matrix* hini2,Matrix* original);
Matrix* Rezero(Matrix* hini);
Matrix* inverse(Matrix* hini);
bool printHa(Matrix* inicio, int* linhaf, int* colunaf);
Matrix* HaZeros(Matrix* ini);
int VerificarZeros(Matrix* ini);
Matrix* SimplificarMatriz(Matrix* ini, Matrix* ini2, int menor);
Matrix* finalCombL(Matrix* ini);
Matrix* finalCombC(Matrix* ini);
Matrix* finalCombM(Matrix* ini, int mlc);
int onlyCombination(Matrix* hini, Matrix* ini);
Matrix* multiCombination(Matrix* hini);

Matrix* selectLineC(Matrix* ini, int zc);
Matrix* selectLineL(Matrix* ini, int zc);
int VerfZerosLine(Matrix* ini, int* contZl);
int VerfZerosCollumn(Matrix* ini, int* contZc);
int menorNum(Matrix* ini);