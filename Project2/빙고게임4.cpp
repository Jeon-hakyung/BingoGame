#include <iostream>
#include <time.h> //타임헤더
using namespace std;
//빙고는 열두개의 줄이 나올수가있죠. 
int main() {
	
	srand((unsigned int)time(0));

	int iNumber[25] = {};
	// 2차원 배열은 무조건 2중 for문을 써야함
	
	//1~25까지 숫자를 넣어준다
	for (int i = 0; i < 25; ++i) {
		iNumber[i] = i + 1;
	}

	//숫자를 섞어준다.
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; ++i) {
		
		idx1 = rand() % 25;
		idx2 = rand() & 25;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}
	// 빙고 개수를 체크해 줘야 함

	int iBingo = 0; 


	while (true)
	{
		system("cls"); // 섞어놓고 난 뒤에 화면을 깨끗하게 하는 과정

		// 숫자를 5x5로 출력한다
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (iNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";

				else
					cout << iNumber[i * 5 + j] << "\t";
				// 세로 줄 그어놓은 것 곱하기 더하기 가로 줄 개수?

			}

			cout << endl;
		}
		cout << "Bingo Line: " << iBingo << endl;

		// 줄수가 5 이상일 경우 게임을 종료한다.
		if (iBingo >= 5)
			cout << "빙고!" << endl;
			break;
		
			
			
			cout << "숫자를 입력하세요. 0을 누르면 종료됩니다.";
		int iInput;
		cin >> iInput; 


		if (iInput == 0)
			break;

		else if (iInput < 1 || iInput>25)
			continue;

		bool bAcc = true; // 중복체크를 해줄거임 
		
		// 모든 숫자를 차례대로 검사해서 입력한 숫자와 같은 숫자가 있는지를 체크
		for (int i = 0; i < 25; ++i)
		{	// 같은 숫자가 있을 경우
			if (iInput == iNumber[i]) {

				bAcc = false; //왜냐면 중복이 있는 경우를 true라고 했으니까
				// 없는 경우는 false로 잡아줘야됨. 
				
				// 숫자를 *로 변경하기 위한 특수한 값인 INT_MAX로 해준다.
				iNumber[i] = INT_MAX;

				// 더이상 다른 숫자를 찾아볼 필요가 없으므로 for문을 탈출한다. 
				break; 
			}
		}

		// bAcc 변수가 true일 경우 중복된 숫자를 입력해서 숫자를 *로 
		// 바꾸지 못했으므로 다시 입력받게 continue를 해주는 것이다. 

		if (bAcc)
			continue;

		//빙고 줄 수를 체크하는 것은 매번 숫자를 입력할 때마다 
		// 새로 카운트를 할 것임. 그러므로 iBingo 변수를 매번 0으로 새로 
		// 초기화하고 새롭게 줄 수를 구해주도록 한다. 

		iBingo = 0;

		// 가로, 세로 줄 수를 구해준다.
		int iStar1 = 0, iStar2 = 0;
		for (int i = 0; i < 5; ++i)
		{
			// 진입할 때 한 줄 초기화 하기 전에 미리 초기화를 해둠. 
			iStar1 = iStar2 = 0;
			for (int j = 0;j < 5; ++j)
			{
				//가로 별 개수를 구해준다
				if (iNumber[i * 5 + j] == INT_MAX)
					++iStar1;
				// 세로 별 개수를 구해준다
				if (iNumber[j * 5 + i] == INT_MAX)
					++iStar2;
			}

			// j for문을 빠져나오고 나면 가로의 * 개수가 몇개인지
			// iStar1 변수에 들어가게 된다.  iStar1 값이 5이면 
			// 모두 *이라는 의미이므로 빙고 줄 카운트를 추가해준다.

			if (iStar1 == 5)
				++iBingo;

			if (iStar2 == 5)
				++iBingo;
		}

		// 왼쪽 상단-> 오른쪽 하단 대각선 체크
		iStar1 = 0;
		for (int i = 0; i < 25; i += 6)
		{
			if (iNumber[i] == INT_MAX)
				++iStar1;
		}
		if (iStar1 == 5)
			++iBingo;

		//오른쪽 하단-> 왼쪽 상단 대각선 체크
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