#include <bits/stdc++.h>
#include "funcao.h"

using namespace std;

int dados[M][N] = {0};
int coluna = -1;
int quantConjunto = 0;

int lerLinhaValida(){
    int linha = -1;
    while (linha <= 0 || linha > quantConjunto) {
        cout << "Em qual linha você deseja inserir os dados? (INTERVALO: 1 - "<< quantConjunto << ")" << endl;
        cin >> linha;
        if(linha <= 0 || linha > quantConjunto)
            cout << "Você digitou um valor inválido, pois essa linha não existe" << endl;
    }
    return linha - 1; 
}
bool msgQuantConjunto(int plus = 0){
    cout << quantConjunto;
    if(quantConjunto+plus > M){
        cout << "limite maximo de conjuntos atingido"<<endl;
        return true;
    }else if(quantConjunto == 0){
        cout << "voce nao possui nenhum conjunto"<< endl;
        return true;
    }else{
        return false;
    }
}
void buscarValor() {
    int valor, pos = 0;
    if(msgQuantConjunto())return;
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
}

void criarConjunto() {
    if (quantConjunto < M) {
        quantConjunto++;
    }
    else {
        cout << "Você não pode criar mais conjuntos, pois você já criou todos possíveis" << endl;
    }
}

void inserirValor(){
    int linha = -1;
    int valor;
    if(msgQuantConjunto())return;
    linha = lerLinhaValida();

    cout << "ok" <<endl;
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
    int linha = -1;
    if(msgQuantConjunto())return;
    linha = lerLinhaValida();

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
    if(msgQuantConjunto(1))return;
    cout << "Quais dois conjunto você deseja unir?" << endl;
    cout << endl << "Primeiro conjunto: ";
    linha1 = lerLinhaValida();
    
    cout << endl << "Segundo conjunto: ";
    linha2 = lerLinhaValida();
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
void interseccao2Conjuntos(){
    int linha1, linha2, pos = 0;
    map<int,int> freq;
    if(msgQuantConjunto(1))return;

    cout << "Quais dois conjunto você deseja fazer a intersecção?" << endl;
    cout << "Primeiro conjunto: ";
    linha1 = lerLinhaValida();

    cout << endl << "Segundo conjunto: ";
    linha2 = lerLinhaValida();
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

void mostrarConjunto() {
    int linha = -1;
    if(msgQuantConjunto())return;
    linha = lerLinhaValida();

    cout << "Conjunto " << linha << " = {";
    for (int i = 0; i < N; i++) {
        if (dados[linha-1][0] == 0) {
            cout << "Vazio";
            break;
        }
        else if (dados[linha][i] == 0) {
            break;
        }
        else {
            cout << dados[linha][i] << " ";
            cout << ", ";
        }
    }
    cout << "}"<<endl;
}
void mostrarTodosConjuntos() {
    int linha = 0;
    if(msgQuantConjunto())return;
    cout << "Temos " << quantConjunto << " conjuntos:" << endl;
    while (linha < quantConjunto) {
        cout << "Conjunto " << linha << " = {";
        for (int i = 0; i < N; i++) {
            if (dados[linha][0] == 0) {
                cout << "Vazio";
                break;
            }
            else if (dados[linha][i] == 0) {
                break;
            }
            else {
                cout << dados[linha][i] << " ";
                cout << ", ";
            }
            
        }
        cout << "}" << endl;
        linha++;
    }
}
void mostrarTUDO() {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << dados[i][j] << ' ';
        }
        cout << endl;
    }
}

