#include <iostream>

using namespace std;

const int MAX = 15;

void rotarMatriz(int matriz[MAX][MAX], int n, int* matrixR, int fil, int col) {
    // Crear una matriz auxiliar para almacenar la matriz rotada
    int matriz_rotada[MAX][MAX];

    // Rotar la matriz
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matriz_rotada[n - 1 - j][i] = matriz[i][j];
        }
    }

    *matrixR = matriz_rotada[fil][col];

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
    
    int n1 = 3, n2 = 5, fil = 2, col = 2, matriz[MAX][MAX], matrix, matrixR, tamMatriz = 0; //n1 representa el tamaño de la matriz 1
    int keyInt[5]={};

    cout << "Ingrese los valores de la llave" << endl << endl;

    for (int i = 0; i < 5; i++){
        cout << "Valor " << i + 1 << ": "; 
        cin >> keyInt[i];
    }

    if ((keyInt[0] > keyInt[1]) || (keyInt[0] == keyInt[1])){
        tamMatriz = keyInt[0];
    } else if (keyInt[0] < keyInt[1]){
        tamMatriz = keyInt[1];
    } else if ((keyInt[0] < 3) || (keyInt[1] < 3)){
        tamMatriz = 3;
    }
    
    if ((tamMatriz % 2) == 0){
        tamMatriz ++;
    }
    
    if ((tamMatriz == 3) and (keyInt[2] == -1)){
        tamMatriz = 5;
    }
    
    cout << "Tamanho de la matriz primera " << tamMatriz << " Tamanho del valor tercero: " << keyInt[2] << endl;

    hacerMatriz(matriz, tamMatriz, &matrix, fil, col);


    /*hacerMatriz(matriz, n1, &matrix, fil, col);
    cout << "Ingrese el valor de la llave";
    //cout << "El valor del return: " << matrix << endl << endl;

    if (matrix == 0){
        cout << "El tamaño rotarMatriz(matriz, n1) debería ser diferente.  \n \n";
    } else {
        cout << "El tamaño de la matriz está bién. \n \n";
    }

    rotarMatriz(matriz, n1, &matrixR, fil, col); */
   
    return 0;
}