#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	int key;
	Node* left;
	Node* right;
};

class Tree
{
private:
	int size = 0;
	Node nodes[10000];
	Node* root = &nodes[0];

public:
	void createRoot(int key)
	{
		createNode(key);
	}
	Node* createNode(int key)
	{
		nodes[size].key = key;
		size++;

		return &nodes[size - 1];
	}
	void setLeft(Node* node, Node* left)
	{
		(*node).left = left;
	}
	void setRight(Node* node, Node* right)
	{
		(*node).right = right;
	}
	Node* getRoot()
	{
		return root;
	}
};

void scanData();
void solveProblem();
void maketree();
void addNode(Node* cur, int key);
void postOrder(Node* node);

Tree tree;
int num[10000];
int cnt = 0;

int main()
{
	scanData();
	solveProblem();
}

void scanData()
{
	while(scanf("%d", &num[cnt]) != EOF)
		cnt++;
}

void solveProblem()
{
	maketree();
	postOrder(tree.getRoot());
}

void maketree()
{
	tree.createRoot(num[0]);

	for(int i = 1; i < cnt; i++)
		addNode(tree.getRoot(), num[i]);
}

void addNode(Node* cur, int key)
{
	if((*cur).key > key)
	{
		if((*cur).left == NULL)
		{
			Node* newNode = tree.createNode(key);
			tree.setLeft(cur, newNode);
		}
		else
			addNode((*cur).left, key);
	}
	else
	{
		if((*cur).right == NULL)
		{
			Node* newNode = tree.createNode(key);
			tree.setRight(cur, newNode);
		}
		else
			addNode((*cur).right, key);
	}
}

void postOrder(Node* node)
{
	if((*node).left != 0)
		postOrder((*node).left);
	if((*node).right != 0)
		postOrder((*node).right);

	printf("%d\n", (*node).key);
}