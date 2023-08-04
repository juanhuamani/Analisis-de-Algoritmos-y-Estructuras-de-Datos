#include <iostream>
#include <vector>
using namespace std;

int max_value = 0;

struct Nodo {
    int peso_acumulado;
    int valor_acumulado;
    int nivel;
};

void backtrack_knapsack(const vector<int>& weights, const vector<int>& values, int capacity) {
    vector<Nodo> pila;
    Nodo nodo_actual, nodo_izquierdo, nodo_derecho;

    nodo_actual.peso_acumulado = 0;
    nodo_actual.valor_acumulado = 0;
    nodo_actual.nivel = 0;

    pila.push_back(nodo_actual);

    while (!pila.empty()) {
        nodo_actual = pila.back();
        pila.pop_back();

        if (nodo_actual.nivel == weights.size() || nodo_actual.peso_acumulado >= capacity) {
            max_value = max(max_value, nodo_actual.valor_acumulado);
            continue;
        }

        nodo_izquierdo.peso_acumulado = nodo_actual.peso_acumulado + weights[nodo_actual.nivel];
        nodo_izquierdo.valor_acumulado = nodo_actual.valor_acumulado + values[nodo_actual.nivel];
        nodo_izquierdo.nivel = nodo_actual.nivel + 1;

        if (nodo_izquierdo.peso_acumulado <= capacity) {
            pila.push_back(nodo_izquierdo);
        }

        nodo_derecho.peso_acumulado = nodo_actual.peso_acumulado;
        nodo_derecho.valor_acumulado = nodo_actual.valor_acumulado;
        nodo_derecho.nivel = nodo_actual.nivel + 1;

        pila.push_back(nodo_derecho);
    }
}

int main() {
    int capacity;
    cout << "Ingrese la capacidad máxima de la mochila: ";
    cin >> capacity;

    int n;
    cout << "Ingrese el número de elementos: ";
    cin >> n;

    vector<int> weights(n);
    vector<int> values(n);

    cout << "Ingrese los pesos de los elementos:\n";
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    cout << "Ingrese los valores de los elementos:\n";
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    backtrack_knapsack(weights, values, capacity);

    cout << "El valor máximo que se puede obtener es: " << max_value << endl;

    return 0;
}
