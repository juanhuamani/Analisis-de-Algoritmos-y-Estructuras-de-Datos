#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int izquierda, int medio, int derecha) {
    int n1 = medio - izquierda + 1;
    int n2 = derecha - medio;

    vector<int> arregloIzquierdo(n1);
    vector<int> arregloDerecho(n2);

    for (int i = 0; i < n1; i++) {
        arregloIzquierdo[i] = arr[izquierda + i];
    }
    for (int j = 0; j < n2; j++) {
        arregloDerecho[j] = arr[medio + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = izquierda;

    while (i < n1 && j < n2) {
        if (arregloIzquierdo[i] <= arregloDerecho[j]) {
            arr[k] = arregloIzquierdo[i];
            i++;
        } else {
            arr[k] = arregloDerecho[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = arregloIzquierdo[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = arregloDerecho[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int izquierda, int derecha) {
    if (izquierda < derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        mergeSort(arr, izquierda, medio);
        mergeSort(arr, medio + 1, derecha);

        merge(arr, izquierda, medio, derecha);
    }
}

void printArray(const vector<int>& arr) {
    for (int elemento : arr) {
        cout << elemento << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {45, 23, 13, 32, 26, 11};
    int n = arr.size();

    cout << "Arreglo original: "<<endl;
    printArray(arr);
	
	//ORDENANDO EL ARREGLO
    mergeSort(arr, 0, n - 1);
	
    cout << endl<<"Arreglo ordenado: "<<endl;
    printArray(arr);

    return 0;
}