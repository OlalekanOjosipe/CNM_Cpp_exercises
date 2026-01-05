// Exercise 2
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string mystr;
    int number_of_days = 0;
    
    cout << "Enter the total number of days: ";
    getline(cin, mystr); 
    stringstream(mystr) >> number_of_days;
    cout<< "The year is: "
    << number_of_days / 365  << ".\n"
    << "The month is: " << number_of_days / 30  << ".\n"
    << "The week is: " << number_of_days / 7 << "."
    << endl;
    return 0;
}
