#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int main() {

string mystr;
    
    int x = 0;
    
    cout<< "Enter an integer: ";
    cin >> x;

    if (x % 2 != 0) {   // conditional statement and conditional operator

        cout<< "The number is odd"<< endl;
    }
    else {
    cout<< "The integer is even" << endl;
    }
    return 0;

}
