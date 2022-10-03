#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>
using namespace std;

void scanData();
void printAnswer();
void printSignals();
void solvingProblem();
void solvingT();
void solvingM();

vector<vector<int>> signals;
string answer;
int signalsLength;

int main(void)
{
	//clock_t start, end;
	//start = clock();

	scanData();
	solvingProblem();
	printAnswer();
	//printSignals();

	//end = clock();
	//double result = (double)(end - start);
	//cout << "\n" << result << " mili second\n";

	return 0;
}
void solvingProblem()
{
	string query;

	while(cin >> query)
	{
		if(query == "T") //질문이 T인 경우
			solvingT();
		else //질문이 M인 경우
			solvingM();
	}
}
void solvingT()
{
	int tmp1, cnt;
	cnt = 0;
	cin >> tmp1;

	//오류 처리
	if(tmp1 > signalsLength || tmp1 < 1)
	{
		answer += "-1\n";
		return;
	}

	//문제 풀이 시작
	while(true)
	{
		if(tmp1 >= signals[cnt][1] && tmp1 <= signals[cnt][2])
		{
			answer += to_string(signals[cnt][0]) + "\n";
			break;
		}
		else
			cnt++;
	}
}
void solvingM()
{
	int tmp1, tmp2, cnt, max, min;
	cnt = 0;
	cin >> tmp1 >> tmp2;

	//오류 처리
	if(tmp1 > signalsLength || tmp2 > signalsLength || tmp1 < 1 || tmp2 < 1)
	{
		answer += "-1\n";
		return;
	}

	//문제 풀이 시작
	//su의 위치를 찾아냄.
	while(true)
	{
		if(tmp1 >= signals[cnt][1] && tmp1 <= signals[cnt][2])
		{
			max = signals[cnt][0];
			min = signals[cnt][0];
			break;
		}
		else
			cnt++;
	}

	//범위내의 모든 값 탐색.
	while(true)
	{
		//시그널 데이터의 제일 마지막 값까지 모두 탐색한 경우 탐색 종료.
		if(cnt >= signals.size())
			break;

		//v값 이상의 범위에 들어섰으면, 탐색을 종료한다.
		if(tmp2 < signals[cnt][1])
			break;

		if(signals[cnt][0] > max)
			max = signals[cnt][0];
		if(signals[cnt][0] < min)
			min = signals[cnt][0];
		cnt++;
	}
	answer += to_string(min) + " " + to_string(max) + "\n";
}
void scanData()
{
	//zsignal.txt를 읽어들이는 함수이다.
	ifstream zsignalTxt;
	zsignalTxt.open("zsignal.txt");
	int start;
	int tmp;
	int curNum;
	int cnt = 1;
	
	if(zsignalTxt.is_open())
	{
		//s0값 입력 받음.
		vector<int> firstVec;
		zsignalTxt >> start;
		firstVec.push_back(start);
		firstVec.push_back(0);
		firstVec.push_back(0);
		signals.push_back(firstVec);
		curNum = start;

		//si값을 입력 받음.
		while(!zsignalTxt.eof())
		{
			zsignalTxt >> tmp;
			vector<int> vec;
			
			if(tmp != 0)
			{
				curNum += tmp;
				vec.push_back(curNum);
				vec.push_back(cnt);
				vec.push_back(cnt);
				signals.push_back(vec);
				cnt++;
			}
			else
			{
				zsignalTxt >> tmp;
				vec.push_back(curNum);
				vec.push_back(cnt);
				cnt += tmp - 1;
				vec.push_back(cnt);
				signals.push_back(vec);
				cnt++;
			}
		}
		signalsLength = signals.back()[2];
		zsignalTxt.close();
	}
	else
		cout << "파일을 읽어들이는데 실패하였습니다." << endl;
}
void printSignals()
{
	//시그널 데이터를 담아놓은 signals 벡터의 내용물을 보여주는,
	//오류 테스트 용도의 함수이다.
	string tmp;
	cout << "\n\nprint zsignal." << endl << endl;
	cout << "number\trange(min)\trange(max)" << endl;
	for(int i = 0; i < signals.size(); i++)
		tmp += to_string(signals[i][0]) + "\t" 
			+ to_string(signals[i][1]) + "\t" 
			+ to_string(signals[i][2]) + "\n";
	cout << tmp;
}
void printAnswer()
{
	cout << answer;
}