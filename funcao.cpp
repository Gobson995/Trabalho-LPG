#include <bits/stdc++.h>
#include "funcao.h"
#define n linha
#define m coluna

using namespace std;
int quantConjunto = 0;
void inserirValor(){

}
void criarConjunto(){
    int numeroElementos =  m;
    cout << "quantos elementos deseja ter no conjunto\n";
    while(numeroElementos > m){
        cin >> numeroElementos;
        if(numeroElementos > m)cout << "informe um numero valido\n";
    }
    for(int j = 0;j<numeroElementos;j++){
        cin >> dados[quantConjunto][j];
    }
}
void removerConjunto(){

}
void unir2Conjuntos(){

}
void interseccao2Conjuntos(){

}
void mostrarConjunto(){

}
void mostrarTodosConjuntos(){

}
void buscarValor(){

}

int main(){

}