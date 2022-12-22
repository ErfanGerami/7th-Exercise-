#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>



char* SameSize(char* num, int WantedSize) {
	int size = strlen(num);
	int shift = WantedSize - size;
	for (int i = size - 1; i >= 0; i--) {
		*(num + i + shift) = *(num + i);
	}
	for (int i = 0; i < shift; i++) {
		*(num + i) = '0';
	}
	*(num + WantedSize) = '\0';
	return num;
}

char* SUM(char* first, char* second) {
	int DoWeHaveAfterWantedSize = 0;
	/////////set to a same size
	int WantedSize;
	if (strlen(first) > strlen(second)) {
		WantedSize = strlen(first);
		second = SameSize(second, WantedSize);

	}
	else {
		WantedSize = strlen(second);
		first = SameSize(first, WantedSize);

	}
	///////////////////

	char* main = (char*)malloc(WantedSize * sizeof(char));
	int DigitSum;
	*(main + WantedSize - 1) = '0';

	for (int i = WantedSize - 1; i >= 0; i--) {
		DigitSum = *(first + i) + *(second + i) + *(main + i) - (3 * 48);
		if (DigitSum >= 10) {
			if (i == 0) {
				main = SameSize(main, WantedSize + 1);
				*(main) = '1';
				DoWeHaveAfterWantedSize = 1;
				*(main + i + 1) = DigitSum - 10 + 48;
			}
			else {
				*(main + i - 1) = '1';
				*(main + i) = DigitSum - 10 + 48;

			}



		}
		else {
			*(main + i) = DigitSum + 48;
			*(main + i - 1) = '0';

		}

		*(main + WantedSize + DoWeHaveAfterWantedSize) = '\0';
	}
	return main;
}

int main() {
	char* first = (char*)malloc(53 * sizeof(char));
	char* second = (char*)malloc(53 * sizeof(char));

	scanf("%s\n%s", first, second);
	printf("%s", SUM(first, second));

}