#include <iostream>
using namespace std;

void solveProblem();

int main()
{
    solveProblem();

    return 0;
}

void solveProblem()
{
    char curDirect = 'N';
    int order;

    for(int i = 0; i < 10; i++)
    {
        cin >> order;

        switch(order)
        {
        case 1:
            if(curDirect == 'N')
                curDirect = 'E';
            else if(curDirect == 'E')
                curDirect = 'S';
            else if(curDirect == 'S')
                curDirect = 'W';
            else
                curDirect = 'N';
            break;
        case 2:
            if(curDirect == 'N')
                curDirect = 'S';
            else if(curDirect == 'E')
                curDirect = 'W';
            else if(curDirect == 'S')
                curDirect = 'N';
            else
                curDirect = 'E';
            break;
        case 3:
            if(curDirect == 'N')
                curDirect = 'W';
            else if(curDirect == 'E')
                curDirect = 'N';
            else if(curDirect == 'S')
                curDirect = 'E';
            else
                curDirect = 'S';
            break;
        }
    }

    cout << curDirect << endl;
}