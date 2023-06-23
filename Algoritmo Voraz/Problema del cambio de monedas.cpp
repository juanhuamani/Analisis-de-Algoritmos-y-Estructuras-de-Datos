#include <iostream>
#include <vector>

using namespace std;

vector<int> cambioMonedas(int monto, const vector<int>& denominaciones) {
    vector<int> resultado(denominaciones.size(), 0);

    for (int i = denominaciones.size() - 1; i >= 0; i--) {
        while (monto >= denominaciones[i]) {
            resultado[i]++;
            monto -= denominaciones[i];
        }
    }

    return resultado;
}

int main() {
    int monto = 74;
    vector<int> denominaciones = {1, 5, 10, 25};

    vector<int> resultado = cambioMonedas(monto, denominaciones);

    cout << "MONEDAS:" << endl;
    for (int i = 0; i < resultado.size(); i++) {
        cout << denominaciones[i] << " centimos: " << resultado[i] << endl;
    }

    return 0;
}