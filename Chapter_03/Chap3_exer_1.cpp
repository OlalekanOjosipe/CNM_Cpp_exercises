#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int main() {

string mystr;
    
    double x, sum = 0, sumSquares = 0;
// the for loop to request multiple entries (six numbers)
for (int i = 0; i < 6; i++) {
    cout << "Enter number " << i + 1 << ": ";
    cin >> x;

    sum += x;
    sumSquares += x * x;
}
    double Xmed = sum/6;
    double half_dev = sumSquares/6;
    cout<< "The Xmed: " << Xmed << "\n";
    cout<< "The standard deviation (σ): " << sqrt(half_dev - (Xmed*Xmed)) << endl;
    return 0;

}
