#include <iostream>
#include <time.h>

using namespace std;

int main() {

	srand((unsigned int)time(NULL));
	int bingo[5][5];
	int input;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			bingo[i][j] = i * 5 + j + 1;
		}
	}

	for (int i = 0; i < 100; i++) {
		int randNum1 = rand() % 5;
		int randNum2 = rand() % 5;
		int randNum3 = rand() % 5;
		int randNum4 = rand() % 5;
		int temp = bingo[randNum1][randNum2];
		bingo[randNum1][randNum2] = bingo[randNum3][randNum4];
		bingo[randNum3][randNum4] = temp;
	}

	cout << "=========================================" << endl;
	cout << "|               빙고 게임               |" << endl;
	cout << "=========================================" << endl;

	int bingoCount = 0;

	while (true) {

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (bingo[i][j] == 35)
					cout << (char)bingo[i][j] << "\t";
				else
					cout << bingo[i][j] << "\t";
			}
			cout << endl << endl;
		}

		if (bingoCount >= 5) {
			cout << "=========================================" << endl;
			cout << "|               게임 끝                 |" << endl;
			cout << "=========================================" << endl;
			break;
		}
		else {
			bingoCount = 0;
		}

		cout << "숫자 입력 : ";
		cin >> input;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (bingo[i][j] == input) {
					bingo[i][j] = 35;
				}
			}
		}

		int countCross1 = 0;
		int countCross2 = 0;

		for (int i = 0; i < 5; i++) {
			int countCal = 0;
			int countRow = 0;

			for (int j = 0; j < 5; j++) {
				if (bingo[i][j] == 35) countRow++;
				if (bingo[j][i] == 35) countCal++;
				if (i == j && bingo[i][j] == 35) countCross1++;
				if ((i + j == 4) && bingo[i][j] == 35) countCross2++;
			}

			if (countRow == 5) bingoCount++;
			if (countCal == 5) bingoCount++;
		}

		if (countCross1 == 5) bingoCount++;
		if (countCross2 == 5) bingoCount++;

		system("cls");

		cout << "=========================================" << endl;
		cout << "|          현재 빙고 수 : " << bingoCount << "             |" << endl;
		cout << "=========================================" << endl;

	}


	return 0;
}