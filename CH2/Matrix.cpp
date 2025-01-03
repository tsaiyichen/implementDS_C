#include <iostream>
#include <cmath>

using namespace std;

class Matrix{
    private:
        int* arr;
        string type;
        int row;
        int column;
    public:
        Matrix(int**, char, int, char);
        ~Matrix();
        void printMatrix();
};
Matrix::~Matrix() {
    cout << "destroy object";
}
Matrix::Matrix(int ** matrix, char method, int n, char type) {
}