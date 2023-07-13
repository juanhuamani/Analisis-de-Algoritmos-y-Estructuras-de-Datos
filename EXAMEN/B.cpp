#include <cstdio>
#include <cmath>
#include <algorithm>
#include <limits>
using namespace std;

struct Point {
    int x, y;
};

bool compareX(const Point& a, const Point& b) {
    return a.x < b.x;
}

bool compareY(const Point& a, const Point& b) {
    return a.y < b.y;
}

double dist(const Point& a, const Point& b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

double distanciaParesCercanos(Point* puntos, int n) {
    if (n <= 1)
        return numeric_limits<double>::infinity();

    sort(puntos, puntos + n, compareX);

    if (n == 2)
        return dist(puntos[0], puntos[1]);

    int medio = n / 2;
    int medioX = puntos[medio].x;

    double dl = distanciaParesCercanos(puntos, medio);
    double dr = distanciaParesCercanos(puntos + medio, n - medio);

    double d = min(dl, dr);

    Point tira[n];
    int tamTira = 0;

    for (int i = 0; i < n; i++) {
        if (abs(puntos[i].x - medioX) < d) {
            tira[tamTira] = puntos[i];
            tamTira++;
        }
    }

    sort(tira, tira + tamTira, compareY);

    for (int i = 0; i < tamTira; i++) {
        for (int j = i + 1; j < tamTira && (tira[j].y - tira[i].y) < d; j++) {
            double distanciaActual = dist(tira[i], tira[j]);
            d = min(d, distanciaActual);
        }
    }

    return d;
}

int main() {
    int N;
    while (scanf("%d", &N) && N > 0) {
        Point puntos[N];
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &puntos[i].x, &puntos[i].y);
        }

        double distanciaMasCercana = distanciaParesCercanos(puntos, N);

        if (distanciaMasCercana < 10000)
            printf("%.4lf\n", distanciaMasCercana);
        else
            printf("INFINITO\n");
    }

    return 0;
}