#include "calculator.h"
#include <iostream>
#include <string>
#include <cmath>

using Number = double;

// Возвращает true, если удалось прочитать число
// и сохранить его в result.
bool ReadNumber(Number& result) {
    if (!(std::cin >> result)) {
        std::cerr << "Error: Numeric operand expected" << std::endl;
        return false;
    } else {
        return true;
    }
}

// Возвращает true, если работа завершилась штатно 
// командой q. Если из-за ошибки, возвращает false.
bool RunCalculatorCycle() {

    Number number; // Число калькулятора.
    Number calculation_result; // Итог вычислений
    Number memory; // Ячейка памяти
    bool is_memory_empty = true; // Пуста ли ячейка сохранения
    std::string operation; // Текущая операция
    
    if (!ReadNumber(number)) { // Пытаемся считать первое число
        return false;
    } 
    calculation_result = number;

    while (true) {
        std::cin >> operation; // Читаем операцию
        if (operation == "q") {
            return true;
        } else if (operation == "=") {
            std::cout << calculation_result << std::endl;
        } else if (operation == "+") {
            if (!ReadNumber(number)) {
                return false;
            } else {
                 calculation_result += number;
            }
        } else if (operation == "-") {
            if (!ReadNumber(number)) {
                return false;
            } else {
                calculation_result -= number;
            }
        } else if (operation == "*") {
            if (!ReadNumber(number)) {
                return false;
            } else {
                calculation_result *= number;
            }
        } else if (operation == "/") {
            if (!ReadNumber(number)) {
                return false;
            } else {
                calculation_result /= number;
            }
        } else if (operation == "**") {
            if (!ReadNumber(number)) {
                return false;
            } else {
                 calculation_result = std::pow(calculation_result, number);
            }
        } else if (operation == ":") {
            if (!ReadNumber(number)) {
                return false;
            } else {
                calculation_result = number;
            }
        } else if (operation == "c") {                
            calculation_result = 0;              
        } else if (operation == "s") {
            memory = calculation_result;
            is_memory_empty = false; // Память теперь не пуста
        } else if (operation == "l") {
            if (is_memory_empty) { // Проверка ниличия сохранения в памяти
                std::cerr << "Error: Memory is empty" << std::endl;
                return false;
            } else { 
                calculation_result = memory;
            }
        }else {
            std::cerr << "Error: Unknown token " << operation << std::endl;
            return false;
        }
    }
}