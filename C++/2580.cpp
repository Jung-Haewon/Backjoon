#include <iostream>
using namespace std;

void inputFunc(void);
void outputFunc(void);
void backTrack(int n, int m);

int sudoku[9][9];
bool answer = false;

int main(void){
	inputFunc();

	backTrack(0, 0);

	outputFunc();

	return 0;
}

void backTrack(int n, int m){
	if(sudoku[n][m] == 0){
		for(int i = 1; i < 10; i++){

			if(answer == true)
				return;

			bool isCan = true;

			for(int j = 0; j < 9; j++)
				if(sudoku[n][j] == i || sudoku[j][m] == i)
					isCan = false;

			if(isCan == false)
				continue;

			for(int j = (n/3) * 3; j < (n/3) * 3 + 3; j++)
				for(int k = (m/3) * 3; k < (m/3) * 3 + 3; k++)
					if(sudoku[j][k] == i)
						isCan = false;

			if(isCan == true){
				sudoku[n][m] = i;
				if(n != 8 || m != 8){
					if(m != 8)
						backTrack(n, m + 1);
					else
						backTrack(n + 1, 0);
				}
				else
					answer = true;
			}
		}
	}
	else{
		if(n != 8 || m != 8){
			if(m != 8)
				backTrack(n, m + 1);
			else
				backTrack(n + 1, 0);
		}
		else
			answer = true;
		return;
	}

	if(answer == false)
		sudoku[n][m] = 0;
}

void inputFunc(void){
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++)
			cin >> sudoku[i][j];
}

void outputFunc(void){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cout << sudoku[i][j];
			if(j == 8)
				cout << endl;
			else
				cout << " ";
		}
	}
}