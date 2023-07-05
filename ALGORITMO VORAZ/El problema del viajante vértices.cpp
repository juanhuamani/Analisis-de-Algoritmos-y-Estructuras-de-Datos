#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Ciudad {
    int x;
    int y;
};

double distanciaEntreCiudades(const Ciudad& c1, const Ciudad& c2) {
    int dx = c1.x - c2.x;
    int dy = c1.y - c2.y;
    return sqrt(dx*dx + dy*dy);
}

vector<int> viajanteHeuristicaVertices(const vector<Ciudad>& ciudades) {
    int n = ciudades.size();
    vector<int> ruta;
    ruta.reserve(n);
    
    vector<bool> visitado(n, false);
    ruta.push_back(0);
    visitado[0] = true;
    
    for (int i = 1; i < n; i++) {
        int ciudadActual = ruta.back();
        int siguienteCiudad = -1;
        double distanciaMinima = numeric_limits<double>::max();
        
        for (int j = 0; j < n; j++) {
            if (!visitado[j]) {
                double distancia = distanciaEntreCiudades(ciudades[ciudadActual], ciudades[j]);
                if (distancia < distanciaMinima) {
                    distanciaMinima = distancia;
                    siguienteCiudad = j;
                }
            }
        }
        
        ruta.push_back(siguienteCiudad);
        visitado[siguienteCiudad] = true;
    }
    
    return ruta;
}

int main() {
    vector<Ciudad> ciudades = {{0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}};
    vector<int> ruta = viajanteHeuristicaVertices(ciudades);
    
    cout << "Ruta: ";
    for (int ciudad : ruta) {
        cout << ciudad << " ";
    }
    cout << endl;
    
    return 0;
}