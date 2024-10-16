/**
 * @file lib.c
 * @author Nuno Silva 28005
 * @brief Project Lib (funções do projeto)
 * @version 0.4.3
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
 * @param c parametro para verificar se a matriz tem apenas 1 coluna (c=0/existe apenas uma coluna).
 * @param verf parametro que verifica o ultimo carater lido no fim do ficheiro, caso seja um "enter" uma linha extra incorreta será criada e a função removerLine que remove a linha extra irá ser executada.
 * @return fazemos a retoma do apondator da caixa inicial da lista.
 */
Matrix* ler(const char* filename, int* r){
    int num=NULL, j=0, i=0, c=0, verf=1;
    char s;    
    FILE *file=fopen(filename, "r");
    Matrix* ini=fmalloc(NULL,NULL);
    Matrix* aux=ini;
    Matrix* ant=ini;
    Matrix* cima=ini;
    if(file==NULL){
        *r=0;
        return NULL; //erro ao abrir file
    }
    while ((fscanf(file, "%d%c", &num, &s) ==2))
    {
        replaceValue(ini,i,j,num);
        if (s==';')
        {
            aux=fmalloc(NULL,NULL);
            ant->proxc=aux;
            if (i!=0)
            {
                cima=cima->proxc;
                cima->proxl=aux;
            }
            j++;
            verf=0;
            c++;
        }else if(s=='\n'){
            i++;
            j=0;
            cima=ini;
            while (cima->proxl!=NULL)cima=cima->proxl;
            aux=fmalloc(NULL,NULL);
            cima->proxl=aux;
            verf=1;
        }else{
            *r=-1;
            return NULL;
        }
        ant=aux;
    }
    if(i==0 && j==0){
        *r=-1;
        return NULL;
    }
    if (verf==0 || c==0)replaceValue(ini,i,j,num);
    else if(c!=0) removeLine(ini,i);
    *r=1;
    fclose(file);
    return ini;
}
/* Matrix* ler(char* filename, int* r){
    int num, j=0, verf = 0;
    char s;
    
    FILE *file=fopen(filename, "r");
    Matrix* aux=NULL;
    if(file==NULL){
        *r=0;
        return NULL; //erro ao abrir file
    }
    while ((fscanf(file, "%d%c", &num, &s) ==2))//leitura do primeiro valor
    {
        aux=addColumn(aux,j,r);
        replaceValue(aux,0,j,num);
        j++;
        if(s=='\n'){
            break;
        }
    }
    j=0;
    int i=1;
    aux=addLine(aux,i,r);
    while (fscanf(file, "%d%c", &num, &s) == 2)
    {
        replaceValue(aux,i,j,num);
        if (s==';')
        {
            j++;
            verf=0;
        }else if(s=='\n'){
            verf++;
            i++;
            j=0;
            aux=addLine(aux,i,r);
        }else{
            *r=-1;//formato da matriz nao valido
            return NULL;
        }
    }
    if (verf > 0){
        aux=removeLine(aux,i);
    }else{
        replaceValue(aux,i,j,num);
    }
    fclose(file);
    *r=1;
    lerErro(r,filename);
    return aux;
} */
/**
 * @brief Imprimir tipo de erro sucedido na leitura.
 */
void lerErro(int r, const char* filename){
    if(r==0)printf("\nErro ao abrir ficheiro %s\n", filename);
    else if(r==-1)printf("\nErro, a matriz não está no formato necessario em %s\n", filename);
    else if(r==1)printf("\nSucesso na leitura do ficheiro de texto %s\n", filename);
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
 * Adiciona 1 nova linha no lugar indicado da matriz.
 * Caso o ficheiro de texto esteja vazio e a matriz consequentemente também, a função irá criar a primeira casa da matriz.
 *
 * @return se a matriz estava vazia ao inicio da função ira ser criada a primeira casa e logo o inicio da matriz ira ser returnado.
 */
Matrix* addLine(Matrix* inicio, int linha, bool* r){
    Matrix* aux=inicio;
    Matrix* ant=inicio;
    Matrix* next=inicio;
    if (aux==NULL)
    {
        aux=fmalloc(NULL,NULL);
        if(aux==NULL)return inicio;
        return aux;
    }
    if (linha==0)
    {
        aux=fmalloc(next,NULL);
        if(aux==NULL)return inicio;
        inicio=aux;
        next=next->proxc;
        while (next!=NULL)
        {

            aux->proxc=fmalloc(next,NULL);
            if(aux->proxc==NULL)return inicio;
            aux=aux->proxc;
            next=next->proxc;
        }
        return inicio;
    }else{
        for (int i = 0; i < linha-1; i++)
        {
            ant=ant->proxl;
        }
        if (ant==NULL)
        {
            r=false;
            return inicio;
        }
        
        next=ant;
        next=next->proxl;
        aux=fmalloc(next,NULL);
        if(aux==NULL)return inicio;
        ant->proxl=aux;
        ant=ant->proxc;
        if (next!=NULL)next=next->proxc;
        while (ant!=NULL)
        {
            aux->proxc=fmalloc(next,NULL);
            if(aux->proxc==NULL)return inicio;
            aux=aux->proxc;
            ant->proxl=aux;
            ant = ant->proxc;
            if (next!=NULL)next=next->proxc;
        }
    }
    r=true;
    return inicio;
}
#pragma endregion
#pragma region adicionar coluna
/**
 * @brief Adicionar coluna à matriz.
 * 
 * Adiciona 1 nova coluna no lugar indicado da matriz.
 * Caso o ficheiro de texto esteja vazio e a matriz consequentemente também, a função irá criar a primeira casa da matriz.
 *
 * @return se a matriz estava vazia ao inicio da função ira ser criada a primeira casa e logo o inicio da matriz ira ser returnado.
 */
Matrix* addColumn(Matrix* inicio, int coluna, bool* r){
    Matrix* aux=inicio;
    Matrix* ant=inicio;
    Matrix* next=inicio;
    if (aux==NULL)
    {
        aux=fmalloc(NULL,NULL);
        if(aux==NULL)return inicio;
        return aux;
    }
    if (coluna==0)
    {
        aux=fmalloc(NULL,next);
        if(aux==NULL)return inicio;
        inicio=aux;
        next=next->proxl;
        while (next!=NULL)
        {
            aux->proxl=fmalloc(NULL,next);
            if(aux->proxl==NULL)return inicio;
            aux=aux->proxl;
            next=next->proxl;
        }
        return inicio;
    }else{
        for (int i = 0; i < coluna-1; i++)
        {
            ant=ant->proxc;
        }
        if (ant==NULL)
        {
            r=false;
            return inicio;
        }
        next=ant;
        next=next->proxc;
        aux=fmalloc(NULL,next);
        if(aux==NULL)return inicio;
        ant->proxc=aux;
        ant=ant->proxl;
        if (next!=NULL)next=next->proxl;
        while (ant!=NULL)
        {
            aux->proxl=fmalloc(NULL,next);
            if(aux->proxl==NULL)return inicio;
            aux=aux->proxl;
            ant->proxc=aux;
            ant = ant->proxl;
            if (next!=NULL)next=next->proxl;
        }
        r=true;
        return inicio;
    }
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
 * @brief Remover coluna na matriz.
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
bool replaceValue(Matrix* inicio, int linha, int coluna, int value){
    Matrix* aux=inicio;
    for (int i = 0; i < linha; i++)
    {
        aux=aux->proxl;
        if (aux==NULL)
        {
            return false;
        }
    }
    for (int i = 0; i < coluna; i++)
    {
        aux=aux->proxc;
        if (aux==NULL)
        {
            return false;
        }
    }
    aux->x=value;
    return true;
}
#pragma endregion
#pragma region escrever em file nova matriz
/**
 * @brief Escrita dos valores presentes na matriz num novo ficheiro de texto.
 */
bool EscreverMatriz(Matrix* ini){
    Matrix* aux=ini;
    Matrix* ant=ini;
    if (ini==NULL)return false;    
    FILE* file=fopen("matriz_alt.txt", "w");
    if (file==NULL)return false;
    while (aux!=NULL)
    {
        fprintf(file, "%d",aux->x);
        aux=aux->proxc;
        while (aux!=NULL)
        {
            fprintf(file, ";%d",aux->x);
            aux=aux->proxc;
        }
        fprintf(file,"\n");
        ant=ant->proxl;
        aux=ant;
    }
    fclose(file);
    return true;
}
#pragma endregion
#pragma region malloc
/**
 * @brief Criar novo nó.
 * Criar novo nó e atribuir os valores devidos.
 * 
 * @param pline variavel que trás o valor a atribuir a próxima linha da matriz neste novo nó.
 * @param pcol variavel que trás o valor a atribuir a próxima coluna da matriz neste novo nó.
 * @return o novo nó da matriz.
 */
Matrix* fmalloc(Matrix* pline, Matrix* pcol){
    Matrix* aux=NULL;
    aux=(Matrix*)malloc(sizeof(Matrix));
    if (aux==NULL)return NULL;
    aux->proxc=pcol;
    aux->proxl=pline;
    aux->x=0;
    return aux;
}
#pragma endregion
