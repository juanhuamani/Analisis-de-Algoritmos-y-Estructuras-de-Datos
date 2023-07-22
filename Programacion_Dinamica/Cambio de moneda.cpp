#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int Cambio_de_moneda(vector<int>& monedas, int cantidad) {
    int n = monedas.size();
    vector<int> dp(cantidad + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= cantidad; ++i) {
        for (int j = 0; j < n; ++j) {
            if (monedas[j] <= i) {
                dp[i] = min(dp[i], dp[i - monedas[j]] + 1);
            }
        }
    }

    return dp[cantidad] < INF ? dp[cantidad] : -1;
}

int main() {
    vector<int> monedas = {1, 5, 10, 25};
    int cantidad_cambio = 31;

    int min_monedas = Cambio_de_moneda(monedas, cantidad_cambio);
    cout << "\033[32mCantidad mínima de monedas : \033[0m" << min_monedas << endl;

    return 0;
}