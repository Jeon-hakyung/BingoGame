#include <iostream>
using namespace std;

void Init(); // 1~25������ ���ڸ� �غ���
void Shuffle(int count); //1���� 25���� �غ��� ���ڸ� �������� ���� 
void ShowNumbers(); // ȭ�鿡 ���ڸ� �����
int GetInput; //���ڸ� �Է¹޴� ����
void SetMarking(int num); //�Է¹��� ���ڸ� ��ŷ��
void CountBingo(); //�ϼ��� �� ���� ����� 


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
	cout << "����!" << endl;

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