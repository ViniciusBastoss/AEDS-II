/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   veiculos.h
 * Author: Vinicius
 *
 * Created on 16 de Março de 2021, 22:46
 */

#ifndef VEICULOS_H
#define VEICULOS_H

#include <iostream>
#include<fstream>


using namespace std;

typedef struct no_ {
    string modelo;
    string marca;
    string tipo;
    int ano;
    int km;
    float potencia;
    string combustivel;
    string cambio;
    string direcao;
    string cor;
    int portas;
    char placa[7];
    struct no_ * prox;
} no;

typedef struct no2_ {
    no_ * veiculo;
    no2_ * prox;
} no2;

typedef struct lis_ {
    int tam;
    struct no_ * lista;
} tlista;

typedef struct lis2_ {
    int tam;
    struct no2_ * lista;
} tbusc;

int Comp_placa(char *pla1, char *pla2);
bool busca_lista(tlista * list, char * placaT, no** ant);
bool busca_busc(tbusc * list, char *placaT, no2** ant);
bool insere_busc(tbusc * list, no2 * novo);
bool insere_lista(tlista * list, no * novo);
no* Remove_lista(tlista * list, char *placaT);
no2* Remove_busc(tbusc * list, char *placaT);
void Relatorio(tlista * listaT);
void Relatorio2(tbusc * listaT);
void Print_no(no * novo);
no2 * Cria_no2(no * novo);
tlista  encerra_lista(tlista * list);
tbusc * encerra_busc(tbusc * list);
void Modificar_doc(tlista * list, char * caminho);
void MENU();
void MENU2();
void MENU3();


#endif /* VEICULOS_H */

