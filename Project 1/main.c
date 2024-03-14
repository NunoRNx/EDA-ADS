/**
 * @file main.c
 * @author honun
 * @brief testes extensivos
 * @version 0.5
 * @date 2024-02-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "header.h"

#pragma comment(lib, "biblioteca.dll")
#pragma comment(lib, "halg.dll")

#pragma region main
/**
 * @brief Função main.
 *
 * A main está a ser utilizada apenas para fins de teste de todas as funcções presentes em lib.c.
 *
 * @param ini apontador inicial da matriz.
 * @param hini apontador inicial da matriz utilizada para a solução do projeto.
 */

int main(){
    Matrix* ini=NULL;
    const char* file = "nums.txt";
    printf("\nLeitura de ficheiro de texto\n");
    ini=ler(file);
    printMatrix(ini);

    printf("\nadd coluna 0\n");
    ini=addColumn(ini,0);
    printMatrix(ini);
    printf("\n\nadd coluna 2\n");
    ini=addColumn(ini,2);
    printMatrix(ini);
    printf("\nadd linha 0\n");
    ini=addLine(ini,0);
    printMatrix(ini);
    printf("\n\nadd linha 2\n");
    ini=addLine(ini,2);
    printMatrix(ini);
    printf("\nremover linha 0\n");
    ini=removeLine(ini,0);
    printMatrix(ini);
    printf("\nremover linha 3\n");
    ini=removeLine(ini,3);
    printMatrix(ini);
    printf("\nremover coluna 1\n");
    ini=removeColumn(ini,1);
    printMatrix(ini);
    printf("\nmudar valores\n[0][1] para 1\n[1][0] para 2\n[2][0] para 3\n[2][1] para 4\n");
    replaceValue(ini,0,1,1);
    replaceValue(ini,1,0,2);
    replaceValue(ini,2,0,3);
    replaceValue(ini,2,1,4);
    printMatrix(ini);
    
    /* SOLUÇÃO */
    Matrix* hini=ler(file);
    Matrix* original=ler(file);
    hungAlgorithm(hini,original);
    return 0;
}
#pragma endregion