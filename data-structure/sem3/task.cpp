#include <iostream>
#include <vector>
#include <chrono>
#include <random>

using namespace std;

// Хоёр элементийн байрыг солино
void swapItems(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Bubble Sort
void bubbleSort(vector<int> &arr) {
    bool swapped = false;

    // Гадна давталт
    for (int i = 0; i < (int)arr.size() - 1; i++) {
        swapped = false;

        // Хөрш элементүүдийг харьцуулна
        for (int j = 0; j < (int)arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swapItems(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Swap хийгдээгүй бол массив эрэмбэлэгдсэн
        if (swapped == false) {
            break;
        }
    }
}

// Cocktail Shaker Sort
void cocktailShakerSort(vector<int> &arr) {
    bool swapped = true;
    int start = 0;
    int end = (int)arr.size() - 1;

    while (swapped) {
        swapped = false;

        // Зүүнээс баруун тийш явна
        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                swapItems(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        // Swap хийгдээгүй бол эрэмбэлэлт дууссан
        if (swapped == false) {
            break;
        }

        // Баруун талын хамгийн том элемент байрандаа орсон
        end--;

        swapped = false;

        // Баруунаас зүүн тийш явна
        for (int i = end; i > start; i--) {
            if (arr[i] < arr[i - 1]) {
                swapItems(arr[i], arr[i - 1]);
                swapped = true;
            }
        }

        // Зүүн талын хамгийн жижиг элемент байрандаа орсон
        start++;
    }
}


// Массив хэвлэх
void printArray(const vector<int> &arr) {
    for (int value : arr) {
        cout << value << " ";
    }
    cout << endl;
}


int main() {
    // Лабын материалтай ижил төрлийн жишээ массив
    vector<int> arr = {64, 25, 12, 22, 11};

    // Хоёр алгоритм ижил өгөгдөл дээр ажиллахын тулд copy хийнэ
    vector<int> cocktailArr = arr;
    vector<int> bubbleArr = arr;

    cout << "Original array: ";
    printArray(arr);

    // Cocktail Shaker Sort хугацаа хэмжих
    auto cocktailStart = chrono::high_resolution_clock::now();

    cocktailShakerSort(cocktailArr);

    auto cocktailEnd = chrono::high_resolution_clock::now();

    auto cocktailTime =
        chrono::duration<double, milli>(cocktailEnd - cocktailStart).count();

    cout << "\nCocktail Shaker Sort result: ";
    printArray(cocktailArr);

    cout << "Cocktail Shaker Sort time: "
         << cocktailTime << " ms" << endl;


    // Bubble Sort хугацаа хэмжих
    auto bubbleStart = chrono::high_resolution_clock::now();

    bubbleSort(bubbleArr);

    auto bubbleEnd = chrono::high_resolution_clock::now();

    auto bubbleTime =
        chrono::duration<double, milli>(bubbleEnd - bubbleStart).count();

    cout << "\nBubble Sort result: ";
    printArray(bubbleArr);

    cout << "Bubble Sort time: "
         << bubbleTime << " ms" << endl;


    // Хугацааны харьцуулалт
    cout << "\n--- Comparison ---" << endl;

    if (cocktailTime < bubbleTime) {
        cout << "Cocktail Shaker Sort was faster." << endl;
    }
    else if (bubbleTime < cocktailTime) {
        cout << "Bubble Sort was faster." << endl;
    }
    else {
        cout << "Both algorithms took the same time." << endl;
    }

    return 0;
}
