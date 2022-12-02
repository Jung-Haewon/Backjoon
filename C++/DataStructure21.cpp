#include <iostream>
#include <queue>
#include <functional>
using namespace std;

struct Client
{
	int arriveTime;
	int ID;
	int remainTime;

	Client(int at, int id, int rt): arriveTime(at), ID(id), remainTime(rt) {}

	bool operator<(const Client c) const {
		if(this->remainTime == c.remainTime)
			return this->ID > c.ID;
		else
			return this->remainTime < c.remainTime;
	}
};

void scanData();
void solveProblem();
void clientEnter();
void showWaitingRoom();
vector<Client> notYetArrive;
priority_queue<Client> waitingRoom;
int curTime = 30;

int main()
{
	scanData();
	solveProblem();

	return 0;
}

void scanData()
{
	int arriveTime, ID, remainTime, n;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> arriveTime >> ID >> remainTime;
		notYetArrive.push_back(Client(arriveTime, ID, remainTime));
	}
}

void solveProblem()
{
	while(true)
	{
		clientEnter();

		if(waitingRoom.empty())
		{
			if(notYetArrive.empty())
				break;
			curTime++;
			continue;
		}

		showWaitingRoom();
		if(waitingRoom.top().remainTime <= 10)
		{
			cout << waitingRoom.top().ID << endl;
			curTime += waitingRoom.top().remainTime;
			waitingRoom.pop();
		}
		else
		{
			Client client = waitingRoom.top();
			int time = client.remainTime / 2;
			client.remainTime -= time;
			curTime += time;

			waitingRoom.pop();
			waitingRoom.push(client);
		}
	}
}

void clientEnter()
{
	while(true)
	{
		if(notYetArrive.empty())
			break;

		if(notYetArrive[0].arriveTime <= curTime)
		{
			waitingRoom.push(notYetArrive[0]);
			notYetArrive.erase(notYetArrive.begin());
		}
		else
			break;
	}
}

void showWaitingRoom()
{
	/*
	cout << "time:" << curTime << endl;
	vector<Client> testVector;

	while (!waitingRoom.empty()) {
        cout << waitingRoom.top().arriveTime << "\t" 
		<< waitingRoom.top().ID << "\t"
		<< waitingRoom.top().remainTime << endl;

		testVector.push_back(waitingRoom.top());
        waitingRoom.pop();
    }

    cout << endl;

    while(!testVector.empty())
    {
    	waitingRoom.push(*testVector.begin());
    	testVector.erase(testVector.begin());
    }
    */
}