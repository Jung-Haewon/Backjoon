#include <iostream>
#include <fstream>
#include <tuple>
#include <string>
using namespace std;

tuple<string, string, int, int, int> cal(string first, string second, int match, int mis, int gap);
int max(int a, int b, int c, int d);

int main(void) {
	//입력을 받는 부분
	ifstream in("music.inp");
	ofstream out("music.out");

	int match, mis, gap, best = 0, f_best, s_best;
	string str, first, second;
	in >> match >> mis >> gap;
	getline(in, str);
	getline(in, str);

	//계산하는 부분
	for(int i = 1; i < str.length()-1; i++) {
		tuple<string, string, int, int, int> ret = cal(str.substr(0, i), str.substr(i), match, mis, gap);

		if(get<2>(ret) > best) {
			first = get<0>(ret);
			second = get<1>(ret);
			best = get<2>(ret);
			f_best = get<3>(ret);
			s_best = get<4>(ret) + i;
		}
		else if(get<2>(ret) == best ){
			if(f_best > get<3>(ret))
			{
				first = get<0>(ret);
				second = get<1>(ret);
				best = get<2>(ret);
				f_best = get<3>(ret);
				s_best = get<4>(ret) + i;
			}
			else if(f_best == get<3>(ret) && s_best > get<4>(ret) + i)
			{
				first = get<0>(ret);
				second = get<1>(ret);
				best = get<2>(ret);
				f_best = get<3>(ret);
				s_best = get<4>(ret) + i;
			}
		}
	}

	//출력하는 부분
	string result = first + "\n" + second + "\n" + to_string(best);
	out.write(result.c_str(), result.size());

	in.close();
	out.close();
	return 0;
}

tuple<string, string, int, int, int> cal(string first, string second, int match, int mis, int gap) {
	int best = 0;
	int bLoc[2] = {1, 1};

	int f_len = first.length() + 1;
	int s_len = second.length() + 1;

	int** arr = new int* [f_len];
	for(int i = 0; i < f_len; i++)
		arr[i] = new int[s_len] {0};

	for(int i = 1; i < f_len; i++) {
		for(int j = 1; j < s_len; j++) {
			int tmp = arr[i-1][j-1];
			if(first[i-1] == second[j-1])
				tmp += match;
			else
				tmp += mis;

			arr[i][j] = max(tmp, arr[i][j-1] + gap, arr[i-1][j] + gap, 0);

			if(arr[i][j] > best) {
				best = arr[i][j];
				bLoc[0] = i;
				bLoc[1] = j;
			}
		}
	}

	int start[2] = {bLoc[0], bLoc[1]};

	while(true) {
		if(start[0] == 0 && start[1] == 0) {
			break;
		}
		else if(start[0] == 0) {
			if(arr[start[0]][start[1]-1] != 0)
				start[1] -= 1;
			else
				break;
		}
		else if(start[1] == 0) {
			if(arr[start[0]-1][start[1]] != 0)
				start[0] -= 1;
			else
				break;
		}
		else{
			if (arr[start[0]-1][start[1]-1] != 0) {
        		start[0] -= 1;
        		start[1] -= 1;
    		}
    		else if (arr[start[0]-1][start[1]] != 0)
        		start[0] -= 1;
    		else if (arr[start[0]][start[1]-1] != 0)
        		start[1] -= 1;
    		else
            	break;
		}
	}

	for(int i = 0; i < f_len; i++)
        delete [] arr[i];

    return tuple<string, string, int, int, int>(first.substr(start[0]-1, bLoc[0]+1-start[0]), second.substr(start[1]-1, bLoc[1]+1-start[1]), best, start[0], start[1]);
}

int max(int a, int b, int c, int d)
{
    if(a >= b && a >= c && a >= d)
    	return a;
    else if(b >= c && b >= d)
    	return b;
    else if(c >= d)
    	return c;
    else
    	return d;
}