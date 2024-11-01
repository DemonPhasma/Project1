#include <iostream>
#include <vector>
#include <algorithm>

// Перегруженная функция для нахождения максимального значения в одномерном массиве
int maxInArray(const std::vector<int>& arr) {
    return *std::max_element(arr.begin(), arr.end());
}

// Перегруженная функция для нахождения максимального значения в двумерном массиве
int maxInArray(const std::vector<std::vector<int>>& arr) {
    int maxVal = arr[0][0];
    for (const auto& row : arr) {
        maxVal = std::max(maxVal, *std::max_element(row.begin(), row.end()));
    }
    return maxVal;
}

// Перегруженная функция для нахождения максимального значения в трёхмерном массиве
int maxInArray(const std::vector<std::vector<std::vector<int>>>& arr) {
    int maxVal = arr[0][0][0];
    for (const auto& matrix : arr) {
        for (const auto& row : matrix) {
            maxVal = std::max(maxVal, *std::max_element(row.begin(), row.end()));
        }
    }
    return maxVal;
}

// Перегруженная функция для нахождения максимального значения двух целых
int maxInArray(int a, int b) {
    return (a > b) ? a : b;
}

// Перегруженная функция для нахождения максимального значения трёх целых
int maxInArray(int a, int b, int c) {
    return std::max({ a, b, c });
}

int main() {
    setlocale(LC_ALL, "RU");
    // Тестирование функции нахождения максимума в одномерном массиве
    std::vector<int> oneDArray = { 1, 5, 3, 9, 2 };
    std::cout << "Максимальное значение в одномерном массиве: " << maxInArray(oneDArray) << std::endl;

    // Тестирование функции нахождения максимума в двумерном массиве
    std::vector<std::vector<int>> twoDArray = { {1, 5, 3}, {9, 2, 8}, {4, 6, 7} };
    std::cout << "Максимальное значение в двумерном массиве: " << maxInArray(twoDArray) << std::endl;

    // Тестирование функции нахождения максимума в трёхмерном массиве
    std::vector<std::vector<std::vector<int>>> threeDArray = {
        {{1, 5, 3}, {9, 2, 8}},
        {{4, 6, 7}, {10, 12, 14}}
    };
    std::cout << "Максимальное значение в трёхмерном массиве: " << maxInArray(threeDArray) << std::endl;

    // Тестирование функции нахождения максимума из двух целых
    int a = 10, b = 20;
    std::cout << "Максимальное значение между " << a << " и " << b << ": " << maxInArray(a, b) << std::endl;

    // Тестирование функции нахождения максимума из трёх целых
    int x = 10, y = 20, z = 15;
    std::cout << "Максимальное значение между " << x << ", " << y << " и " << z << ": " << maxInArray(x, y, z) << std::endl;

    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------\\    
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Рекурсивная функция для нахождения позиции с минимальной суммой последовательности из 10 чисел
int findMinSumPosition(const std::vector<int>& arr, int index, int minPos, int& minSum) {
    if (index > arr.size() - 10) {
        return minPos;
    }

    int currentSum = 0;
    for (int i = index; i < index + 10; ++i) {
        currentSum += arr[i];
    }

    if (currentSum < minSum) {
        minSum = currentSum;
        minPos = index;
    }

    return findMinSumPosition(arr, index + 1, minPos, minSum);
}

int main() {
    setlocale(LC_ALL, "RU");
    std::vector<int> arr(100);
    std::srand(std::time(0)); // Инициализация генератора случайных чисел

    // Заполнение массива случайными числами
    for (int& num : arr) {
        num = std::rand() % 100; // Случайные числа от 0 до 99
    }

    // Нахождение позиции с минимальной суммой последовательности из 10 чисел
    int minPos = 0;
    int minSum = INT_MAX; // Начальное значение для минимальной суммы
    minPos = findMinSumPosition(arr, 0, minPos, minSum);

    std::cout << "Позиция, с которой начинается последовательность из 10 чисел с минимальной суммой: " << minPos << std::endl;

    return 0;
}

