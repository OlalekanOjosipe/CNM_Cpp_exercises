#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
    ifstream fin("data.dat");
    if (!fin) {
        cerr << "Error: could not open data.dat for reading.\n";
        return 1;
    }

    double x, y;   // x = channel, y = energy
    int N = 0;

    double Sx = 0.0, Sy = 0.0;
    double Sxx = 0.0, Syy = 0.0;
    double Sxy = 0.0;

    // Read: each line "channel  energy"
    while (fin >> x >> y) {
        N++;
        Sx  += x;
        Sy  += y;
        Sxx += x * x;
        Syy += y * y;
        Sxy += x * y;
    }

    fin.close();

    if (N < 2) {
        cerr << "Not enough data points (N = " << N << ").\n";
        return 1;
    }

    // Linear regression y = a + b x
    double denom = N * Sxx - Sx * Sx;
    if (denom == 0.0) {
        cerr << "Denominator zero in slope calculation.\n";
        return 1;
    }

    double b = (N * Sxy - Sx * Sy) / denom;          // slope
    double a = (Sxx * Sy - Sx * Sxy) / denom;        // intercept

    double r_num = N * Sxy - Sx * Sy;
    double r_den = sqrt((N * Sxx - Sx * Sx) * (N * Syy - Sy * Sy));
    double r = 0.0;
    if (r_den != 0.0) {
        r = r_num / r_den;                           // correlation coefficient
    }

    ofstream fout("calib.out");
    if (!fout) {
        cerr << "Error: could not open calib.out for writing.\n";
        return 1;
    }

    fout << "# Linear calibration y = a + b x\n";
    fout << "# N = " << N << "\n";
    fout << "a (offset) = " << a << "\n";
    fout << "b (slope)  = " << b << "\n";
    fout << "r (corr.)  = " << r << "\n";

    fout.close();

    cout << "Done. Results written to calib.out\n";
    return 0;
}
