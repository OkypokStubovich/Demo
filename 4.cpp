#include <iostream>
#include <cmath>
#include <vector>
#include <stdexcept>

using namespace std;

// Функция для вычисления значения y(x)
double calculateY(double x) {
    // Проверяем, что x положительный, так как ln(x) определен только для x > 0
    if (x <= 0) {
        throw invalid_argument("x должен быть положительным");
    }
    
    double ln_x = log(x); // Вычисляем натуральный логарифм x
    return sin(ln_x) - cos(ln_x) + 2 * ln_x;
}

// Функция для табулирования функции на заданном интервале
void tabulateFunction(double start, double end, double step, vector<double>& x_values, vector<double>& y_values) {
    // Очищаем векторы для хранения результатов
    x_values.clear();
    y_values.clear();
    
    // Проверяем корректность входных параметров
    if (start <= 0) {
        throw invalid_argument("Начальное значение x должно быть положительным");
    }
    if (step <= 0) {
        throw invalid_argument("Шаг должен быть положительным");
    }
    if (start > end) {
        throw invalid_argument("Начальное значение x должно быть меньше конечного");
    }
    
    // Табулируем функцию
    for (double x = start; x <= end + 1e-9; x += step) {
        try {
            double y = calculateY(x);
            x_values.push_back(x);
            y_values.push_back(y);
        } catch (const invalid_argument& e) {
            cout << "Ошибка при x = " << x << ": " << e.what() << " - пропускаем эту точку" << endl;
        }
    }
}

// Простая функция для округления чисел при выводе
void printNumber(double num) {
    // Округляем до 4 знаков после запятой
    double rounded = round(num * 10000) / 10000;
    
    // Выводим целую часть
    int int_part = static_cast<int>(rounded);
    cout << int_part;
    
    // Выводим дробную часть, если она есть
    double fractional = rounded - int_part;
    if (fractional != 0) {
        cout << ".";
        // Выводим до 4 знаков после запятой
        for (int i = 0; i < 4; i++) {
            fractional *= 10;
            int digit = static_cast<int>(fractional) % 10;
            cout << digit;
        }
    }
}

int main() {
    // Параметры табулирования по умолчанию (из задания)
    double start = 1.0;
    double end = 3.0;
    double step = 0.2;
    
    // Векторы для хранения результатов
    vector<double> x_values, y_values;
    
    try {
        // Табулируем функцию
        tabulateFunction(start, end, step, x_values, y_values);
        
        // Выводим заголовок таблицы
        cout << "Табулирование функции y = sin(ln x) - cos(ln x) + 2ln x" << endl;
        cout << "на интервале [" << start << ", " << end << "] с шагом " << step << endl << endl;
        cout << "     x          y(x)" << endl;
        cout << "---------------------" << endl;
        
        // Выводим результаты
        for (size_t i = 0; i < x_values.size(); ++i) {
            // Выводим x с выравниванием
            cout << " ";
            printNumber(x_values[i]);
            
            // Выводим y(x) с выравниванием
            cout << "     ";
            printNumber(y_values[i]);
            cout << endl;
        }
        
        // Сообщение для построения графика
        cout << endl << "Для построения графика скопируйте данные в Excel или другое приложение:" << endl;
        cout << "x\ty" << endl;
        for (size_t i = 0; i < x_values.size(); ++i) {
            printNumber(x_values[i]);
            cout << "\t";
            printNumber(y_values[i]);
            cout << endl;
        }
        
    } catch (const invalid_argument& e) {
        cout << "Ошибка: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}
