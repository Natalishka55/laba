#include <iostream>

int counter = 0;
int* findcolswithzero(double** matrix, int rows, int cols) {
    int* arr = (int*)calloc(rows * cols, sizeof(int));
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            if (matrix[j][i] == 0) {
                arr[counter] = i;
                ++counter;
                break;
            }
        }
    }
    return arr;
}
void printmatrix(double** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void part1() {
    double** matrix = (double**)malloc(2 * sizeof(double*));
    for (int i = 0; i < 2; ++i) {
        matrix[i] = (double*)malloc(2 * sizeof(double));
    }
    std::cout << "Введите 4 числа: " << std::endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            std::cin >> matrix[i][j];
        }
    }
    int A, B, C, D;    
    do {
        std::cout << "Введите A: ";
        std::cin >> A;
        if (A < 0) std::cout << "ОШИБКА" << std::endl;
    } while (A < 0);
    do {
        std::cout << "Введите B: ";
        std::cin >> B;
        if (B < 0) std::cout << "ОШИБКА" << std::endl;
    } while (B < 0);
    std::cout << "Введите C и D: ";
    std::cin >> C >> D;
    int newrows = 2 + A;
    int newcols = 2 + B;
    double** bigmatrix = (double**)calloc(newrows, sizeof(double*));
    for (int i = 0; i < newrows; ++i) {
        bigmatrix[i] = (double*)calloc(newcols, sizeof(double));
    }
    for (int i = 0; i < newrows; ++i) {
        for (int j = 0; j < newcols; ++j) {
            if (i < 2 && j < 2) {
                bigmatrix[i][j] = matrix[i][j];
            }
            else {
                bigmatrix[i][j] = (i - 1) * C + (j - 1) * D;
            }
        }
    }
    for (int i = 0; i < 2; ++i) {
        free(matrix[i]);
    }
    free(matrix);
    std::cout << "Расширенная матрица:" << std::endl;
    printmatrix(bigmatrix, newrows, newcols);   
    int zerocount;
    int* zerocolumns = findcolswithzero(bigmatrix, newrows, newcols);   
    int finalcols = newcols - counter;
    double** finalmatrix = (double**)calloc(newrows, sizeof(double*));
    for (int i = 0; i < newrows; ++i) {
        finalmatrix[i] = (double*)calloc(finalcols, sizeof(double));
    }
    for (int i = 0; i < newrows; ++i) {
        int newj = 0;
        for (int j = 0; j < newcols; ++j) {
            bool skip = false;
            for (int k = 0; k < counter; ++k) {
                if (j == zerocolumns[k]) {
                    skip = true;
                    break;
                }
            }
            if (!skip) {
                finalmatrix[i][newj] = bigmatrix[i][j];
                newj++;
            }
        }
    }
    std::cout << "Матрица после удаления столбиков с нулями:" << std::endl;
    printmatrix(finalmatrix, newrows, finalcols);
    free(zerocolumns);
    for (int i = 0; i < newrows; ++i) {
        free(bigmatrix[i]);
        free(finalmatrix[i]);
    }
    free(bigmatrix);
    free(finalmatrix);
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
