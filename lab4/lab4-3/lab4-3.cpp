#include <iostream>
#include <vector>

using namespace std;

class VectorUInt {
private:
    vector<unsigned int> data;

public:
    // ������������
    VectorUInt() {}

    VectorUInt(int size, unsigned int initValue = 0) : data(size, initValue) {}

    // �������� ���������� []
    unsigned int& operator[](int index) {
        if (index < 0 || index >= data.size()) {
            cerr << "Error: Index out of bounds." << endl;
            exit(1); // ��� ������� ������� ����� �����
        }
        return data[index];
    }

    // ����� ������� ��� �������� �� ���������
    friend istream& operator>>(istream& is, VectorUInt& vector);
    friend ostream& operator<<(ostream& os, const VectorUInt& vector);
};

// ��������� ������ �������
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
    // ������������
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

    // ����������� ���������
    MatrixUInt(const MatrixUInt& other) : n(other.n), size(other.size), codeError(other.codeError) {
        UIntArray = new VectorUInt[n];
        for (int i = 0; i < n; ++i) {
            UIntArray[i] = other.UIntArray[i];
        }
        num_matrix++;
    }

    // ����������
    ~MatrixUInt() {
        delete[] UIntArray;
        num_matrix--;
    }

    // ������� ������� �� ����
    int getN() const { return n; }
    int getSize() const { return size; }
    int getCodeError() const { return codeError; }

    // �������� ���������
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

    // ����� �������� �� ��������� ++ �� --
    MatrixUInt& operator++();    // ���������� ++
    MatrixUInt operator++(int); // ����������� ++

    MatrixUInt& operator--();    // ���������� --
    MatrixUInt operator--(int); // ����������� --

    // ����� ����� �� ������ ��������
    bool operator!();  // ������ �����������
    MatrixUInt operator~(); // ������� �����������

    // ������� ������������ -
    MatrixUInt operator-();

    // ��������� =
    MatrixUInt& operator=(const MatrixUInt& other);

    // ���������� ����� ��������
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

    // ������ ����� ��������
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

    // ��������� ������ �� ��������
    bool operator==(const MatrixUInt& other);
    bool operator!=(const MatrixUInt& other);

    // ���������
    bool operator>(const MatrixUInt& other);
    bool operator>=(const MatrixUInt& other);
    bool operator<(const MatrixUInt& other);
    bool operator<=(const MatrixUInt& other);

    // �������� ���������� []
    VectorUInt& operator[](int index);

    // ������� ���'�� new �� delete
    void* operator new(size_t size);
    void operator delete(void* ptr);

    // ������ ������� ()
    void operator()();

    // ������ �������� �����
    friend MatrixUInt operator>>(const MatrixUInt& matrix, int shift);
    friend MatrixUInt operator<<(const MatrixUInt& matrix, int shift);

    // ����� ������� ��� �������� �� ���������
    friend istream& operator>>(istream& is, MatrixUInt& matrix);
    friend ostream& operator<<(ostream& os, const MatrixUInt& matrix);

    // ������ �������� �����, �� ����� �������� �������� �� ��������� ������� � ����
    friend istream& operator>>(istream& is, VectorUInt& vector);
    friend ostream& operator<<(ostream& os, const VectorUInt& vector);
};

int MatrixUInt::num_matrix = 0;

// ��������� ������� ����� MatrixUInt

int main() {
    // ����� ��� ����� MatrixUInt
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
