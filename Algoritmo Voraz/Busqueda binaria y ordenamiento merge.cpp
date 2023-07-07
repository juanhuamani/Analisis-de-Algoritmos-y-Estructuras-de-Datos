#include <iostream>
#include <vector>

using namespace std;

void mergeSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        vector<int> temp(high - low + 1);
        int i = low, j = mid + 1, k = 0;
        
        while (i <= mid && j <= high) {
            if (arr[i] <= arr[j]) {
                temp[k] = arr[i];
                i++;
            } else {
                temp[k] = arr[j];
                j++;
            }
            k++;
        }
        
        while (i <= mid) {
            temp[k] = arr[i];
            i++;
            k++;
        }
        
        while (j <= high) {
            temp[k] = arr[j];
            j++;
            k++;
        }
        
        for (int x = 0; x < temp.size(); x++) {
            arr[low + x] = temp[x];
        }
    }
}


void sortMatrix(vector<vector<int>>& matrix, int rowLow, int rowHigh, int colLow, int colHigh) {
    for (int i = rowLow; i <= rowHigh; i++) {
        mergeSort(matrix[i], colLow, colHigh);
    }
    for (int j = colLow; j <= colHigh; j++) {
        vector<int> column;
        for (int i = rowLow; i <= rowHigh; i++) {
            column.push_back(matrix[i][j]);
        }
        mergeSort(column, 0, rowHigh - rowLow);
        for (int i = rowLow; i <= rowHigh; i++) {
            matrix[i][j] = column[i - rowLow];
        }
    }
}

bool binarySearch(const vector<vector<int>>& matrix, int target, int rowLow, int rowHigh, int colLow, int colHigh) {
    if (rowLow > rowHigh || colLow > colHigh) {
        return false;
    }
    
    int rowMid = rowLow + (rowHigh - rowLow) / 2;
    int colMid = colLow + (colHigh - colLow) / 2;
    
    if (matrix[rowMid][colMid] == target) {
        return true;
    } else if (matrix[rowMid][colMid] > target) {
        return binarySearch(matrix, target, rowLow, rowMid - 1, colLow, colHigh) ||
               binarySearch(matrix, target, rowLow, rowHigh, colLow, colMid - 1);
    } else {
        return binarySearch(matrix, target, rowMid + 1, rowHigh, colLow, colHigh) ||
               binarySearch(matrix, target, rowLow, rowHigh, colMid + 1, colHigh);
    }
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows, cols;
    cout << "Ingrese el número de filas de la matriz: ";
    cin >> rows;
    cout << "Ingrese el número de columnas de la matriz: ";
    cin >> cols;
    
    vector<vector<int>> matrix(rows, vector<int>(cols));
    
    cout << "Ingrese los elementos de la matriz:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    
    cout << "Matriz original:" << endl;
    printMatrix(matrix);

    sortMatrix(matrix, 0, rows - 1, 0, cols - 1);
    
    cout << "Matriz ordenada:" << endl;
    printMatrix(matrix);
    
    int target;
    cout << "Ingrese el elemento que desea buscar: ";
    cin >> target;
    
    bool found = binarySearch(matrix, target, 0, rows - 1, 0, cols - 1);
    if (found) {
        cout << "El elemento " << target << " está presente en la matriz." << endl;
    } else {
        cout << "El elemento " << target << " no está presente en la matriz." << endl;
    }
    
    return 0;
}
