#ifndef FUNCOES_H
#define FUNCOES_H

#include <vector>

using namespace std;

const int M = 8;
const int N = 10;

extern vector<vector<int>> dados; 
extern int quantConjuntos;

void criarConjunto();
void inserirValor();
void removerConjunto();
void unir2Conjuntos();
void interseccao2Conjuntos();
void mostrarConjunto();
void mostrarTodosConjuntos();
void buscarValor();

#endif