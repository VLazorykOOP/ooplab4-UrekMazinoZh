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
    // Конструктори
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

    // Деструктор
    ~VectorUInt() {
        delete[] data;
    }

    // Оператор присвоєння
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

    // Оператори унарних префіксних та постфіксних ++ та --
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

    // Оператори для логічних та побітових операцій
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


    // Оператори присвоєння
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
            codeError = 2;  // Код помилки - ділення на нуль
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
            codeError = 2;  // Код помилки - ділення на нуль
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

    // Оператори арифметичних бінарних операцій
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

    // Оператори побітових бінарних операцій
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

    // Оператори порівняння
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

    // Функція-операція індексації
    unsigned int& operator[](size_t index) {
        if (index < size) {
            codeError = 0;
            return data[index];
        }
        else {
            codeError = 1;  // Код помилки - індекс виходить за межі масиву
            return data[size - 1];  // Повертаємо останній елемент
        }
    }

    // Дружня функція для виведення вектора у потік
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
    // Приклад використання класу VectorUInt
    VectorUInt v1; // Конструктор за замовчуванням
    VectorUInt v2(5); // Конструктор із розміром
    VectorUInt v3(3, 7); // Конструктор із розміром та значенням ініціалізації

    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;
    cout << "v3: " << v3 << endl;

    v2[2] = 10; // Приклад використання оператора індексації

    cout << "v2 after modification: " << v2 << endl;

    ++v1; // Приклад використання унарного префіксного ++
    cout << "v1 after ++v1: " << v1 << endl;

    VectorUInt v4 = v3++; // Приклад використання унарного постфіксного ++
    cout << "v3 after v4 = v3++: " << v3 << endl;
    cout << "v4: " << v4 << endl;

    v4 += v2; // Приклад використання операції +=
    cout << "v4 after v4 += v2: " << v4 << endl;

    VectorUInt v5 = v2 * 2; // Приклад використання операції множення на скаляр
    cout << "v2 * 2: " << v5 << endl;

    // Інші операції перевантаження
    VectorUInt v6 = v4 - v2; // Приклад використання операції віднімання
    cout << "v4 - v2: " << v6 << endl;

    VectorUInt v7 = v4 | v2; // Приклад використання операції побітового "або"
    cout << "v4 | v2: " << v7 << endl;

    VectorUInt v8 = v4 & v2; // Приклад використання операції побітового "і"
    cout << "v4 & v2: " << v8 << endl;

    // Оператор порівняння
    if (v2 == v3) {
        cout << "v2 is equal to v3" << endl;
    }
    else {
        cout << "v2 is not equal to v3" << endl;
    }

    return 0;
}
