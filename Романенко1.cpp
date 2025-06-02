#include <iostream> 
#include <cmath>
#define_use_math_defines //for c++

using namespace std;

/**
* @brief Функция для вычисления значения a по заданной формуле
* @param x - значение переменной x
* @param y - значение переменной у
* @return возвращает рассчитанное значение a
*/
double calculateA(double x, double y);

/**
* @brief Функция для вычисления значения b по заданной формуле
* @param x - значение переменной x
* @param y - значение переменной y
* @return возвращает рассчитанное значение b
*/
double calculateB(double x, double y);

int main() {
    // Значения из задания
    const double x = 0.335;
    const double y = 0.025;
    
    // Вычисление и вывод результатов
    cout << "a = " << calculateA(x, y) << endl;
    cout << "b = " << calculateB(x, y) << endl;
    
    return 0;
}

double calculateA(double x, double y) {
    // Вычисляем a = 1 + x + x²/2 + x³/3 + x⁴/4
    (void)y;
    return 1 + x + (x*x)/2 + (x*x*x)/3 + (x*x*x*x)/4;
}

double calculateB(double x, double y) {
    // Вычисляем b = x*(sin(x³) + cos²(y))
    double x_cubed = x * x * x;
    double cos_y = cos(y);
    return x * (sin(x_cubed) + cos_y*cos_y);
}
