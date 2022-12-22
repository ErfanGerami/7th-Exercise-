#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
void sort(int* p, int size) {
	int temp;
	for (int i = 0; i < size - 1; i++) {
		for (int j = size - 1; j > i; j--) {
			if (*(p + j - 1) < *(p + j)) {
				temp = *(p + j - 1);
				*(p + j - 1) = *(p + j);
				*(p + j) = temp;
			}

		}
	}

}
int main(void)
{



	int n, k;

	int counter = 0;
	scanf("%d %d", &n, &k);
	int* p = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", (p + i));
	}
	sort(p, n);
	for (int i = 0; i < n; i++) {
		if (*(p + i) < *(p + k - 1)) {
			break;
		}
		if (*(p + i) != 0)
			counter++;
	}

	printf("%d", counter);
}
