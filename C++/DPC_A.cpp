#include <iostream>
using namespace std;

int main()
{
    int p, gp, cp, np;

    int soft = 0;
    int embeded = 0;
    int ai = 0;
    int junior = 0;

    scanf("%d", &p);

    for(int i = 0; i < p; i++)
    {
        scanf("%d %d %d", &gp, &cp, &np);

        if(gp == 1)
            junior++;
        else if(cp <= 2)
            soft++;
        else if(cp == 3)
            embeded++;
        else
            ai++;
    }

    cout << soft << endl;
    cout << embeded << endl;
    cout << ai << endl;
    cout << junior << endl;

    return 0;
}
