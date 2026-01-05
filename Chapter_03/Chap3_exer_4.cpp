#include <iostream>
#include <string>
#include <sstream>
#define _USE_MATH_DEFINES
#include <cmath>
#define PI 3.14159

using namespace std;

// define function

double rad_converter(double x) {
    double y = 0;
    y = (x* PI/180);
    
    return y;
}

// Convert degrees → radians
double deg_to_rad(double degrees) {
    return degrees * PI / 180.0;
}

int main() {
    // Mass ratio x = M_proj / M_target = 6 / 12
    const double x = 6.0 / 12.0;   // = 0.5

    // Print table header
    cout << "theta_lab_deg\ttheta_cm_deg" << endl;

    // Step size in degrees (you can change to 1 for more detail)
    int step = 10;

    // Loop over theta_lab from 0° to 180°
    for (int theta_lab_deg = 0; theta_lab_deg <= 180; theta_lab_deg += step) {
        // Convert lab angle to radians
        double theta_lab_rad = deg_to_rad(theta_lab_deg);

        // Trig functions in lab frame
        double s = sin(theta_lab_rad);  // sin(theta_lab)
        double c = cos(theta_lab_rad);  // cos(theta_lab)

        // Squares: sin^2 and cos^2
        double s2 = s * s;
        double c2 = c * c;

        // Inner = 1 - x^2 * sin^2(theta_lab)
        double inner = 1.0 - x * x * s2;

        // Under the square root: cos^2(theta_lab) * (1 - x^2 * sin^2(theta_lab))
        double under_sqrt = c2 * inner;

        // Guard against tiny negative values from rounding
        if (under_sqrt < 0.0) {
            under_sqrt = 0.0;
        }

        double root = sqrt(under_sqrt);

        // Base term: -x * sin^2(theta_lab)
        double base = -x * s2;

        // Two possible values for cos(theta_cm)
        double cos_cm_plus  = base + root;
        double cos_cm_minus = base - root;

        double cos_cm;

        // According to the problem: use + for theta_lab < 90°, - for theta_lab >= 90°
        if (theta_lab_deg < 90) {
            cos_cm = cos_cm_plus;
        } else {
            cos_cm = cos_cm_minus;
        }

        // Numerical safety: clamp cos_cm into [-1, 1]
        if (cos_cm > 1.0)  cos_cm = 1.0;
        if (cos_cm < -1.0) cos_cm = -1.0;

        // Now get theta_cm in radians
        double theta_cm_rad = acos(cos_cm);

        // Convert theta_cm to degrees
        double theta_cm_deg = theta_cm_rad * 180.0 / PI;

        // Print the pair
        cout << theta_lab_deg << "\t\t" << theta_cm_deg << endl;
    }

    return 0;
}
