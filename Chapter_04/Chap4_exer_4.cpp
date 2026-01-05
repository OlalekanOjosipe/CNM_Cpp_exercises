// ex4_find_first.cpp
#include <iostream>
using namespace std;

// Returns first index where a[i] == value, or -1 if not found
int find_first(const double a[], int n, double value) {
    for (int i = 0; i < n; ++i) {
        if (a[i] == value) {
            return i;
        }
    }
    return -1;
}

int main() {
    const int N = 7;
    double arr[N] = {2.0, 4.5, 7.7, 4.5, 9.0, -1.0, 4.5};

    double x;
    cout << "Enter value to search: ";
    cin >> x;

    int pos = find_first(arr, N, x);

    if (pos == -1) {
        cout << x << " not found in array.\n";
    } else {
        cout << x << " found at position " << pos << ".\n";
    }

    return 0;
}
