#include <stdio.h>
//Library for uint64_t
#include <inttypes.h>
#include <math.h>

uint64_t addition(uint64_t a, uint64_t b, uint64_t m) {
	//Если условие выполняется, то можно спокойно вычитать
	if (a < (m - b)) {
		return (a + b);
	} else { //Иначе коэффициент подгона
		return (a + b - m);
	}
}

uint64_t multiplication(uint64_t multA, uint64_t multB, uint64_t module) {
	uint64_t bitChecker;
	uint64_t multiplicationResult = 0;
	bitChecker = (uint64_t) pow(2,63);
	//printf("%lu\n", bitChecker);
	int done = 0;

	while (bitChecker) {
		if (multA & bitChecker) { //Сначала на 2, потом + В
			multiplicationResult = addition(multiplicationResult, multiplicationResult, module);
			//printf("bit = 1, result after B+B: %lu\n", multiplicationResult);
			multiplicationResult = addition(multiplicationResult, multB, module);
			//printf("result bit = 1: %lu\n", multiplicationResult);
		} else {
			multiplicationResult = addition(multiplicationResult, multiplicationResult, module);
			//printf("result bit = 0 : %lu\n", multiplicationResult);
		}
		bitChecker = bitChecker >> 1;
		//printf("Checker: %lu\n", bitChecker);
	}

	return multiplicationResult;
}

uint64_t modPow(uint64_t powA, uint64_t module, uint64_t power) {
	uint64_t i;
	uint64_t result;
	for (i = 0; i < power; ++i) {
		result = multiplication(powA, powA, module);
	}
	return result;
}

int main() {
	uint64_t m, a, b, power;
	//Just for test
	printf("uint64_t size: %lu\n",sizeof(a));
	
	printf("Module: ");
	scanf("%lu", &m);
	printf("\nA: ");
	scanf("%lu", &a);
	printf("\nB: ");
	scanf("%lu", &b);
	printf("\nPower: ");
	scanf("%lu", &power);
	printf("\n");
	//Input validation
	printf("M: %lu\nA: %lu\nB: %lu\n", m, a, b);
	printf("Sum Result: %lu\n", addition(a, b, m));
	printf("Mult Result: %lu\n", multiplication(a, b, m));
	printf("Pow Result: %lu\n", modPow(a, m, power));
	
	return 0;
}