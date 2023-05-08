/*
 * Copyright (c) 2009-2010, Oracle and/or its affiliates. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of Oracle nor the names of its contributors
 *   may be used to endorse or promote products derived from this software without
 *   specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <iostream>
#include<fstream>
#include "veiculos.h"


using namespace std;

tbusc * busc2020, *potenc, *ports;

int Carregar_doc(tlista * listaP, const char *caminho) {
    int quant, i;
    ifstream arquivo(caminho);
    if (!arquivo.is_open()) {
        cout << "Erro Na abertura do arquivo" << endl;
        return 0;
    }
    no * novo_no;
    arquivo >> quant;
    for (i = 0; i < quant; i++) {
        novo_no = new(no);
        arquivo >> novo_no->modelo;
        arquivo >> novo_no->marca;
        arquivo >> novo_no->tipo;
        arquivo >> novo_no->ano;
        arquivo >> novo_no->km;
        arquivo >> novo_no->potencia;
        arquivo >> novo_no->combustivel;
        arquivo >> novo_no->cambio;
        arquivo >> novo_no->direcao;
        arquivo >> novo_no->cor;
        arquivo >> novo_no->portas;
        arquivo >> novo_no->placa;
        if (insere_lista(listaP, novo_no)) {
            if (novo_no->ano == 2020)
                insere_busc(busc2020, Cria_no2(novo_no));
            if (novo_no->potencia >= 1.6)
                insere_busc(potenc, Cria_no2(novo_no));
            if (novo_no->portas == 4)
                insere_busc(ports, Cria_no2(novo_no));
        }
    }
    arquivo.close();

    return 1;
}

void Modificar_doc(tlista * list, const char * caminho) {
    no * aux = list->lista;
    ofstream arquivo;
    arquivo.open(caminho);
    if (!arquivo.is_open()) {
        cout << "Erro na abertura do arquivo" << endl;
        exit;
    }
    arquivo << list->tam << endl;
    while (aux != NULL) {
        arquivo << aux->modelo << " ";
        arquivo << aux->marca << " ";
        arquivo << aux->tipo << " ";
        arquivo << aux->ano << " ";
        arquivo << aux->km << " ";
        arquivo << aux->potencia << " ";
        arquivo << aux->combustivel << " ";
        arquivo << aux->cambio << " ";
        arquivo << aux->direcao << " ";
        arquivo << aux->cor << " ";
        arquivo << aux->portas << " ";
        arquivo << aux->placa << endl;
        aux = aux->prox;
    }
    arquivo.close();

}

tlista * Aloca_listas() {
    tlista * princ = new(tlista);
    princ->tam = 0;
    princ->lista = NULL;
    busc2020 = new(tbusc);
    busc2020->tam = 0;
    busc2020->lista = NULL;
    potenc = new(tbusc);
    potenc->tam = 0;
    potenc->lista = NULL;
    ports = new(tbusc);
    ports->tam = 0;
    ports->lista = NULL;

    return princ;
}

int main(int argc, char**argv) {
    tlista * lista_princ = Aloca_listas();
    no * novo;
    no2 * ant;
    if(!Carregar_doc(lista_princ, "Veiculos.txt"))
        return 0;
    int a, b;
    char placaR[7];
    do {
        MENU();
        cin >> a;
        switch (a) {
            case 1:
                novo = new(no);
                cout << "Digite os dados do veiculo a seguir:" << endl;
                cout << "Modelo" << endl;
                cin >> novo->modelo;
                cout << "Marca" << endl;
                cin >> novo->marca;
                cout << "Tipo" << endl;
                cin >> novo->tipo;
                cout << "Ano" << endl;
                cin >> novo->ano;
                cout << "Km" << endl;
                cin >> novo->km;
                cout << "Potência" << endl;
                cin >> novo->potencia;
                cout << "Combustivel" << endl;
                cin >> novo->combustivel;
                cout << "Cambio" << endl;
                cin >> novo->cambio;
                cout << "direcao" << endl;
                cin >> novo->direcao;
                cout << "Cor" << endl;
                cin >> novo->cor;
                cout << "Portas" << endl;
                cin >> novo->portas;
                cout << "Placa" << endl;
                cin >> novo->placa;
                if (!insere_lista(lista_princ, novo)) {
                    cout << "Não foi possível realizar a inserção do veículo" << endl;
                    delete(novo);
                } else {
                    if (novo->ano == 2020)
                        insere_busc(busc2020, Cria_no2(novo));
                    if (novo->potencia >= 1.6)
                        insere_busc(potenc, Cria_no2(novo));
                    if (novo->portas == 4)
                        insere_busc(ports, Cria_no2(novo));
                    cout << "Veículo adicionado com sucesso!" << endl;
                }

                break;
            case 2:
                cout << "Digite a placa do veiculo a ser removido" << endl;
                cin >> placaR;
                novo = Remove_lista(lista_princ, placaR);
                if (novo == NULL)
                    cout << "Não foi possível realizar a remoção" << endl;
                else {
                    if (novo->ano == 2020)
                        delete(Remove_busc(busc2020, placaR));
                    if (novo->potencia >= 1.6)
                        delete(Remove_busc(potenc, placaR));
                    if (novo->portas == 4)
                        delete(Remove_busc(ports, placaR));
                    delete (novo);
                    cout << "Veículo removido com sucesso!" << endl;
                }
                break;

            case 3:
                MENU3();
                cin >> b;
                switch (b) {
                    case 1:
                        cout << "Digite a placa do veiculo a ser encontrado" << endl;
                        cin >> placaR;
                        if (!busca_lista(lista_princ, placaR, &novo))
                            cout << "Veículo não encontrado" << endl;
                        else {
                            cout << "Veículo encontrado com sucesso!" << endl;
                            Print_no(novo->prox);
                        }
                        break;
                    case 2:
                        cout << "Digite a placa do veiculo a ser encontrado" << endl;
                        cin >> placaR;
                        if (!busca_busc(busc2020, placaR, &ant))
                            cout << "Veículo não encontrado" << endl;
                        else {
                            cout << "Veículo encontrado com sucesso!" << endl;
                            Print_no(ant->prox->veiculo);
                        }
                        break;

                    case 3:
                        cout << "Digite a placa do veiculo a ser encontrado" << endl;
                        cin >> placaR;
                        if (!busca_busc(potenc, placaR, &ant))
                            cout << "Veículo não encontrado" << endl;
                        else {
                            cout << "Veículo encontrado com sucesso!" << endl;
                            Print_no(ant->prox->veiculo);
                        }
                        break;

                    case 4:
                        cout << "Digite a placa do veiculo a ser encontrado" << endl;
                        cin >> placaR;
                        if (!busca_busc(ports, placaR, &ant))
                            cout << "Veículo não encontrado" << endl;
                        else {
                            cout << "Veículo encontrado com sucesso!" << endl;
                            Print_no(ant->prox->veiculo);
                        }
                        break;
                }
                break;
            case 4:
                do {
                    MENU2();
                    cin >> b;
                    switch (b) {
                        case 1:
                            Relatorio(lista_princ);
                            break;
                        case 2:
                            Relatorio2(busc2020);
                            break;
                        case 3:
                            Relatorio2(potenc);
                            break;
                        case 4:
                            Relatorio2(ports);
                            break;
                    }
                } while (b != 5);
                break;
        }
    } while (a != 5);
    Modificar_doc(lista_princ,"Veiculos.txt");
    encerra_lista(lista_princ);
    encerra_busc(busc2020);
    encerra_busc(potenc);
    encerra_busc(ports);
    return 0;
}
