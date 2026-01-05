#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

const double PI = 3.141592653589793;

// degrees → radians
double deg_to_rad(double deg) {
    return deg * PI / 180.0;
}

// radians → degrees
double rad_to_deg(double rad) {
    return rad * 180.0 / PI;
}

int main() {
    // User-specified reaction (Ap,Zp)+(At,Zt) at Elab
    double Ap, At;
    int Zp, Zt;
    double E_lab;

    cout << "Enter projectile mass number Ap: ";
    cin >> Ap;
    cout << "Enter projectile charge Zp: ";
    cin >> Zp;

    cout << "Enter target mass number At: ";
    cin >> At;
    cout << "Enter target charge Zt: ";
    cin >> Zt;

    cout << "Enter E_lab (MeV): ";
    cin >> E_lab;

    // mass ratio x = m_proj / m_target ≈ Ap / At
    double x = Ap / At;

    ofstream fout("angles_cm.out");
    if (!fout) {
        cerr << "Error opening angles_cm.out for writing.\n";
        return 1;
    }

    fout << "# Ap=" << Ap << " Zp=" << Zp
         << "  At=" << At << " Zt=" << Zt
         << "  Elab(MeV)=" << E_lab << "\n";
    fout << "# theta_lab_deg   theta_cm_deg\n";

    // loop from 0° to 180° in steps of 0.5°
    for (double theta_lab_deg = 0.0; theta_lab_deg <= 180.0; theta_lab_deg += 0.5) {
        double theta_lab_rad = deg_to_rad(theta_lab_deg);

        double s = sin(theta_lab_rad);
        double c = cos(theta_lab_rad);

        double s2 = s * s;
        double c2 = c * c;

        double inner = 1.0 - x * x * s2;
        double under_sqrt = c2 * inner;
        if (under_sqrt < 0.0) under_sqrt = 0.0;

        double root = sqrt(under_sqrt);
        double base = -x * s2;

        double cos_cm_plus  = base + root;
        double cos_cm_minus = base - root;

        double cos_cm;
        if (theta_lab_deg < 90.0) {
            cos_cm = cos_cm_plus;   // use +
        } else {
            cos_cm = cos_cm_minus;  // use −
        }

        // clamp to [-1,1] for numerical safety
        if (cos_cm > 1.0)  cos_cm = 1.0;
        if (cos_cm < -1.0) cos_cm = -1.0;

        double theta_cm_rad = acos(cos_cm);
        double theta_cm_deg = rad_to_deg(theta_cm_rad);

        fout << theta_lab_deg << "  " << theta_cm_deg << "\n";
    }

    fout.close();
    cout << "File angles_cm.out written.\n";
    return 0;
}
