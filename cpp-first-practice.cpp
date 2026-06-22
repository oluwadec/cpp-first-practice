#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
    cout << fixed                 << setprecision(2);
	cout << sqrt(64)              << endl;
	cout << round(2.6)            << endl;
	cout << log(2)                << endl;
	cout << max(5, 10)            << endl;
	cout << min(5, 10)            << endl;
	cout << sqrt(225)             << endl;
	cout << sqrt(255) + sqrt(100) << endl;
	return 0;
}