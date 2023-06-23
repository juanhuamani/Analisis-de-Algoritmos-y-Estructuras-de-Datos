#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> sumaMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> resultado(n, vector<int>(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            resultado[i][j] = A[i][j] + B[i][j];
        }
    }
    
    return resultado;
}

vector<vector<int>> restaMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> resultado(n, vector<int>(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            resultado[i][j] = A[i][j] - B[i][j];
        }
    }
    
    return resultado;
}

vector<vector<int>> multiplicacionMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    
    if (n == 1) {
        vector<vector<int>> C(1, vector<int>(1));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }
    
    vector<vector<int>> C(n, vector<int>(n));
    
    int k = n / 2;
    
    vector<vector<int>> A11(k, vector<int>(k));
    vector<vector<int>> A12(k, vector<int>(k));
    vector<vector<int>> A21(k, vector<int>(k));
    vector<vector<int>> A22(k, vector<int>(k));
    
    vector<vector<int>> B11(k, vector<int>(k));
    vector<vector<int>> B12(k, vector<int>(k));
    vector<vector<int>> B21(k, vector<int>(k));
    vector<vector<int>> B22(k, vector<int>(k));
    
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];
            
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }
    
    vector<vector<int>> P1 = multiplicacionMatrices(A11, restaMatrices(B12, B22));
    vector<vector<int>> P2 = multiplicacionMatrices(sumaMatrices(A11, A12), B22);
    vector<vector<int>> P3 = multiplicacionMatrices(sumaMatrices(A21, A22), B11);
    vector<vector<int>> P4 = multiplicacionMatrices(A22, restaMatrices(B21, B11));
    vector<vector<int>> P5 = multiplicacionMatrices(sumaMatrices(A11, A22), sumaMatrices(B11, B22));
    vector<vector<int>> P6 = multiplicacionMatrices(restaMatrices(A12, A22), sumaMatrices(B21, B22));
    vector<vector<int>> P7 = multiplicacionMatrices(restaMatrices(A11, A21), sumaMatrices(B11, B12));
    
    vector<vector<int>> C11 = sumaMatrices(restaMatrices(sumaMatrices(P5, P4), P2), P6);
    vector<vector<int>> C12 = sumaMatrices(P1, P2);
    vector<vector<int>> C21 = sumaMatrices(P3, P4);
    vector<vector<int>> C22 = restaMatrices(restaMatrices(sumaMatrices(P5, P1), P3), P7);
    
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }
    
    return C;
}

void imprimirMatriz(const vector<vector<int>>& matriz) {
    for (const auto& fila : matriz) {
        for (int elemento : fila) {
            cout<<"\t"<< elemento << " ";
        }
        cout << endl;
    }
}



int main() {
    vector<vector<int>> A = {{3, 2}, {2, 5}};
    vector<vector<int>> B = {{4, 8}, {7, 7}};
    
    vector<vector<int>> resultado = multiplicacionMatrices(A, B);
    
    cout<<"\tMATRIZ A "<<endl;
    imprimirMatriz(A);
    cout<<"\n\n\tMATRIZ B "<<endl;
    imprimirMatriz(B);
    cout<<"\n\n\tMULTIPLICACION : A X B "<<endl;
    imprimirMatriz(resultado);
    
    return 0;
}