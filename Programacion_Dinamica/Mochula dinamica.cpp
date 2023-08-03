#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, const vector<int>& weights, const vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= W; ++j) {
            if (weights[i - 1] <= j) {
                dp[i][j] = max(values[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n, W;
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

    cout << "Ingrese la capacidad máxima de la mochila: ";
    cin >> W;

    int maxValue = knapsack(W, weights, values, n);
    cout << "El valor máximo que se puede obtener es: " << maxValue << endl;

    return 0;
}
