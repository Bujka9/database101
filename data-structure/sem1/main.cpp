#include <iostream>

using namespace std;

int main() {

    int n;

    cout << "N = ";
    cin >> n;

    // Энэ давталт n удаа ажиллана
    for (int i = 0; i < n; i++) {

        // i-ийн утгыг хэвлэж байна
        cout << "i = " << i << endl;
    }
    
    // Complexity
    // O(n)
    return 0;
}