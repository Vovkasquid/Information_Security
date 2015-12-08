#include <stdio.h>
//Library for uint64_t
#include <inttypes.h>

int main() {
	uint64_t m, a, b;
	//Just for test
	printf("uint64_t size: %lu\n",sizeof(a));
	
	scanf("%lu", &m);
	scanf("%lu", &a);
	scanf("%lu", &b);
	//Input validation
	printf("M: %lu\nA: %lu\nB: %lu\n", m, a, b);
	//Если условие выполняется, то можно спокойно вычитать
	if (a < (m - b)) {
		printf("Result of adding: %lu\n", a + b);
	} else { //Иначе легкая математика
		printf("Result of adding: %lu\n", m - ((m - a) + (m - b)));
	}
	return 0;
}