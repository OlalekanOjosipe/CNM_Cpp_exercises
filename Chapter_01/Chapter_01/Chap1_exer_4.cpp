// Exercise 4
#include <iostream>
#include <string>
#include <sstream>
#define PI 3.14159
using namespace std;

int main()
{
    string mystr;
    int a = 0;
    int b = 0;
    int c = 0;
    
    cout << "input the a term of the quadratic equation: ";
    getline(cin, mystr);  
    stringstream(mystr) >> a;
    cout << "input the b term of the quadratic equation: ";
    getline(cin, mystr);  
    stringstream(mystr) >> b;
    cout << "input the c term of the quadratic equation: ";
    getline(cin, mystr);  
    stringstream(mystr) >> c;
    cout<< "The roots of the quadratic equation are: " << "\n"
    << "The first term: " << -b/2*a + sqrt(b*b - 4*a*c)/2*a  << ".\n"
    << "The second term: " << -b/2*a - sqrt(b*b - 4*a*c)/2*a << ".\n"
    << endl;
    return 0;
}
