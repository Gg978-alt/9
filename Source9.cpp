#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// ======= Шифрование (String62) =======
char shiftChar(char ch) {
    if (ch >= 'A' && ch <= 'Z') return (ch == 'Z') ? 'A' : ch + 1;
    if (ch >= 'a' && ch <= 'z') return (ch == 'z') ? 'a' : ch + 1;

    if (ch == 'е') return 'ж';
    if (ch == 'Е') return 'Ж';

    if ((ch >= 'А' && ch <= 'Я') || ch == 'Ё') {
        return (ch == 'Я') ? 'А' : (ch == 'Ё' ? 'Ж' : ch + 1);
    }
    if ((ch >= 'а' && ch <= 'я') || ch == 'ё') {
        return (ch == 'я') ? 'а' : (ch == 'ё' ? 'ж' : ch + 1);
    }

    return ch;
}

string encrypt(const string& input) {
    string result = input;
    for (size_t i = 0; i < result.length(); ++i)
        result[i] = shiftChar(result[i]);
    return result;
}

// ======= Демонстрация find_last_of =======
string demoFindLastOf(const string& text, const string& symbols) {
    size_t pos = text.find_last_of(symbols.c_str());
    if (pos != string::npos) {
        return "Последний символ из набора найден на позиции: " + to_string(pos) +
            " (символ '" + text[pos] + "')\n";
    }
    else {
        return "Ни один символ не найден.\n";
    }
}

// ======= Основная программа с логированием =======
int main() {
    ofstream logfile("results.txt");
    if (!logfile) {
        cerr << "Ошибка при создании файла.\n";
        return 1;
    }

    int choice;
    do {
        cout << "\nВыберите программу:\n";
        cout << "1. Шифрование строки (String62)\n";
        cout << "2. Демонстрация find_last_of\n";
        cout << "0. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;
        cin.ignore(); // очистка буфера

        if (choice == 1) {
            string input;
            cout << "Введите строку для шифрования: ";
            getline(cin, input);
            string result = encrypt(input);
            cout << "Зашифрованная строка: " << result << "\n";
            logfile << "[String62]\nВвод: " << input << "\nРезультат: " << result << "\n\n";
        }
        else if (choice == 2) {
            string text, symbols;
            cout << "Введите строку: ";
            getline(cin, text);
            cout << "Введите символы, которые искать: ";
            getline(cin, symbols);
            string result = demoFindLastOf(text, symbols);
            cout << result;
            logfile << "[find_last_of]\nСтрока: " << text << "\nСимволы: " << symbols
                << "\nРезультат: " << result << "\n";
        }
        else if (choice == 0) {
            cout << "Выход из программы.\n";
            logfile << "[Выход]\nПрограмма завершена.\n";
        }
        else {
            cout << "Неверный выбор. Попробуйте снова.\n";
        }

    } while (choice != 0);

    logfile.close();
    return 0;
}
