#include <iostream>
using namespace std;

int countChars(const char str[], int index) {
	if (str[index] == '\0') {
		return 0;
	} else {
		return 1 + countChars(str, index + 1);
	}
}

int main() {
	const char str[] = "hello";
	cout << "Número de caracteres: " << countChars(str, 0) << endl; 
	return 0;
}
