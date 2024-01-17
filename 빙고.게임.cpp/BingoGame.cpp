#include <iostream>
#include <time.h>
using namespace std;

class Random { //난수를 발생시키는 class 
public:
	Random();
	int next();

};

Random::Random() {
	srand((unsigned int)time(0));
}

int Random::next() {
	return rand();
}

class MixNumber { //숫자를 섞어주는 클래스를 만들어줍니다.
public:
	
	friend Random::Random();
	MixNumber(); 
	

};

MixNumber::MixNumber() {
	
	 // 숫자를 섞고 난 뒤 출력까지 해주는 클래스. 
		int Temp, Number1, Number2;
		for (int i = 0; i < 100; ++i) {

			int BingoNumber[25] = {}; //이걸 다시 선언안할순없나

			Number1 = rand() % 25;
			Number2 = rand() % 25;

			Temp = BingoNumber[Number1];

			while (true) {
				system("cls"); //섞어놓고 난 뒤에 화면을 깨끗하게 해줌

				int BingoNumber[25] = {};
				// 숫자를 5x5로 출력한다.
				for (int i = 0; i < 5; ++i) {
					for (int j = 0; j < 5; ++j) {
						if (BingoNumber[i * 5 + j] == INT_MAX)
							cout << "*\t";

						else
							cout << BingoNumber[i * 5 + j] << "\t";
					}

					cout << endl;

				}

			}

		}

	
}

class Bingo {
public:

	Bingo() { 
		//friend MixNumber::MixNumber();
		while (true) {
			system("cls"); //섞어놓고 난 뒤에 화면을 깨끗하게 해줌

			int BingoNumber[25] = {};
			// 숫자를 5x5로 출력한다.
			for (int i = 0; i < 5; ++i) {
				for (int j = 0; j < 5; ++j) {
					if (BingoNumber[i * 5 + j] == INT_MAX)
						cout << "*\t";

					else
						cout << BingoNumber[i * 5 + j] << "\t";
				}

				cout << endl;

			}
			
		}

	}
};

class BingoExit {
public:
	BingoExit() {

		while (true) {
			int iBingo = 0;
			if (iBingo >= 5)
				cout << "빙고!" << endl;
			break; 
		}


	}
};

class Bingo2 {
public:
	Bingo2() {
		
		while (true) {
			int iInput;
			cin >> iInput;

			if (iInput == 0)
				break;

			else if (iInput < 1 || iInput>25)
				continue;
			
			bool bAcc = true; // 중복체크를 해줄거임.

			
			// 모든 숫자를 차례대로 검사해서 
			// 입력한 숫자와 같은 숫자가 있는 경우 *으로 변경
			int BingoNumber[25] = {};
			for (int i = 0; i < 25; ++i)
			{  // 같은 숫자가 있을 경우
				
				if (iInput == BingoNumber[i]) {

					bAcc = false; // 중복이 있는 경우는 true.
					// 그러니까 없는 경우는 false 

					BingoNumber[i] = INT_MAX;

					break;

				}

			}

			if (bAcc)
				continue;

			int iBingo = 0;

			int iStar1 = 0, iStar2 = 0;
			for (int i = 0; i < 5; ++i)
			{
				iStar1 = iStar2 = 0;
				for (int j = 0; j < 5; ++j)
				{
					// 가로 별 개수를 구해준다. 
					if (BingoNumber[i * 5 + j] == INT_MAX)
						++iStar1;
					//세로 별 개수를 구해준다. 
					if (BingoNumber[j * 5 + i] == INT_MAX)
						++iStar2;
				}

				if (iStar1 == 5)
					++iBingo;

				if (iStar2 == 5)
					++iBingo;
				
			}

			// 왼쪽 상단-> 오른쪽 하단 대각선 체크
			iStar1 = 0;
			for (int i = 0; i < 25; i += 6) {

				if (BingoNumber[i] == INT_MAX)
					++iStar1;
			}
			if (iStar1 == 5)
				++iBingo;

			// 오른쪽 하단-> 왼쪽 상단 대각선 체크
			for (int i = 4; i <= 20; i += 4)
			{
				if (BingoNumber[i] == INT_MAX)
					++iStar1;
			}
			if (iStar1 == 5)
				++iBingo;
		}
		


		
	}
};

int main() {

	
	Random r;
	srand((unsigned int)time(0));
	int BingoNumber[25] = {}; //배열을 선언하고, 그 안에 난수를 넣어줌. 
	for (int i = 0; i < 25; ++i) {
		BingoNumber[i] = i + 1;
		
	}
	MixNumber g;



	int iBingo = 0; //빙고 개수를 체크해 줘야 한다. 
	cout << "BinGo Line: " << iBingo << endl;
}