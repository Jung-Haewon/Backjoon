#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//마라톤 예제 1번을 보고 참고했습니다!!

//전역변수
int target[4] = { 0, };
int infor[50][5];
int zeroPrice[50];

int n, best = 0, bestSum = 0;
string ans = "";
string path = "";

//문제풀이를 위한 함수
void branch();
int match(int* current);
int sum(int* arr);

int main(void) {
	ifstream in("food.inp");
	ofstream out("food.out");
	
	//입력을 받는 부분
	in >> n;

	for (int i = 0; i < 4; i++)
		in >> target[i];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 5; j++)
			in >> infor[i][j];

	for (int i = 0; i < n; i++) {
		best += infor[i][4];
		ans.push_back('0');
	}

	//가격이 0이고, 영양소는 존재하는 특수 케이스를 검출합니다
	for (int i = 0; i < n; i++) {
		if (infor[i][4] == 0) {
			bool trigger = false;
			for (int j = 0; j < 4; j++) {
				if (infor[i][j] != 0) {
					trigger = true;
					break;
				}
			}
			if (trigger == true)
				zeroPrice[i] = 1;
			else
				zeroPrice[i] = 0;
		}
		else
			zeroPrice[i] = 0;
	}

	//정답이 없는경우 먼저 걸러냅니다.
	int isAns[4] = { 0, 0, 0, 0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			isAns[j] += infor[i][j];
		}
	}

	if (match(isAns) != 1) {
		cout << "-1" << endl;
		return 0;
	}

	//결과를 출력하는 부분
	branch();

	string output = "";
	for (int i = 1; i < n + 1; i++) {
		if (zeroPrice[i - 1] == 1)
			output += to_string(i) + " ";
		else if(ans[i-1] == '1')
			output += to_string(i) + " ";
	}

	out.write(output.c_str(), output.size());
	in.close();
	out.close();
	return 0;
}

void branch() {
	int pathLen = path.length();
	//더이상 추가할 재료가 없는경우
	//다시 말해서, 트리가 최대길이에 도달했을때 값을 반환합니다
	if (pathLen == n) {
		int current[5] = { 0, 0, 0, 0, 0 };
		for (int i = 0; i < n; i++) {
			if (path[i] == '1') {
				for (int j = 0; j < 5; j++)
					current[j] += infor[i][j];
			}
		}

		string temp = path;
		if (match(current) != -1) {
			if (current[4] < best) {
				ans = temp;
				best = current[4];
				bestSum = sum(current);
			}
			else if (current[4] == best && sum(current) > bestSum) {
				ans = temp;
				bestSum = sum(current);
			}
		}
		path.pop_back();
		return;
	}

	//첫번째 bound 조건
	//지금까지의 값들로도 목표값을 달성했다면
	//더 이상 탐색을 하지 않고, 값을 반환합니다
	int zero[5] = { 0, 0, 0, 0, 0 };
	for (int i = 0; i < pathLen; i++) {
		if (path[i] == '1') {
			for (int j = 0; j < 5; j++)
				zero[j] += infor[i][j];
		}
	}

	string temp = path;
	if (match(zero) == 1) {
		if (zero[4] < best) {
			for (int i = 0; i < n - pathLen; i++) {
				temp += "0";
			}
			ans = temp;
			best = zero[4];
			bestSum = sum(zero);
		}
		if (path.length() != 0) {
			path.pop_back();
		}
		return;
	}

	//두번째 bound 조건
	//현재까지의 best와 비교해서, 무슨일이 있어도 현재값이 더 좋지않다면
	//더 이상 탐색을 하지 않고, 값을 반환합니다
	if (zero[4] > best) {
		if (path.length() != 0) {
			path.pop_back();
		}
		return;
	}

	//bound되지 않았다면
	//좀 더 탐색을 진행합니다
	path.push_back('1');
	branch();
	path.push_back('0');
	branch();

	if(path.length() != 0)
		path.pop_back();
	return;
}

int match(int* current) {
	for (int i = 0; i < 4; i++) {
		if (target[i] > current[i])
			return -1;
	}
	return 1;
}

int sum(int* arr) {
	int result = 0;
	for (int i = 0; i < 4; i++) {
		result += arr[i];
	}
	return result;
}