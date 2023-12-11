#include <iostream>
#include <iomanip>
#pragma warning(disable : 4146)

using namespace std;

class VectorUInt {
private:
    unsigned int* data;
    size_t size;
    int codeError;

public:
    // ������������
    VectorUInt() {
        size = 1;
        data = new unsigned int[size]();
        codeError = 0;
    }

    VectorUInt(size_t newSize) {
        size = newSize;
        data = new unsigned int[size]();
        codeError = 0;
    }

    VectorUInt(size_t newSize, unsigned int initValue) {
        size = newSize;
        data = new unsigned int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = initValue;
        }
        codeError = 0;
    }

    VectorUInt(const VectorUInt& other) {
        size = other.size;
        data = new unsigned int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
        codeError = other.codeError;
    }

    // ����������
    ~VectorUInt() {
        delete[] data;
    }

    // �������� ���������
    VectorUInt& operator=(const VectorUInt& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new unsigned int[size];
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
            codeError = other.codeError;
        }
        return *this;
    }

    // ��������� ������� ���������� �� ����������� ++ �� --
    VectorUInt& operator++() {
        for (size_t i = 0; i < size; ++i) {
            ++data[i];
        }
        return *this;
    }

    VectorUInt operator++(int) {
        VectorUInt temp(*this);
        ++(*this);
        return temp;
    }

    VectorUInt& operator--() {
        for (size_t i = 0; i < size; ++i) {
            --data[i];
        }
        return *this;
    }

    VectorUInt operator--(int) {
        VectorUInt temp(*this);
        --(*this);
        return temp;
    }

    // ��������� ��� ������� �� �������� ��������
    bool operator!() const {
        for (size_t i = 0; i < size; ++i) {
            if (data[i] != 0) {
                return false;
            }
        }
        return true;
    }

    VectorUInt operator~() const {
        VectorUInt result(*this);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] = ~result.data[i];
        }
        return result;
    }

    VectorUInt operator-() const {
        VectorUInt result(*this);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] = static_cast<unsigned int>(-result.data[i]);
        }
        return result;
    }


    // ��������� ���������
    VectorUInt& operator+=(const VectorUInt& other) {
        for (size_t i = 0; i < size; ++i) {
            data[i] += other.data[i];
        }
        return *this;
    }

    VectorUInt& operator-=(const VectorUInt& other) {
        for (size_t i = 0; i < size; ++i) {
            data[i] -= other.data[i];
        }
        return *this;
    }

    VectorUInt& operator*=(unsigned int scalar) {
        for (size_t i = 0; i < size; ++i) {
            data[i] *= scalar;
        }
        return *this;
    }

    VectorUInt& operator/=(unsigned int scalar) {
        if (scalar != 0) {
            for (size_t i = 0; i < size; ++i) {
                data[i] /= scalar;
            }
        }
        else {
            codeError = 2;  // ��� ������� - ������ �� ����
        }
        return *this;
    }

    VectorUInt& operator%=(unsigned int scalar) {
        if (scalar != 0) {
            for (size_t i = 0; i < size; ++i) {
                data[i] %= scalar;
            }
        }
        else {
            codeError = 2;  // ��� ������� - ������ �� ����
        }
        return *this;
    }

    VectorUInt& operator|=(const VectorUInt& other) {
        for (size_t i = 0; i < size; ++i) {
            data[i] |= other.data[i];
        }
        return *this;
    }

    VectorUInt& operator^=(const VectorUInt& other) {
        for (size_t i = 0; i < size; ++i) {
            data[i] ^= other.data[i];
        }
        return *this;
    }

    VectorUInt& operator&=(const VectorUInt& other) {
        for (size_t i = 0; i < size; ++i) {
            data[i] &= other.data[i];
        }
        return *this;
    }

    // ��������� ������������ ������� ��������
    VectorUInt operator+(const VectorUInt& other) const {
        VectorUInt result(*this);
        result += other;
        return result;
    }

    VectorUInt operator-(const VectorUInt& other) const {
        VectorUInt result(*this);
        result -= other;
        return result;
    }

    VectorUInt operator*(unsigned int scalar) const {
        VectorUInt result(*this);
        result *= scalar;
        return result;
    }

    VectorUInt operator/(unsigned int scalar) const {
        VectorUInt result(*this);
        result /= scalar;
        return result;
    }

    VectorUInt operator%(unsigned int scalar) const {
        VectorUInt result(*this);
        result %= scalar;
        return result;
    }

    // ��������� �������� ������� ��������
    VectorUInt operator|(const VectorUInt& other) const {
        VectorUInt result(*this);
        result |= other;
        return result;
    }

    VectorUInt operator^(const VectorUInt& other) const {
        VectorUInt result(*this);
        result ^= other;
        return result;
    }

    VectorUInt operator&(const VectorUInt& other) const {
        VectorUInt result(*this);
        result &= other;
        return result;
    }

    // ��������� ���������
    bool operator==(const VectorUInt& other) const {
        if (size != other.size) {
            return false;
        }
        for (size_t i = 0; i < size; ++i) {
            if (data[i] != other.data[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const VectorUInt& other) const {
        return !(*this == other);
    }

    bool operator>(const VectorUInt& other) const {
        for (size_t i = 0; i < size; ++i) {
            if (data[i] <= other.data[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator>=(const VectorUInt& other) const {
        return (*this > other) || (*this == other);
    }

    bool operator<(const VectorUInt& other) const {
        for (size_t i = 0; i < size; ++i) {
            if (data[i] >= other.data[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator<=(const VectorUInt& other) const {
        return (*this < other) || (*this == other);
    }

    // �������-�������� ����������
    unsigned int& operator[](size_t index) {
        if (index < size) {
            codeError = 0;
            return data[index];
        }
        else {
            codeError = 1;  // ��� ������� - ������ �������� �� ��� ������
            return data[size - 1];  // ��������� ������� �������
        }
    }

    // ������ ������� ��� ��������� ������� � ����
    friend ostream& operator<<(ostream& os, const VectorUInt& vec) {
        os << "[ ";
        for (size_t i = 0; i < vec.size; ++i) {
            os << vec.data[i];
            if (i < vec.size - 1) {
                os << ", ";
            }
        }
        os << " ]";
        return os;
    }
};

int main() {
    // ������� ������������ ����� VectorUInt
    VectorUInt v1; // ����������� �� �������������
    VectorUInt v2(5); // ����������� �� �������
    VectorUInt v3(3, 7); // ����������� �� ������� �� ��������� �����������

    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;
    cout << "v3: " << v3 << endl;

    v2[2] = 10; // ������� ������������ ��������� ����������

    cout << "v2 after modification: " << v2 << endl;

    ++v1; // ������� ������������ �������� ����������� ++
    cout << "v1 after ++v1: " << v1 << endl;

    VectorUInt v4 = v3++; // ������� ������������ �������� ������������ ++
    cout << "v3 after v4 = v3++: " << v3 << endl;
    cout << "v4: " << v4 << endl;

    v4 += v2; // ������� ������������ �������� +=
    cout << "v4 after v4 += v2: " << v4 << endl;

    VectorUInt v5 = v2 * 2; // ������� ������������ �������� �������� �� ������
    cout << "v2 * 2: " << v5 << endl;

    // ���� �������� ��������������
    VectorUInt v6 = v4 - v2; // ������� ������������ �������� ��������
    cout << "v4 - v2: " << v6 << endl;

    VectorUInt v7 = v4 | v2; // ������� ������������ �������� ��������� "���"
    cout << "v4 | v2: " << v7 << endl;

    VectorUInt v8 = v4 & v2; // ������� ������������ �������� ��������� "�"
    cout << "v4 & v2: " << v8 << endl;

    // �������� ���������
    if (v2 == v3) {
        cout << "v2 is equal to v3" << endl;
    }
    else {
        cout << "v2 is not equal to v3" << endl;
    }

    return 0;
}
