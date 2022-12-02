#include <iostream>
#include <map>
using namespace std;

void scanData();
void showNodes();
void dynamic();
void findAnswer();
void deleteData();

int** graph;
int* nodeDegrees;
map<char, int> nodes;
int nodeCnt = 0;
int n;

int main(void)
{
	scanData();
	dynamic();
	findAnswer();
	showNodes();
	deleteData();
	
	return 0;
}

void scanData()
{
	cin >> n;
	graph = new int*[n];
	nodeDegrees = new int[n];
	
	for(int i = 0; i < n; i++)
	{
		graph[i] = new int[n];
		for(int j = 0; j < n; j++)
		{
			if(i == j)
				graph[i][j] = 0;
			else
				graph[i][j] = -1;
		}
	}

	for(int i = 0; i < n; i++)
	{
		char nodeName;
		int degree = 0;
		cin >> nodeName;

		if(nodes.find(nodeName) == nodes.end())
		{
			nodes[nodeName] = nodeCnt;
			nodeCnt++;
		}

		while(true)
		{
			char neighborName;
			int distance;

			cin >> neighborName;

			if(neighborName == '$')
				break;

			cin >> distance;
			distance *= 2;

			if(nodes.find(neighborName) == nodes.end())
			{
				nodes[neighborName] = nodeCnt;
				nodeCnt++;
			}

			graph[nodes[nodeName]][nodes[neighborName]] = distance;
			graph[nodes[neighborName]][nodes[nodeName]] = distance;

			degree++;
		}

		nodeDegrees[nodes[nodeName]] = degree;
	}
}

void showNodes()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cout << graph[i][j] << ' ';
		cout << endl;
	}
	cout << endl;

	for(int i = 0; i < n; i++)
		cout << nodeDegrees[i] << ' ';
	cout << endl << endl;

	for(auto iter = nodes.begin(); iter != nodes.end(); ++iter)
		cout << iter->first << ' ' << iter->second << endl;
	cout << endl;
}

void dynamic()
{
	for(int cnt = 0; cnt < n; cnt ++)
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(graph[i][j] <= 0)
					continue;

				for(int k = 0; k < n; k++)
				{
					if(graph[j][k] <= 0)
						continue;

					int newLen = graph[i][j] + graph[j][k] + nodeDegrees[j];

					if(graph[i][k] == -1 || graph[i][k] > newLen)
					{
						graph[i][k] = newLen;
						graph[k][i] = newLen;
					}

					//showNodes();
				}
			}
		}
	}
}

void findAnswer()
{
	int answer = graph[0][0];

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(graph[i][j] > answer)
				answer = graph[i][j];

	cout << answer << endl;
}

void deleteData()
{
	for(int i = 0; i < n; i++)
		delete[] graph[i];
	delete[] graph;
	delete[] nodeDegrees;
}