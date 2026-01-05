#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

const double PI = 3.141592653589793;

double deg_to_rad(double deg) {
    return deg * PI / 180.0;
}

int main() {
    // Reaction: 4He + 197Au at 3.5 MeV
    const int Zp = 2;
    const int ZT = 79;
    const double Ap = 4.0;
    const double At = 197.0;
    const double E_lab = 3.5;   // MeV

    // constants
    const double e2 = 1.44;     // MeV·fm
    const double fm2_to_b = 0.01; // 1 fm^2 = 0.01 b

    // E_cm = (At / (At + Ap)) * E_lab
    double E_cm = (At / (At + Ap)) * E_lab;

    // prefactor A = (Zp * ZT * e^2 / (4 E_cm))^2  (fm^2)
    double num = Zp * ZT * e2;
    double A = (num / (4.0 * E_cm));
    A = A * A;

    ifstream fin("angles_cm.out");
    if (!fin) {
        cerr << "Error opening angles_cm.out for reading.\n";
        return 1;
    }

    ofstream fout("ruth.out");
    if (!fout) {
        cerr << "Error opening ruth.out for writing.\n";
        return 1;
    }

    fout << "# Rutherford cross section for 4He+197Au at Elab=3.5 MeV\n";
    fout << "# theta_cm_deg   dsigma/dOmega (b/sr)\n";

    string line;
    // skip comment lines starting with '#'
    while (getline(fin, line)) {
        if (!line.empty() && line[0] == '#') continue;

        // angles_cm.out format: theta_lab_deg  theta_cm_deg
        double theta_lab_deg, theta_cm_deg;
        {
            // use a stringstream to parse numbers from this line
            std::stringstream ss(line);
            if (!(ss >> theta_lab_deg >> theta_cm_deg)) {
                continue; // skip malformed lines
            }
        }

        double theta_cm_rad = deg_to_rad(theta_cm_deg);
        double s = sin(theta_cm_rad / 2.0);
        double s2 = s * s;
        double s4 = s2 * s2;

        if (s4 == 0.0) continue;  // avoid division by zero at 0 and 180

        double sigma_fm2 = A / s4;         // fm^2/sr
        double sigma_b   = sigma_fm2 * fm2_to_b; // b/sr

        fout << theta_cm_deg << "  " << sigma_b << "\n";
    }

    fin.close();
    fout.close();

    cout << "File ruth.out written.\n";
    return 0;
}
