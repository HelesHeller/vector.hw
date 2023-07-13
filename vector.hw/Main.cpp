#include <iostream>

template <typename T>
class Vector {
private:
    T* data;  // Вказівник на динамічний масив елементів
    size_t size;  // Розмір вектора

public:
    Vector(size_t initialSize = 0) : size(initialSize) {
        data = new T[size];
    }

    ~Vector() {
        delete[] data;
    }

    // Оператор доступу до елементів вектора за індексом
    T& operator[](size_t index) {
        return data[index];
    }

    // Оператор складання двох векторів
    Vector<T> operator+(const Vector<T>& other) const {
        if (size != other.size) {
            throw std::runtime_error("Vector dimensions mismatch");
        }

        Vector<T> result(size);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] = data[i] + other.data[i];
        }

        return result;
    }

    // Оператор віднімання двох векторів
    Vector<T> operator-(const Vector<T>& other) const {
        if (size != other.size) {
            throw std::runtime_error("Vector dimensions mismatch");
        }

        Vector<T> result(size);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] = data[i] - other.data[i];
        }

        return result;
    }

    // Оператор множення вектора на скалярне значення
    Vector<T> operator*(T scalar) const {
        Vector<T> result(size);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] = data[i] * scalar;
        }

        return result;
    }

    // Перевантажений оператор виведення вектора у стандартний потік
    friend std::ostream& operator<<(std::ostream& os, const Vector<T>& vector) {
        for (size_t i = 0; i < vector.size; ++i) {
            os << vector.data[i] << " ";
        }
        return os;
    }
};

int main() {
    Vector<int> v1(3);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;

    Vector<int> v2(3);
    v2[0] = 4;
    v2[1] = 5;
    v2[2] = 6;

    Vector<int> sum = v1 + v2;
    Vector<int> diff = v1 - v2;
    Vector<int> scaled = v1 * 2;

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << diff << std::endl;
    std::cout << "Scaled: " << scaled << std::endl;

    return 0;
}
