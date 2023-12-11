#include <iostream>
#include <vector>

using namespace std;

class VectorUInt {
private:
    vector<unsigned int> data;

public:
    // Конструктори
    VectorUInt() {}

    VectorUInt(int size, unsigned int initValue = 0) : data(size, initValue) {}

    // Оператор індексації []
    unsigned int& operator[](int index) {
        if (index < 0 || index >= data.size()) {
            cerr << "Error: Index out of bounds." << endl;
            exit(1); // або обробка помилки іншим чином
        }
        return data[index];
    }

    // Дружні функції для введення та виведення
    friend istream& operator>>(istream& is, VectorUInt& vector);
    friend ostream& operator<<(ostream& os, const VectorUInt& vector);
};

// Реалізації дружніх функцій
istream& operator>>(istream& is, VectorUInt& vector) {
    for (unsigned int& value : vector.data) {
        is >> value;
    }
    return is;
}

ostream& operator<<(ostream& os, const VectorUInt& vector) {
    for (const unsigned int& value : vector.data) {
        os << value << " ";
    }
    os << endl;
    return os;
}

class MatrixUInt {
private:
    VectorUInt* UIntArray;
    int n, size;
    int codeError;
    static int num_matrix;

public:
    // Конструктори
    MatrixUInt() : UIntArray(nullptr), n(0), size(0), codeError(0) { num_matrix++; }
    MatrixUInt(int newSize) : n(newSize), size(newSize), codeError(0) {
        UIntArray = new VectorUInt[n];
        num_matrix++;
    }
    MatrixUInt(int rows, int cols, int initValue = 0) : n(rows), size(cols), codeError(0) {
        UIntArray = new VectorUInt[n];
        for (int i = 0; i < n; ++i) {
            UIntArray[i] = VectorUInt(cols, initValue);
        }
        num_matrix++;
    }

    // Конструктор копіювання
    MatrixUInt(const MatrixUInt& other) : n(other.n), size(other.size), codeError(other.codeError) {
        UIntArray = new VectorUInt[n];
        for (int i = 0; i < n; ++i) {
            UIntArray[i] = other.UIntArray[i];
        }
        num_matrix++;
    }

    // Деструктор
    ~MatrixUInt() {
        delete[] UIntArray;
        num_matrix--;
    }

    // Функції доступу до полів
    int getN() const { return n; }
    int getSize() const { return size; }
    int getCodeError() const { return codeError; }

    // Оператор копіювання
    MatrixUInt& operator=(const MatrixUInt& other) {
        if (this != &other) {
            delete[] UIntArray;
            n = other.n;
            size = other.size;
            codeError = other.codeError;
            UIntArray = new VectorUInt[n];
            for (int i = 0; i < n; ++i) {
                UIntArray[i] = other.UIntArray[i];
            }
        }
        return *this;
    }

    // Унарні префіксні та постфіксні ++ та --
    MatrixUInt& operator++();    // Префіксний ++
    MatrixUInt operator++(int); // Постфіксний ++

    MatrixUInt& operator--();    // Префіксний --
    MatrixUInt operator--(int); // Постфіксний --

    // Унарні логічні та побітові операції
    bool operator!();  // Логічне заперечення
    MatrixUInt operator~(); // Побітове заперечення

    // Унарний арифметичний -
    MatrixUInt operator-();

    // Присвоєння =
    MatrixUInt& operator=(const MatrixUInt& other);

    // Арифметичні бінарні операції
    MatrixUInt operator+(const MatrixUInt& other);
    MatrixUInt operator+(unsigned int scalar);

    MatrixUInt operator-(const MatrixUInt& other);
    MatrixUInt operator-(unsigned int scalar);

    MatrixUInt operator*(const MatrixUInt& other);
    MatrixUInt operator*(const VectorUInt& vector);
    MatrixUInt operator*(unsigned int scalar);

    MatrixUInt operator/(unsigned int scalar);
    MatrixUInt operator%(unsigned int scalar);

    MatrixUInt& operator+=(const MatrixUInt& other);
    MatrixUInt& operator+=(unsigned int scalar);

    MatrixUInt& operator-=(const MatrixUInt& other);
    MatrixUInt& operator-=(unsigned int scalar);

    MatrixUInt& operator*=(const MatrixUInt& other);
    MatrixUInt& operator*=(const VectorUInt& vector);
    MatrixUInt& operator*=(unsigned int scalar);

    MatrixUInt& operator/=(unsigned int scalar);
    MatrixUInt& operator%=(unsigned int scalar);

    // Побітові бінарні операції
    MatrixUInt operator|(const MatrixUInt& other);
    MatrixUInt operator|(unsigned int scalar);

    MatrixUInt operator^(const MatrixUInt& other);

    MatrixUInt operator&(const VectorUInt& vector);
    MatrixUInt operator&(unsigned int scalar);

    MatrixUInt operator>>(int shift);
    MatrixUInt operator<<(int shift);

    MatrixUInt& operator|=(const MatrixUInt& other);
    MatrixUInt& operator|=(unsigned int scalar);

    MatrixUInt& operator^=(const MatrixUInt& other);

    MatrixUInt& operator&=(const VectorUInt& vector);
    MatrixUInt& operator&=(unsigned int scalar);

    MatrixUInt& operator>>=(int shift);
    MatrixUInt& operator<<=(int shift);

    // Оператори рівності та нерівності
    bool operator==(const MatrixUInt& other);
    bool operator!=(const MatrixUInt& other);

    // Порівняння
    bool operator>(const MatrixUInt& other);
    bool operator>=(const MatrixUInt& other);
    bool operator<(const MatrixUInt& other);
    bool operator<=(const MatrixUInt& other);

    // Оператор індексації []
    VectorUInt& operator[](int index);

    // Розподіл пам'яті new та delete
    void* operator new(size_t size);
    void operator delete(void* ptr);

    // Виклик функції ()
    void operator()();

    // Побітові операції зсувів
    friend MatrixUInt operator>>(const MatrixUInt& matrix, int shift);
    friend MatrixUInt operator<<(const MatrixUInt& matrix, int shift);

    // Дружні функції для введення та виведення
    friend istream& operator>>(istream& is, MatrixUInt& matrix);
    friend ostream& operator<<(ostream& os, const MatrixUInt& matrix);

    // Побітові операції зсувів, як дружні операції введення та виведення вектора у потік
    friend istream& operator>>(istream& is, VectorUInt& vector);
    friend ostream& operator<<(ostream& os, const VectorUInt& vector);
};

int MatrixUInt::num_matrix = 0;

// Реалізації функцій класу MatrixUInt

int main() {
    // Тести для класу MatrixUInt
    MatrixUInt matrix1(3, 3, 1);
    MatrixUInt matrix2(3, 3, 2);

    cout << "Matrix1:\n" << matrix1 << endl;
    cout << "Matrix2:\n" << matrix2 << endl;

    MatrixUInt matrix3 = matrix1 + matrix2;
    cout << "Matrix1 + Matrix2:\n" << matrix3 << endl;

    MatrixUInt matrix4 = matrix1 * matrix2;
    cout << "Matrix1 * Matrix2:\n" << matrix4 << endl;

    matrix1 += 2;
    cout << "Matrix1 += 2:\n" << matrix1 << endl;

    matrix2 *= matrix1;
    cout << "Matrix2 *= Matrix1:\n" << matrix2 << endl;

    return 0;
}
