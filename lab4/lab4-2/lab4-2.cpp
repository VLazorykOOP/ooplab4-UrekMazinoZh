#include <iostream>
#include <map>
#include <string>

using namespace std;

class AssociatedClass {
private:
    map<string, string> entities; // асоціативний масив між банківським рахунком та ім'ям

public:
    int codeError; 

    // Конструктор за замовчуванням
    AssociatedClass() : codeError(0) {}

    // Функція додавання асоціативної сутності
    void addEntity(const string& account, const string& name) {
        entities[account] = name;
    }

    // Перевантаження оператора індексації
    string& operator[](const string& account) {
        if (entities.find(account) != entities.end()) {
            codeError = 0; // Сутність знайдена, код помилки - 0
            return entities[account];
        }
        else {
            codeError = 1; // Сутності не знайдено, код помилки - 1
            static string emptyString;
            return emptyString;
        }
    }

    // Дружня функція для виведення в асоціативний клас у потік
    friend ostream& operator<<(ostream& os, const AssociatedClass& obj) {
        for (const auto& pair : obj.entities) {
            os << "Account: " << pair.first << ", Name: " << pair.second << endl;
        }
        return os;
    }

    // Дружня функція для введення з потоку в асоціативний клас
    friend istream& operator>>(istream& is, AssociatedClass& obj) {
        string account, name;
        cout << "Enter new entities (account name pairs, enter 'exit' to finish input):\n";
        while (is >> account >> name) {
            if (account == "exit") {
                break;
            }
            obj.addEntity(account, name);
        }
        return is;
    }

    // Перевантаження оператора виклику функції
    string operator() (const string& account) {
        return entities[account];
    }
};

int main() {
    AssociatedClass assocClass;

    // Додаємо асоціативні сутності
    assocClass.addEntity("123456", "John Doe");
    assocClass.addEntity("789012", "Jane Smith");

    // Виводимо асоціативний клас
    cout << "Associated Class:\n" << assocClass << endl;

    // Використання оператора індексації
    cout << "Name for account '123456': " << assocClass["123456"] << endl;

    // Використання оператора виклику функції
    cout << "Name for account '789012': " << assocClass("789012") << endl;

    // Введення асоціативного класу з консолі
    cin >> assocClass;

    // Виведення асоціативного класу після введення
    cout << "Associated Class after input:\n" << assocClass << endl;

    return 0;
}
