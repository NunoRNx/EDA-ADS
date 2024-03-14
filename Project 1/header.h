/**
 * @file header.h
 * @author honun
 * @brief ficheiro de organização
 * @version 0.3
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
 * @brief Declaração das funções.
 */
Matrix* fmalloc(Matrix* pline, Matrix* pcol);
Matrix* ler(const char* filename);
Matrix* removeLine(Matrix* inicio, int linha);
Matrix* removeColumn(Matrix* inicio, int coluna);
Matrix* addLine(Matrix* inicio, int linha);
Matrix* addColumn(Matrix* inicio, int coluna);
bool printMatrix(Matrix* inicio);
bool replaceValue(Matrix* inicio, int linha, int coluna, int value);
bool EscreverMatriz(Matrix* ini);
/**
 * @brief Declaração das funções utilizadas no Algoritmo Hungaro.
 */
bool hungAlgorithm(Matrix* hini,Matrix* original);
Matrix* Rezero(Matrix* hini);
Matrix* inverse(Matrix* hini);
int finalComb(Matrix* ini);
int printHa(Matrix* inicio);
Matrix* HaZeros(Matrix* ini);
bool VeriricarZeros(Matrix* ini, int LZ);
Matrix* SimplificarMatriz(Matrix* ini);
int onlyCombination(Matrix* hini, Matrix* ini);
