#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

// Функция для вычисления значения y(x)
double calculateY(double x) {
    double ln_x = log(x); // Вычисляем натуральный логарифм x
    return sin(ln_x) - cos(ln_x) + 2 * ln_x;
}

// Функция для вывода числа с округлением до 4 знаков
void printNumber(double num) {
    // Округляем до 4 знаков после запятой
    double rounded = round(num * 10000) / 10000;
    
    // Выводим целую часть
    cout << static_cast<int>(rounded);
    
    // Выводим дробную часть, если она есть
    double fractional = rounded - static_cast<int>(rounded);
    if (abs(fractional) > numeric_limits<double>::epsilon()) {
        cout << ".";
        // Выводим 4 знака после запятой
        fractional *= 10000;
        int digits = static_cast<int>(round(fractional));
        printf("%04d", digits);
    }
}

int main() {
    double start, end, step;
    
    // Ввод параметров с клавиатуры
    cout << "Введите начальное значение x: ";
    cin >> start;
    cout << "Введите конечное значение x: ";
    cin >> end;
    cout << "Введите шаг табулирования: ";
    cin >> step;
    
    // Проверка корректности шага
    if (step <= 0) {
        cout << "Ошибка: шаг должен быть положительным" << endl;
        return 1;
    }
    
    // Вывод заголовка таблицы
    cout << "\nТабулирование функции y = sin(ln x) - cos(ln x) + 2ln x\n";
    cout << "на интервале [" << start << ", " << end << "] с шагом " << step << "\n\n";
    cout << "     x          y(x)\n";
    cout << "---------------------\n";
    
    // Табулирование и вывод результатов
    for (double x = start; x <= end + numeric_limits<double>::epsilon(); x += step) {
        // Проверка, что x положительный
        if (x > 0) {
            double y = calculateY(x);
            
            // Вывод x
            cout << " ";
            printNumber(x);
            
            // Вывод y(x)
            cout << "     ";
            printNumber(y);
            cout << endl;
        }
    }
    
    return 0;
}
