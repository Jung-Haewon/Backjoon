#include <iostream>
#include <vector>
#include <string>
using namespace std;

void initDisk();
void solveProblem();
void processWrite();
void processShow();
void processDelete();
void processCompact();

struct diskFile
{
	string name;
	int size;
	vector<vector<int>> location;
};

vector<diskFile> files;
int entireSpace;
int remainSpace;

int main()
{
	initDisk();
	solveProblem();

	return 0;
}

void initDisk()
{
	cin >> entireSpace;
	remainSpace = entireSpace;
}

void solveProblem()
{
	string query;
	cin >> query;

	while(query != "end")
	{
		if(query == "write")
			processWrite();
		else if(query == "show")
			processShow();
		else if(query == "delete")
			processDelete();
		else if(query == "compact")
			processCompact();

		cin >> query;
	}
}

void processWrite()
{
	bool errorTrigger = true;
	string fileName;
	int fileSize;
	cin >> fileName >> fileSize;

	if(fileSize > remainSpace)
	{
		cout << "diskfull" << endl;
		return;
	}

	remainSpace -= fileSize;

	int remainFileSize;
	diskFile newFile;
	newFile.name = fileName;

	for(int i = 1; i < files.size(); i++)
	{
		if(remainFileSize <= 0)
			break;


	}

	//cout << "write" << endl;
}

void processShow()
{
	bool errorTrigger = true;
	string fileName;
	cin >> fileName;

	vector<diskFile>::iterator iter;
	for(iter = files.begin(); iter != files.end(); iter++)
	{
		if((*iter).name == "fileName")
		{
			for(int i = 0; i < (*iter).location.size(); i++)
				cout << (*iter).location[i][0] << " ";

			errorTrigger = false;
			break;
		}
	}

	if(errorTrigger == true)
		cout << "error" << endl;

	//cout << "show" << endl;
}

void processDelete()
{
	bool errorTrigger = true;
	string fileName;
	cin >> fileName;

	vector<diskFile>::iterator iter;
	for(iter = files.begin(); iter != files.end(); iter++)
	{
		if((*iter).name == "fileName")
		{
			files.erase(iter);
			errorTrigger = false;
			break;
		}
	}

	if(errorTrigger == true)
		cout << "error" << endl;

	//cout << "delete" << endl;
}

void processCompact()
{
	//cout << "compact" << endl;
}