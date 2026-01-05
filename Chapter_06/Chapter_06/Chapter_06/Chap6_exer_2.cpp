#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    long long N;
    cout << "Number of Monte Carlo simulations: ";
    cin >> N;

    const int PANELS = 5;
    const double LMIN = 1000.0;
    const double LMAX = 5000.0;

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist(LMIN, LMAX);

    double sum = 0.0;
    double sumSq = 0.0;

    vector<double> lifetimes(PANELS);

    for (long long i = 0; i < N; ++i) {
        // Generate lifetimes for the 5 panels
        for (int j = 0; j < PANELS; ++j) {
            lifetimes[j] = dist(gen);
        }

        // Sort them: t0 <= t1 <= t2 <= t3 <= t4
        sort(lifetimes.begin(), lifetimes.end());

        // Failure when 4th panel fails → index 3
        double failure_time = lifetimes[3];

        sum   += failure_time;
        sumSq += failure_time * failure_time;
    }

    double mean = sum / N;
    double meanSq = sumSq / N;
    double variance = meanSq - mean * mean;
    if (variance < 0) variance = 0; // numerical safety
    double stddev = sqrt(variance);

    cout << "Estimated MTTF (mean time to failure) = " << mean << " hours\n";
    cout << "Estimated standard deviation = " << stddev << " hours\n";

    return 0;
}
