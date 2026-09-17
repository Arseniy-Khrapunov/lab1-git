// Лабораторная работа № 1. Вариант 54.
// Двоичная система: перевод из десятичной в двоичную и обратно.
// Выполнил: Храпунов А.А., группа ПИ-53.

#include <iostream>
#include <windows.h>
using namespace std;

// ===== Расчётные функции варианта =====

// Перевод десятичного числа в двоичное (результат — число из 0 и 1)
long long toBinary(int n) {
    long long result = 0;
    long long place = 1;
    if (n == 0) return 0;
    while (n > 0) {
        int bit = n % 2;
        result += bit * place;
        place *= 10;
        n /= 2;
    }
    return result;
}

// Перевод двоичного числа (записанного как 0 и 1) обратно в десятичное
int fromBinary(long long b) {
    int result = 0;
    int power = 1;
    while (b > 0) {
        int digit = b % 10;
        if (digit != 0 && digit != 1) {
            cout << "Ошибка: число не является двоичным!\n";
            return -1;
        }
        result += digit * power;
        power *= 2;
        b /= 10;
    }
    return result;
}

// Количество единиц в двоичной записи числа
int countOnes(int n) {
    int count = 0;
    if (n == 0) return 0;
    while (n > 0) {
        if (n % 2 == 1) count++;
        n /= 2;
    }
    return count;
}

// ===== Главная функция: меню =====
int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int choice;
    do {
	cout << " \n--- Программа расчётов. Вариант 54 ---\n";
        cout << "1. Перевести десятичное число в двоичное\n";
        cout << "2. Перевести двоичное число в десятичное\n";
	cout << "3. Подсчитать количество единиц в двоичной записи\n";
        cout << "0. Выход\n";
        cout << "Выберите пункт: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int n;
                cout << "Введите целое неотрицательное число: ";
                cin >> n;
                if (n < 0) {
                    cout << "Ошибка: число должно быть неотрицательным.\n";
                    break;
                }
                cout << "Десятичное число " << n << " в двоичной системе = " << toBinary(n) << "\n";
                break;
            }
            case 2: {
                long long b;
                cout << "Введите двоичное число (только 0 и 1): ";
                cin >> b;
                int result = fromBinary(b);
                if (result != -1) {
                    cout << "Десятичное представление: " << result << "\n";
                }
                break;
            }
	    case 3: {
    		int n;
    		cout << "Введите целое неотрицательное число: ";
    		cin >> n;
    		if (n < 0) {
        	    cout << "Ошибка: число должно быть неотрицательным.\n";
        	    break;
    		}
    		cout << "Количество единиц: " << countOnes(n) << "\n";
    		break;
	    }
            case 0:
                cout << "Работа завершена.\n";
                break;
            default:
                cout << "Такого пункта нет.\n";
        }
    } while (choice != 0);
    return 0;
}
