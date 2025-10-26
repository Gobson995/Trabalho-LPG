#include <bits/stdc++.h>
#include "funcoes.h"

using namespace std;

int main() {
    int opcao = -1;

    cout << "=== GERENCIAMENTO DE CONJUNTOS ===" << endl;
    cout << "Máximo de conjuntos (M): " << M << endl;
    cout << "Máximo de elementos por conjunto (N): " << N << endl;

    while (opcao != 9) {
        cout << "\nEsse é o menu de opções para você escolher: " << endl;
        cout << "1 - Criar um novo conjunto vazio" << endl;
        cout << "2 - Inserir dados em um conjunto" << endl;
        cout << "3 - Remover um conjunto" << endl;
        cout << "4 - Fazer a união entre dois conjuntos" << endl;
        cout << "5 - Fazer a intersecção entre dois conjuntos" << endl;
        cout << "6 - Mostrar um conjunto" << endl;
        cout << "7 - Mostrar todos os conjuntos" << endl;
        cout << "8 - Fazer busca por um valor" << endl;
        cout << "9 - Sair do programa" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                criarConjunto();
                break;
            case 2:
                inserirValor();
                break;
            case 3:
                removerConjunto();
                break;
            case 4:
                unir2Conjuntos();
                break;
            case 5:
                interseccao2Conjuntos();
                break;
            case 6:
                mostrarConjunto();
                break;
            case 7:
                mostrarTodosConjuntos();
                break;
            case 8:
                buscarValor();
                break;
            case 9:
                cout << "\nEncerrando o programa..." << endl;
                break;
            default:
                cout << "\nOpção inválida. Tente novamente." << endl;
        }
    }
}
