#include <iostream>
#include <map>
#include <string>

using namespace std;

class AssociatedClass {
private:
    map<string, string> entities; // ������������ ����� �� ���������� �������� �� ��'��

public:
    int codeError; 

    // ����������� �� �������������
    AssociatedClass() : codeError(0) {}

    // ������� ��������� ����������� �������
    void addEntity(const string& account, const string& name) {
        entities[account] = name;
    }

    // �������������� ��������� ����������
    string& operator[](const string& account) {
        if (entities.find(account) != entities.end()) {
            codeError = 0; // ������� ��������, ��� ������� - 0
            return entities[account];
        }
        else {
            codeError = 1; // ������� �� ��������, ��� ������� - 1
            static string emptyString;
            return emptyString;
        }
    }

    // ������ ������� ��� ��������� � ������������ ���� � ����
    friend ostream& operator<<(ostream& os, const AssociatedClass& obj) {
        for (const auto& pair : obj.entities) {
            os << "Account: " << pair.first << ", Name: " << pair.second << endl;
        }
        return os;
    }

    // ������ ������� ��� �������� � ������ � ������������ ����
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

    // �������������� ��������� ������� �������
    string operator() (const string& account) {
        return entities[account];
    }
};

int main() {
    AssociatedClass assocClass;

    // ������ ���������� �������
    assocClass.addEntity("123456", "John Doe");
    assocClass.addEntity("789012", "Jane Smith");

    // �������� ������������ ����
    cout << "Associated Class:\n" << assocClass << endl;

    // ������������ ��������� ����������
    cout << "Name for account '123456': " << assocClass["123456"] << endl;

    // ������������ ��������� ������� �������
    cout << "Name for account '789012': " << assocClass("789012") << endl;

    // �������� ������������� ����� � ������
    cin >> assocClass;

    // ��������� ������������� ����� ���� ��������
    cout << "Associated Class after input:\n" << assocClass << endl;

    return 0;
}
