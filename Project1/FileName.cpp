#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


void findMinMax(int arr[], int size) {
    int min = arr[0];
    int max = arr[0];
    int minIndex = 0;
    int maxIndex = 0;


    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
            minIndex = i;
        }
        if (arr[i] > max) {
            max = arr[i];
            maxIndex = i;
        }
    }


    cout << "Минимальный элемент: " << min << " (индекс: " << minIndex << ")" << endl;
    cout << "Максимальный элемент: " << max << " (индекс: " << maxIndex << ")" << endl;
}


int main() {
    setlocale(LC_ALL, "ru");
    const int size = 10;
    int arr[size];

    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    cout << "Массив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    findMinMax(arr, size);

    return 0;
}
    
