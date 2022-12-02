#include <iostream>
#include <vector>
#include <string>
using namespace std;

void scanData();
void printAnswer();
bool dynamicPrograming();
bool execFunction();
//void printFunctions(); //함수가 올바르게 저장되었는지 확인하는 함수
//void printSequence(); //코드의 수행 순서를 확인하는 함수

vector<vector<string>> functions;
vector<string> codeSequence;
vector<string> returnFunctions;
int n, k1, k2;

int main()
{
	scanData();
	if(dynamicPrograming() == false)
		cout << "DEADLOCK" << endl;
	else
		printAnswer();

	//printFunctions();
	//printSequence();
	return 0;
}

void scanData()
{
	cin >> n >> k1 >> k2;

	for(int i = 0; i < n; i++)
	{
		vector<string> function;
		string tmp;

		while(true)
		{
			cin >> tmp;
			if(tmp == "$")
				break;
			function.push_back(tmp);
		}

		functions.push_back(function);
	}
}

void printAnswer()
{
	if(k1-1 < codeSequence.size())
		cout << codeSequence[k1-1] << endl;
	else
		cout << "NONE" << endl;

	if(k2-1 < codeSequence.size())
		cout << codeSequence[k2-1] << endl;
	else
		cout << "NONE" << endl;
}

bool dynamicPrograming()
{
	returnFunctions.push_back("M");
	return execFunction();
}

bool execFunction()
{
	string curFunction = returnFunctions.back();
	int index;

	for(int i = 0; i < returnFunctions.size() - 1; i++)
		if(returnFunctions[i] == curFunction)
			return false;

	for(int i = 0; i < functions.size(); i++)
	{
		if(functions[i][0] == curFunction)
		{
			index = i;
			break;
		}
	}

	for(int i = 1; i < functions[index].size(); i++)
	{
		string term = functions[index][i];

		if(term[0] >= 65 && term[0] <= 90)
		{
			returnFunctions.push_back(term);
			if(execFunction() == false)
				return false;
		}
		else
		{
			string sequence = curFunction + "-" + term;
			codeSequence.push_back(sequence);
		}
	}

	returnFunctions.pop_back();
	return true;
}

/*
void printFunctions()
{
	for(int i = 0; i < functions.size(); i++)
	{
		for(int j = 0; j < functions[i].size(); j++)
			cout << functions[i][j] << " ";
		cout << endl;
	}
}

void printSequence()
{
	for(int i = 0; i < codeSequence.size(); i++)
		cout << i << " " << codeSequence[i] << endl;
}
*/