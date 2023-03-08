#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;

#define MAX_SIZE 15
#define MAX_COST INT_MAX

int x_dir[4] = {1, 0, -1, 0};
int y_dir[4] = {0, 1, 0, -1};

class Block {
public:
    int x;
    int y;
    int cost;
    int dir;    // 0: right, 1: up, 2: left, 3: down

    Block(int _x, int _y, int _cost, int _dir)
    : x(_x), y(_y), cost(_cost), dir(_dir) {};

    Block() {
        x = -1;
        y = -1;
        cost = -1;
        dir = -1;
    }
};

int N, turnTime;
int maze[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE] = { false, };
Block path[MAX_SIZE][MAX_SIZE];

queue<Block> q;

bool isValid(Block &b) {
    if (b.x >= 0 && b.x < N && b.y >= 0 && b.y < N)
        return true;
    else
        return false;
}

int bfs(int startX, int startY) {
    visited[startX][startY] = true;
    q.push(Block(1, 0, 1, 0));
    q.push(Block(0, 1, 1, 1));
    visited[1][0] = true;
    visited[0][1] = true;

    while (!q.empty()) {
        Block currBlock = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newX = currBlock.x + x_dir[i];
            int newY = currBlock.y + y_dir[i];
            int newCost = currBlock.cost + 1;
            if (currBlock.dir != i)
                newCost += turnTime;

            Block newBlock(newX, newY, newCost, i);

            if (isValid(newBlock) && maze[newX][newY] == 0) {
                if (!visited[newX][newY]) {
                    path[newX][newY] = newBlock;
                    visited[newX][newY] = true;
                    q.push(newBlock);
                }
                else if (path[newX][newY].cost > newBlock.cost) {
                    path[newX][newY] = newBlock;
                    q.push(newBlock);
                }
            }
        }
    }
    if (path[N-1][N-1].cost == -1)
        return -1;
    else
        return path[N-1][N-1].cost;
}

int main() {
    cin >> N >> turnTime;
    for (int i = N - 1; i >= 0; i--)
        for (int j = 0; j < N; j++) 
            cin >> maze[i][j];
    
    int result = bfs(0, 0);
    cout << result << endl;

    // for (int i = N - 1; i >= 0; i--) {
    //     for (int j = 0; j < N; j++) {
    //         cout << path[i][j].cost << " ";
    //     }
    //     cout << '\n';
    // }
    return 0;
}