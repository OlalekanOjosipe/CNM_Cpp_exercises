// ex1_max_position.cpp
#include <iostream>
using namespace std;

// Returns index (position) of maximum element in array
int index_of_max(double a[], int n) {
    if (n <= 0) return -1;      // safety
    int idx = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] > a[idx]) {
            idx = i;
        }
    }
    return idx;
}

int main() {
    const int N = 8;
    double arr[N] = {3.5, 7.2, 1.1, 9.0, 4.4, 9.0, -2.0, 5.5};

    int pos = index_of_max(arr, N);

    cout << "Position of maximum = " << pos
         << " (value = " << arr[pos] << ")\n";

    return 0;
}
