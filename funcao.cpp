#include <bits/stdc++.h>
#include "funcao.h"
#define m linha
#define n coluna

using namespace std;

int quantConjunto;

void inserirValor(){
    int qualConjunto = m+1;
    int valor = 0;
    bool realizado = false;

    cout << "qual conjunto deseja inserir um valor \n";

    while(qualConjunto > m && qualConjunto <= 0){
        cin >> qualConjunto;
        if(qualConjunto > m && qualConjunto <= 0) cout << "informe um numero valido\n";
    }

    cout << "qual o numero que deseja adicionar\n";
    cin >> valor;

    for(int j = 0;j<n;j++){
        if(dados[qualConjunto][j] == NULL){
            dados[qualConjunto][j] = valor;
            realizado = true;
        }
    }

    if(realizado)cout << "numero adicionado\n";
    else cout << "conjunto cheio\n";
}

void criarConjunto(){
    int numeroElementos =  n;
    if(quantConjunto >= m){
        //endereco dos conjuntos
        cout << "numero maximo de conjuntos atingido\n";
    }else{
        cout << "quantos elementos deseja ter no conjunto\n";
        while(numeroElementos > n){
            cin >> numeroElementos;
            if(numeroElementos > n)cout << "informe um numero valido\n";
        }
        for(int j = 0;j<numeroElementos;j++){
            cin >> dados[quantConjunto][j];
        }
        quantConjunto++;
    }
}
void removerConjunto(){
    int qualConjunto = m+1;
    bool realizado = false;
    cout << "qual conjunto deseja remover\n";
    while(qualConjunto > m && qualConjunto <= 0){
        cin >> qualConjunto;
        if(qualConjunto > m && qualConjunto <= 0){
            cout << "informe um numero valido\n";
        }else{
            for(int j = 0;j<m;j++){
                dados[qualConjunto-1][j] = NULL;
            }
            cout << "conjunto apagado\n";
        }
    }
}
void unir2Conjuntos() {
    quantConjunto++;
    int linha1, linha2;
    cout << "Quais dois conjunto você deseja unir?" << endl;
    cout << "Primeiro conjunto: ";
    cin >> linha1;
    cout << endl << "Segundo conjunto: ";
    cin >> linha2;
    cout << endl;

    vector<int> valores;

    int final = 0;

    for (int i = final; i < n; i++) {
        if (dados[linha1][i] == 0) break;
        valores.push_back(dados[linha1][i]);
        final = i;
    }

    for (int i = 0; i < n; i++) {
        if (final == n) break;
        valores.push_back(dados[linha2][i]);
        final++;
    }

    for (int i = 0; i < valores.size(); i++) {
        dados[quantConjunto][i] = valores[i];
    }
}
void interseccao2Conjuntos(){
    quantConjunto++;
    
    int linha1, linha2;

    cout << "Quais dois conjuntos você deseja fazer a intersecção?" << endl;
    cout << "Primeiro: ";
    cin >> linha1;
    cout << endl << "Segundo: ";
    cin >> linha2;
    cout << endl;

    vector<int> valores;

    for (int i = 0; dados[linha1][i] != 0; i++) {
        for (int j = 0; dados[linha2][j] != 0; j++) {
            if (dados[linha1][i] == dados[linha2][j]) {
                valores.push_back(dados[linha1][i]);
                break;
            }
        }
    }

    for (int i = 0; i < valores.size(); i++) {
        dados[quantConjunto][i] = valores[i];
    }

}
void mostrarConjunto(){

}
void mostrarTodosConjuntos(){

}
void buscarValor(){

}

int main(){

}