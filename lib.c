/**
 * @file lib.c
 * @author honun
 * @brief Project Lib (funções do projeto)
 * @version 0.4.1
 * @date 2024-03-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "header.h"

#pragma region leitura
/**
 * @brief Leitura dos valores presentes no ficheiro de texto.
 * 
 * Leitura de valores separardos entre ";" na matriz com divisão de linha na divisão de linhas do mesmo ficheiro.
 * 
 * @param num valor inteiro lido do ficheiro.
 * @param s caracter lido após o valor inteiro para determinar se é o último valor da linha.
 * @param j parametro para rodar a matriz para a proxima coluna.
 * @param i parametro para rodar a matriz para a proxima linha.
 * @return fazemos a retoma do apondator da caixa inicial da lista.
 */
Matrix* ler(Matrix* inicio, const char* filename){
    int num, j=0;
    char s;
    
    FILE *file=fopen(filename, "r");
    Matrix* aux=inicio;
    if(file==NULL)return NULL; //erro ao abrir file
    while ((fscanf(file, "%d%c", &num, &s) ==2))//leitura do primeiro valor
    {
        aux=addColumn(aux);
        replaceValue(aux,0,j,num);
        j++;
        if(s=='\n'){
            break;
        }
    }
    j=0;
    int i=1;
    aux=addLine(aux);
    while ((fscanf(file, "%d%c", &num, &s) == 2))
    {
        replaceValue(aux,i,j,num);
        if (s==';')
        {
            j++;
        }else if(s=='\n'){
            i++;
            j=0;
            aux=addLine(aux);
        }else{
            printf("\nMatriz mal formatada\n");
        }
    }
    replaceValue(aux,i,j,num);
    fclose(file);
    if(i==0)return NULL;//linha 13
    printf("leu com sucesso\n");
    return aux;
}
#pragma endregion
#pragma region print
/**
 * @brief Escrita de todos os valores presentes na matriz.
 * 
 * Escrita em forma de matriz dos dados presentes na lista.
 */
void printMatrix(Matrix* inicio){
    Matrix* aux=inicio;
    Matrix* ant=aux;
    printf("Matriz:\n");
    while (aux!=NULL)
    {
        while (aux!=NULL)
        {
            printf("%d",aux->x);
            if (aux->proxc==NULL)
            {
                printf("\n");
            }else{
                printf("\t");
            }
            aux=aux->proxc;
        }
        ant=ant->proxl;
        aux=ant;
    }
}
#pragma endregion
#pragma region adicionar linha
/**
 * @brief Adicionar linhas à matriz.
 * 
 * Adiciona 1 nova linha no fim da matriz.
 * Caso o ficheiro de texto esteja vazio e a matriz consequentemente também, a função irá criar a primeira casa da matriz.
 *
 * @return se a matriz estava vazia ao inicio da função ira ser criada a primeira casa e logo o inicio da matriz ira ser returnado.
 */
Matrix* addLine(Matrix* inicio){
    Matrix* aux=inicio;
    Matrix* ant;
    if (aux==NULL)
    {
        aux= (Matrix*)malloc(sizeof(Matrix));
        if(aux==NULL)return inicio;
        aux->proxc=NULL;
        aux->proxl=NULL;
        aux->x=0;
        return aux;
    }
    while (aux->proxl!=NULL)
    {
        aux=aux->proxl;
    }
    aux->proxl= (Matrix*)malloc(sizeof(Matrix));
    if(aux->proxl==NULL)return inicio;
    ant=aux;
    aux=aux->proxl;
    ant=ant->proxc;
    aux->proxl=NULL;
    aux->proxc=NULL;
    aux->x=0;
    while (ant!=NULL)
    {
        aux->proxc= (Matrix*)malloc(sizeof(Matrix));
        if(aux->proxc==NULL)return inicio;
        aux=aux->proxc;
        ant->proxl=aux;
        ant = ant->proxc;
        aux->proxl=NULL;
        aux->proxc=NULL;
        aux->x=0;//alterar valores / falar com stor sobre valores novos
    } 
    return inicio;
}
#pragma endregion
#pragma region adicionar coluna
/**
 * @brief Adicionar coluna à matriz.
 * 
 * Adiciona 1 nova coluna no fim da matriz.
 * Caso o ficheiro de texto esteja vazio e a matriz consequentemente também, a função irá criar a primeira casa da matriz.
 *
 * @return se a matriz estava vazia ao inicio da função ira ser criada a primeira casa e logo o inicio da matriz ira ser returnado.
 */
Matrix* addColumn(Matrix* inicio){
    Matrix* aux=inicio;
    Matrix* ant;
    if (aux==NULL)
    {
        aux= (Matrix*)malloc(sizeof(Matrix));
        if(aux==NULL)return NULL;
        aux->proxc=NULL;
        aux->proxl=NULL;
        aux->x=0;
        return aux;
    }
    while (aux->proxc!=NULL)
    {
        aux=aux->proxc;
    }
    aux->proxc= (Matrix*)malloc(sizeof(Matrix));
    if(aux->proxc==NULL)return;
    ant=aux;
    aux=aux->proxc;
    ant=ant->proxl;
    aux->proxl=NULL;
    aux->proxc=NULL;
    aux->x=0;
    while (ant!=NULL)
    {
        aux->proxl= (Matrix*)malloc(sizeof(Matrix));
        if(aux->proxl==NULL)return;
        aux=aux->proxl;
        ant->proxc=aux;
        ant = ant->proxl;
        aux->proxl=NULL;
        aux->proxc=NULL;
        aux->x=0;//alterar valores / falar com stor sobre valores novos
    }
    return inicio;
}
#pragma endregion
#pragma region remover linha
/**
 * @brief Remover linhas à matriz.
 * 
 * Remover 1  linha no local indicado na função main.
 * Caso o ficheiro de texto esteja vazio e a matriz consequentemente também, a função irá returnar sem nenhuma alteração efectuada.
 * Caso a linha selecionada não exista, a função irá retornar sem nenhuma alteração efetuada.
 * 
 * @param linha número que representa a linha na matriz a ser removida.
 * @return a função retorna o inicio que apenas será alterado se a linha escolhida para ser apagada for a linha 0 que contém o inicio.
 */
Matrix* removeLine(Matrix* inicio, int linha){
    Matrix* aux=inicio;
    Matrix* cur;
    Matrix* cima;
    Matrix* ini=inicio;
    if (aux==NULL)
    {
        return inicio;
    }
    if (linha==0)
    {
        ini=ini->proxl;
        while (aux!=NULL)
        {
            cur=aux;
            aux=aux->proxc;
            free(cur);
        }
        return ini;
    }
    for (int i = 0; i < linha; i++)
    {
        cima=aux;
        aux=aux->proxl;
    }
    while (aux!=NULL)
    {
        cima->proxl=aux->proxl;
        cima=cima->proxc;
        cur=aux;
        aux=aux->proxc;
        free(cur);
    }
    return inicio;
}
#pragma endregion
#pragma region remover coluna
/**
 * @brief Remover colunas à matriz.
 * 
 * Remover 1  coluna no local indicado na função main.
 * Caso o ficheiro de texto esteja vazio e a matriz consequentemente também, a função irá returnar sem nenhuma alteração efectuada.
 * Caso a coluna selecionada não exista, a função irá retornar sem nenhuma alteração efetuada.
 * 
 * @param linha número que representa a linha na matriz a ser removida.
 * @return a função retorna o inicio que apenas será alterado se a coluna escolhida para ser apagada for a coluna 0 que contém o inicio.
 */
Matrix* removeColumn(Matrix* inicio, int coluna){
    Matrix* aux=inicio;
    Matrix* cur;
    Matrix* ant;
    Matrix* ini=inicio;
    if (aux==NULL)
    {
        return inicio;
    }
    if (coluna==0)
    {
        ini=ini->proxc;
        while (aux!=NULL)
        {
            cur=aux;
            aux=aux->proxl;
            free(cur);
        }
        return ini;
    }
    for (int i = 0; i < coluna; i++)
    {
        ant=aux;
        aux=aux->proxc;
    }
    while (aux!=NULL)
    {
        ant->proxc=aux->proxc;
        ant=ant->proxl;
        cur=aux;
        aux=aux->proxl;
        free(cur);
    }
    return inicio;
}
#pragma endregion
#pragma region alterar valor
/**
 * @brief Alterar valor na matriz.
 * 
 * Alterar valor na matriz no local indicado na função main.
 * Caso a posição indicada não seja valida nenhuma alteração será efetuada.
 * 
 * @param linha coordenada que representa a linha do valor a que deseja ser alterado na matriz.
 * @param coluna coordenada que representa a coluna do valor a que deseja ser alterado na matriz.
 * @param i contador para chegar até à posição desejada.
 */
void replaceValue(Matrix* inicio, int linha, int coluna, int value){
    Matrix* aux=inicio;
    for (int i = 0; i < linha; i++)
    {
        aux=aux->proxl;
        if (aux==NULL)
        {
            return;
        }
    }
    for (int i = 0; i < coluna; i++)
    {
        aux=aux->proxc;
        if (aux==NULL)
        {
            return;
        }
    }
    aux->x=value;
}
#pragma endregion
