#include <bits/stdc++.h>
#include "funcao.h"
#define n linha
#define m coluna

using namespace std;

int quantConjunto;

void inserirValor(){
    int qualConjunto = n+1;
    int valor = 0;
    bool realizado = false;
    cout << "qual conjunto deseja inserir um valor \n";
    while(qualConjunto > n && qualConjunto <= 0){
        cin >> qualConjunto;
        if(qualConjunto > n && qualConjunto <= 0)cout << "informe um numero valido\n";
    }
    cout << "qual o numero que deseja adicionar\n";
    cin >> valor;
    for(int j = 0;j<m;j++){
        if(dados[qualConjunto][j] == NULL){
            dados[qualConjunto][j] = valor;
            realizado = true;
        }
    }
    if(realizado)cout << "numero adicionado\n";
    else cout << "conjunto cheio\n";
}

void criarConjunto(){
    int numeroElementos =  m;
    if(quantConjunto >= n){
        //endereco dos conjuntos
        cout << "numero maximo de conjuntos atingido\n";
    }else{
        cout << "quantos elementos deseja ter no conjunto\n";
        while(numeroElementos > m){
            cin >> numeroElementos;
            if(numeroElementos > m)cout << "informe um numero valido\n";
        }
        for(int j = 0;j<numeroElementos;j++){
            cin >> dados[quantConjunto][j];
        }
        quantConjunto++;
    }
}
void removerConjunto(){
    int qualConjunto = n+1;
    bool realizado = false;
    cout << "qual conjunto deseja remover\n";
    while(qualConjunto > n && qualConjunto <= 0){
        cin >> qualConjunto;
        if(qualConjunto > n && qualConjunto <= 0){
            cout << "informe um numero valido\n";
        }else{
            for(int j = 0;j<m;j++){
                dados[qualConjunto-1][j] = NULL;
            }
            cout << "conjunto apagado\n";
        }
    }
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