#include <iostream>
#include <vector>
#include <algorithm>

// ������������� ������� ��� ���������� ������������� �������� � ���������� �������
int maxInArray(const std::vector<int>& arr) {
    return *std::max_element(arr.begin(), arr.end());
}

// ������������� ������� ��� ���������� ������������� �������� � ��������� �������
int maxInArray(const std::vector<std::vector<int>>& arr) {
    int maxVal = arr[0][0];
    for (const auto& row : arr) {
        maxVal = std::max(maxVal, *std::max_element(row.begin(), row.end()));
    }
    return maxVal;
}

// ������������� ������� ��� ���������� ������������� �������� � ��������� �������
int maxInArray(const std::vector<std::vector<std::vector<int>>>& arr) {
    int maxVal = arr[0][0][0];
    for (const auto& matrix : arr) {
        for (const auto& row : matrix) {
            maxVal = std::max(maxVal, *std::max_element(row.begin(), row.end()));
        }
    }
    return maxVal;
}

// ������������� ������� ��� ���������� ������������� �������� ���� �����
int maxInArray(int a, int b) {
    return (a > b) ? a : b;
}

// ������������� ������� ��� ���������� ������������� �������� ��� �����
int maxInArray(int a, int b, int c) {
    return std::max({ a, b, c });
}

int main() {
    setlocale(LC_ALL, "RU");
    // ������������ ������� ���������� ��������� � ���������� �������
    std::vector<int> oneDArray = { 1, 5, 3, 9, 2 };
    std::cout << "������������ �������� � ���������� �������: " << maxInArray(oneDArray) << std::endl;

    // ������������ ������� ���������� ��������� � ��������� �������
    std::vector<std::vector<int>> twoDArray = { {1, 5, 3}, {9, 2, 8}, {4, 6, 7} };
    std::cout << "������������ �������� � ��������� �������: " << maxInArray(twoDArray) << std::endl;

    // ������������ ������� ���������� ��������� � ��������� �������
    std::vector<std::vector<std::vector<int>>> threeDArray = {
        {{1, 5, 3}, {9, 2, 8}},
        {{4, 6, 7}, {10, 12, 14}}
    };
    std::cout << "������������ �������� � ��������� �������: " << maxInArray(threeDArray) << std::endl;

    // ������������ ������� ���������� ��������� �� ���� �����
    int a = 10, b = 20;
    std::cout << "������������ �������� ����� " << a << " � " << b << ": " << maxInArray(a, b) << std::endl;

    // ������������ ������� ���������� ��������� �� ��� �����
    int x = 10, y = 20, z = 15;
    std::cout << "������������ �������� ����� " << x << ", " << y << " � " << z << ": " << maxInArray(x, y, z) << std::endl;

    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------\\    
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// ����������� ������� ��� ���������� ������� � ����������� ������ ������������������ �� 10 �����
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
    std::srand(std::time(0)); // ������������� ���������� ��������� �����

    // ���������� ������� ���������� �������
    for (int& num : arr) {
        num = std::rand() % 100; // ��������� ����� �� 0 �� 99
    }

    // ���������� ������� � ����������� ������ ������������������ �� 10 �����
    int minPos = 0;
    int minSum = INT_MAX; // ��������� �������� ��� ����������� �����
    minPos = findMinSumPosition(arr, 0, minPos, minSum);

    std::cout << "�������, � ������� ���������� ������������������ �� 10 ����� � ����������� ������: " << minPos << std::endl;

    return 0;
}

