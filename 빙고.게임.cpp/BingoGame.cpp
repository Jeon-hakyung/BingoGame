#include <iostream>
#include <time.h>
using namespace std;

class Random { //������ �߻���Ű�� class 
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

class MixNumber { //���ڸ� �����ִ� Ŭ������ ������ݴϴ�.
public:
	
	friend Random::Random();
	MixNumber(); 
	

};

MixNumber::MixNumber() {
	
	 // ���ڸ� ���� �� �� ��±��� ���ִ� Ŭ����. 
		int Temp, Number1, Number2;
		for (int i = 0; i < 100; ++i) {

			int BingoNumber[25] = {}; //�̰� �ٽ� ������Ҽ�����

			Number1 = rand() % 25;
			Number2 = rand() % 25;

			Temp = BingoNumber[Number1];

			while (true) {
				system("cls"); //������� �� �ڿ� ȭ���� �����ϰ� ����

				int BingoNumber[25] = {};
				// ���ڸ� 5x5�� ����Ѵ�.
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
			system("cls"); //������� �� �ڿ� ȭ���� �����ϰ� ����

			int BingoNumber[25] = {};
			// ���ڸ� 5x5�� ����Ѵ�.
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
				cout << "����!" << endl;
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
			
			bool bAcc = true; // �ߺ�üũ�� ���ٰ���.

			
			// ��� ���ڸ� ���ʴ�� �˻��ؼ� 
			// �Է��� ���ڿ� ���� ���ڰ� �ִ� ��� *���� ����
			int BingoNumber[25] = {};
			for (int i = 0; i < 25; ++i)
			{  // ���� ���ڰ� ���� ���
				
				if (iInput == BingoNumber[i]) {

					bAcc = false; // �ߺ��� �ִ� ���� true.
					// �׷��ϱ� ���� ���� false 

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
					// ���� �� ������ �����ش�. 
					if (BingoNumber[i * 5 + j] == INT_MAX)
						++iStar1;
					//���� �� ������ �����ش�. 
					if (BingoNumber[j * 5 + i] == INT_MAX)
						++iStar2;
				}

				if (iStar1 == 5)
					++iBingo;

				if (iStar2 == 5)
					++iBingo;
				
			}

			// ���� ���-> ������ �ϴ� �밢�� üũ
			iStar1 = 0;
			for (int i = 0; i < 25; i += 6) {

				if (BingoNumber[i] == INT_MAX)
					++iStar1;
			}
			if (iStar1 == 5)
				++iBingo;

			// ������ �ϴ�-> ���� ��� �밢�� üũ
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
	int BingoNumber[25] = {}; //�迭�� �����ϰ�, �� �ȿ� ������ �־���. 
	for (int i = 0; i < 25; ++i) {
		BingoNumber[i] = i + 1;
		
	}
	MixNumber g;



	int iBingo = 0; //���� ������ üũ�� ��� �Ѵ�. 
	cout << "BinGo Line: " << iBingo << endl;
}