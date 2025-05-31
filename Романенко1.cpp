#include <iostream> 
#include <cmath>
#define _use_math_defines //for c++

using namespace std;
/**
*@brief - Функция для вычисления А по заданному уравнению
*@param х - значение переменной х
*@param у - значение переменной у
*@return- возвращает рассчитанное значение
*/
double getA(const double x, const double y);
/**
*@brief - Функция для вычисления А по заданному уравнению
*@param х - значение переменной х
*@param у - значение переменной у
*@return- возвращает рассчитанное значение
*/
double getB(const double x, const double y);
/**
*@brief - Точко входа в программу
*@return - возвращает 0, если программа выполнена корректно 
*/
int main() {
    const double x = 0.335; 
    const double y = 0.025; 
    cout << "a = " << getA(x,y) << endl; 
    cout << "b = " << getB(x,y); 
    return 0;
}
double getA(const double x, const double y)
{
    return(1 + x + ((pow(x, 2)) / 2) + ((pow(x, 3)) / 3) + ((pow(x, 4)) / 4));
}
double getB(const double x, const double y)
{
    return(x * (sin(pow(x, 3)) + pow(cos(y), 2)));
}
