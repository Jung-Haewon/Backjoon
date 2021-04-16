#include <iostream>
using namespace std;

int main(void)
{
	int a[10];
	int b[10];
	int aScore = 0, bScore = 0;
	char ans = 'D';

	for(int i = 0; i < 10; i++)
		cin >> a[i];
	for(int i = 0; i < 10; i++)
		cin >> b[i];

	for(int i = 0; i < 10; i++){
		if(a[i] > b[i]){
			aScore += 3;
			ans = 'A';
		}
		else if(a[i] < b[i]){
			bScore += 3;
			ans = 'B';
		}
		else{
			aScore++;
			bScore++;
		}
	}

	if(aScore > bScore)
		ans = 'A';
	else if(aScore < bScore)
		ans = 'B';

	printf("%d %d\n%c", aScore, bScore, ans);
	return 0;
}