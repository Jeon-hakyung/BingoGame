// ������� Ŭ���� 5�� �̻� ����ؼ� ����� 
#include <iostream>
#include <time.h> //������ ����ϱ� ���� ������� 
using namespace std;
// ȥ�� �ϴ� ���� �ƴ϶� ��ǻ�Ͷ� ����ϴ� �������

void GameTable(int* table);
void Show(int* table);
void UserSelect(int* usertable, int* comtable);

class BinGo {

};

int main() {
	
	srand(time(NULL)); //���� ����
	rand(); //���� �ʱ�ȭ
	
	//���̺� �迭�� ���� ���� ���� 
	int UserNumber[25]; //������� ����'
	int UserBinGo = 0;

	int ComputerNumber[25]; // ��ǻ���� ���� 
	int ComputerBinGo = 0;

	// ������ �ݺ������� �� �� �ְ� �����. ���� ���� ���� ����
	bool Replaying = true;

	//���� ���� 
	while (Replaying)
	{
		//�÷���.
		GameTable(UserNumber);
		GameTable(ComputerNumber);

		while (UserBinGo < 5 && ComputerBinGo < 5) //������ �ʵ��� ���ѹݺ��ϰ� ���ִ� �� 
		{
			Show(UserNumber);
			cout << endl;
			Show(ComputerNumber);
			cout << endl;
			UserSelect(UserNumber, ComputerNumber);
		}


		// ���� ���� ���� 
		cout << "1. �� ����, 2. ���� ����: ";
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

	cout << "1���� 25 �� ���ڸ� �ϳ� �����ϼ���: " << endl;
	cin >> Select;

	//���̺� ��ü�� �˻�
	for (int i = 0; i < 25; i++) {
		if (Select == usertable[i])
		{
			//0�� �̹� ���̺��� ���õ� ĭ�� �ǹ��Ѵ�. 
			usertable[i] = 0;

			for (int j = 0; j < 25; j++) {
				if (Select == comtable[j]) {
					comtable[j] = 0;
					break;
				}

			}
			break; 
		}
		// ������ ���ڸ� ã�� �� �� ��� 
		if (i == 24) //���������� for���� �������� ���� ���� ��� 
		{
			cout << "���ڸ� �ٽ� ����ּ���." << endl;
			
		}
	}
}