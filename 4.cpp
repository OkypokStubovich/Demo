#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

double calculateY(double x) {
    double ln_x = log(x);
    return sin(ln_x) - cos(ln_x) + 2 * ln_x;
}

int main() {
    double start, end, step;
    
    cout << "Введите начальное значение x: ";
    cin >> start;
    cout << "Введите конечное значение x: ";
    cin >> end;
    cout << "Введите шаг табулирования: ";
    cin >> step;
    
    if (step <= 0) {
        cout << "Ошибка: шаг должен быть положительным\n";
        return 1;
    }
    
    cout << "\nТабулирование функции y = sin(ln x) - cos(ln x) + 2ln x\n";
    cout << "x\ty(x)\n";
    cout << "----------------\n";
    
    for (double x = start; x <= end + numeric_limits<double>::epsilon(); x += step) {
        cout << x << "\t";
        cout << (x > 0 ? to_string(calculateY(x)) : "не определено") << "\n";
    }
    
    return
