// 빙고게임 클래스 5개 이상 사용해서 만들기 
#include <iostream>
#include <time.h> //랜덤을 사용하기 위한 헤더파일 
using namespace std;
// 혼자 하는 것이 아니라 컴퓨터랑 대결하는 빙고게임

void GameTable(int* table);
void Show(int* table);
void UserSelect(int* usertable, int* comtable);

class BinGo {

};

int main() {
	
	srand(time(NULL)); //랜덤 선언
	rand(); //랜덤 초기화
	
	//테이블 배열과 빙고 변수 선언 
	int UserNumber[25]; //사용자의 숫자'
	int UserBinGo = 0;

	int ComputerNumber[25]; // 컴퓨터의 숫자 
	int ComputerBinGo = 0;

	// 게임을 반복적으로 할 수 있게 만들기. 게임 진행 변수 선언
	bool Replaying = true;

	//게임 진행 
	while (Replaying)
	{
		//플레이.
		GameTable(UserNumber);
		GameTable(ComputerNumber);

		while (UserBinGo < 5 && ComputerBinGo < 5) //끝나지 않도록 무한반복하게 해주는 것 
		{
			Show(UserNumber);
			cout << endl;
			Show(ComputerNumber);
			cout << endl;
			UserSelect(UserNumber, ComputerNumber);
		}


		// 게임 종료 선택 
		cout << "1. 새 게임, 2. 게임 종료: ";
		cin >> Replaying;

	}

	

	return 0;
}

void GameTable(int* table) {
	int i = 0;
	for (i = 0; i < 25; i++)
	{
		table[i] = i + 1;
	}

	int nSrc;
	int nDest;
	int nTemp;

	for (int i = 0; i < 250; i++)
	{
		nSrc = rand() % 25;
		nDest = rand() % 25;
		
		nTemp = table[nSrc];
		table[nSrc] = table[nDest];
		table[nDest] = nTemp;
		
	}
}

void Show(int* table) {

	cout << "========================================" << endl;
	for (int i = 0; i < 25; i++) {

		cout << "|  " << table[i] << "\t|";
		
		if (i % 5 == 4) {
			cout << endl;
			cout << "========================================" << endl;
		}
	}
}

void UserSelect(int* usertable, int* comtable) {

	int Select;

	cout << "1에서 25 중 숫자를 하나 선택하세요: " << endl;
	cin >> Select;

	//테이블 전체를 검사
	for (int i = 0; i < 25; i++) {
		if (Select == usertable[i])
		{
			//0은 이미 테이블에서 선택된 칸을 의미한다. 
			usertable[i] = 0;

			for (int j = 0; j < 25; j++) {
				if (Select == comtable[j]) {
					comtable[j] = 0;
					break;
				}

			}
			break; 
		}
		// 선택한 숫자를 찾지 못 한 경우 
		if (i == 24) //마지막까지 for문의 안쪽으로 들어가지 못한 경우 
		{
			cout << "숫자를 다시 골라주세요." << endl;
			
		}
	}
}