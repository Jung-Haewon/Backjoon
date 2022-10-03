#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Music
{
	string name;
	char genre;
	int broadNum;
	double size;
	int downloadNum;
};

void scanData();
void printAnswer();
void printStreaming(); // 정답 확인용.
void sortingStreaming();
bool compareMusic(Music a, Music b);


vector<Music> streaming;
int n, k;

int main()
{
	scanData();
	sortingStreaming();
	printAnswer();
	printStreaming();

	return 0;
}

void scanData()
{
	cin >> n >> k;

	for(int i = 0; i < n; i++)
	{
		Music music;
		cin >> music.name >> music.genre >> music.broadNum >> music.size >> music.downloadNum;
		streaming.push_back(music);
	}
}

void printAnswer()
{
	cout << streaming[k-1].name << endl;
}

void printStreaming()
{
	//정답 확인을 위한 테스트용 함수.
	printf("\nrank\tname\t\t\tGenre\tbroad\tdown\tsize\n");
	printf("----------------------------------------------------\n");
	for(int i = 0; i < n; i++)
	{
		cout << i + 1 << "\t"
			 << (streaming[i].name + "                    ").substr(0, 20) << "\t" 
		     << streaming[i].genre << "\t" 
			 << streaming[i].broadNum << "\t" << streaming[i].downloadNum << "\t" 
			 << streaming[i].size << endl;
	}
}

void sortingStreaming()
{
	//정렬 4번 조건을 제외하고, 우선 1~3번 조건만을 기준으로 하여 정렬.
	sort(streaming.begin(), streaming.end(), compareMusic);

	//정렬 4번 조건을 포함하여 정렬.
	for(int i = 1; i < n; i++)
	{
		//연속된 두 음원의 장르가 다른 경우. 그 다음으로 넘어감.
		if(streaming[i].genre != streaming[i - 1].genre)
			continue;

		//연속된 두 음원의 장르가 같은 경우.
		for(int j = i + 1; j < n; j++)
		{
			//다른 장르의 음원이 나올때까지 탐색.
			if(streaming[i].genre == streaming[j].genre)
				continue;

			//다른 장르의 음원이 나온경우.
			//j번째 음원을 i번째로, i ~ j-1번 음원은 i+1 ~ j번으로 밀려나게 됨.
			Music music = streaming[j];
			for(int k = j; k > i; k--)
				streaming[k] = streaming[k-1];
			streaming[i] = music;
			
			break;
		}
	}
}

bool compareMusic(Music a, Music b)
{
	//정렬 1번 조건, 방송 수가 더 높을수록 등수가 높음.
	if(a.broadNum != b.broadNum) 
		return a.broadNum > b.broadNum;
	//정렬 2번 조건, 다운로드 수가 더 높을수록 등수가 높음.
	else if(a.downloadNum != b.downloadNum)
		return a.downloadNum > b.downloadNum;
	//정렬 3번 조건, 파일크기가 작을수록 등수가 높음.
	else
		return a.size < b.size;
}