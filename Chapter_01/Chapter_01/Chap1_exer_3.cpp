// Exercise three
#include <iostream>
#include <string>
#include <sstream>
#define PI 3.14159
using namespace std;

int main()
{
    string mystr;
    float degrees = 0;
    
    cout << "input your value in degrees: ";
    getline(cin, mystr);  
    stringstream(mystr) >> degrees;
    degrees = (PI*degrees/180);
    cout<< "The sine is: "
    << sin(degrees)  << ".\n"
    << "The cosine is: " << cos(degrees)  << ".\n"
    << "The tangent is: " << tan(degrees) << "."
    << endl;
    return 0;
}
