#include <bits/stdc++.h>
#include "funcoes.h"

using namespace std;

vector<vector<int>> dados(M, vector<int> (N,0));
int quantConjunto = 0;

void criarConjunto() {
    if (quantConjunto < M) {
        quantConjunto++;
        cout << "O conjunto " << quantConjunto -1 << " foi criado." << endl;
    }
    else {
        cout << "Você não pode criar mais conjuntos, pois você já criou todos possíveis" << endl;
    }
}

void inserirValor() {
    int linha, valor;

    if (quantConjunto == 0) {
        cout << "Nenhum conjunto foi criado ainda." << endl;
        return;
    }

    cout << "Em qual conjunto você deseja inserir os dados?" << endl;
    cin >> linha;
    
    while (linha < 0 || linha >= quantConjunto) {
        cout << "Você digitou um valor inválido, pois essa linha (ainda) não existe" << endl;
        cout << "Em qual conjunto você deseja inserir os dados?" << endl;
        cin >> linha;
    }

    int pos = 0;
    while (pos < N && dados[linha][pos] != 0) {
        pos++;
    }

    if (pos == N) {
        cout << "O conjunto está cheio." << endl;
        return;
    }

    cout << "Digite os valores (0 encerra): " << endl;
    
    while (pos < N) {
        cin >> valor;

        if (valor == 0) {
            break;
        }

        bool repetido = false;
        for (int j = 0; j < pos; j++) {
            if (dados[linha][j] == valor) {
                repetido = true;
                break;
            }
        }

        if (repetido) {
            cout << "Valor repetido. Digite outro: ";
            continue;
        }

        dados[linha][pos] = valor;
        pos++;

        if (pos == N) {
            cout << "Você atingiu o limite do conjunto." << endl;
            break;
        }
    }
}

void removerConjunto() {
    int linha;

    if (quantConjunto == 0) {
        cout << "Nenhum conjunto foi criado ainda." << endl;
        return;
    }

    cout << "Em qual conjunto você deseja remover?" << endl;
    cin >> linha;
    
    while (linha < 0 || linha >= quantConjunto) {
        cout << "Você digitou um valor inválido, pois essa linha não existe" << endl;
        cout << "Qual conjunto você deseja remover?" << endl;
        cin >> linha;
    }

    for (int i = linha; i < (quantConjunto - 1); i++) {
        for (int j = 0; j < N; j++) {
            dados[i][j] = dados[i+1][j];
        }
    }

    for (int i = 0; i < N; i++) {
        dados[quantConjunto - 1][i] = 0;
    }

    quantConjunto--;
    cout << "Conjunto removido." << endl;
}

void unir2Conjuntos() {
    int linha1, linha2, final = 0, pos = 0;
    map<int,int> freq;

    if (quantConjunto >= M) {
        cout << "Não há espaço para um novo conjunto" << endl;
        return;
    }

    if (quantConjunto < 2) {
        cout << "Não existe dois conjuntos para fazer a união." << endl;
        return;
    }

    cout << "Quais dois conjunto você deseja unir?" << endl;
    cout << "Primeiro conjunto: ";
    cin >> linha1;
    
    while (linha1 < 0 || linha1 >= quantConjunto) {
        cout << "Você digitou um valor inválido, pois essa linha não existe" << endl;
        cout << "Primeiro conjunto: " << endl;
        cin >> linha1;
    }

    cout << endl << "Segundo conjunto: ";
    cin >> linha2;

    while (linha2 < 0 || linha2 >= quantConjunto) {
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

    quantConjunto++;

    for (auto x : freq) {
        int valor = x.first;
        if (pos >= N) {
            break;
        }
        dados[quantConjunto-1][pos] = valor;
        pos++;
    }

    cout << "União de conjuntos criada." << endl;
}

void interseccao2Conjuntos(){
    int linha1, linha2, pos = 0;
    map<int,int> freq;

    if (quantConjunto >= M) {
        cout << "Não há espaço para um novo conjunto" << endl;
        return;
    }

    if (quantConjunto < 2) {
        cout << "Não existe dois conjuntos para fazer a intersecção." << endl;
        return;
    }

    cout << "Quais dois conjunto você deseja fazer a intersecção?" << endl;
    cout << "Primeiro conjunto: ";
    cin >> linha1;
    
    while (linha1 < 0 || linha1 >= quantConjunto) {
        cout << "Você digitou um valor inválido, pois essa linha não existe" << endl;
        cout << "Primeiro conjunto: " << endl;
        cin >> linha1;
    }

    cout << endl << "Segundo conjunto: ";
    cin >> linha2;

    while (linha2 < 0 || linha2 >= quantConjunto) {
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

    quantConjunto++;

    for (auto x : freq) {
        int valor = x.first;
        int vezes = x.second;
        if (vezes == 2) {
            dados[quantConjunto-1][pos] = valor;
            pos++;
        }
    }   

    cout << "Intersecção de conjuntos criada." << endl; 
}
void mostrarConjunto() {
    int linha;

    if (quantConjunto == 0) {
        cout << "Nenhum conjunto foi criado ainda." << endl;
        return;
    }

    cout << "Qual dos conjuntos você deseja ver?" << endl;
    cin >> linha;
    
    while (linha < 0 || linha >= quantConjunto) {
        cout << "Você digitou um valor inválido, pois essa linha não existe" << endl;
        cout << "Qual conjunto você deseja ver?" << endl;
        cin >> linha;
    }

    cout << "Conjunto " << linha << " = ";

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
        }
        cout << endl;
    }
}

void mostrarTodosConjuntos() {
    int linha = 0;

    if (quantConjunto == 0) {
        cout << "Nenhum conjunto foi criado ainda." << endl;
        return;
    }

    cout << "Temos " << quantConjunto << " conjuntos:" << endl;
    
    while (linha < quantConjunto) {
        cout << "Conjunto " << linha << " = ";
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
        }
        cout << endl;
        }
        linha++;
    }

}
void buscarValor() {
    int valor, pos = 0;

    if (quantConjunto == 0) {
        cout << "Nenhum conjunto foi criado ainda." << endl;
        return;
    }

    cout << "Qual valor você deseja buscar?" << endl;
    cin >> valor;

    if (valor == 0) {
        cout << "O valor 0 não existe, pois não é permitido." << endl;
        return;
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

    if (pos == 0) {
        cout << "Nenhum conjunto contém o valor " << valor << "." << endl;
    }
    else {
        cout << "Conjuntos que contêm o valor " << valor << ":" << endl;
        for (int i = 0; i < pos; i++) {
            cout << "Conjunto " << indices[i] << endl;
        }
    }
}
