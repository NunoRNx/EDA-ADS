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

<<<<<<< Updated upstream
#pragma region ex7 teste
//mlc menor linha/coluna
void hungAlgorithm(Matrix* hini, Matrix* ini){
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
            printHa(hini);
=======
#pragma comment(lib, "biblioteca.dll")

#pragma region solução
//mlc menor linha/coluna
bool hungAlgorithm(Matrix* hini,Matrix* hini2,Matrix* original){
    if(hini==NULL)return false;
    int l,c,mlc,r;
    hini=inverse(hini);
    hini2=inverse(hini2);
    if (printHa(hini2,&l,&c)==1)
    {
        mlc=l;
    }else if(l>c){
        mlc=l-c;
        for (int i = 0; i < mlc; i++)
        {
            addColumn(hini2,c,r);
        }
        mlc=mlc+2;
    }else{
        mlc=c-l;
        for (int i = 0; i < mlc; i++)
        {
            addLine(hini2,l,r);
        }
        mlc=mlc+2;
    }
    printf("\nmatriz modificada 1 mlc:%d\n",mlc);
    printHa(hini2,&l,&c);
    hini=HaZeros(hini);
    hini2=HaZeros(hini2);
    printf("\nmatriz modificada 1.5 mlc:%d\n",mlc);
    printHa(hini2,&l,&c);
    int LZ=0, v=0, contZl=0, contZc=0, zc=0, zl=0,menor;
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
        LZ=0;
        printf("\nteste 1\n");
        while (1)
        {
            printf("\nteste 2\n");
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
            printf("\nteste 3\n");
>>>>>>> Stashed changes
        }
        if (LZ>=mlc)
        {
            i++;
        }else{
            Rezero(hini);
            SimplificarMatriz(hini);
        }
<<<<<<< Updated upstream
    }
    int comb=finalComb(hini);
    printHa(hini);
    if (comb==mlc)
    {
        onlyCombination(hini, ini);
    }else{
        printf("\nA matriz tem mais do que uma solução\n");
=======
        printf("\nteste 4\n");
        Rezero(hini2);
        printf("\nteste 4.1\n");
        menor=menorNum(hini2);
        printf("\nteste 4.2 menor:%d\n", menor);
        printHa(hini2,&l,&c);
        SimplificarMatriz(hini,hini2,menor);
        printf("\nteste 5\n");
    }
    printf("\nmatriz modificada 2 mlc: %d LZ:%d\n", mlc, LZ);
    printHa(hini2,&l,&c);
    printf("\nteste 1\n");
    hini=finalCombL(hini);
    hini=finalCombC(hini);
    printf("\nteste 2\n");
    printHa(hini,&l,&c);
    printf("\nteste 2.5\n");
    printHa(original,&l,&c);
    printf("\nteste 3\n");
    if(finalCombM(hini, mlc)==0){
        hini=multiCombination(hini);
>>>>>>> Stashed changes
    }
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
<<<<<<< Updated upstream

int printHa(Matrix* inicio){
=======
bool printHa(Matrix* inicio, int* linhaf, int* colunaf){
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
    if (linha>=coluna)
    {
        return linha;
    }
    return coluna;
=======
    if (linha==coluna){
        *linhaf=linha;
        return true;
    }
    *linhaf=linha;
    *colunaf=coluna;
    return false;
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream

void onlyCombination(Matrix* hini, Matrix* ini){
    Matrix* aux=hini;
    Matrix* ant=hini;
    Matrix* origin=ini;
    Matrix* antO=ini;
    int sum=0;
=======
Matrix* finalCombM(Matrix* ini, int mlc){
    Matrix* aux=ini;
    Matrix* ant=ini;
    int cont=0;
>>>>>>> Stashed changes
    while (aux!=NULL)
    {
        while (aux!=NULL)
        {
<<<<<<< Updated upstream
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
=======
            if(aux->x==-1)cont++;
            aux=aux->proxc;
        }
        ant=ant->proxl;
        aux=ant;
    }
    if (cont==mlc)return true;
    return false;
}
Matrix* multiCombination(Matrix* hini){
    Matrix* aux=hini;
    Matrix* aux2=hini;
    Matrix* ant=hini;
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
>>>>>>> Stashed changes
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
#pragma endregion