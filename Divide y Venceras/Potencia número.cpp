#include <iostream>

using namespace std;

double potencia(double x, int n) {
    if (n == 0) {
        return 1;
    }

    double temp = potencia(x, n / 2);
    double resultado = temp * temp;

    if (n % 2 == 0) {
        return resultado;
    } else {
        return x * resultado;
    }
}

int main() {
    double x = 4.6;
    int n = 4;

    double resultado = potencia(x, n);

    cout << x << "^" << n << " = " << resultado << endl;

    return 0;
}