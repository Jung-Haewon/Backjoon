#include <iostream>
#include <string>
using namespace std;

string branch(int target[4], int** infor, string tree, int n, int best);
int match(int target[4], int* current);
int sum(int* arr);

int main(void) {
	//입력을 받는 부분
	int n;
	int target[4] = { 0 };
	cin >> n;

	for (int i = 0; i < 4; i++)
		cin >> target[i];

	int** infor = new int* [n];
	for (int i = 0; i < n; i++)
		infor[i] = new int[5]{ 0 };

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 5; j++)
			cin >> infor[i][j];

	//문제를 해결하는 부분
	int best = 0;
	for (int i = 0; i < n; i++)
		best += infor[i][4];

	int* zeroPrice = new int[n];
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

	string tree = "";
	string result = branch(target, infor, tree, n, best);

	//결과를 출력하는 부분
	int tmp = 0;

	string ans = "";
	if (result == "-1")
		cout << "-1";
	else {
		for (int i = 1; i < n + 1; i++) {
			if (zeroPrice[i - 1] == 1){
				ans += to_string(i) + " ";
			}
			else if(result[i-1] == '1'){
				ans += to_string(i) + " ";
				tmp += infor[i-1][4];
			}

		}
		cout << tmp << endl;
		cout << ans << endl;
	}

	for (int i = 0; i < n; i++)
		delete[] infor[i];
	delete[] zeroPrice;

	return 0;
}

string branch(int target[4], int** infor, string tree, int n, int best) {
	int treeLen = tree.length();

	//더이상 추가할 재료가 없는경우
	//다시 말해서, 트리가 최대길이에 도달했을때 값을 반환합니다
	if (treeLen == n) {
		int current[5] = { 0, 0, 0, 0, 0 };
		for (int i = 0; i < n; i++) {
			if (tree[i] == '1') {
				for (int j = 0; j < 5; j++)
					current[j] += infor[i][j];
			}
		}

		if (match(target, current) == -1)
			return "-1";
		else
			return tree;
	}

	//첫번째 bound 조건
	//지금까지의 값들로도 목표값을 달성했다면
	//더 이상 탐색을 하지 않고, 값을 반환합니다
	string zeroTree = tree;
	for (int i = 0; i < n - treeLen; i++)
		zeroTree += "0";

	int zero[5] = { 0, 0, 0, 0, 0 };
	for (int i = 0; i < n; i++) {
		if (zeroTree[i] == '1') {
			for (int j = 0; j < 5; j++)
				zero[j] += infor[i][j];
		}
	}
	if (match(target, zero) == 1)
		return zeroTree;

	//두번째 bound 조건
	//현재까지의 best와 비교해서, 무슨일이 있어도 현재값이 더 좋지않다면
	//더 이상 탐색을 하지 않고, 값을 반환합니다
	if (zero[4] > best)
		return "-1";

	
	//세번째 bound 조건
	//앞으로 남은 재료를 모두 넣더라도, 목표값을 달성할 수 없다면
	//더 이상 탐색을 하지 않고, 값을 반환합니다
	string failTree = tree;
	for (int i = 0; i < n - treeLen; i++)
		failTree += "1";

	int fail[5] = { 0, 0, 0, 0, 0 };
	for (int i = 0; i < n; i++) {
		if (failTree[i] == '1') {
			for (int j = 0; j < 5; j++)
				fail[j] += infor[i][j];
		}
	}
	if (match(target, fail) == -1)
		return "-1";

	//bound 되지도 않고, 아직 트리도 완성되지 않았다면
	//좀 더 탐색을 시도합니다
	string case1 = tree + "1";
	string case2 = tree + "0";
	string tree1 = branch(target, infor, case1, n, best);
	if (tree1 != "-1") {
		int ans1[5] = { 0, 0, 0, 0, 0 };
		for (int i = 0; i < n; i++) {
			if (tree1[i] == '1') {
				for (int j = 0; j < 5; j++)
					ans1[j] += infor[i][j];
			}
		}
		if (ans1[4] < best)
			best = ans1[4];
	}
	string tree2 = branch(target, infor, case2, n, best);

	//탐색한 트리중에서, 최적의 값을 추려냅니다
	if (tree1 == "-1")
		return tree2;
	else if (tree2 == "-1")
		return tree1;
	else {
		int ans1[5] = { 0, 0, 0, 0, 0 };
		for (int i = 0; i < n; i++) {
			if (tree1[i] == '1') {
				for (int j = 0; j < 5; j++)
					ans1[j] += infor[i][j];
			}
		}
		int ans2[5] = { 0, 0, 0, 0, 0 };
		for (int i = 0; i < n; i++) {
			if (tree2[i] == '1') {
				for (int j = 0; j < 5; j++)
					ans2[j] += infor[i][j];
			}
		}
		if (ans1[4] <= ans2[4])
			return tree1;
		else
			return tree2;
	}
}

int match(int target[4], int* current) {
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