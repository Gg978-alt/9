#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// ======= ���������� (String62) =======
char shiftChar(char ch) {
    if (ch >= 'A' && ch <= 'Z') return (ch == 'Z') ? 'A' : ch + 1;
    if (ch >= 'a' && ch <= 'z') return (ch == 'z') ? 'a' : ch + 1;

    if (ch == '�') return '�';
    if (ch == '�') return '�';

    if ((ch >= '�' && ch <= '�') || ch == '�') {
        return (ch == '�') ? '�' : (ch == '�' ? '�' : ch + 1);
    }
    if ((ch >= '�' && ch <= '�') || ch == '�') {
        return (ch == '�') ? '�' : (ch == '�' ? '�' : ch + 1);
    }

    return ch;
}

string encrypt(const string& input) {
    string result = input;
    for (size_t i = 0; i < result.length(); ++i)
        result[i] = shiftChar(result[i]);
    return result;
}

// ======= ������������ find_last_of =======
string demoFindLastOf(const string& text, const string& symbols) {
    size_t pos = text.find_last_of(symbols.c_str());
    if (pos != string::npos) {
        return "��������� ������ �� ������ ������ �� �������: " + to_string(pos) +
            " (������ '" + text[pos] + "')\n";
    }
    else {
        return "�� ���� ������ �� ������.\n";
    }
}

// ======= �������� ��������� � ������������ =======
int main() {
    ofstream logfile("results.txt");
    if (!logfile) {
        cerr << "������ ��� �������� �����.\n";
        return 1;
    }

    int choice;
    do {
        cout << "\n�������� ���������:\n";
        cout << "1. ���������� ������ (String62)\n";
        cout << "2. ������������ find_last_of\n";
        cout << "0. �����\n";
        cout << "��� �����: ";
        cin >> choice;
        cin.ignore(); // ������� ������

        if (choice == 1) {
            string input;
            cout << "������� ������ ��� ����������: ";
            getline(cin, input);
            string result = encrypt(input);
            cout << "������������� ������: " << result << "\n";
            logfile << "[String62]\n����: " << input << "\n���������: " << result << "\n\n";
        }
        else if (choice == 2) {
            string text, symbols;
            cout << "������� ������: ";
            getline(cin, text);
            cout << "������� �������, ������� ������: ";
            getline(cin, symbols);
            string result = demoFindLastOf(text, symbols);
            cout << result;
            logfile << "[find_last_of]\n������: " << text << "\n�������: " << symbols
                << "\n���������: " << result << "\n";
        }
        else if (choice == 0) {
            cout << "����� �� ���������.\n";
            logfile << "[�����]\n��������� ���������.\n";
        }
        else {
            cout << "�������� �����. ���������� �����.\n";
        }

    } while (choice != 0);

    logfile.close();
    return 0;
}
