#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string backTracking(int edge[][26], string use, int state, int length);

int main(void) {
	ifstream in("marathon.inp");
	ofstream out("marathon.out");
	int n, m;
	int edge[26][26] = { 0 };
	in >> n >> m;

	for (int i = 0; i < m; i++) {
		char tmp1, tmp2;
		int tmp3;
		in >> tmp1 >> tmp2 >> tmp3;
		edge[int(tmp1) - 97][int(tmp2) - 97] = tmp3;
		edge[int(tmp2) - 97][int(tmp1) - 97] = tmp3;
	}
	string result = "a";
	result += backTracking(edge, "", 0, 0);

	out << result.length()/2 + 1 << endl;
	out << result;

	in.close();
	out.close();
	return 0;
}

string backTracking(int edge[][26], string use, int state, int length) {
	string result = "";
	for (int i = 0; i < 26; i++) {
		if (edge[state][i] != 0 && use.find((char)(i+97)) == - 1) {
			int tmp = length + edge[state][i];
			if (tmp < 42 && i != 0) {
				string nextUse = use + " " + (char)(i + 97);
				string tmpResult = backTracking(edge, nextUse, i, tmp);
				if (tmpResult.length() > result.length())
					result = tmpResult;
			}
			else if (tmp == 42 && i == 0) {
				if (use.length() > result.length())
					result = use;
			}
		}
	}
	return result;
}