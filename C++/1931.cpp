#include <iostream>
using namespace std;

void sort(void);
int greedy(int cur, int answer, int last);

int arr[100001][2];
int n;

int main(void){
	cin >> n;

	for(int i = 0; i < n; i++)
		scanf("%d %d", &arr[i][0], &arr[i][1]);

	sort();

	/*
	for(int i = 0; i < n; i++)
		printf("%d %d\n", arr[i][0], arr[i][1]);
	*/
	
	
	int answer = greedy(0, 0, 0);
	cout << answer << endl;
	
	return 0;
}

void sort(void){
	for(int i = 0; i < n; i++){

		int small = i;

		for(int j = i + 1; j < n; j++){
			if(arr[j][0] < arr[small][0])
				small = j;
			else if(arr[j][0] == arr[small][0]){
				if(arr[j][1] > arr[small][1]){
					arr[j][0] = arr[n-1][0];
					arr[j][1] = arr[n-1][1];
					n--;
				}
				else{
					arr[small][0] = arr[n-1][0];
					arr[small][1] = arr[n-1][1];
					n--;
					small = j;
				}
			}
		}

		int tmp[2] = {arr[i][0], arr[i][1]};
		arr[i][0] = arr[small][0];
		arr[i][1] = arr[small][1];
		arr[small][0] = tmp[0];
		arr[small][1] = tmp[1];
	}
}

int greedy(int cur, int answer, int last){
	if(cur == n)
		return answer;

	int result = 0;
	int tmp = 0;
	if(last >= arr[cur][0]) //본인을 선택할 수 없는 경우
		result = greedy(cur + 1, answer, last);
	else{
		result = greedy(cur + 1, answer, last); //본인을 선택 안하는 경우
		tmp = greedy(cur + 1, answer + 1, arr[cur][1]); //선택함
		if(tmp > result)
			result = tmp;
	}

	return result;
}