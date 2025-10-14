#include <bits/stdc++.h>
using namespace std;
int main(){
    int opcao = -1;

    while(opcao != 0){
        cout << "1 - criar um conjunto vazio" << '\n';
        cout << "2 - inserir dados no conjunto" << '\n';
        cout << "3 - remover conjunto" << '\n';
        cout << "4 - fazer união de dois conjuntos" << '\n';
        cout << "5 - fazer intersecção de dois conjuntos" << '\n';
        cout << "6 - mostrar um conjunto" << '\n';
        cout << "7 - mostrar todos os conjuntos" << '\n';
        cout << "8 - Fazer busca por um valor" << '\n';
        cout << "0 - sair do sistema" << '\n';
        cin >> opcao;
        switch(opcao){
            case 1:
                criarConjunto();
            break;
            case 2:
                inserirvalor();
            break;
            case 3:
                removerConjunto();
            break;
            case 4:
            break;
            case 5:
            break;
            case 6:
            break;
            case 7:
            break;
            case 8:

            break;
            case 0:
            cout << "Encerrando...\n";
            break;
            default : 
            cout << "infome um valor valido \n";
        }
    }
}