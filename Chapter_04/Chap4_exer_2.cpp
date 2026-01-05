// ex2_sum.cpp
#include <iostream>
using namespace std;

// Returns sum of elements of array
double sum_array(const double a[], int n) {
    double s = 0.0;
    for (int i = 0; i < n; ++i) {
        s += a[i];
    }
    return s;
}

int main() {
    const int N = 6;
    double arr[N] = {1.0, 2.5, -3.0, 4.2, 0.3, 5.0};

    double s = sum_array(arr, N);

    cout << "Sum of elements = " << s << "\n";

    return 0;
}
