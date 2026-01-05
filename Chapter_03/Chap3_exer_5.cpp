#include <iostream>
#include <string>
#include <sstream>
#define _USE_MATH_DEFINES
#include <cmath>
#define PI 3.14159

// degrees → radians
double deg_to_rad(double degrees) {
    return degrees * PI / 180.0;
}

int main() {
    // Reaction: 4He + 197Au at 3.5 MeV (lab)
    // Charges:
    int Zp = 2;   // 4He
    int ZT = 79;  // 197Au

    // Mass numbers (approximate masses in same units)
    double m_proj = 4.0;
    double m_targ = 197.0;

    // Given constants
    double e2 = 1.44;     // MeV·fm
    double E_lab = 3.5;   // MeV
    double fm2_to_b = 0.01; // 1 fm^2 = 0.01 b

    // Center-of-mass energy:
    // Ec.m. = (m_targ / (m_targ + m_proj)) * E_lab
    double E_cm = (m_targ / (m_targ + m_proj)) * E_lab;

    // Prefactor A = (Zp * ZT * e^2 / (4 * Ec.m.))^2   (in fm^2)
    double numerator = Zp * ZT * e2;
    double A = (numerator / (4.0 * E_cm));
    A = A * A;  // square it

    cout << "Rutherford cross section for 4He + 197Au at 3.5 MeV\n";
    cout << "Ec.m. = " << E_cm << " MeV\n";
    cout << "theta_cm_deg\tdsigma/dOmega [b/sr]\n";

    int step = 5;  // step in degrees (you can make this 1 if you like)

    // Loop from 1° to 179° to avoid the singularities at 0 and 180
    for (int theta_deg = 1; theta_deg <= 179; theta_deg += step) {
        double theta_rad = deg_to_rad(theta_deg);

        // s = sin(theta/2)
        double s = sin(theta_rad / 2.0);
        double s2 = s * s;
        double s4 = s2 * s2;

        // Avoid division by very small numbers
        if (s4 == 0.0) continue;

        // dσ/dΩ in fm^2/sr
        double sigma_fm2 = A / s4;

        // Convert to barns
        double sigma_b = sigma_fm2 * fm2_to_b;

        cout << theta_deg << "\t\t" << sigma_b << endl;
    }

    return 0;
}
