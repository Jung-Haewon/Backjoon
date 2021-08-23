#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(void) {
	ifstream in("ct.inp");
	ofstream out("ct.out");

	int n;
	in >> n;

	int** infor = new int* [4];
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
		for (int j = 0; j < n; j++)
			arr[i][j] = -1;
	}

    for (int i = 0; i < 4; i++) {
        if (i < 2)
            infor[i] = new int[n];
        else
            infor[i] = new int[2 * n - 1];
    }

    for (int i = 0; i < 4; i++) {
        if (i < 2)
            for (int j = 0; j < n; j++)
                in >> infor[i][j];
        else
            for(int j = 0; j < 2*n-1; j++)
                in >> infor[i][j];
    }

	for(int i = 0; i < 10; i++) {
		for(int i = 0; i < n; i++){
            int tmp = 0;
            for (int j = 0; j < n; j++)
                if (arr[j][i] == 1 || arr[j][i] == -1)
                    tmp += 1;
            if (tmp == infor[0][i])
                for (int j = 0; j < n; j++)
                    if (arr[j][i] == -1)
                        arr[j][i] = 1;
         }

        for (int i = 0; i < n; i++) {
            int tmp = 0;
            for (int j = 0; j < n; j++)
                if (arr[j][i] == 1)
                    tmp += 1;
            if (tmp == infor[0][i])
                for (int j = 0; j < n; j++)
                    if (arr[j][i] == -1)
                        arr[j][i] = 0;
        }
                        
        for (int i = 0; i < n; i++) {
            int tmp = 0;
            for (int j = 0; j < n; j++)
                if (arr[i][j] == 1 || arr[i][j] == -1)
                    tmp += 1;
            if (tmp == infor[1][i])
                for (int j = 0; j < n; j++)
                    if (arr[i][j] == -1)
                        arr[i][j] = 1;
        }

        for (int i = 0; i < n; i++) {
            int tmp = 0;
            for (int j = 0; j < n; j++)
                if (arr[i][j] == 1)
                    tmp += 1;
            if (tmp == infor[1][i])
                for (int j = 0; j < n; j++)
                    if (arr[i][j] == -1)
                        arr[i][j] = 0;
        }

        for (int i = 0; i < 2 * n - 1; i++) {
            int tmp1 = 0;
            int tmp2 = 0;

            if (i < n) {
                int start = n - i - 1;
                int tmp = 0;
                while (start < n) {
                    if (arr[start][tmp] == 1 || arr[start][tmp] == -1)
                        tmp1 += 1;
                    if (arr[start][tmp] == 1)
                        tmp2 += 1;
                    start += 1;
                    tmp += 1;
                }
                if (tmp1 == infor[2][2 * n - 1 - i - 1]) {
                    start = n - i - 1;
                    tmp = 0;
                    while (start < n) {
                        if (arr[start][tmp] == -1)
                            arr[start][tmp] = 1;
                        start += 1;
                        tmp += 1;
                    }
                }
                if (tmp2 == infor[2][2 * n - 1 - i - 1]) {
                    start = n - i - 1;
                    tmp = 0;
                    while (start < n) {
                        if (arr[start][tmp] == -1)
                            arr[start][tmp] = 0;
                        start += 1;
                        tmp += 1;
                    }
                }
            }
            else {
                int start = i - n + 1;
                int tmp = 0;
                while (start < n) {
                    if (arr[tmp][start] == 1 || arr[tmp][start] == -1)
                        tmp1 += 1;
                    if (arr[tmp][start] == 1)
                        tmp2 += 1;
                    start += 1;
                    tmp += 1;
                }
                if (tmp1 == infor[2][2 * n - 1 - i - 1]) {
                    start = i - n + 1;
                    tmp = 0;
                    while (start < n) {
                        if (arr[tmp][start] == -1)
                            arr[tmp][start] = 1;
                        start += 1;
                        tmp += 1;
                    }
                }
                if (tmp2 == infor[2][2 * n - 1 - i - 1]) {
                    start = i - n + 1;
                    tmp = 0;
                    while (start < n) {
                        if (arr[tmp][start] == -1)
                            arr[tmp][start] = 0;
                        start += 1;
                        tmp += 1;
                    }
                }
            }
        }

        for (int i = 0; i < 2 * n - 1; i++) {
            int tmp1 = 0;
            int tmp2 = 0;
            if (i < n) {
                int start = i;
                int tmp = 0;
                while (start >= 0) {
                    if (arr[tmp][start] == 1 || arr[tmp][start] == -1)
                        tmp1 += 1;
                    if (arr[tmp][start] == 1)
                        tmp2 += 1;
                    start -= 1;
                    tmp += 1;
                }
                if (tmp1 == infor[3][i]) {
                    while (start >= 0) {
                        if (arr[tmp][start] == -1)
                            arr[tmp][start] = 1;
                        start -= 1;
                        tmp += 1;
                    }
                }
                if (tmp2 == infor[3][i]) {
                    while (start >= 0) {
                        if (arr[tmp][start] == -1)
                            arr[tmp][start] = 0;
                        start -= 1;
                        tmp += 1;
                    }
                }
            }
            else {
                int start = i - n + 1;
                int tmp = n - 1;
                while (start < n) {
                    if (arr[start][tmp] == 1 || arr[start][tmp] == -1)
                        tmp1 += 1;
                    if (arr[start][tmp] == 1)
                        tmp2 += 1;
                    start += 1;
                    tmp -= 1;
                }
                if (tmp1 == infor[3][i]) {
                    while (start < n) {
                        if (arr[start][tmp] == -1)
                            arr[start][tmp] = 1;
                        start += 1;
                        tmp -= 1;
                    }
                }
                if (tmp2 == infor[3][i]) {
                    while (start < n) {
                        if (arr[start][tmp] == -1)
                            arr[start][tmp] = 0;
                        start += 1;
                        tmp -= 1;
                    }
                }
            }
        }
        int tmp3 = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (arr[i][j] == -1)
                    tmp3++;
        if (tmp3 == 0)
            break;
	}

    string ans = "";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 1)
                ans += "B";
            else
                ans += "-";
            if (j != n - 1)
                ans += " ";
        }
        ans += "\n";
    }
    out.write(ans.c_str(), ans.size());


	for (int i = 0; i < n; i++)
	{
		delete[] arr[i];
	}

    for (int i = 0; i < 4; i++) {
        delete[] infor[i];
    }

	return 0;
}