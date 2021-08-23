#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
using namespace std;

int total;
int ansLoc[4];
string ans[4];

void radix(list<string> current, int target, int index, int now);

int main(void) {
	list <string> aList;
	list <string> cList;
	list <string> gList;
	list <string> tList;

	//파일 입력
	//버퍼를 이용해, 파일전체를 한번에 read
	FILE* fp = fopen("read.inp", "r");
	int FileSize;
	char* buffer;
	fseek(fp, 0, SEEK_END);
	FileSize = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	buffer = new char[FileSize+1];

	fread(buffer, FileSize, 1, fp);
	*(buffer + FileSize) = 0;
	fclose(fp);

	//입력받은 값으로 최초의 acgt분리과정
	//char* buffer를 쪼개는 과정이 필요하므로 함수를 이용하지 않고, 별도의 코드 작성
	istringstream iss(buffer);
	string token;
	while (getline(iss, token, '\n')) {
		switch (token[0]) {
		case 'a': aList.push_back(token); break;
		case 'c': cList.push_back(token); break;
		case 'g': gList.push_back(token); break;
		case 't': tList.push_back(token); break;
		}
	}

	//전역변수의 값 초기화
	int aLen = aList.size();
	int cLen = cList.size();
	int gLen = gList.size();
	int tLen = tList.size();

	total = aLen + cLen + gLen + tLen;
	for (int i = 0; i < 4; i++)
		ansLoc[i] = (total * (i + 1)) / 5;

	//본격적인 radix sort의 시작
	for (int i = 0; i < 4; i++) {
		if (ansLoc[i] < aLen)
			radix(aList, i, 1, 0);
		else if (ansLoc[i] < aLen + cLen)
			radix(cList, i, 1, aLen);
		else if (ansLoc[i] < aLen + cLen + gLen)
			radix(gList, i, 1, aLen + cLen);
		else
			radix(tList, i, 1, aLen + cLen + gLen);
	}

	//정답출력
	/*
	string result = "";
	for (int i = 0; i < 4; i++)
		result += ans[i];

	ofstream out("read.out");
	out.write(result.c_str(), result.size());
	out.close();
	*/
	ofstream out("read.out");
	for (int i = 0; i < 4; i++)
		out << ans[i] << endl;

	return 0;
}

void radix(list<string> current, int target, int index, int now) {
	list <string> blankList;
	list <string> aList;
	list <string> cList;
	list <string> gList;
	list <string> tList;

	list<string>::iterator iter;
	for (iter = current.begin(); iter != current.end(); iter++)
		switch ((*iter)[index]) {
		case 'a': aList.push_back(*iter); break;
		case 'c': cList.push_back(*iter); break;
		case 'g': gList.push_back(*iter); break;
		case 't': tList.push_back(*iter); break;
		default: blankList.push_back(*iter); break;
	}

	//전역변수의 값 초기화
	int blankLen = blankList.size();
	int aLen = aList.size();
	int cLen = cList.size();
	int gLen = gList.size();

	
	cout << "target: " << ansLoc[target] << endl;
	cout << "now: " << ansLoc[target] << endl;
	for (iter = blankList.begin(); iter != blankList.end(); iter++)
		cout << *iter << endl;
	for (iter = aList.begin(); iter != aList.end(); iter++)
		cout << *iter << endl;
	for (iter = cList.begin(); iter != cList.end(); iter++)
		cout << *iter << endl;
	for (iter = gList.begin(); iter != gList.end(); iter++)
		cout << *iter << endl;
	for (iter = tList.begin(); iter != tList.end(); iter++)
		cout << *iter << endl;
	cout << blankLen << " " << aLen << " " << cLen << " " << gLen << " " << tList.size() << " " << endl;
	cout << endl;
	

	if (ansLoc[target] < now + blankLen) {
		ans[target] = blankList.front();
		return;
	}
	else if (ansLoc[target] < now + blankLen + aLen)
		radix(aList, target, index + 1, now + blankLen);
	else if (ansLoc[target] < now + blankLen + aLen + cLen)
		radix(cList, target, index + 1, now + blankLen + aLen);
	else if (ansLoc[target] < now + blankLen + aLen + cLen + gLen)
		radix(gList, target, index + 1, now + blankLen + aLen + cLen);
	else
		radix(tList, target, index + 1, now + blankLen + aLen + cLen + gLen);
}