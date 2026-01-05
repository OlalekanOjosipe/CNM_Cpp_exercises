// Exercise 5
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
    int d = 0;
    int N = 0;
    float Xmed = 0;
    float σ = 0;
    
    cout << "input the a term: ";
    getline(cin, mystr);  
    stringstream(mystr) >> a;
    cout << "input the b term: ";
    getline(cin, mystr);  
    stringstream(mystr) >> b;
    cout << "input the c term: ";
    getline(cin, mystr);  
    stringstream(mystr) >> c;
    cout << "input the d term: ";
    getline(cin, mystr);  
    stringstream(mystr) >> d;
    N = 4; 
    cout<< "The Xmed: " << (a+b+c+d)/N << ".\n";
    cout<< "The standard deviation (σ): " << sqrt((a - Xmed)* (a - Xmed)/4 + (b - Xmed)*(b - Xmed)/4 + (c - Xmed)*(c - Xmed)/4 + (d - Xmed)*(d - Xmed)/4)
    << endl;
    return 0;
}
