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
    if(ini==NULL){
        printf("\nErro ao ler ficheiro!\n");
        return 0;
    }else{
        printf("leu matriz com sucesso\n");
    }
    if(printMatrix(ini)==0)printf("\nErro ao escrever matriz. Matriz vazia!\n");
    printf("\nadd coluna 0\n");
    ini=addColumn(ini,0);
    if(printMatrix(ini)==0)printf("\nErro ao escrever matriz. Matriz vazia!\n");
    printf("\n\nadd coluna 2\n");
    ini=addColumn(ini,2);
    if(printMatrix(ini)==0)printf("\nErro ao escrever matriz. Matriz vazia!\n");
    printf("\nadd linha 0\n");
    ini=addLine(ini,0);
    if(printMatrix(ini)==0)printf("\nErro ao escrever matriz. Matriz vazia!\n");
    printf("\n\nadd linha 2\n");
    ini=addLine(ini,2);
    if(printMatrix(ini)==0)printf("\nErro ao escrever matriz. Matriz vazia!\n");
    printf("\nremover linha 0\n");
    ini=removeLine(ini,0);
    if(printMatrix(ini)==0)printf("\nErro ao escrever matriz. Matriz vazia!\n");
    printf("\nremover linha 3\n");
    ini=removeLine(ini,3);
    if(printMatrix(ini)==0)printf("\nErro ao escrever matriz. Matriz vazia!\n");
    printf("\nremover coluna 1\n");
    ini=removeColumn(ini,1);
    if(printMatrix(ini)==0)printf("\nErro ao escrever matriz. Matriz vazia!\n");
    printf("\nmudar valores\n[0][1] para 1\n[1][0] para 2\n[2][0] para 3\n[2][1] para 4\n");
    if(replaceValue(ini,0,1,1)==0)printf("Erro a alterar valor\n");
    if(replaceValue(ini,1,0,2)==0)printf("Erro a alterar valor\n");
    if(replaceValue(ini,2,0,3)==0)printf("Erro a alterar valor\n");
    if(replaceValue(ini,2,1,4)==0)printf("Erro a alterar valor\n");
    if(printMatrix(ini)==0)printf("\nErro ao escrever matriz. Matriz vazia!\n");
    if(EscreverMatriz(ini)==0)printf("\nErro ao escrever matriz no ficheiro. Matriz vazia ou erro ao criar novo ficheiro!\n");
    
    /* SOLUÇÃO */
    printf("\n\nAlgoritmo Hungaro\n");
    Matrix* hini=ler(file);
    Matrix* hini2=ler(file);
    Matrix* original=ler(file);
    if(hini==NULL || original==NULL || hini2==NULL){
        printf("\nErro ao ler ficheiro!\n");
        return 0;
    }else{
        printf("\nleu matriz com sucesso\n");
    }
    if(hungAlgorithm(hini,hini2,original)==0)printf("\nErro, matriz vazia.\n");
    return 0;
}
#pragma endregion