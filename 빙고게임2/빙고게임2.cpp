#include <iostream>
using namespace std;

void Init(); // 1~25까지의 숫자를 준비함
void Shuffle(int count); //1부터 25까지 준비한 숫자를 랜덤으로 섞음 
void ShowNumbers(); // 화면에 숫자를 출력함
int GetInput; //숫자를 입력받는 과정
void SetMarking(int num); //입력받은 숫자를 마킹함
void CountBingo(); //완성된 줄 수를 계산함 


int main() {

	void Init();
	Shuffle(100);
	int BinGoCount;

	while (true)
	{
		ShowNumbers();
		SetMarking(GetInput());
		CountBingo();

		if (BinGoCount >= 5) break;

	}

	ShowNumbers();
	cout << "빙고!" << endl;

}

void Init() {

	for (int i = 0; i < 25; i++)
		Numbers[i] = i + 1;
}

void Shuffle(int count) {
	
	srand(time(NULL));

	for (int i = 0; i < count; i++) {

		int temp;
		int nRandom1 = rand() % 25;
		int nRandom2 = rand() % 25;

		temp = Numbers[nRandom1];
		Numbers[nRandom1] = Numbers[nRandom2];
		Numbers[nRandom2] = temp;

	}
}

void ShowNumbers() {

	system("cls");
	for (int i = 0; i < 25; i++) {
		if (i % 5 == 0) cout << endl;
		if (Numbers[i] == Marking)
			cout << (char)Numbers[i] << '\t';
	}
}