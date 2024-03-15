/**
 * @file main.c
 * @author honun
 * @brief testes extensivos
 * @version 0.31
 * @date 2024-02-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "header.h"

#pragma region ex7 teste
//mlc menor linha/coluna
bool hungAlgorithm(Matrix* hini,Matrix* hini2,Matrix* original){
    if(hini==NULL)return false;
    hini=inverse(hini);
    hini2=inverse(hini2);
    int mlc=printHa(hini);
    hini=HaZeros(hini);
    hini2=HaZeros(hini2);
    printHa(hini);
    int LZ, v=0, contZl=0, contZc=0, zc=0, zl=0,menor;
    while (1)
    {
        zl=VerfZerosLine(hini2,&contZl);
        zc=VerfZerosCollumn(hini2,&contZc);
        if (contZc>=contZl)
        {
            hini2=selectLineC(hini2,zc);
        }else{
            hini2=selectLineL(hini2,zl);
        }
        LZ=1;
        printHa(hini2);
        while (1)
        {
            zl=VerfZerosLine(hini2,&contZl);
            zc=VerfZerosCollumn(hini2,&contZc);
            if(contZc==0 && contZl==0)break;
            if (contZl>=contZc)
            {
                hini2=selectLineL(hini2,zl);
            }else{
                hini2=selectLineC(hini2,zc);
            }
            LZ++;
            printHa(hini2);
        }
        if (LZ>=mlc)
        {
            printf("\nSolucao final\n");
            break;
        }
        Rezero(hini2);
        printHa(hini2);
        menor=menorNum(hini2);
        SimplificarMatriz(hini,hini2,menor);
        printHa(hini);
    }
    hini=finalCombL(hini);
    hini=finalCombC(hini);
    printHa(hini);
    printHa(original);
    if(finalCombM(hini, mlc)==0){
        hini=multiCombination(hini);
    }
    int sum=onlyCombination(hini, original);
    printf("\nSolucao:%d\n",sum);
    return true;
}

Matrix* inverse(Matrix* hini){
    Matrix* aux=hini;
    Matrix* ant=aux;
    while (aux!=NULL)
    {
        while (aux!=NULL)
        {
            aux->x=aux->x*-1;
            aux=aux->proxc;
        }
        ant=ant->proxl;
        aux=ant;
    }
    return hini;
}
Matrix* Rezero(Matrix* hini){
    Matrix* aux=hini;
    Matrix* ant=aux;
    while (aux!=NULL)
    {
        while (aux!=NULL)
        {
            if (aux->x==-1)
            {
                aux->x=0;
            }
            aux=aux->proxc;
        }
        ant=ant->proxl;
        aux=ant;
    }
    return hini;
}
int printHa(Matrix* inicio){
    Matrix* aux=inicio;
    Matrix* ant=aux;
    int linha=0, coluna=0;
    printf("Matriz Hungara:\n");
    while (aux!=NULL)
    {
        linha++;
        coluna=0;
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
            coluna++;
        }
        ant=ant->proxl;
        aux=ant;
    }
    if (linha>=coluna)
    {
        return coluna;
    }
    return linha;
}
Matrix* HaZeros(Matrix* ini){
    Matrix* aux=ini;
    Matrix* ant=ini;
    int menor, i;
    while (aux!=NULL)
    {
        i=0;
        while (aux!=NULL)
        {
            if (i==0)
            {
                i++;
                menor=aux->x;
            }else{
                if (menor>aux->x)
                {
                    menor=aux->x;
                }
            }
            aux=aux->proxc;
        }
        aux=ant;
        while (aux!=NULL)
        {
            aux->x=aux->x-menor;
            aux=aux->proxc;
        }
        ant=ant->proxl;
        aux=ant;
    }
    aux=ini;
    ant=ini;
    while (aux!=NULL)
    {
        i=0;
        while (aux!=NULL)
        {
            if (i==0)
            {
                i++;
                menor=aux->x;
            }else{
                if (menor>aux->x)
                {
                    menor=aux->x;
                }
            }
            aux=aux->proxl;
        }
        aux=ant;
        while (aux!=NULL)
        {
            aux->x=aux->x-menor;
            aux=aux->proxl;
        }
        ant=ant->proxc;
        aux=ant;
    }
    return ini;
}

//zc/zl coluna/linha com mais zeros
//contZc/contZl quantidade de zeros da coluna/linha com mais zeros
Matrix* selectLineC(Matrix* ini, int zc){
    Matrix* aux=ini;
    Matrix* teste=ini;
    for ( int i = 0; i < zc; i++)
    {
        aux=aux->proxc;
    }
    while (aux!=NULL)
    {
        if (aux->x==0)
        {
            teste=aux->proxc;
            aux->x=-1;
        }else if(aux->x>0){
            aux->x=-2;
        }else if(aux->x==-2){
            aux->x=-3;
        }
        aux=aux->proxl;
    }
    return ini;
}
Matrix* selectLineL(Matrix* ini, int zc){
    Matrix* aux=ini;
    for ( int i = 0; i < zc; i++)
    {
        aux=aux->proxl;
    }
    while (aux!=NULL)
    {
        if (aux->x==0)
        {
            aux->x=-1;
        }else if(aux->x>0){
            aux->x=-2;
        }else if(aux->x==-2){
            aux->x=-3;
        }
        aux=aux->proxc;
    }
    return ini;
}
int VerfZerosLine(Matrix* ini, int* contZl){
    //linhas
    Matrix* aux=ini;
    Matrix* ant=ini;
    int i=0, temp, cont=0, zl=0;
    while (aux!=NULL)
    {
        temp=0;
        while (aux!=NULL)
        {
            if (aux->x==0)
            {
                temp++;
            }
            aux=aux->proxc;
        }
        if (i==0)
        {
            zl=cont;
            *contZl=temp;
            i++;
        }else if(*contZl<temp){
            zl=cont;
            *contZl=temp;
        }
        cont++;
        ant=ant->proxl;
        aux=ant; 
    }
    return zl;
}
int VerfZerosCollumn(Matrix* ini, int* contZc){
    //colunas
    Matrix* aux=ini;
    Matrix* ant=ini;
    int i=0, temp, cont=0, zc=0;
    while (aux!=NULL)
    {
        temp=0;
        while (aux!=NULL)
        {
            if (aux->x==0)
            {
                temp++;//quantidade de zeros na coluna atual
            }
            aux=aux->proxl;
        }
        if (i==0)
        {
            zc=cont;
            *contZc=temp;
            i++;
        }else if (*contZc<temp)
        {
            zc=cont;
            *contZc=temp;
        }
        
        cont++;
        ant=ant->proxc;
        aux=ant;
    }
    return zc;
}
int VerificarZeros(Matrix* ini){
    Matrix* aux=ini;
    Matrix* ant=ini;
    int i;
    while (aux!=NULL)
    {
        while (aux!=NULL)
        {
            if (aux->x==0)
            {
                aux->x=-1;
            }
            aux=aux->proxc;
        }
        ant=ant->proxl;
        aux=ant;
    }
    return 1;
}
int menorNum(Matrix* ini){
    Matrix* aux=ini;
    Matrix* ant=ini;
    int menor, i=0, v=0;
    while (aux!=NULL)
    {
        while (aux!=NULL)
        {
            if (i==0 && aux->x!=0 && aux->x!=-2 && aux->x!=-3)
            {
                menor=aux->x;
                i++;
            }else if(aux->x<menor && aux->x!=0 && aux->x!=-2 && aux->x!=-3)
            {
                menor=aux->x;
            }
            aux=aux->proxc;
        }
        ant=ant->proxl;
        aux=ant;
    }
    return menor;
}
Matrix* SimplificarMatriz(Matrix* ini, Matrix* ini2, int menor){
    Matrix* aux=ini;
    Matrix* aux2=ini2;
    Matrix* ant=ini;
    Matrix* ant2=ini2;
    int i=0, v=0;
    aux=ini;
    ant=ini;
    while (aux2!=NULL)
    {
        while (aux2!=NULL)
        {
            if(aux2->x!=0){
                if (aux2->x>0)
                {
                    aux->x=aux->x-menor;
                }
                if (aux2->x==-3)
                {
                    aux->x=aux->x+menor;
                }
            }
            aux2=aux2->proxc;
            aux=aux->proxc;
        }
        ant2=ant2->proxl;
        aux2=ant2;
        ant=ant->proxl;
        aux=ant;
    }
    aux=ini;
    aux2=ini2;
    ant=ini;
    ant2=ini2;
    while (aux!=NULL)
    {
        while (aux!=NULL)
        {
            aux2->x=aux->x;
            aux2=aux2->proxc;
            aux=aux->proxc;
        }
        ant=ant->proxl;
        ant2=ant2->proxl;
        aux=ant;
        aux2=ant2;
    }
    return ini;
}
Matrix* finalCombL(Matrix* ini){
    Matrix* aux=ini;
    Matrix* ant=ini;
    Matrix* aux2=ini;
    Rezero(ini);
    int z=0;
    while (aux!=NULL)
    {
        while (aux!=NULL)
        {
            if(aux->x==0)z++;
            aux=aux->proxc;
        }
        if (z==1)
        {
            aux=ant;
            while (1)
            {
                if (aux->x==0)break;               
                aux=aux->proxc;
                aux2=aux2->proxc;
            }
            aux->x=-1;
            while (aux2!=NULL)
            {
                if (aux2->x==0)
                {
                    aux2->x=-2;
                }
                aux2=aux2->proxl;
            }
        }
        z=0;
        ant=ant->proxl;
        aux=ant;
        aux2=ini;
    }
    return ini;
}
Matrix* finalCombC(Matrix* ini){
    Matrix* aux=ini;
    Matrix* ant=ini;
    Matrix* aux2=ini;
    int z=0;
    while (aux!=NULL)
    {
        while (aux!=NULL)
        {
            if(aux->x==0)z++;
            aux=aux->proxl;
        }
        if (z==1)
        {
            aux=ant;
            while (1)
            {
                if (aux->x==0)break;               
                aux=aux->proxl;
                aux2=aux2->proxl;
            }
            aux->x=-1;
            while (aux2!=NULL)
            {
                if (aux2->x==0)
                {
                    aux2->x=-2;
                }
                aux2=aux2->proxc;
            }
        }
        z=0;
        ant=ant->proxc;
        aux=ant;
        aux2=ini;
    }
    return ini;
}
Matrix* finalCombM(Matrix* ini, int mlc){
    Matrix* aux=ini;
    Matrix* ant=ini;
    int cont=0;
    while (aux!=NULL)
    {
        while (aux!=NULL)
        {
            if(aux->x==-1)cont++;
            aux=aux->proxc;
        }
        ant=ant->proxl;
        aux=ant;
    }
    if (cont==mlc)return true;
    return false;
}
int onlyCombination(Matrix* hini, Matrix* ini){
    Matrix* aux=hini;
    Matrix* ant=hini;
    Matrix* origin=ini;
    Matrix* antO=ini;
    int sum=0;
    printf("\nSelcionados: ");
    while (aux!=NULL)
    {
        while (aux!=NULL)
        {
            if (aux->x==-1)
            {
                sum+=origin->x;
                printf("%d",origin->x);
            }
            aux=aux->proxc;
            origin=origin->proxc;
        }
        ant=ant->proxl;
        aux=ant;
        antO=antO->proxl;
        origin=antO;
        if(aux!=NULL)printf("+");
    }
    return sum;
}
Matrix* multiCombination(Matrix* hini){
    Matrix* aux=hini;
    Matrix* aux2=hini;
    Matrix* ant=hini;
    printf("\nteste force\n");
    printHa(hini);
    while (aux!=NULL)
    {
        int i=0;
        while (i==0)
        {
            if (aux->x==0)break;              
            aux=aux->proxc;
        }
        aux->x=-1;
        aux2=aux;
        aux=aux->proxc;
        aux2=aux2->proxl;
        while (aux!=NULL)
        {
            if (aux->x==0)aux->x=-2;
            aux=aux->proxc;
        }
        while (aux2!=NULL)
        {
            if (aux2->x==0)aux2->x=-2;
            aux2=aux2->proxl;
        }
        ant=ant->proxl;
        aux=ant;
        aux2=ant;
    }
    return hini;
}
#pragma endregion