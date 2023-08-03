#include <iostream>
#include <vector>
using namespace std;

int minCoins(vector<int>& coins, int N) {
    int n = coins.size();
    vector<int> dp(N + 1, INT_MAX);

    // El valor 0 se puede representar con 0 monedas
    dp[0] = 0;

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < n; ++j) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    return dp[N];
}

int main() {
    int N;
    cout << "Ingrese el valor N: ";
    cin >> N;

    int numCoins;
    cout << "Ingrese el número de monedas disponibles: ";
    cin >> numCoins;

    vector<int> coins(numCoins);
    cout << "Ingrese las denominaciones de las monedas:\n";
    for (int i = 0; i < numCoins; ++i) {
        cin >> coins[i];
    }

    int minNumCoins = minCoins(coins, N);
    cout << "El número mínimo de monedas necesarias para representar el valor N es: " << minNumCoins << endl;

    return 0;
}
