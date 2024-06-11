#include <iostream>

int mdc(int a, int b) {
	if (b == 0)
		return a;
	else
		return mdc(b, a % b);
}

int main() {
	int num1, num2;
	std::cout << "Digite dois números inteiros: ";
	std::cin >> num1 >> num2;
	std::cout << "O MDC de " << num1 << " e " << num2 << " é " << mdc(num1, num2) << std::endl;
	return 0;
}
