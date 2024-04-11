/**
 * @file main.c
 * @author Nuno Silva 28005
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
    int r;
    const char* file = "nums.txt";
    //ler
    printf("\nLeitura de ficheiro de texto\n");
    ini=ler(file,&r);
    lerErro(r, file);
    if(r==1){
        printMatrix(ini);
        //addColumn
        printf("\nadd coluna 0\n");
        ini=addColumn(ini,0,r);
        if(r==0)printf("\ncoluna fora da matriz\n");
        printMatrix(ini);
        printf("\n\nadd coluna 2\n");
        ini=addColumn(ini,2,r);
        if(r==0)printf("\ncoluna fora da matriz\n");
        printMatrix(ini);
        //addLine
        printf("\nadd linha 0\n");
        ini=addLine(ini,0,r);
        if(r==0)printf("\nlinha fora da matriz\n");
        printMatrix(ini);
        printf("\n\nadd linha 2\n");
        ini=addLine(ini,2,r);
        if(r==0)printf("\nlinha fora da matriz\n");
        printMatrix(ini);
        //removerLine
        printf("\nremover linha 0\n");
        ini=removeLine(ini,0);
        printMatrix(ini);
        printf("\nremover linha 3\n");
        ini=removeLine(ini,3);
        printMatrix(ini);
        //removerColumn
        printf("\nremover coluna 1\n");
        ini=removeColumn(ini,1);
        printMatrix(ini);
        //replaceValue
        printf("\nmudar valores\n[0][1] para 1\n[1][0] para 2\n[2][0] para 3\n[2][1] para 4\n");
        if(replaceValue(ini,0,1,1)==0)printf("Erro a alterar valor\n");
        if(replaceValue(ini,1,0,2)==0)printf("Erro a alterar valor\n");
        if(replaceValue(ini,2,0,3)==0)printf("Erro a alterar valor\n");
        if(replaceValue(ini,2,1,4)==0)printf("Erro a alterar valor\n");
        printMatrix(ini);
        if(EscreverMatriz(ini)==0)printf("\nErro ao escrever matriz no ficheiro. Matriz vazia ou erro ao criar novo ficheiro!\n");
    }
    /* SOLUÇÃO */
    int r1,r2,r3;
    printf("\n\nAlgoritmo Hungaro\n");
    Matrix* hini=ler(file,&r1);
    lerErro(r1,file);
    Matrix* hini2=ler(file,&r2);
    lerErro(r2,file);
    Matrix* original=ler(file,&r3);
    lerErro(r3,file);
    if(r1==1 && r2==1 && r3==1){
        int sum;
        if(hungAlgorithm(hini,hini2,original,&sum)==0)printf("\nErro, matriz vazia.\n");
        printf("\nSolucao:%d\n",sum);
        return 0;
    }
    printf("\nErro na leitura da martiz, o algotimo nao ira comecar.\n");
    return 0;
}
#pragma endregion