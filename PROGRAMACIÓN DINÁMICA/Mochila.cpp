#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int valor;
    int peso;
};

int Mochila(int capacidad, const vector<Item>& elementos) {
    int n = elementos.size();
    vector<int> dp(capacidad + 1, 0);

    for (int i = 0; i < n; ++i) {
        for (int w = capacidad; w >= elementos[i].peso; --w) {
            dp[w] = max(dp[w], dp[w - elementos[i].peso] + elementos[i].valor);
        }
    }

    return dp[capacidad];
}

int main() {
    int capacidad_mochila = 10;
    vector<Item> elementos = {{13, 5}, {4, 4}, {32, 6}};

    int max_ganancia = Mochila(capacidad_mochila, elementos);
    cout << "La máxima ganancia que se puede obtener es: " << max_ganancia << endl;

    return 0;
}