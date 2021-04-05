#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool choice(int s[], int ball, int ignore, int first, int second, bool turn);

int main() {
	ifstream in("jug.inp");
	ofstream out("jug.out");

	int s[3], n;
	string result;

	in >> s[0] >> s[1] >> s[2];

	for (int i = 0; i < 10; i++)
	{
		in >> n;
		bool tmp = choice(s, n, 3, 0, 0, false);
		if (tmp == false)
			result += "F\n";
		else
			result += "S\n";
	}

	out.write(result.c_str(), result.size());

	in.close();
	out.close();
	return 0;
}

bool choice(int s[], int ball, int ignore, int first, int second, bool turn)
{
	bool ans = !turn;

	for (int i = 0; i < 3; i++)
		if ((i != ignore) && (ball - s[i] >= 0))
			if(turn == choice(s, ball - s[i], i, first, second, !turn))
				return turn;


	if (turn == false && first == 0 && ignore != 4)
		ans = choice(s, ball, 4, 1, second, !turn);
	else if (turn == true && second == 0 && ignore != 4)
		ans = choice(s, ball, 4, first, 1, !turn);

	return ans;
}
