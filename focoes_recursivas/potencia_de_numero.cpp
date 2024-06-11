#include <iostream>
using namespace std;

int power(int b, int n) {
	if (n == 0) {
		return 1;
	} else {
		return b * power(b, n - 1);
	}
}

int main() {
    int b = 2, n = 3;
    cout << "Potência: " << power(b, n) << endl; 
    return 0;
}
