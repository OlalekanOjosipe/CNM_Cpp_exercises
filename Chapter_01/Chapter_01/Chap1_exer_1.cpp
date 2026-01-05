// Example program
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string mystr;
    int first_number = 0;
    int second_number = 0;
    
    
    cout << "Enter your first number: ";
    getline(cin, mystr); 
    stringstream(mystr) >> first_number;
    cout<< "Enter your second number: ";
    getline(cin, mystr); 
    stringstream(mystr) >> second_number;
    cout << "Your swapped numbers are "
    << second_number<< " " <<   first_number
    << endl;
    return 0;
}
