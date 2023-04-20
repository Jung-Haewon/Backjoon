#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node
{
	char name;
	char left;
	char right;
};

void scanData();
void solveProblem();
void printAnswer();

void preOrder(int index);
void inOrder(int index);
void postOrder(int index);

vector<Node> tree;
string answer = "";

int main()
{
	scanData();
	solveProblem();
	printAnswer();

	return 0;
}

void scanData()
{
	for(int i = 0; i < 26; i++)
	{
		Node node;
		node.name = 65 + i;
		tree.push_back(node);
	}

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		char name, left, right;
		cin >> name >> left >> right;

		tree[name - 65].left = left;
		tree[name - 65].right = right;
	}
}

void solveProblem()
{
	preOrder(0);
	answer += "\n";

	inOrder(0);
	answer += "\n";

	postOrder(0);
}

void printAnswer()
{
	cout << answer << endl;
}

void preOrder(int index)
{
	answer += tree[index].name;

	if(tree[index].left != '.')
		preOrder(tree[index].left - 65);

	if(tree[index].right != '.')
		preOrder(tree[index].right - 65);
}

void inOrder(int index)
{
	if(tree[index].left != '.')
		inOrder(tree[index].left - 65);

	answer += tree[index].name;

	if(tree[index].right != '.')
		inOrder(tree[index].right - 65);
}

void postOrder(int index)
{
	if(tree[index].left != '.')
		postOrder(tree[index].left - 65);

	if(tree[index].right != '.')
		postOrder(tree[index].right - 65);

	answer += tree[index].name;
}