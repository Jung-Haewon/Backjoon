#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAX_WEIGHT 100

void solveProblem();
void printData();

vector<vector<int>> containers;

int main()
{
	solveProblem();
	printData();
}

void solveProblem()
{
	// 5 <= N <= 200
	// 1 <= W <= 100
	int n, w;
	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		bool newContainerTrigger = true;
		cin >> w;

		for(int j = 0; j < containers.size(); j++)
		{
			if(containers[j][0] + w <= MAX_WEIGHT)
			{
				newContainerTrigger = false;
				containers[j][0] += w;
				containers[j].push_back(i);
				break;
			}
		}

		if(newContainerTrigger == true)
		{
			vector<int> newContainer;
			newContainer.push_back(w);
			newContainer.push_back(i);
			containers.push_back(newContainer);
		}
	} 
}

void printData()
{
	string answer = "";

	for(int i = 0; i < containers.size(); i++)
	{
		for(int j = 1; j < containers[i].size(); j++)
		{
			answer += to_string(containers[i][j]);

			if(j != containers[i].size() - 1)
				answer += " ";
			else
				answer += "\n";
		}
	}

	cout << answer;
}