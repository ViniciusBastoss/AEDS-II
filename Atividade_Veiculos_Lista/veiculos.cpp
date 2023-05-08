/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include <fstream>
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

int Comp_placa(char *pla1, char *pla2) {
    int i = 0;
    while (i < 7) {
        if (pla1[i] > pla2[i]) return 1;
        if (pla1[i] < pla2[i]) return -1;
        if (pla1[i] == pla2[i]);
        i++;
    }
    return 0;
}

bool busca_lista(tlista * list, char * placaT, no** ant) {
    *ant = list->lista;
    no * ptr = list->lista;

    while (ptr != NULL && Comp_placa(ptr->placa, placaT) == -1) {
        *ant = ptr;
        ptr = ptr->prox;
    }
    return ptr != NULL && Comp_placa(ptr->placa, placaT) == 0;
}

bool busca_busc(tbusc * list, char *placaT, no2** ant) {
    *ant = list->lista;
    no2 * ptr = list->lista;
    while (ptr != NULL && Comp_placa(ptr->veiculo->placa, placaT) == -1) {
        *ant = ptr;
        ptr = ptr->prox;
    }
    return ptr != NULL && Comp_placa(ptr->veiculo->placa, placaT) == 0;
}

bool insere_busc(tbusc * list, no2 * novo) {

    if (list->tam == 0) {
        novo->prox = NULL;
        list->lista = novo;
        list->tam++;
        return true;
    }
    no2 * ant;
    if (busca_busc(list, novo->veiculo->placa, &ant)) {
        return false;
    }
    list->tam++;
    if (Comp_placa(ant->veiculo->placa, novo->veiculo->placa) == 1) {
        novo->prox = list->lista;
        list->lista = novo;
    } else {
        novo->prox = ant->prox;
        ant->prox = novo;
    }

    return true;
}

bool insere_lista(tlista * list, no * novo) {
    if (list->tam == 0) {
        novo->prox = NULL;
        list->lista = novo;
        list->tam++;
        return true;
    }
    no * ant;
    if (busca_lista(list, novo->placa, &ant)) {
        return false;
    }
    list->tam++;
    if (Comp_placa(ant->placa, novo->placa) == 1) {
        novo->prox = list->lista;
        list->lista = novo;
    } else {
        novo->prox = ant->prox;
        ant->prox = novo;
    }

    return true;
}

no* Remove_lista(tlista * list, char *placaT) {
    no *ant, *ptr;
    if (list->tam == 0 || !busca_lista(list, placaT, &ant)) {
        return NULL;
    }
    if (Comp_placa(ant->placa, placaT) == 0) {
        list->lista = ant->prox;
        ptr = ant;
    } else {
        ptr = ant->prox;
        ant->prox = ptr->prox;
    }
    ptr->prox = NULL;
    list->tam--;
    return ptr;


}

no2* Remove_busc(tbusc * list, char *placaT) {
    no2 *ant, *ptr;
    if (list->tam == 0 || !busca_busc(list, placaT, &ant)) {
        return NULL;
    }
    if (Comp_placa(ant->veiculo->placa, placaT) == 0) {
        list->lista = ant->prox;
        ptr = ant;
    } else {
        ptr = ant->prox;
        ant->prox = ptr->prox;
    }
    ptr->prox = NULL;
    list->tam--;
    return ptr;


}

void Relatorio(tlista * listaT) {
    no * tp = listaT->lista;
    while (tp != NULL) {
        cout << tp->modelo << "    ";
        cout << tp->marca << "    ";
        cout << tp->tipo << "    ";
        cout << tp->ano << "    ";
        cout << tp->km << "    ";
        cout << tp->potencia << "    ";
        cout << tp->combustivel << "    ";
        cout << tp->cambio << "    ";
        cout << tp->direcao << "    ";
        cout << tp->cor << "    ";
        cout << tp->portas << "    ";
        cout << tp->placa << "   " << endl;
        tp = tp->prox;
    }
    cout << endl;
}

void Relatorio2(tbusc * listaT) {
    no2 * tp = listaT->lista;
    while (tp != NULL) {
        cout << tp->veiculo->modelo << "    ";
        cout << tp->veiculo->marca << "    ";
        cout << tp->veiculo->tipo << "    ";
        cout << tp->veiculo->ano << "    ";
        cout << tp->veiculo->km << "    ";
        cout << tp->veiculo->potencia << "    ";
        cout << tp->veiculo->combustivel << "    ";
        cout << tp->veiculo->cambio << "    ";
        cout << tp->veiculo->direcao << "    ";
        cout << tp->veiculo->cor << "    ";
        cout << tp->veiculo->portas << "    ";
        cout << tp->veiculo->placa << "   " << endl;
        tp = tp->prox;
    }
    cout << endl;
}

void Print_no(no * novo) {
    cout << novo->modelo << "    ";
    cout << novo->marca << "    ";
    cout << novo->tipo << "    ";
    cout << novo->ano << "    ";
    cout << novo->km << "    ";
    cout << novo->potencia << "    ";
    cout << novo->combustivel << "    ";
    cout << novo->cambio << "    ";
    cout << novo->direcao << "    ";
    cout << novo->cor << "    ";
    cout << novo->portas << "    ";
    cout << novo->placa << "   " << endl;
}

no2 * Cria_no2(no * novo) {
    no2 * novob = new(no2);
    novob->veiculo = novo;
    novob->prox = NULL;
    return novob;
}



tlista  encerra_lista(tlista * list) {
	no * ant = list->lista;
	no * pont = list->lista;
	
	while(ant != NULL){
		pont = ant->prox;
		delete(ant);
		ant = pont;
	}
	delete(list);
        cout << "-A lista foi removida."<<endl;
	
        return *list;
}

tbusc * encerra_busc(tbusc * list) {
	no2 * ant = list->lista;
	no2 * pont = list->lista;
	
	while(ant != NULL){
		pont = ant->prox;
		delete(ant);
		ant = pont;
	}
	delete(list);
        
	
        return list;
}
void MENU() {
    puts("");
    puts(" _________________________________________");
    puts("| ---Menu de Opções---                    |");
    puts("|                                         |");
    puts("| 1 - Inserir novo veiculo                |");
    puts("|                                         |");
    puts("| 2 - Excluir veiculo                     |");
    puts("|                                         |");
    puts("| 3 - Buscar veiculo                      |");
    puts("|                                         |");
    puts("| 4 - Relatorio                           |");
    puts("|                                         |");
    puts("| 5 - Sair                                |");
    puts("|                                         |");
    puts("|_________________________________________|");
}

void MENU2() {
    puts("");
    puts(" _______________________________________________________________");
    puts("| ---Menu de Opções---                                         |");
    puts("|                                                              |");
    puts("| 1 - Relatorio geral                                          |");
    puts("|                                                              |");
    puts("| 2 - Relatorio de veiculos ano 2020                           |");
    puts("|                                                              |");
    puts("| 3 - Relatorio de veiculos com potência maior ou igual ha 1.6 |");
    puts("|                                                              |");
    puts("| 4 - Relatorio de veiculos com 4 portas                       |");
    puts("|                                                              |");
    puts("| 5 - Sair                                                     |");
    puts("|                                                              |");
    puts("|______________________________________________________________|");
}

void MENU3() {
    puts("");
    puts(" _______________________________________________________________");
    puts("| ---Menu de Opções---                                         |");
    puts("|                                                              |");
    puts("| 1 - Busca                                                    |");
    puts("|                                                              |");
    puts("| 2 - Busca de veiculos ano 2020                               |");
    puts("|                                                              |");
    puts("| 3 - Busca  de veiculos com potência maior ou igual ha 1.6    |");
    puts("|                                                              |");
    puts("| 4 - Busca de veiculos com 4 portas                           |");
    puts("|                                                              |");
    puts("| 5 - Sair                                                     |");
    puts("|                                                              |");
    puts("|______________________________________________________________|");
}





