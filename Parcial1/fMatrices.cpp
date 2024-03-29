#include <iostream>

using namespace std;

const int MAX = 10;

void rotarMatriz(int matriz[MAX][MAX], int n) {
    // Crear una matriz auxiliar para almacenar la matriz rotada
    int matriz_rotada[MAX][MAX];

    // Rotar la matriz
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matriz_rotada[n - 1 - j][i] = matriz[i][j];
        }
    }

    // Copiar la matriz rotada de vuelta a la matriz original
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matriz[i][j] = matriz_rotada[i][j];
        }
    }

    // Imprimir la matriz rotada
    cout << endl << "Matriz rotada de tamanho " << n << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matriz[i][j] == 0) {
                cout << "  "; // Espacio vacío en el centro
            } else {
                cout << matriz[i][j] << " ";
            }
        }
        cout << endl;
    }
}



void hacerMatriz(int matriz[MAX][MAX], int n){

    int valor = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == n / 2 && j == n / 2) { // Dejar el centro vacío
                matriz[i][j] = 0;
            } else {
                matriz[i][j] = valor++;
            }
        }
    }

    // Imprimir la matriz original
    cout << "Matriz original de tamanho " << n << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matriz[i][j] == 0) {
                cout << "  "; // Espacio vacío en el centro
            } else {
                cout << matriz[i][j] << " ";
            }
        }
        cout << endl;
    }

}

int main() {
    int n1, n2, n3, n4;
    cout << "Ingrese un número impar para el tamaño de la matriz 1: ";
    cin >> n1;
    cout << "Ingrese un número impar para el tamaño de la matriz 2: ";
    cin >> n2;
    cout << "Ingrese un número impar para el tamaño de la matriz 3: ";
    cin >> n3;
    cout << "Ingrese un número impar para el tamaño de la matriz 4: ";
    cin >> n4;

    if ((n1 % 2 == 0) or (n2 % 2 == 0) or (n3 % 2 == 0) or (n4 % 2 == 0)) {
        cout << "El número ingresado no es impar. Por favor, intente de nuevo con un número impar." << endl;
        return 1;
    }

    int matriz[MAX][MAX];


    hacerMatriz(matriz, n1);
    rotarMatriz(matriz, n1);

    hacerMatriz(matriz, n2);
    rotarMatriz(matriz, n2);

    hacerMatriz(matriz, n3);
    rotarMatriz(matriz, n2);

    hacerMatriz(matriz, n4);
    rotarMatriz(matriz, n4);
   


    // Imprimir la matriz rotada
    /*cout << endl << "Matriz rotada: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matriz[i][j] == 0) {
                cout << "  "; // Espacio vacío en el centro
            } else {
                cout << matriz[i][j] << " ";
            }
        }
        cout << endl;
    }*/

    return 0;
}