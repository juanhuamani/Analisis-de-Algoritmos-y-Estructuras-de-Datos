#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Objeto {
    int peso;
    int valor;
};

bool compararPorRatio(const Objeto& obj1, const Objeto& obj2) {
    double ratio1 = double(obj1.valor) / obj1.peso;
    double ratio2 = double(obj2.valor) / obj2.peso;
    return ratio1 > ratio2;
}

int mochila(int capacidad, const vector<Objeto>& objetos) {
    vector<Objeto> objetosOrdenados(objetos);
    sort(objetosOrdenados.begin(), objetosOrdenados.end(), compararPorRatio);

    int pesoActual = 0;
    double valorActual = 0.0;

    for (const auto& objeto : objetosOrdenados) {
        if (pesoActual + objeto.peso <= capacidad) {
            pesoActual += objeto.peso;
            valorActual += objeto.valor;
        } else {
            int pesoRestante = capacidad - pesoActual;
            valorActual += (double(pesoRestante) / objeto.peso) * objeto.valor;
            break;
        }
    }

    return int(valorActual);
}

int main() {
    int capacidadMochila = 15;
    vector<Objeto> objetos = {{10, 60}, {20, 100}, {30, 120}};

    int valorOptimo = mochila(capacidadMochila, objetos);

    cout << "Valor en la mochila: " << valorOptimo << endl;

    return 0;
}