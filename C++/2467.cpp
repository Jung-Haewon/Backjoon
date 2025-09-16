#include <iostream>
#include <string>
using namespace std;

int n = 0;
long long liquid[100000];
long long answer[2];

void scanData();
void solveProblem();
void printResult();

int main(void) {
	scanData();
	solveProblem();
	printResult();

	return 0;
}

void scanData(void) {
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> liquid[i];
}

void solveProblem(void) {
	int leftP = 0;
	int rightP = n-1;

	int bestLeft = leftP;
	int bestRight = rightP;
	long long best = labs(liquid[leftP] + liquid[rightP]);

	while(true) {
		long long sum = liquid[leftP] + liquid[rightP];

		if(labs(sum) < best) {
			best = labs(sum);
			bestLeft = leftP;
			bestRight = rightP;
		}

		if(sum < 0) {
			leftP += 1;
		} else if (sum > 0) {
			rightP -= 1;
		} else {
			bestLeft = leftP;
			bestRight = rightP;

			break;
		}

		if(leftP == rightP)
			break;
	}

	answer[0] = liquid[bestLeft];
	answer[1] = liquid[bestRight];
}

void printResult(void) {
	cout << answer[0] << " " << answer[1] << endl;
}