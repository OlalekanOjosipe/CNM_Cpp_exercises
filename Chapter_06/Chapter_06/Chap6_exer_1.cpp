#include <iostream>
#include <random>
#include <cmath>
using namespace std;

int main() {
    // Number of random points
    long long N;
    cout << "Number of random points N: ";
    cin >> N;

    // Random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist(0.0, 1.0); // [0,1) for x and y

    long long inside = 0;  // points under curve

    for (long long i = 0; i < N; ++i) {
        double x = dist(gen);
        double y = dist(gen);

        if (y <= x * x) {
            inside++;
        }
    }

    // Area of rectangle is 1 * 1 = 1
    double estimate = static_cast<double>(inside) / N;

    cout << "Monte Carlo estimate of integral_0^1 x^2 dx = " << estimate << "\n";
    cout << "Exact value = 1/3 ≈ " << 1.0 / 3.0 << "\n";

    return 0;
}
