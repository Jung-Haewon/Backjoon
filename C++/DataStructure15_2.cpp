#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct FilePiece
{
	string fileName;
	int start, end, size;
};

class DiskManager
{
private:
	int DiskSize, RemainDiskSize;
	vector<FilePiece> disk;

public:
	DiskManager(int size)
	{
		DiskSize = size;
		RemainDiskSize = size;

		FilePiece initDisk = MakeNullSpace(0, size - 1, size);
		disk.push_back(initDisk);
	}

	void WriteFile(string name, int size)
	{
		vector<FilePiece>::iterator iter;

		//디스크에 넣지 못하는 경우
		if(size > RemainDiskSize)
		{
			cout << "diskfull\n";
			return;
		}

		//이미 같은 이름의 파일이 존재하는 경우
		for(iter = disk.begin(); iter != disk.end(); iter++)
		{
			if((*iter).fileName == name)
			{
				cout << "error\n";
				return;
			}
		}

		RemainDiskSize -= size;

		//파일 전체가 쪼개지지 않고 들어가는 경우
		for(iter = disk.begin(); iter != disk.end(); iter++)
		{
			if((*iter).fileName != "")
				continue;

			if((*iter).size == size)
			{
				(*iter).fileName = name;
				return;
			}
			else if((*iter).size > size)
			{
				FilePiece nullSpace = MakeNullSpace((*iter).start + size, (*iter).end, (*iter).size - size);

				(*iter).fileName = name;
				(*iter).end = nullSpace.start - 1;
				(*iter).size = size;

				iter++;
				disk.insert(iter, nullSpace);
				return;
			}
		}


		//파일을 쪼개서라도 넣는 경우
		int remainFileSize = size;
		for(iter = disk.begin(); iter != disk.end(); iter++)
		{
			if((*iter).fileName != "")
				continue;

			if((*iter).size <= remainFileSize)
			{
				(*iter).fileName = name;
				remainFileSize -= (*iter).size;
				continue;
			}
			else if((*iter).size > remainFileSize)
			{
				FilePiece nullSpace = MakeNullSpace((*iter).start + remainFileSize, (*iter).end, (*iter).size - remainFileSize);

				(*iter).fileName = name;
				(*iter).end = nullSpace.start - 1;
				(*iter).size = remainFileSize;

				iter++;
				disk.insert(iter, nullSpace);
				return;
			}
		}
	}

	void ShowFile(string name)
	{
		bool errorTrigger = true;
		string message = "";

		for(int i = 0; i < disk.size(); i++)
		{
			if(disk[i].fileName != name)
				continue;

			message += to_string(disk[i].start) + " ";
			errorTrigger = false;
		}

		if(errorTrigger)
			cout << "error\n";
		else
			cout << message + "\n";
	}

	void DeleteFile(string name)
	{
		vector<FilePiece>::iterator iter;
		bool errorTrigger = true;

		for(iter = disk.begin(); iter != disk.end(); iter++)
		{
			if((*iter).fileName != name)
				continue;

			RemainDiskSize += (*iter).size;
			(*iter).fileName = "";
			errorTrigger = false;

			if(iter != disk.begin())
			{
				if((*(iter+1)).fileName == (*iter).fileName)
					iter++;

				if((*(iter-1)).fileName == (*iter).fileName)
				{
					(*(iter-1)).end = (*iter).end;
					(*(iter-1)).size += (*iter).size;
					disk.erase(iter);
					iter--;
				}
			}
		}

		if(errorTrigger)
			cout << "error\n";
	}

	void CompactDisk()
	{
		if(RemainDiskSize == 0 || RemainDiskSize == DiskSize)
			return;

		vector<FilePiece>::iterator iter;
		for(iter = disk.begin(); iter != disk.end(); iter++)
		{
			if((*iter).fileName == "")
			{
				disk.erase(iter);
				iter--;
			}
			else if(iter == disk.begin())
			{
				(*iter).start = 0;
				(*iter).end = (*iter).size - 1;
			}
			else
			{
				(*iter).start = (*(iter-1)).end + 1;
				(*iter).end = (*iter).start + (*iter).size - 1;

				if((*(iter-1)).fileName == (*iter).fileName)
				{
					(*(iter-1)).end = (*iter).end;
					(*(iter-1)).size += (*iter).size;
					disk.erase(iter);
					iter--;
				}
			}
		}

		FilePiece nullSpace = MakeNullSpace(disk.back().end + 1, (DiskSize) - 1, RemainDiskSize);
		disk.push_back(nullSpace);
	}

	FilePiece MakeNullSpace(int start, int end, int size)
	{
		FilePiece nullSpace;
		nullSpace.fileName = "";
		nullSpace.start = start;
		nullSpace.end = end;
		nullSpace.size = size;

		return nullSpace;
	}

	void ShowDisk()
	{
		cout << "-----------------------------" << endl;
		cout << "Remain Disk Memory: " << this->RemainDiskSize << endl;
		for(int i = 0; i < disk.size(); i++)
			cout << disk[i].fileName << "\t" << disk[i].start << "\t" << disk[i].end << endl;

		cout << "-----------------------------" << endl << endl;
	}
};

void initDisk();
void solveProblem();
DiskManager *diskManager;

int main()
{
	initDisk();
	solveProblem();

	return 0;
}

void initDisk()
{
	int diskSize;
	cin >> diskSize;
	diskManager = new DiskManager(diskSize);
}

void solveProblem()
{
	string query, fileName;
	int size;
	cin >> query;

	while(query != "end")
	{
		if(query == "compact")
			diskManager->CompactDisk();
		else
		{
			cin >> fileName;
			if(query == "write")
			{
				cin >> size;
				diskManager->WriteFile(fileName, size);
			}
			else if(query == "show")
				diskManager->ShowFile(fileName);
			else if(query == "delete")
				diskManager->DeleteFile(fileName);
			else
				cout << "problem Error\n";
		}
		
		//diskManager->ShowDisk(); //정상작동 디버그 확인용
		cin >> query;
	}
	//cout << "end\n"; //확인용
}