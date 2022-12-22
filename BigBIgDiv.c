

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* baghi;

void arrEqual(char* arr1, char* arr2) {
	for (int i = 0; i < strlen(arr2); i++) {
		arr1[i] = arr2[i];

	}
	arr1[strlen(arr2)] = '\0';
}
void SameSize(char* num, int size) {
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


void change(char* first, char* second) {
	char temp;
	for (int i = 0; i < strlen(first); i++) {
		temp = first[i];
		first[i] = second[i];
		second[i] = temp;

	}
}

char* SUM(char* first, char* second) {
	char* main = (char*)malloc(256 * sizeof(char));;
	int IsSubZero = 0;
	int size;
	if (first[0] == '0') {
		arrEqual(main, second);
		return main;
	}
	else if (second[0] == '0') {
		arrEqual(main, first);
		return main;
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

	return main;


}
char* SuB(char* firstM, char* second) {
	char* first = (char*)malloc(256 * sizeof(char));
	arrEqual(first, firstM);

	int IsSubZero = 0;
	int size;
	if (strcmp(first, second) == 0) {
		first[0] = '0';
		first[1] = '\0';
		return first;
	}
	if (strlen(first) > strlen(second)) {
		size = strlen(first);
		SameSize(second, size);


	}
	else {
		if (strlen(first) == strlen(second)) {
			size = strlen(second);
			if (strcmp(first, second) < 0) {

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

	return first;

}


char* mulBy10Power(char* numM, int power) {
	char* num = (char*)malloc(256 * sizeof(char));
	arrEqual(num, numM);

	SameSize(num, strlen(num) + power);
	for (int i = power; i < strlen(num); i++) {
		num[i - power] = num[i];
	}
	for (int i = strlen(num) - power; i < strlen(num); i++) {
		num[i] = '0';
	}
	num[strlen(num)] = '\0';
	return num;

}
char* MuLByOnDigit(char* num, int digit) {
	char* main = (char*)malloc(256 * sizeof(char));



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
	if (main[0] == '0') {
		main[1] = '\0';
	}
	return main;
}


int Compare(char* first, char* second) {
	if (strlen(first) > strlen(second)) {
		return 1;
	}
	else if (strlen(first) < strlen(second)) {
		return -1;
	}
	else {
		return strcmp(first, second);
	}
}

int gues(char* first, char* second) {

	for (int i = 1; i <= 10; i++) {
		if (Compare(first, MuLByOnDigit(second, i)) < 0) {
			return i - 1;
			break;
		}
	}
}

char* DIV(char* first, char* second) {


	char* main = (char*)malloc(256 * sizeof(char));
	char* temp = (char*)malloc(256 * sizeof(char));
	temp[0] = '1';
	temp[1] = '\0';
	if (Compare(first, second) < 0) {
		main[0] = '0';
		main[1] = '\0';
		return main;
	}
	int DivTimes = strlen(first) - strlen(second);
	int GuesResult;
	for (int i = 0; i <= DivTimes; i++) {

		GuesResult = gues(first, mulBy10Power(second, DivTimes - i));
		main[i] = GuesResult + 48;
		first = SuB(first, MuLByOnDigit(mulBy10Power(second, DivTimes - i), GuesResult));


	}
	main[DivTimes + 1] = '\0';


	while (*main == '0') {
		main++;
	}
	baghi = first;
	return  main;




}
int main(void) {
	int Number = 100;
	char* first = (char*)malloc(256 * sizeof(char));
	baghi = (char*)malloc(256 * sizeof(char));
	char* second = (char*)malloc(256 * sizeof(char));
	char* main = (char*)malloc(256 * sizeof(char));
	char* main2 = (char*)malloc(256 * sizeof(char));
	char* zeroes = (char*)malloc(256 * sizeof(char));
	scanf("%s\n", first);
	scanf("%s", second);
	//////////////////////////


	//main=MuLByOnDigit(first, 3);
	/////////////////////////
	//Setn(first, second, 1, 3);
//	SUB(first, second);
	main = DIV(first, second);
	if (main[0] == '0') {
		baghi = first;

	}
	if (baghi[0] == '0') {
		printf("%s\n", main);
		return 0;
	}
	main2 = DIV(mulBy10Power(baghi, Number), second);
	int Msize = strlen(main2);
	int size = strlen(main2);
	while (size--) {
		if (main2[size] == '0')
			main2[size] = '\0';
		else
			break;

	}
	int last = 0;
	for (int i = 0; i < Number - Msize; i++) {
		zeroes[i] = '0';


	}
	zeroes[Number - Msize] = '\0';



	printf("%s.%s%s\n", main, zeroes, main2);
}
