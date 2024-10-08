#include <iostream>
using namespace std;

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        cout << "Ошибка: деление на ноль!" << endl;
        return 0;
    }
    return a / b;
}

int main() {
    setlocale(LC_ALL, "ru");
    double num1, num2;
    char operation;

    cout << "Введите первое число: ";
    cin >> num1;

    cout << "Введите операцию (+, -, *, /): ";
    cin >> operation;

    cout << "Введите второе число: ";
    cin >> num2;

    switch (operation) {
    case '+':
        cout << "Результат: " << add(num1, num2) << endl;
        break;
    case '-':
        cout << "Результат: " << subtract(num1, num2) << endl;
        break;
    case '*':
        cout << "Результат: " << multiply(num1, num2) << endl;
        break;
    case '/':
        cout << "Результат: " << divide(num1, num2) << endl;
        break;
    default:
        cout << "Ошибка: неизвестная операция!" << endl;
        break;
    }

    return 0;
}