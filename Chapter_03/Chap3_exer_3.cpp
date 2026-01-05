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

int main() {

string mystr;
    
    double a = 0;
    
    cout<< "Enter an integer in degrees: ";
    cin >> a;

    cout<< "This is the conveter radian equivalent: " << rad_converter(a) << endl;
    return 0;

}
