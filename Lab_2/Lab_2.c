#include <stdio.h>
//Library for uint64_t
#include <inttypes.h>
#include <math.h>

uint64_t addition(uint64_t a, uint64_t b, uint64_t m) {
	//Если условие выполняется, то можно спокойно вычитать
	if (a < (m - b)) {
		return(a + b);
	} else { //Иначе легкая математика
		return(m - ((m - a) + (m - b)));
	}
}

uint64_t multiplication(uint64_t multA, uint64_t multB, uint64_t module) {
	uint64_t bitChecker;
	uint64_t multiplicationResult = 0;
	bitChecker = (uint64_t) pow(2,63);
	printf("%lu\n", bitChecker);
	int done = 0;
	/*while (!(bitChecker & multA)) {
		while ("Have iter\n");
		bitChecker = bitChecker >> 1;
	}*/
	while (bitChecker) {
		if (multA & bitChecker) { //Проверь, сначала умножать или потом умножать
			multiplicationResult = addition(multiplicationResult, multB, module);
			multiplicationResult = addition(multiplicationResult, multiplicationResult, module);
			printf("Check result 1: %lu\n", multiplicationResult);
		} else {
			multiplicationResult = addition(multiplicationResult, multiplicationResult, module);
			printf("Check result 0 : %lu\n", multiplicationResult);
		}
		bitChecker = bitChecker >> 1;
		printf("Checker: %lu\n", bitChecker);
	}

	return multiplicationResult;


}

int main() {
	uint64_t m, a, b;
	//Just for test
	printf("uint64_t size: %lu\n",sizeof(a));
	
	scanf("%lu", &m);
	scanf("%lu", &a);
	scanf("%lu", &b);
	//Input validation
	printf("M: %lu\nA: %lu\nB: %lu\n", m, a, b);
	printf("Sum Result: %lu\n", addition(a, b, m));
	printf("Mult Result: %lu\n", multiplication(a, b, m));
	
	return 0;
}