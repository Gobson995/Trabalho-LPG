#include <bits/stdc++.h>
#include "funcao.h"

using namespace std;

int dados[M][N] = {0};
int linha = -1;
int coluna = -1;
int quantConjunto = 0;


void criarConjunto() {
    if (quantConjunto <= M) {
        quantConjunto++;
    }
    else {
        cout << "Você não pode criar mais conjuntos, pois você já criou todos possíveis" << endl;
    }
}

void inserirValor(){
    int valor;
    if(!quantConjunto){
        cout << "Nao ha conjuntos criados " << '\n';
        return;
    }
    while (linha <= 0 || linha > quantConjunto) {
        cout << "Em qual linha você deseja inserir os dados? (informe um numero maior que 0)" << endl;
        cin >> linha;
        if(linha <= 0 || linha > quantConjunto)
        cout << "Você digitou um valor inválido, pois essa linha não existe" << endl;
    }
    linha--;
    cout << "ok"<<endl;
    cout << "insira os valores do conjunto, informe 0 para parar" << endl;
    for (int i = 0; i < N; i++) {
        cin >> valor;
        if (valor == 0) {
            cout << "Interrompido" << endl;
            break;
        }else if(i == N){
            cout << "limite do conjunto" << endl;
            break;
        }
        else {
            dados[linha][i] = valor;
        }
    }
}

void removerConjunto() {
    int linha;
    if(!quantConjunto){
        cout << "Nao ha conjuntos criados " << '\n';
        return;
    }
    cout << "Em qual linha você deseja remover os dados?" << endl;
    cin >> linha;
    
    while (linha <= 0 || linha > quantConjunto) {
        cout << "Você digitou um valor inválido, pois essa linha não existe" << endl;
        cout << "Em qual linha você deseja remover os dados?" << endl;
        cin >> linha;
    }
    linha--;
    for(int i = 0; i < N; i++) {
        dados[linha][i] = 0;
    }

    while (linha < (quantConjunto - 1)) {
        for (int i = 0; i < N; i++) {
            dados[linha][i] = dados[linha+1][i];
            dados[linha+1][i] = 0;
        }
        linha++;
    }

    quantConjunto--;
}

void unir2Conjuntos() {
    int linha1, linha2, final = 0, pos = 0;
    map<int,int> freq;
    if(!quantConjunto){
        cout << "Nao ha conjuntos criados " << '\n';
        return;
    }
    quantConjunto++;

    if (quantConjunto <= M) {
        cout << "Quais dois conjunto você deseja unir?" << endl;
        cout << "Primeiro conjunto: ";
        cin >> linha1;
        
        while (linha1 <= 0 || linha1 > quantConjunto) {
            cout << "Você digitou um valor inválido, pois essa linha não existe" << endl;
            cout << "Primeiro conjunto: " << endl;
            cin >> linha1;
        }
    
        cout << endl << "Segundo conjunto: ";
        cin >> linha2;
    
        while (linha2 <= 0 || linha2 > quantConjunto) {
            cout << "Você digitou um valor inválido, pois essa linha não existe" << endl;
            cout << "Segundo conjunto: " << endl;
            cin >> linha2;
        }
        cout << endl;
    
        for (int i = 0; i < N; i++) {
            if (dados[linha1][i] != 0) {
                freq[dados[linha1][i]]++;
            }
            if (dados[linha2][i] != 0) {
                freq[dados[linha2][i]]++;
            }
        }
    
        for (auto x : freq) {
            int valor = x.first;
            if ((pos+1) == N) {
                break;
            }
            dados[quantConjunto-1][pos] = valor;
            pos++;
        }
    }
    else {
        cout << "Você não pode unir dois conjuntos, pois você não tem espaço para mais um conjuto" << endl;
    }

}
void interseccao2Conjuntos(){
    int linha1, linha2, pos = 0;
    map<int,int> freq;
    if(!quantConjunto){
        cout << "Nao ha conjuntos criados " << '\n';
        return;
    }
    quantConjunto++;

    if (quantConjunto <= M) {
        cout << "Quais dois conjunto você deseja fazer a intersecção?" << endl;
        cout << "Primeiro conjunto: ";
        cin >> linha1;
        
        while (linha1 <= 0 || linha1 > quantConjunto) {
            cout << "Você digitou um valor inválido, pois essa linha não existe" << endl;
            cout << "Primeiro conjunto: " << endl;
            cin >> linha1;
        }
    
        cout << endl << "Segundo conjunto: ";
        cin >> linha2;
    
        while (linha2 <= 0 || linha2 > quantConjunto) {
            cout << "Você digitou um valor inválido, pois essa linha não existe" << endl;
            cout << "Segundo conjunto: " << endl;
            cin >> linha2;
        }
        cout << endl;

        for (int i = 0; i < N; i++) {
            if (dados[linha1][i] != 0) {
                freq[dados[linha1][i]]++;
            }
            if (dados[linha2][i] != 0) {
                freq[dados[linha2][i]]++;
            }
        }

        for (auto x : freq) {
            int valor = x.first;
            int vezes = x.second;
            if (vezes == 2) {
                dados[quantConjunto-1][pos] = valor;
                pos++;
            }
        }   
    }
    else {
        cout << "Você não pode unir dois conjuntos, pois você não tem espaço para mais um conjuto" << endl;
    }
}
void mostrarConjunto() {
    if(!quantConjunto){
        cout << "Nao ha conjuntos criados " << '\n';
        return;
    }
    cout << "Qual dos conjuntos você deseja ver?" << endl;
    cin >> linha;
    while (linha <= 0 || linha > quantConjunto) {
        cout << "Você digitou um valor inválido, pois essa linha não existe" << endl;
        cout << "Qual conjunto você deseja ver?" << endl;
        cin >> linha;
    }

    for (int i = 0; i < N; i++) {
        if (dados[linha-1][0] == 0) {
            cout << "Vazio";
            break;
        }
        else if (dados[linha][i] == 0) {
            break;
        }
        else {
            cout << "Conjunto " << linha << " = ";
            cout << dados[linha][i] << " ";
        }
        cout << endl;
    }
}
void mostrarTodosConjuntos() {
    linha = 0;
    if(!quantConjunto){
        cout << "Nao ha conjuntos criados " << '\n';
        return;
    }
    cout << "Temos " << quantConjunto << " conjuntos:" << endl;
    while (linha < quantConjunto) {
        for (int i = 0; i < N; i++) {
        cout << "Conjunto " << linha << " = ";
        if (dados[linha][0] == 0) {
            cout << "Vazio";
            break;
        }
        else if (dados[linha][i] == 0) {
            break;
        }
        else {
            cout << dados[linha][i] << " ";
        }
        cout << endl;
        }
    }

}
void buscarValor() {
    int valor, pos = 0;;
    if(!quantConjunto){
        cout << "Nao ha conjuntos criados " << '\n';
        return;
    }
    cout << "Qual valor você deseja buscar?" << endl;
    cin >> valor;

    while (valor != 0) {
        cout << "0 não existe dentro dos valores" << endl;
        cout << "Qual valor você deseja buscar?" << endl;
        cin >> valor;
    }

    vector<int> indices(M,-1);

    for (int i = 0; i < quantConjunto; i++) {
        for (int j = 0; j < N; j++) {
            if (dados[i][j] == 0) {
                break;
            }
            
            if (dados[i][j] == valor) {
                indices[pos] = i;
                pos++;
                break;
            }
        }
    }

    cout << "Conjuntos que contêm o valor " << valor << ":" << endl;

    for (int i = 0; i < M; i++) {
        if (indices[i] == -1) {
            break;
        }
        cout << "Conjunto " << indices[i] << endl;
    }
}
void mostrarTUDO(){
    for(int i = 0; i < M;i++){
        for(int j = 0;j < N;j++){
            cout << dados[i][j] << ' ';
        }
        cout << endl;
    }
}