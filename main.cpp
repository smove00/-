#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <locale>

using namespace std;

// Прототипы функций
int inputArraySize();
vector<double> inputArrayElements(int size);
char inputSortOrder();
int inputN(int maxSize);
double calculateAverage(const vector<double>& arr, int n);
void printArray(const vector<double>& arr, const string& message);

int main() {
    // Установка локализации для русского языка
    setlocale(LC_ALL, "Russian");
    
    cout << "=== Программа сортировки и вычисления среднего арифметического ===\n\n";
    
    try {
        // Ввод размера массива
        int size = inputArraySize();
        
        // Ввод элементов массива
        vector<double> arr = inputArrayElements(size);
        
        // Вывод исходного массива
        printArray(arr, "Исходный массив: ");
        
        // Выбор типа сортировки
        char sortOrder = inputSortOrder();
        
        // Сортировка массива
        if (sortOrder == 'A') {
            sort(arr.begin(), arr.end());
            cout << "Массив отсортирован по возрастанию.\n";
        } else {
            sort(arr.begin(), arr.end(), greater<double>());
            cout << "Массив отсортирован по убыванию.\n";
        }
        
        // Вывод отсортированного массива
        printArray(arr, "Отсортированный массив: ");
        
        // Ввод значения n
        int n = inputN(size);
        
        // Вычисление и вывод среднего арифметического
        double average = calculateAverage(arr, n);
        cout << "\nСреднее арифметическое первых " << n << " элементов: " << average << endl;
        
    } catch (const exception& e) {
        cerr << "Критическая ошибка: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}

/**
 * Функция для ввода размера массива с проверкой
 * @return корректный размер массива
 */
int inputArraySize() {
    int size;
    while (true) {
        cout << "Введите размер массива (положительное целое число): ";
        cin >> size;
        
        if (cin.fail() || size <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка! Размер должен быть положительным целым числом.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }
    return size;
}

/**
 * Функция для ввода элементов массива с проверкой на уникальность
 * @param size размер массива
 * @return вектор с уникальными элементами
 */
vector<double> inputArrayElements(int size) {
    vector<double> arr;
    double element;
    
    cout << "Введите " << size << " различных элементов массива:\n";
    
    for (int i = 0; i < size; i++) {
        while (true) {
            cout << "Элемент " << i + 1 << ": ";
            cin >> element;
            
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ошибка! Введите числовое значение.\n";
                continue;
            }
            
            // Проверка на уникальность
            bool isDuplicate = false;
            for (double val : arr) {
                if (val == element) {
                    isDuplicate = true;
                    break;
                }
            }
            
            if (isDuplicate) {
                cout << "Ошибка! Элементы должны быть различными. Попробуйте снова.\n";
            } else {
                arr.push_back(element);
                break;
            }
        }
    }
    return arr;
}

/**
 * Функция для выбора типа сортировки
 * @return символ типа сортировки ('A' или 'D')
 */
char inputSortOrder() {
    char order;
    while (true) {
        cout << "Выберите тип сортировки:\n";
        cout << "A - по возрастанию\n";
        cout << "D - по убыванию\n";
        cout << "Ваш выбор: ";
        cin >> order;
        
        order = toupper(order);
        if (order == 'A' || order == 'D') {
            break;
        } else {
            cout << "Ошибка! Выберите A или D.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return order;
}

/**
 * Функция для ввода значения n с проверкой
 * @param maxSize максимально допустимое значение n
 * @return корректное значение n
 */
int inputN(int maxSize) {
    int n;
    while (true) {
        cout << "Введите значение n (от 1 до " << maxSize << "): ";
        cin >> n;
        
        if (cin.fail() || n < 1 || n > maxSize) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка! n должно быть от 1 до " << maxSize << ".\n";
        } else {
            break;
        }
    }
    return n;
}

/**
 * Функция для вычисления среднего арифметического первых n элементов
 * @param arr массив элементов
 * @param n количество элементов для усреднения
 * @return среднее арифметическое
 */
double calculateAverage(const vector<double>& arr, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

/**
 * Функция для вывода массива на экран
 * @param arr массив для вывода
 * @param message сообщение перед выводом массива
 */
void printArray(const vector<double>& arr, const string& message) {
    cout << message;
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i != arr.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}
