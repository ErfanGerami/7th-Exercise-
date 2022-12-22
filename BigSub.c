#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


void SameSize(char num[], int size) {
	if (size > 0) {
		int shift = size - strlen(num);
		for (int i = strlen(num) - 1; i >= 0; i--) {
			num[i + shift] = num[i];
			if (i < shift) {
				num[i] = '0';
			}
		}
		num[size] = '\0';
	}
	else {
		int counter = 0;
		while (num[counter] == '0') {
			counter++;
		}
		for (int i = counter; i < strlen(num); i++) {
			num[i - counter] = num[i];
		}

		num[strlen(num) - counter] = '\0';
	}
}

void change(char first[], char  second[]) {
	char temp;
	for (int i = 0; i < strlen(first); i++) {
		temp = first[i];
		first[i] = second[i];
		second[i] = temp;

	}
}

void SUB(char first[], char second[]) {
	int IsSubZero = 0;
	int size;

	if (strlen(first) > strlen(second)) {
		size = strlen(first);
		SameSize(second, size);


	}
	else {
		if (strlen(first) == strlen(second)) {
			size = strlen(second);
			if (strcmp(first, second) == -1) {

				change(first, second);
				IsSubZero = 1;
			}
		}
		else {
			size = strlen(second);
			SameSize(first, size);
			IsSubZero = 1;
			change(first, second);
		}
	}
	/////////////////////////////////////////////////////////////SamSize And First is bigger.
	int DigitSub;
	for (int i = size - 1; i >= 0; i--) {
		DigitSub = first[i] - second[i];
		while (DigitSub < 0) {
			first[i - 1]--;
			DigitSub += 10;
		}
		first[i] = DigitSub + 48;



	}

	SameSize(first, -1);

	if (IsSubZero) {
		SameSize(first, strlen(first) + 1);
		first[0] = '-';
	}



}
int main(void) {
	char first[53];
	char second[53];
	scanf("%s%s", first, second);
	SUB(first, second);
	printf("%s\n", first);
}