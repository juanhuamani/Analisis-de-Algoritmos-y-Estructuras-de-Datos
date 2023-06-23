#include <iostream>
#include <vector>

using namespace std;

int particion(vector<int>& arr, int bajo, int alto) {
    int pivote = arr[alto];
    int i = bajo - 1;

    for (int j = bajo; j <= alto - 1; j++) {
        if (arr[j] < pivote) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[alto]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int bajo, int alto) {
    if (bajo < alto) {
        int pi = particion(arr, bajo, alto);

        quickSort(arr, bajo, pi - 1);
        quickSort(arr, pi + 1, alto);
    }
}

void imprimirArreglo(const vector<int>& arr) {
    for (int elemento : arr) {
        cout << elemento << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {53, 27, 42, 29, 41, 35};
    int n = arr.size();

    cout << "ORIGINAL: "<<endl;
    imprimirArreglo(arr);
	
    quickSort(arr, 0, n - 1);

    cout <<endl<< "ORDENADO: "<<endl;
    imprimirArreglo(arr);

    return 0;
}