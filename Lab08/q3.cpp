#include <iostream>
using namespace std;

class Vector2D {
private:
    float x, y;
public:
    Vector2D(float x = 0, float y = 0) {
        this->x = x;
        this->y = y;
    }

   
    Vector2D operator+(const Vector2D& v) {
        return Vector2D(x + v.x, y + v.y);
    }

    Vector2D operator-(const Vector2D& v) {
        return Vector2D(x - v.x, y - v.y);
    }

    Vector2D operator*(float scalar) {
        return Vector2D(x * scalar, y * scalar);
    }

    friend float dotProduct(Vector2D v1, Vector2D v2);
    friend ostream& operator<<(ostream& out, const Vector2D& v);
};

float dotProduct(Vector2D v1, Vector2D v2) {
    return (v1.x * v2.x + v1.y * v2.y);
}

ostream& operator<<(ostream& out, const Vector2D& v) {
    out << "(" << v.x << ", " << v.y << ")";
    return out;
}

int main() {
    Vector2D v1(3, 4), v2(1, 2);

    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;

    cout << "Addition: " << v1 + v2 << endl;
    cout << "Subtraction: " << v1 - v2 << endl;
    cout << "Dot Product: " << dotProduct(v1, v2) << endl;

    Vector2D v3 = v1 * 2;
    cout << "Scalar Multiplication: " << v3 << endl;

    return 0;
}
