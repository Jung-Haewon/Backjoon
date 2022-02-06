#include <iostream>
#include <algorithm>
using namespace std;

class TwoNum{
public:
	int x = 0;
	int y = 0;

	void setNum(int x, int y){
		this -> x = x;
		this -> y = y;
	}

	bool operator <(TwoNum &tn){
		if(this -> x < tn.x)
			return true;
		else if(this -> x > tn.x)
			return false;
		else{
			if(this -> y < tn.y)
				return true;
			else
				return false;
		}
	}
};

int main(void)
{
	int n, x, y;
	scanf("%d", &n);
	TwoNum* tn = new TwoNum[n];

	for(int i = 0; i < n; i++){
		scanf("%d %d", &x, &y);
		tn[i].setNum(x, y);
	}

	sort(tn, tn + n);

	for(int i = 0; i < n; i++)
		printf("%d %d\n", tn[i].x, tn[i].y);

	return 0;
}