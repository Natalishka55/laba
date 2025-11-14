//help :(
#include <iostream>
int counter = 0;
int* findcolswithzero(int** matrix, int rows, int cols) {
    int* arr = (int*)calloc(cols, sizeof(int));
    counter = 0;
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            if (matrix[j][i] == 0) {
                arr[counter] = i;
                ++counter;
                break;
            }
        }
    }
    if (counter > 0) {
        arr = (int*)realloc(arr, counter * sizeof(int));
    }
    else {
        free(arr);
        arr = NULL
    }
    return arr;
}
void printmatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void part1() {
    int** matrix = (int**)malloc(2 * sizeof(int*));
    for (int i = 0; i < 2; ++i) {
        matrix[i] = (int*)malloc(2 * sizeof(int));
    }
    std::cout << "введите матрицу: " << std::endl;
    std::cout << "введите A: ";
    std::cin >> matrix[0][0];
    std::cout << "введите B: ";
    std::cin >> matrix[0][1];
    std::cout << "введите C: ";
    std::cin >> matrix[1][0];
    std::cout << "введите D: ";
    std::cin >> matrix[1][1];
    if (matrix[0][0] < 0 || matrix[0][1] < 0) {
        std::cout << "ОШИБКА!" << std::endl;
        for (int i = 0; i < 2; ++i) {
            free(matrix[i]);
        }
        free(matrix);
        return;
    }
    int A = matrix[0][0];
    int B = matrix[0][1];
    int C = matrix[1][0];
    int D = matrix[1][1];
    std::cout << "Исходная матрица:" << std::endl;
    printmatrix(matrix, 2, 2);
    int newrows = 2 + A;
    int newcols = 2 + B;
    matrix = (int**)realloc(matrix, newrows * sizeof(int*));
    for (int i = 0; i < 2; ++i) {
        matrix[i] = (int*)realloc(matrix[i], newcols * sizeof(int));
    }
    for (int i = 2; i < newrows; ++i) {
        matrix[i] = (int*)malloc(newcols * sizeof(int));
    }
    for (int i = 0; i < newrows; ++i) {
        for (int j = 0; j < newcols; ++j) {
            if (i >= 2 || j >= 2) {
                matrix[i][j] = (i - 1) * C + (j - 1) * D;
            }
        }
    }
    std::cout << "преобразованная матрица:" << std::endl;
    printmatrix(matrix, newrows, newcols);
    int* zerocolumns = findcolswithzero(matrix, newrows, newcols);
    if (counter > 0) {
        std::cout << "Матрица после удаления столбиков с нулями:" << std::endl;
        for (int i = 0; i < newrows; ++i) {
            for (int j = 0; j < newcols; ++j) {
                bool skip = false;
                for (int k = 0; k < counter; ++k) {
                    if (j == zerocolumns[k]) {
                        skip = true;
                        break;
                    }
                }
                if (!skip) {
                    std::cout << matrix[i][j] << " ";
                }
            }
            std::cout << std::endl;
        }
    }
    else {
        std::cout << "Нет столбиков с нулями:" << std::endl;
        printmatrix(matrix, newrows, newcols);
    }
    if (zerocolumns != NULL) {
        free(zerocolumns);
    }
    for (int i = 0; i < newrows; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

void part2() {
    double a, b;
    std::cout << "введите числа a и b: ";
    std::cin >> a >> b;
    double* ptrA = new double;
    double* ptrB = new double;
    *ptrA = a;
    *ptrB = b;
    std::cout << "исходные значения: a = " << a << ", b = " << b << std::endl;
    *ptrA = *ptrA * 3;
    std::cout << "После увеличения a в 3 раза: a = " << *ptrA << ", b = " << *ptrB << std::endl;
    double temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;
    std::cout << "После обмена значений a и b: a = " << *ptrA << ", b = " << *ptrB << std::endl;
    delete ptrA;
    delete ptrB;
}
int main() {
    setlocale(LC_ALL, "RU");
    part1();
    part2();
    return 0;
}
