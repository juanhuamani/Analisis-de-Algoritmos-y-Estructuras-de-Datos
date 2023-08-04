#include <iostream>
#include <vector>
using namespace std;

int max_valor = 0; 

void mochila_backtrack(const vector<int>& pesos, const vector<int>& valores, int capacidad, int indice, int peso_actual, int valor_actual) {
    if (indice == pesos.size() || peso_actual >= capacidad) {
        max_valor = max(max_valor, valor_actual);
        return;
    }
    if (peso_actual + pesos[indice] <= capacidad) {
        mochila_backtrack(pesos, valores, capacidad, indice + 1, peso_actual + pesos[indice], valor_actual + valores[indice]);
    }
    mochila_backtrack(pesos, valores, capacidad, indice + 1, peso_actual, valor_actual);
}

int main() {
    int capacidad;
    cout << "Ingrese la capacidad máxima de la mochila: ";
    cin >> capacidad;

    int n;
    cout << "Ingrese el número de elementos: ";
    cin >> n;

    vector<int> pesos(n);
    vector<int> valores(n);

    cout << "Ingrese los pesos de los elementos:\n";
    for (int i = 0; i < n; ++i) {
        cin >> pesos[i];
    }

    cout << "Ingrese los valores de los elementos:\n";
    for (int i = 0; i < n; ++i) {
        cin >> valores[i];
    }

    mochila_backtrack(pesos, valores, capacidad, 0, 0, 0);

    cout << "El valor máximo que se puede obtener es: " << max_valor << endl;

    return 0;
}
