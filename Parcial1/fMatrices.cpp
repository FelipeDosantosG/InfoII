#include <iostream>

using namespace std;

const int MAX = 10;

int main() {
    int n;
    cout << "Ingrese un número impar para el tamaño de la matriz: ";
    cin >> n;

    if (n % 2 == 0) {
        cout << "El número ingresado no es impar. Por favor, intente de nuevo con un número impar.\n";
        return 1;
    }

    int matriz[MAX][MAX];

    // Llenar la matriz con números
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

    // Imprimir la matriz
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matriz[i][j] == 0) {
                cout << "  "; // Espacio vacío en el centro
            } else {
                cout << matriz[i][j] << "  ";
            }
        }
        cout << endl;
    }

    return 0;
}