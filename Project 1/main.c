/**
 * @file main.c
 * @author honun
 * @brief testes extensivos
 * @version 0.3
 * @date 2024-02-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "header.h"



#pragma region main
/**
 * @brief Função main.
 *
 * A main está a ser utilizada apenas para fins de teste de todas as funcções presentes em lib.c.
 *
 * @param ini apontador inicial da matriz.
 * @param hini apontador inicial da cópia da matriz utilizada para a solução do exercicio.
 */

int main(){
    Matrix* ini=NULL;
    Matrix* hini=NULL;
    const char* file = "nums.txt";
    printf("\nLeitura de file\n");
    ini=ler(ini,file);
    printMatrix(ini);

    printf("add linha 0 e 2");
    ini=addLine(ini,0);
    printMatrix(ini);
    ini=addLine(ini,2);
    printMatrix(ini);

    //hini=ler(hini, file);
    //hungAlgorithm(hini,ini);

    /* printf("\nadicionar linha\n");
    ini=addLine(ini);
    printMatrix(ini);
    printf("\nremover linha 0\n");
    ini=removeLine(ini,0);
    printMatrix(ini);
    printf("\nremover linha 3\n");
    ini=removeLine(ini,3);
    printMatrix(ini);
    printf("\nadicionar 2 linhas\n");
    
    ini=addLine(ini);
    printMatrix(ini);
    printf("\nAdicionar coluna\n");
    ini=addColumn(ini);
    printMatrix(ini);
    printf("\nremover coluna 1\n");
    ini=removeColumn(ini,1);
    printMatrix(ini);
    printf("\nadicionar linha\n");
    ini=addLine(ini);
    printMatrix(ini);
    printf("\nAdicionar coluna\n");
    ini=addColumn(ini);
    printMatrix(ini);
    printf("\nmudar valores\n[0][1] para 1\n[1][0] para 2\n[2][0] para 3\n[2][1] para 4\n");
    replaceValue(ini,0,1,1);
    replaceValue(ini,1,0,2);
    replaceValue(ini,2,0,3);
    replaceValue(ini,2,1,4);
    printMatrix(ini); */
    return 0;
}

#pragma endregion
