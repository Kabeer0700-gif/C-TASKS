#include <iostream>
#include <stdexcept>
#include <cstring>

using namespace std;


class MatrixDimensionException : public exception {
protected:
    char* message;

public:
    MatrixDimensionException(const char* msg) {
        message = new char[strlen(msg) + 1];
        strcpy(message, msg);
    }

    const char* what() const noexcept override {
        return message;
    }

    ~MatrixDimensionException() {
        delete[] message;
    }
};


template <typename T>
class Matrix {
private:
    int rows, columns;
    T** matrix;

public:
  
    Matrix() : rows(0), columns(0), matrix(nullptr) {}

  
    Matrix(int r, int c) : rows(r), columns(c) {
        matrix = new T*[rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new T[columns];
        }
    }

    Matrix(const Matrix& other) : rows(other.rows), columns(other.columns) {
        matrix = new T*[rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new T[columns];
            for (int j = 0; j < columns; ++j) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }


    Matrix operator+(const Matrix& m) {
        if (rows != m.rows || columns != m.columns) {
            throw MatrixDimensionException("Matrix dimension mismatch for addition.");
        }

        Matrix temp(rows, columns);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                temp.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
            }
        }
        return temp;
    }


    void seeMatrix() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

 
    void set(int i, int j, T value) {
        matrix[i][j] = value;
    }

    // Destructor
    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
};


int main() {
    Matrix<int> m1(2, 2);
    Matrix<int> m2(2, 2);

    m1.set(0, 0, 1);
    m1.set(0, 1, 2);
    m1.set(1, 0, 3);
    m1.set(1, 1, 4);

    m2.set(0, 0, 5);
    m2.set(0, 1, 6);
    m2.set(1, 0, 7);
    m2.set(1, 1, 8);

    cout << "Matrix 1:\n";
    m1.seeMatrix();

    cout << "\nMatrix 2:\n";
    m2.seeMatrix();

    try {
        Matrix<int> m3 = m1 + m2;
        cout << "\nMatrix 1 + Matrix 2:\n";
        m3.seeMatrix();
    } catch (const MatrixDimensionException& ex) {
        cout << "Exception: " << ex.what() << endl;
    }

    return 0;
}
