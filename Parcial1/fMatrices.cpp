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

void hacerMatriz(int matriz[MAX][MAX], int n, int* matrix, int fil, int col){

    int valor = 1;
    //int matrix; 

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == n / 2 && j == n / 2) { // Dejar el centro vacío
                matriz[i][j] = 0;
            } else {
                matriz[i][j] = valor++;
            }
        }
    }

    *matrix = matriz[fil][col];

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
    int n1, n2, n3, n4, keyV, fil, col; //n1 representa el tamaño de la matriz 1

    cout << "Ingrese el valor de la llave k";
    cout << "Ingrese un número impar para el tamaño de la matriz 1: ";
    cin >> n1;
    cout << "Ingrese un número impar para el tamaño de la matriz 2: ";
    cin >> n2;
    cout << "Ingrese un número impar para el tamaño de la matriz 3: ";
    cin >> n3;
    cout << "Ingrese un número impar para el tamaño de la matriz 4: ";
    cin >> n4;

    cout << "Ingrese el valor de la fila: ";
    cin >> fil;
    cout << "Ingrese el valor de la columna: ";
    cin >> col;

    if ((n1 % 2 == 0) or (n2 % 2 == 0) or (n3 % 2 == 0) or (n4 % 2 == 0)) {
        cout << "El número ingresado no es impar. Por favor, intente de nuevo con un número impar." << endl;
        return 1;
    }



    int matriz[MAX][MAX], matrix;

    


    hacerMatriz(matriz, n1, &matrix, fil, col);
    keyV = matrix;
    cout << "El valor del return: " << matrix << endl << endl;

    hacerMatriz(matriz, n2, &matrix, fil, col);
    cout << "El valor del return: " << matrix << endl;

    if (matrix == 0){
        cout << "El tamaño de la matriz debería ser diferente.  \n \n";
    } else {
        cout << "El tamaño de la matriz está bién. \n \n";
    }
    
    hacerMatriz(matriz, n3, &matrix, fil, col);
    cout << "El valor del return: " << matrix << endl << endl;
    hacerMatriz(matriz, n4, &matrix, fil, col);
    cout << "El valor del return: " << matrix << endl << endl;

    cout << "El primer dato al que se refiere la llave es: " << keyV << endl;


    /*rotarMatriz(matriz, n1);

    hacerMatriz(matriz, n2);
    rotarMatriz(matriz, n2);

    hacerMatriz(matriz, n3);
    rotarMatriz(matriz, n2);

    hacerMatriz(matriz, n4);
    rotarMatriz(matriz, n4);*/
   
    return 0;
}