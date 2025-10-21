#ifndef FUNCAO_H
#define FUNCAO_H

#include <bits/stdc++.h>
using namespace std;

extern vector<vector<int>> dados; 
extern int coluna,linha;

void criarConjunto();
void inserirValor();
void removerConjunto();
void unir2Conjuntos();
void interseccao2Conjuntos();
void mostrarConjunto();
void mostrarTodosConjuntos();
void buscarValor();

#endif
