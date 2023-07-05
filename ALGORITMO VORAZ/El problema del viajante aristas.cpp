#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Ciudad {
    int x;
    int y;
};

struct Arista {
    int ciudad1;
    int ciudad2;
    double distancia;
};

bool compararAristas(const Arista& arista1, const Arista& arista2) {
    return arista1.distancia < arista2.distancia;
}

double distanciaEntreCiudades(const Ciudad& c1, const Ciudad& c2) {
    int dx = c1.x - c2.x;
    int dy = c1.y - c2.y;
    return sqrt(dx*dx + dy*dy);
}

vector<int> viajanteHeuristicaAristas(const vector<Ciudad>& ciudades) {
    int n = ciudades.size();
    vector<int> ruta;
    ruta.reserve(n);
    
    vector<Arista> aristas;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double distancia = distanciaEntreCiudades(ciudades[i], ciudades[j]);
            aristas.push_back({i, j, distancia});
        }
    }
    
    sort(aristas.begin(), aristas.end(), compararAristas);
    
    vector<int> conjuntoCiudades(n);
    for (int i = 0; i < n; i++) {
        conjuntoCiudades[i] = i;
    }
    
    for (const Arista& arista : aristas) {
        int ciudad1 = arista.ciudad1;
        int ciudad2 = arista.ciudad2;
        
        if (conjuntoCiudades[ciudad1] != conjuntoCiudades[ciudad2]) {
            ruta.push_back(ciudad1);
            ruta.push_back(ciudad2);
            
            int conjuntoAnterior = conjuntoCiudades[ciudad2];
            int nuevoConjunto = conjuntoCiudades[ciudad1];
            
            for (int i = 0; i < n; i++) {
                if (conjuntoCiudades[i] == conjuntoAnterior) {
                    conjuntoCiudades[i] = nuevoConjunto;
                }
            }
        }
    }
    
    ruta.push_back(ruta[0]); // Cerrar el ciclo
    
    return ruta;
}

int main() {
    // Ejemplo de uso
    vector<Ciudad> ciudades = {{0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}};
    vector<int> ruta = viajanteHeuristicaAristas(ciudades);
    
    cout << "Ruta: ";
    for (int ciudad : ruta) {
        cout << ciudad << " ";
    }
    cout << endl;
    
    return 0;
}