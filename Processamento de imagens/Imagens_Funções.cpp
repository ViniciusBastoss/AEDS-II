/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



#include <iostream>

void DESALOCAR(int **mat, int lin) {
    int **aux = mat;
    for (; aux < mat + lin; aux++)
        delete [] * aux;
    delete [] mat;
}

int **ALOCAR(int lin, int col) {
    int **mat, **i;
    mat = new int *[lin];
    for (i = mat; i < mat + lin; i++)
        *i = new int[col];
    return mat;
}



int **ELIMINAR_RUIDOS(int **imagem, int linhas, int colunas, int limit_ton) {

    int i = 0, j = linhas - 1;
    int **imagemruido = ALOCAR(linhas, colunas);
    int **aux = imagemruido, *aux2, **aux3 = imagem, *aux4;

    //Preenchendo as bordas
    for (aux2 = *imagemruido, aux4 = *imagem; aux2 < *imagemruido + colunas; aux2++, aux4++, i++) {
        *aux2 = *aux4;
        *(*(aux + j) + i) = *(*(aux3 + j) + i);
    }
    j = colunas - 1;
    for (; aux < imagemruido + linhas; aux++, aux3++) {
        *aux = *aux3;
        *(*aux + j) = *(*aux3 + j);
    }
    for (aux = imagem, aux3 = imagemruido + 1; aux3 < imagemruido + linhas - 1; aux++, aux3++)
        for (i = 0, aux4 = *aux3 + 1; aux4 < *aux3 + colunas - 1; aux4++, i++)
            *aux4 = (*(*aux + i) + 2 * *(*aux + i + 1) + *(*aux + i + 2) +
                2 * *(*(aux + 1) + i) + 4 * *(*(aux + 1) + i + 1) + 2 * *(*(aux + 1) + i + 2) + *(*(aux + 2) + i) +
                2 * *(*(aux + 2) + i + 1) + *(*(aux + 2) + i + 2)) / 16;
    return imagemruido;


}

int **ESCURECER_BORDAS(int **imagem, int linhas, int colunas, int limit_ton) {
    int Valor_esc = 0, h = 0;
    int b = colunas - 1, cont = 0, i = 0;
    int **aux, *aux2, **aux3, *aux4, **imagembord = ALOCAR(linhas, colunas);
    int **a = imagembord + linhas - 1;

    //preencher matriz
    for (aux = imagem, aux3 = imagembord; aux < imagem + linhas; aux++, aux3++)
        for (aux2 = *aux, aux4 = *aux3; aux2 < *aux + colunas; aux2++, aux4++)
            *aux4 = *aux2;
    //escurecer bordas verticais
    for (; Valor_esc < 49; Valor_esc = Valor_esc + 3, cont++)
        for (aux = imagembord; aux < imagembord + linhas; aux++) {
            *(*aux + cont) = Valor_esc;
            *(*aux + b - cont) = Valor_esc;
        }
    cont = 0;
    Valor_esc = 0;
    //escurecer bordas horizontais
    for (aux = imagembord; Valor_esc < 49; Valor_esc = Valor_esc + 3, aux++) {
        for (aux2 = *aux + cont; aux2 < *aux + colunas - cont; aux2 = *aux + cont + h) {
            *aux2 = Valor_esc;
            *(*(a - cont) + h + i) = Valor_esc;
            h++;
        }
        i++;
        h = 0;
        cont++;
    }
    return imagembord;

}

int **ICONIZAR(int **imagem, int linhas, int colunas, int limit_ton) {
    int linhasP, colunasP, soma = 0;
    int *a, **b, h = 0;
    int **imagemico, **aux, *aux2, **aux3, *aux4;
    imagemico = ALOCAR(64, 64);
    linhasP = linhas / 64;
    colunasP = colunas / 64;
    for (aux = imagem, aux3 = imagemico; aux3 < imagemico + 64; aux3++, h = 0) {
        for (aux4 = *aux3; aux4 < *aux3 + 64; aux4++) {
            b = aux + linhasP;
            for (; aux < b; aux++) {
                aux2 = *aux + h;
                a = aux2 + colunasP;
                for (; aux2 < a; aux2++)
                    soma = soma + *aux2;
            }
            *aux4 = soma / (colunasP * linhasP);
            soma = 0;
            aux = aux - linhasP;
            h = h + colunasP;
        }
        aux = aux + linhasP;
    }

    return imagemico;


}
int **LEIMAGEM(char *caminho, int *lin, int *col, int *limit) {
   char a[2];
   FILE *arquivo;
   arquivo = fopen(caminho, "r");
    if (arquivo == NULL) {
        puts("Erro Na abertura do arquivo de imagem");
        return 0;
    }
   int **aux, *aux2, **mat, li, co, lim;
   fscanf(arquivo, "%s %d %d %d",a, &co, &li, &lim);
   mat = ALOCAR(li, co);
   for (aux = mat; aux < mat + li; aux++)
       for (aux2 = *aux; aux2 < *aux + co; aux2++)
           fscanf(arquivo,"%d", aux2);
   *lin = li;
   *col = co;
   *limit = lim;
   fclose(arquivo);
   return mat;
}
void PASSAIMAGEM (int **imagem, int lin, int col, int limit, char *nome)
{
    FILE *arquivo;
    arquivo = fopen(nome,"w");
    if(arquivo == NULL)
    {
        puts("Erro na abertura do arquivo da nova imagem");
        exit;
    }
    int **aux, *aux2;
    fprintf(arquivo, "P2\n");
    fprintf(arquivo,"#Criado_por_Vinicius_Bueno_Bastos\n");
    fprintf(arquivo,"%d %d\n %d\n", col, lin, limit);
    for(aux = imagem; aux < imagem + lin; aux++)
    {
        for(aux2 = *aux; aux2 < *aux + col; aux2++)
            fprintf(arquivo,"%8d", *aux2);
        fprintf(arquivo,"\n");
    }
    fclose(arquivo);
    
}
