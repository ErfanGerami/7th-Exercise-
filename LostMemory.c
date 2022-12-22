#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* f(int n) {
	int* p = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		*(p + i) = (int)pow(i, 2);
	}
	return p;

}

int main() {
	int n;
	scanf("%d", &n);
	int* b = f(n);
	for (int i = 0; i < n; i++) {
		printf("%d ", b[i]);
	}
}