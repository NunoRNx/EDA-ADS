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
void hungAlgorithm(Matrix* hini,Matrix* original){
    hini=inverse(hini);
    int mlc=printHa(hini);
    hini=HaZeros(hini);
    printHa(hini);
    int LZ, i=0;
    while (i==0)
    {
        LZ=0;
        while (VeriricarZeros(hini, LZ)==0)
        {
            LZ++;
            //printHa(hini);
        }
        if (LZ>=mlc)
        {
            i++;
        }else{
            Rezero(hini);
            SimplificarMatriz(hini);
        }
    }
    int comb=finalComb(hini);
    printHa(hini);
    onlyCombination(hini, original);
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
        return linha;
    }
    return coluna;
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
bool VeriricarZeros(Matrix* ini, int LZ){
    Matrix* aux=ini;
    Matrix* ant=ini;
    int i=0, cont=0, zc=0, zl=0, contZc=0, contZl=0, temp, linhas=0, colunas=0;
    //colunas
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
            contZc=temp;
            i++;
        }else if (contZc<temp)
        {
            zc=cont;
            contZc=temp;
        }
        
        cont++;
        ant=ant->proxc;
        aux=ant;
    }
    colunas=cont-1;
    //linhas
    aux=ini;
    ant=ini;
    i=0;
    cont=0;
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
            contZl=temp;
        }else if(contZl<temp){
            zl=cont;
            contZl=temp;
        }
        cont++;
        ant=ant->proxl;
        aux=ant;
    }
    linhas=cont-1;
    aux=ini;
    if (contZc>=contZl)
    {
        for ( i = 0; i < zc; i++)
        {
            aux=aux->proxc;
        }
        while (aux!=NULL)
        {
            if (aux->x==0)
            {
                aux->x=-1;
            }
            aux=aux->proxl;
        } 
    }else{
        for ( i = 0; i < zl; i++)
        {
            aux=aux->proxl;
        }
        while (aux!=NULL)
        {
            if (aux->x==0)
            {
                aux->x=-1;
            }
            aux=aux->proxc;
        }
    }
    if (contZc==0 && contZl==0)
    {
        return true;
    }
    return false;
}

Matrix* SimplificarMatriz(Matrix* ini){
    Matrix* aux=ini;
    Matrix* ant=ini;
    int menor, i=0;
    while (aux!=NULL)
    {
        while (aux!=NULL)
        {
            if (i==0 && aux->x!=0)
            {
                menor=aux->x;
                i++;
            }else if(aux->x<menor && aux->x!=0)
            {
                menor=aux->x;
            }
            aux=aux->proxc;
        }
        ant=ant->proxl;
        aux=ant;
    }
    aux=ini;
    ant=ini;
    while (aux!=NULL)
    {
        while (aux!=NULL)
        {
            if (aux->x!=0)
            {
                aux->x=aux->x-menor;
            }
            aux=aux->proxc;
        }
        ant=ant->proxl;
        aux=ant;
    }
    return ini;
}

int finalComb(Matrix* ini){
    Matrix* aux=ini;
    Matrix* ant=ini;
    Matrix* Rze=ini;//remaining zeros
    Rezero(ini);
    int z=0, s=0;
    while (aux!=NULL)
    {
        while (aux!=NULL)
        {
            if (aux->x==0)
            {
                z++;
            }
            aux=aux->proxc;
        }
        aux=ant;
        if (z==1)
        {
            while (aux!=NULL)
            {
                if (aux->x==0)
                {
                    aux->x=-1;
                    Rze=aux->proxl;
                    while (Rze!=NULL)
                    { 
                        if (Rze->x==0)
                        {
                            Rze->x=-2;
                        }
                        Rze=Rze->proxl;
                    }
                }
            aux=aux->proxc;
            }
        }
        ant=ant->proxl;
        aux=ant;
        z=0;
    }
    aux=ini;
    ant=ini;
    while (aux!=NULL)
    {
        while (aux!=NULL)
        {
            if (aux->x==0)
            {
                z++;
            }
            aux=aux->proxl;
        }
        aux=ant;
        
        if (z==1)
        {
            while (aux!=NULL)
            {
                if (aux->x==0)
                {
                    aux->x=-1;
                    s++;
                }
            aux=aux->proxl;
            }
        }
        ant=ant->proxc;
        aux=ant;
        z=0;
    }
    return s;
}

void onlyCombination(Matrix* hini, Matrix* ini){
    Matrix* aux=hini;
    Matrix* ant=hini;
    Matrix* origin=ini;
    Matrix* antO=ini;
    int sum=0;
    while (aux!=NULL)
    {
        while (aux!=NULL)
        {
            if (aux->x==-1)
            {
                sum+=origin->x;
            }
            aux=aux->proxc;
            origin=origin->proxc;
        }
        ant=ant->proxl;
        aux=ant;
        antO=antO->proxl;
        origin=antO;
    }
    printf("\nSolucao:%d\n",sum);
}
#pragma endregion