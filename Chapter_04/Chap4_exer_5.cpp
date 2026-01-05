// ex5_vector_stats.cpp
#include <iostream>
#include <vector>
#include <algorithm>   // sort, min_element, max_element
using namespace std;

int main() {
    int n;
    cout << "How many real numbers do you want to input? ";
    cin >> n;

    if (n <= 0) {
        cout << "Nothing to do.\n";
        return 0;
    }

    vector<double> v;
    v.reserve(n);

    cout << "Enter " << n << " numbers:\n";
    for (int i = 0; i < n; ++i) {
        double x;
        cin >> x;
        v.push_back(x);
    }

    // a) average
    double sum = 0.0;
    for (double x : v) {
        sum += x;
    }
    double avg = sum / v.size();

    // b) min and max
    auto it_min = min_element(v.begin(), v.end());
    auto it_max = max_element(v.begin(), v.end());

    // c) sort ascending
    sort(v.begin(), v.end());

    cout << "\nAverage = " << avg << "\n";
    cout << "Minimum = " << *it_min << "\n";
    cout << "Maximum = " << *it_max << "\n";

    cout << "Sorted (ascending): ";
    for (double x : v) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
