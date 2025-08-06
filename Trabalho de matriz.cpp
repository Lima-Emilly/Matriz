#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

// Soma dois números
int somar(int a, int b) {
    return a + b;
}

// Multiplica dois números
int multiplicar(int a, int b) {
    return a * b;
}

// Lê uma matriz de um arquivo .txt
vector<vector<int> > lerMatriz(const string& nomeArquivo) {
    ifstream arquivo(nomeArquivo.c_str());
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
        exit(1);
    }

    vector<vector<int> > matriz;
    string linha;

    while (getline(arquivo, linha)) {
        istringstream iss(linha);
        vector<int> linhaMatriz;
        int numero;
        while (iss >> numero) {
            linhaMatriz.push_back(numero);
        }
        matriz.push_back(linhaMatriz);
    }

    return matriz;
}

// Verifica se a matriz é quadrada
bool matrizQuadrada(const vector<vector<int> >& matriz) {
    int linhas = matriz.size();
    for (int i = 0; i < linhas; ++i) {
        if (matriz[i].size() != linhas) return false;
    }
    return true;
}

// Exibe uma matriz
void exibirMatriz(const vector<vector<int> >& matriz) {
    for (int i = 0; i < matriz.size(); ++i) {
        for (int j = 0; j < matriz[i].size(); ++j) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}

// Multiplica duas matrizes usando funções de soma e multiplicação
vector<vector<int> > multiplicarMatrizes(const vector<vector<int> >& A, const vector<vector<int> >& B) {
    int N = A.size();
    vector<vector<int> > resultado(N, vector<int>(N, 0));

    cout << "\nPasso a passo da multiplicação:\n";

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << "C[" << i << "][" << j << "] = ";
            for (int k = 0; k < N; ++k) {
                int produto = multiplicar(A[i][k], B[k][j]);
                resultado[i][j] = somar(resultado[i][j], produto);
                cout << A[i][k] << "*" << B[k][j];
                if (k < N - 1) cout << " + ";
            }
            cout << " = " << resultado[i][j] << endl;
        }
    }

    return resultado;
}

int main() {
    vector<vector<int> > matriz1 = lerMatriz("matriz1.txt");
    vector<vector<int> > matriz2 = lerMatriz("matriz2.txt");

    if (!matrizQuadrada(matriz1) || !matrizQuadrada(matriz2)) {
        cout << "Erro: As matrizes não são quadradas." << endl;
        return 1;
    }

    if (matriz1.size() != matriz2.size()) {
        cout << "Erro: As matrizes não têm o mesmo tamanho." << endl;
        return 1;
    }

    cout << "Matriz 1:\n";
    exibirMatriz(matriz1);

    cout << "\nMatriz 2:\n";
    exibirMatriz(matriz2);

    vector<vector<int> > resultado = multiplicarMatrizes(matriz1, matriz2);

    cout << "\nMatriz Resultado:\n";
    exibirMatriz(resultado);

    return 0;
}

