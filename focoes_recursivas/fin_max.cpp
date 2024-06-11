#include <iostream>
using namespace std;

int findMax(int arr[], int n) {
	if (n == 1) {
		return arr[0];
	} else {
		int maxRest = findMax(arr, n - 1);
		return (arr[n - 1] > maxRest) ? arr[n - 1] : maxRest;
	}
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    cout << "Maior valor: " << findMax(arr, n) << endl; 
    return 0;
}
