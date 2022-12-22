#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
	return  main;



}
int GuesYXxX(char* first, char* buffer) {
	int cnt = 10;
	int sizeOfsecond = strlen(buffer);
	buffer[sizeOfsecond + 1] = '\0';

	while (cnt--) {
		buffer[sizeOfsecond] = 48 + cnt;
		if (Compare(MuLByOnDigit(buffer, cnt), first) <= 0) {
			buffer[sizeOfsecond] = 48 + cnt;
			return cnt;

		}

	}
	return -1;
}
char* SQRT(char* first, int persistanse) {
	first = mulBy10Power(first, persistanse * 2);
	char* reminder = (char*)malloc(256 * sizeof(char));
	char* main = (char*)malloc(256 * sizeof(char));
	char* buffer = (char*)malloc(256 * sizeof(char));

	char* block = (char*)malloc(6 * sizeof(char));

	buffer[0] = '\0';
	int size = strlen(first);
	int ReminderCnt;
	if (size % 2 == 1) {
		reminder[0] = first[0];
		reminder[1] = '\0';
		ReminderCnt = 0;
	}
	else {
		reminder[0] = first[0];
		reminder[1] = first[1];
		reminder[2] = '\0';
		ReminderCnt = 1;
	}
	int cnt = -1;

	int SizeOfReminder;
	int GuesResult;
	while (cnt++, 1) {
		GuesResult = GuesYXxX(reminder, buffer);
		reminder = SuB(reminder, MuLByOnDigit(buffer, buffer[strlen(buffer) - 1] - 48));
		buffer[strlen(buffer) - 1] = 48;
		main[cnt] = GuesResult + 48;
		block[1] = GuesResult % 10 + 48;
		block[0] = (GuesResult / 10) % 10 + 48;
		block[2] = '\0';
		SameSize(block, -1);

		buffer = SUM(buffer, MuLByOnDigit(block, 2));


		SizeOfReminder = strlen(reminder);
		if (reminder[0] == '0') {
			SizeOfReminder--;
		}
		reminder[SizeOfReminder] = first[ReminderCnt + 1];
		reminder[SizeOfReminder + 1] = first[ReminderCnt + 2];
		reminder[SizeOfReminder + 2] = '\0';
		ReminderCnt += 2;
		//SameSize(reminder, -1);
		/*if (strlen(main) > 3) {
			return main;
		}*/
		if (ReminderCnt >= size) {
			main[cnt] = '\0';
			int sizeOfMain = strlen(main);
			main[sizeOfMain + 1] = '\0';
			for (int i = 0; i < persistanse; i++) {
				main[sizeOfMain - i] = main[sizeOfMain - i - 1];
			}
			main[sizeOfMain - persistanse + 1] = '.';
			main[cnt + 1] = '\0';
			for (int i = sizeOfMain; i >= 0; i--) {
				if (main[i] == '0') {
					main[i] = '\0';
				}
				else if (main[i] == '.') {
					main[i] = '\0';
					break;

				}
				else {
					break;
				}
			}

			sizeOfMain = strlen(main);
			for (int i = 0; i < sizeOfMain; i++) {
				if (main[i] == '.') {
					if (i + 10 < sizeOfMain) {
						main[i + 11] = '\0';

					}
					break;
				}
			}

			return main;
		}
	}

}
int main(void) {
	char* first = (char*)malloc(256 * sizeof(char));
	//char* second = (char*)malloc(256 * sizeof(char));
	//char* main = (char*)malloc(256 * sizeof(char));
	scanf("%s", first);
	//scanf("%s", second);
	//////////////////////////


	//main=MuLByOnDigit(first, 3);
	/////////////////////////
	//Setn(first, second, 1, 3);
//	SUB(first, second);
	printf("%s\n", SQRT(first, 11));
}
