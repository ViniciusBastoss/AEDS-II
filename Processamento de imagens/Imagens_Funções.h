/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Imagens_Funções.h
 * Author: Vinicius
 *
 * Created on 18 de Dezembro de 2020, 20:06
 */

#ifndef IMAGENS_FUNÇÕES_H
#define IMAGENS_FUNÇÕES_H
int **ICONIZAR(int **imagem, int linhas, int colunas, int limit_ton);
int **ESCURECER_BORDAS(int **imagem, int linhas, int colunas, int limit_ton);
int **ELIMINAR_RUIDOS(int **imagem, int linhas, int colunas, int limit_ton);
int **ALOCAR (int lin, int col);
void DESALOCAR (int **mat, int lin);
int **LEIMAGEM (char *caminho, int *lin, int *col, int *limit);
void PASSAIMAGEM (int **imagem, int lin, int col, int limit, char *nome);



#endif /* IMAGENS_FUNÇÕES_H */

