#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//������ ���� 1���� ���� �����߽��ϴ�!!

//��������
int target[4] = { 0, };
int infor[50][5];
int zeroPrice[50];

int n, best = 0, bestSum = 0;
string ans = "";
string path = "";

//����Ǯ�̸� ���� �Լ�
void branch();
int match(int* current);
int sum(int* arr);

int main(void) {
	ifstream in("food.inp");
	ofstream out("food.out");
	
	//�Է��� �޴� �κ�
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

	//������ 0�̰�, ����Ҵ� �����ϴ� Ư�� ���̽��� �����մϴ�
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

	//������ ���°�� ���� �ɷ����ϴ�.
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

	//����� ����ϴ� �κ�
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
	//���̻� �߰��� ��ᰡ ���°��
	//�ٽ� ���ؼ�, Ʈ���� �ִ���̿� ���������� ���� ��ȯ�մϴ�
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

	//ù��° bound ����
	//���ݱ����� ����ε� ��ǥ���� �޼��ߴٸ�
	//�� �̻� Ž���� ���� �ʰ�, ���� ��ȯ�մϴ�
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

	//�ι�° bound ����
	//��������� best�� ���ؼ�, �������� �־ ���簪�� �� �����ʴٸ�
	//�� �̻� Ž���� ���� �ʰ�, ���� ��ȯ�մϴ�
	if (zero[4] > best) {
		if (path.length() != 0) {
			path.pop_back();
		}
		return;
	}

	//bound���� �ʾҴٸ�
	//�� �� Ž���� �����մϴ�
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