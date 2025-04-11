#include <iostream>
using namespace std;

class Matrix2x2 {
private:
    int matrix[2][2];

public:
    Matrix2x2(int a, int b, int c, int d) {
        matrix[0][0] = a;
        matrix[0][1] = b;
        matrix[1][0] = c;
        matrix[1][1] = d;
    }

    Matrix2x2 operator+(Matrix2x2 m) {
        return Matrix2x2(matrix[0][0] + m.matrix[0][0], matrix[0][1] + m.matrix[0][1],
                         matrix[1][0] + m.matrix[1][0], matrix[1][1] + m.matrix[1][1]);
    }

    Matrix2x2 operator-(Matrix2x2 m) {
        return Matrix2x2(matrix[0][0] - m.matrix[0][0], matrix[0][1] - m.matrix[0][1],
                         matrix[1][0] - m.matrix[1][0], matrix[1][1] - m.matrix[1][1]);
    }

    Matrix2x2 operator*(Matrix2x2 m) {
        int a = matrix[0][0]*m.matrix[0][0] + matrix[0][1]*m.matrix[1][0];
        int b = matrix[0][0]*m.matrix[0][1] + matrix[0][1]*m.matrix[1][1];
        int c = matrix[1][0]*m.matrix[0][0] + matrix[1][1]*m.matrix[1][0];
        int d = matrix[1][0]*m.matrix[0][1] + matrix[1][1]*m.matrix[1][1];
        return Matrix2x2(a, b, c, d);
    }

    friend int determinant(Matrix2x2 m);
    friend class MatrixHelper;

    friend ostream& operator<<(ostream& out, Matrix2x2 m) {
        out << m.matrix[0][0] << " " << m.matrix[0][1] << endl;
        out << m.matrix[1][0] << " " << m.matrix[1][1] << endl;
        return out;
    }
};

int determinant(Matrix2x2 m) {
    return (m.matrix[0][0] * m.matrix[1][1]) - (m.matrix[0][1] * m.matrix[1][0]);
}

class MatrixHelper {
public:
    void updateElement(Matrix2x2 &m, int row, int col, int value) {
        m.matrix[row][col] = value;
    }
};

int main() {
    Matrix2x2 m1(1, 2, 3, 4);
    Matrix2x2 m2(5, 6, 7, 8);

    cout << "Matrix 1:\n" << m1;
    cout << "Matrix 2:\n" << m2;

    Matrix2x2 sum = m1 + m2;
    cout << "\nSum:\n" << sum;

    Matrix2x2 product = m1 * m2;
    cout << "\nProduct:\n" << product;

    cout << "\nDeterminant of Matrix 1: " << determinant(m1) << endl;

    MatrixHelper helper;
    helper.updateElement(m1, 0, 0, 10);
    cout << "\nMatrix 1 after updating element:\n" << m1;

    return 0;
}
