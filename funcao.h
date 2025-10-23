#pragma once

inline constexpr int M = 8;
inline constexpr int N = 10;

extern vector<vector<int>> dados(M, vector<int> (N,0)); 
extern int coluna,linha, quantConjuntos;

void criarConjunto();
void inserirValor();
void removerConjunto();
void unir2Conjuntos();
void interseccao2Conjuntos();
void mostrarConjunto();
void mostrarTodosConjuntos();
void buscarValor();

