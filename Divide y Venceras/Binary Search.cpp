#include <iostream>
#include <vector>

using namespace std;

int busquedaBinaria(const vector<int>& arr, int izquierda, int derecha, int objetivo) {
    if (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        if (arr[medio] == objetivo) {
            return medio;
        }

        if (arr[medio] > objetivo) {
            return busquedaBinaria(arr, izquierda, medio - 1, objetivo);
        }

        return busquedaBinaria(arr, medio + 1, derecha, objetivo);
    }

    return -1;
}

int main() {
    vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = arr.size();
    int objetivo = 38;

    int indice = busquedaBinaria(arr, 0, n - 1, objetivo);

    if (indice != -1) {
        cout << "Elemento "<<objetivo<<" encontrado = [ " << indice << " ] "<<endl;
    } else {
        cout << "Elemento no encontrado" << endl;
    }

    return 0;
}