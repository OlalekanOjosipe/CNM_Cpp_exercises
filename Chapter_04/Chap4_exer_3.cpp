// ex3_average.cpp
#include <iostream>
using namespace std;

// Average of elements
double average_array(const double a[], int n) {
    if (n == 0) return 0.0;
    double s = 0.0;
    for (int i = 0; i < n; ++i) {
        s += a[i];
    }
    return s / n;
}

int main() {
    const int N = 5;
    double arr[N] = {10.0, 12.0, 8.0, 15.0, 5.0};

    double avg = average_array(arr, N);

    cout << "Average of elements = " << avg << "\n";

    return 0;
}
