#include <iostream>
//#include <cctype> // Para la función isdigit()


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
    cout << endl << endl;;
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
    cout << endl << endl;;

}

void verifTam(int matriz[MAX][MAX], int tamNumero, int n, int matrixR, int* matrix, int fil, int col, int* nTam){
    //Esta función indica si el valor de la siguiente matriz debe ser más pequeño o grande que el de la actual.

    if (tamNumero == -1){
        n = n + 2;
        hacerMatriz(matriz, n, matrix, fil, col);
        //cout << "El tamaño del siguiente valor debe ser menor a: " << *matrix << endl;
        *nTam = n;

    } else if (tamNumero == 1){
        n = n - 2;
        hacerMatriz(matriz, n, matrix, fil, col);
        //cout << "El tamaño del siguiente valor debe ser mayor a: " << *matrix << endl;
        *nTam = n;

    } else {
        hacerMatriz(matriz, n, matrix, fil, col);
        //cout << "El tamaño del siguiente valor debe ser igual a: " << *matrix << endl;
        *nTam = n;
    }
}

bool esNumero(const char *str) {
    while (*str) {
        if ((*str < '0' || *str > '9') && *str != '-') {
            return false;
        }
        str++;
    }
    return true;
}

int main() {

    int fil, col, matriz[MAX][MAX], matrix, matrixR = 0, tamMatriz = 0,  matriz1[MAX][MAX], nTam, r1; //n1 representa el tamaño de la matriz 1
    int keyInt[5]={}, valMatrices[4]={}, xOut[4] = {};
    char input[MAX];

    cout << "Ingrese los valores de la llave. \nTenga en cuenta que si ingresta Matriza un número con decimales, solo se tendran en cuenta la parte entera" << endl << endl;

    for (int i = 0; i < 5; i++){
        do{
            cout << "Valor " << i + 1 << ": ";
            cin.getline(input, MAX);

            if(!esNumero(input)) {
                cout << "No ingresaste un valor correcto, intenta nuevamente." << endl;
            } else {
                keyInt[i] = atoi(input);
                break;
            }
        } while (true);


        // Esta validación verifica que los primeros dos datos sean mayores a cero y guarda su parte entera en un arreglo llamado keyInt
        while ((i < 2) && (keyInt[i] <= 0)){
            cout << "Recuerde que en este campo solo puede ingresar numeros mayores a cero y enteros: ";
            cin >> keyInt[i];
        }

        // Esta validación verifica que los últimos tres datos sean -1, 0 ó 1
        while ((i > 1) && ((keyInt[i] != -1) && (keyInt[i] != 0) && (keyInt[i] != 1))){
            cout << "Recuerde que en este campo solo puede ingresar uno de tres números: -1, 0, 1. \nFavor ingresar una de estas opciones: ";
            cin >> keyInt[i];
        }
        //cout << "El valor " << i << " es: " << keyInt[i] << endl;
    }

    fil = keyInt[0] - 1, col = keyInt[1] - 1;

    // Estas validaciones se encargan de elegir el tamaño de la matriz primera
    if ((keyInt[0] > keyInt[1]) || (keyInt[0] == keyInt[1])){
        tamMatriz = keyInt[0] + 2;
    } else if (keyInt[0] < keyInt[1]){
        tamMatriz = keyInt[1] + 2;
    } else if ((keyInt[0] < 3) || (keyInt[1] < 3)){
        tamMatriz = 3;
    }

    // Validación que se asegura que el valor seleccionado para el tamaño de la matriz sea impar
    if ((tamMatriz % 2) == 0){
        tamMatriz ++;
    }
    // keiInt()

    if ((tamMatriz == 3) and (keyInt[2] == -1)){
        tamMatriz = 5;
    }

    /*
        if ((tamMatriz = 5) &&  (keyInt[0] == 3) && (keyInt[1] == 3)){
        tamMatriz = 7;
    }
    */

    cout << "Valor de la llave ingresada: K(" << keyInt[0] << ", " << keyInt[1] << ", "  << keyInt[2] << ", "  << keyInt[3] << ", "  << keyInt[4] << ") " << endl;

    hacerMatriz(matriz, tamMatriz, &matrix, fil, col);
    cout << matrix << endl <<"------------------------" << endl;
    valMatrices[0] = matrix;



    verifTam(matriz, keyInt[2], tamMatriz, matrixR, &matrix, fil, col, &nTam);
    cout << matrix << endl <<"------------------------" << endl;

    rotarMatriz(matriz, nTam, &matrixR, fil, col);
    cout << matrixR << endl <<"------------------------" << endl;


    if (keyInt[2] == -1) {


            while (valMatrices[0] < valMatrices[1]){

                rotarMatriz(matriz, nTam, &matrixR, fil, col);
                valMatrices[1] = matrixR;

                r1 ++;
            }
    }






    //verifTam(matriz, keyInt[2], tamMatriz, matrixR, &matrix, fil, col, &nTam);

    //valMatrices[1] = matrix;





    /------------------------------------ Espacio de código basura ------------------------------------/



/*
 if (keyInt[2] == -1) {
        cout << valMatrices[0] << " vs " << valMatrices[1];

        while (valMatrices[0] < valMatrices[1]){

            rotarMatriz(matriz, nTam, &matrixR, fil, col);
            valMatrices[1] = matrixR;

            r1 ++;
        }
    }





     //rotarMatriz(matriz, tamMatriz, &matrixR, fil, col);

    //cout << "El valor de la posición (" << fil << ", " << col << "), es: " << matrixR << endl;
   //verifTam(matriz, keyInt[2], tamMatriz, matrixR, &matrix, fil, col, &nTam);





    //hacerMatriz(matriz, tamMatriz, &matrix, fil, col);

    //verifTam(int tamNumero, int matrix)





    //cout << "Tamanho de la matriz primera " << tamMatriz << " Tamanho del valor tercero: " << keyInt[2] << endl;
 rotarMatriz(matriz, nTam, &matrixR, fil, col);
    rotarMatriz(matriz, nTam, &matrixR, fil, col);

    cout << valMatrices[0] << endl << valMatrices[1] << endl;

*/



    //hacerMatriz(matriz, tamMatriz, &matrix, fil, col);


    /*hacerMatriz(matriz, n1, &matrix, fil, col);
    cout << "Ingrese el valor de la llave";
    //cout << "El valor del return: " << matrix << endl << endl;
    if (matrix == 0){
        cout << "El tamaño rotarMatriz(matriz, n1) debería ser diferente.  \n \n";
    } else {
        cout << "El tamaño de la matriz está bién. \n \n";
    }
    rotarMatriz(matriz, n1, &matrixR, fil, col);
    k(4, 3, 1, -1, 1)
    x(5, 7, 5, 9)
    M1 fil 2 col 3 12
    M2 fil 2 col 3 10
    */

    return 0;
}
