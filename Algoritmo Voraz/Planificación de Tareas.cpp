#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Tarea {
    int inicio;
    int fin;
};

bool compararPorFin(const Tarea& tarea1, const Tarea& tarea2) {
    return tarea1.fin < tarea2.fin;
}

vector<int> planificacionTareas(const vector<Tarea>& tareas) {
    vector<Tarea> tareasOrdenadas(tareas);
    sort(tareasOrdenadas.begin(), tareasOrdenadas.end(), compararPorFin);

    vector<int> seleccionadas;
    seleccionadas.push_back(0);
    int ultimaSeleccionada = 0;

    for (int i = 1; i < tareasOrdenadas.size(); i++) {
        if (tareasOrdenadas[i].inicio >= tareasOrdenadas[ultimaSeleccionada].fin) {
            seleccionadas.push_back(i);
            ultimaSeleccionada = i;
        }
    }

    return seleccionadas;
}

int main() {
    vector<Tarea> tareas = {{1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9}, {6, 10}, {8, 11}};

    vector<int> tareasSeleccionadas = planificacionTareas(tareas);

    cout << "Tareas seleccionadas:" << endl;
    for (int indice : tareasSeleccionadas) {
        cout << "Inicio: " << tareas[indice].inicio << ", Fin: " << tareas[indice].fin << endl;
    }

    return 0;
}