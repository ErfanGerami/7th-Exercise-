#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


void arrEqual(char arr1[], char  arr2[]) {
	for (int i = 0; i < strlen(arr2); i++) {
		arr1[i] = arr2[i];

	}
	arr1[strlen(arr2)] = '\0';
}
void SameSize(char num[], int size) {
	if (size >= 0) {
		int shift = size - strlen(num);


		for (int i = strlen(num) - 1; i >= 0; i--) {
			num[i + shift] = num[i];

		}
		for (int i = 0; i < shift; i++) {
			num[i] = '0';
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

void SUM(char first[], char second[], char main[]) {
	int IsSubZero = 0;
	int size;
	if (first[0] == '0') {
		arrEqual(main, second);
		return;
	}
	else if (second[0] == '0') {
		arrEqual(main, first);
		return;
	}

	else if (strlen(first) > strlen(second)) {
		size = strlen(first);
		SameSize(second, size);


	}
	else {


		size = strlen(second);
		SameSize(first, size);


	}
	/////////////////////////////////////////////////////////////SameSizing.
	int DigitSum;
	int plus = 0;
	for (int i = size - 1; i >= 0; i--) {
		DigitSum = first[i] + second[i] + plus - (2 * 48);
		plus = DigitSum / 10;
		main[i] = DigitSum % 10 + 48;



	}
	main[size] = '\0';
	if (plus) {
		SameSize(main, size + 1);
		main[0] = plus + 48;

	}




}


void mulBy10Power(char num[], int power) {
	SameSize(num, strlen(num) + power);
	for (int i = power; i < strlen(num); i++) {
		num[i - power] = num[i];
	}
	for (int i = strlen(num) - power; i < strlen(num); i++) {
		num[i] = '0';
	}
	num[strlen(num)] = '\0';

}
void MuLByOnDigit(char num[], int digit, char main[]) {
	int plus = 0;

	int DigitMul;
	for (int i = strlen(num) - 1; i >= 0; i--) {
		DigitMul = plus + (num[i] - 48) * digit;
		plus = DigitMul / 10;
		main[i] = DigitMul % 10 + 48;
	}
	if (plus) {
		main[strlen(num)] = '\0';
		SameSize(main, strlen(num) + 1);
		main[0] = plus + 48;
		main[strlen(num) + 1] = '\0';
	}
	else {
		main[strlen(num)] = '\0';

	}
}


void MUL(char first[], char second[], char main[]) {
	char temp[120];
	char temp2[120];
	for (int i = 0; i < strlen(main); i++) {
		main[i] = '0';
	}
	main[strlen(main) - 2] = '\0';
	int SizeOfFirst = strlen(first);
	for (int i = SizeOfFirst - 1; i >= 0; i--) {
		MuLByOnDigit(second, first[i] - 48, temp);
		mulBy10Power(temp, SizeOfFirst - i - 1);
		SUM(main, temp, temp2);
		arrEqual(main, temp2);



	}

}
int main(void) {
	char first[53];
	char second[53];
	char main[120];
	scanf("%s%s", first, second);
	second[52] = '\0';
	main[119] = '\0';
	first[52] = '\0';
	MUL(first, second, main);
	//arrEqual(second, first);
	printf("%s\n", main);
}