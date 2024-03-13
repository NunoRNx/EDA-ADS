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
Matrix* ler(Matrix* inicio, const char* filename);
Matrix* removeLine(Matrix* inicio, int linha);
Matrix* removeColumn(Matrix* inicio, int coluna);
Matrix* addLine(Matrix* inicio, int linha);
Matrix* addColumn(Matrix* inicio);
void printMatrix(Matrix* inicio);
void replaceValue(Matrix* inicio, int linha, int coluna, int value);

void hungAlgorithm(Matrix* hini, Matrix* ini);
Matrix* Rezero(Matrix* hini);
Matrix* inverse(Matrix* hini);
int finalComb(Matrix* ini);
int printHa(Matrix* inicio);
Matrix* HaZeros(Matrix* ini);
bool VeriricarZeros(Matrix* ini, int LZ);
Matrix* SimplificarMatriz(Matrix* ini);
void onlyCombination(Matrix* hini, Matrix* ini);
