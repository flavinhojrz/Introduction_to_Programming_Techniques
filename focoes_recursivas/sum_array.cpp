#include <iostream>
using namespace std;

int sumArray(int arr[], int n) {
	if (n == 0) {
		return 0;
	} else {
		return arr[n - 1] + sumArray(arr, n - 1);
	}
}

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	int n = 5;
	cout << "Somatório: " << sumArray(arr, n) << endl; 
	return 0;
}
