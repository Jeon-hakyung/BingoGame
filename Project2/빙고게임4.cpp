#include <iostream>
#include <time.h> //Ÿ�����
using namespace std;
//����� ���ΰ��� ���� ���ü�������. 
int main() {
	
	srand((unsigned int)time(0));

	int iNumber[25] = {};
	// 2���� �迭�� ������ 2�� for���� �����
	
	//1~25���� ���ڸ� �־��ش�
	for (int i = 0; i < 25; ++i) {
		iNumber[i] = i + 1;
	}

	//���ڸ� �����ش�.
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; ++i) {
		
		idx1 = rand() % 25;
		idx2 = rand() & 25;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}
	// ���� ������ üũ�� ��� ��

	int iBingo = 0; 


	while (true)
	{
		system("cls"); // ������� �� �ڿ� ȭ���� �����ϰ� �ϴ� ����

		// ���ڸ� 5x5�� ����Ѵ�
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (iNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";

				else
					cout << iNumber[i * 5 + j] << "\t";
				// ���� �� �׾���� �� ���ϱ� ���ϱ� ���� �� ����?

			}

			cout << endl;
		}
		cout << "Bingo Line: " << iBingo << endl;

		// �ټ��� 5 �̻��� ��� ������ �����Ѵ�.
		if (iBingo >= 5)
			cout << "����!" << endl;
			break;
		
			
			
			cout << "���ڸ� �Է��ϼ���. 0�� ������ ����˴ϴ�.";
		int iInput;
		cin >> iInput; 


		if (iInput == 0)
			break;

		else if (iInput < 1 || iInput>25)
			continue;

		bool bAcc = true; // �ߺ�üũ�� ���ٰ��� 
		
		// ��� ���ڸ� ���ʴ�� �˻��ؼ� �Է��� ���ڿ� ���� ���ڰ� �ִ����� üũ
		for (int i = 0; i < 25; ++i)
		{	// ���� ���ڰ� ���� ���
			if (iInput == iNumber[i]) {

				bAcc = false; //�ֳĸ� �ߺ��� �ִ� ��츦 true��� �����ϱ�
				// ���� ���� false�� �����ߵ�. 
				
				// ���ڸ� *�� �����ϱ� ���� Ư���� ���� INT_MAX�� ���ش�.
				iNumber[i] = INT_MAX;

				// ���̻� �ٸ� ���ڸ� ã�ƺ� �ʿ䰡 �����Ƿ� for���� Ż���Ѵ�. 
				break; 
			}
		}

		// bAcc ������ true�� ��� �ߺ��� ���ڸ� �Է��ؼ� ���ڸ� *�� 
		// �ٲ��� �������Ƿ� �ٽ� �Է¹ް� continue�� ���ִ� ���̴�. 

		if (bAcc)
			continue;

		//���� �� ���� üũ�ϴ� ���� �Ź� ���ڸ� �Է��� ������ 
		// ���� ī��Ʈ�� �� ����. �׷��Ƿ� iBingo ������ �Ź� 0���� ���� 
		// �ʱ�ȭ�ϰ� ���Ӱ� �� ���� �����ֵ��� �Ѵ�. 

		iBingo = 0;

		// ����, ���� �� ���� �����ش�.
		int iStar1 = 0, iStar2 = 0;
		for (int i = 0; i < 5; ++i)
		{
			// ������ �� �� �� �ʱ�ȭ �ϱ� ���� �̸� �ʱ�ȭ�� �ص�. 
			iStar1 = iStar2 = 0;
			for (int j = 0;j < 5; ++j)
			{
				//���� �� ������ �����ش�
				if (iNumber[i * 5 + j] == INT_MAX)
					++iStar1;
				// ���� �� ������ �����ش�
				if (iNumber[j * 5 + i] == INT_MAX)
					++iStar2;
			}

			// j for���� ���������� ���� ������ * ������ �����
			// iStar1 ������ ���� �ȴ�.  iStar1 ���� 5�̸� 
			// ��� *�̶�� �ǹ��̹Ƿ� ���� �� ī��Ʈ�� �߰����ش�.

			if (iStar1 == 5)
				++iBingo;

			if (iStar2 == 5)
				++iBingo;
		}

		// ���� ���-> ������ �ϴ� �밢�� üũ
		iStar1 = 0;
		for (int i = 0; i < 25; i += 6)
		{
			if (iNumber[i] == INT_MAX)
				++iStar1;
		}
		if (iStar1 == 5)
			++iBingo;

		//������ �ϴ�-> ���� ��� �밢�� üũ
		for (int i = 4; i <= 20; i += 4)
		{
			if (iNumber[i] == INT_MAX)
				++iStar1;
		}
		if (iStar1 == 5)
			++iBingo;
	}

	return 0;

}