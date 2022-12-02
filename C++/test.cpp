#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> printList;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string _name){
        name = _name;
        left = NULL;    
        right = NULL;
    }
};

void insertNode(Node** tree, Node* newNode) {
    if (*tree == NULL)
        *tree = newNode;
    else if ((*tree)->name < newNode->name){
        if ((*tree)->right == NULL){
            (*tree)->right = newNode;
            return;
        }
        else insertNode(&((*tree)->right), newNode);
    }
    else if ((*tree)->name > newNode->name){
        if ((*tree)->left == NULL){
            (*tree)->left = newNode;
            return;
        }
        else insertNode(&((*tree)->left), newNode);
    }
    else if ((*tree)->name == newNode->name){
        return;
    }
}

Node* searchMaxNode(Node* tree){
    if (tree == NULL) return NULL;

    if (tree->right == NULL){
        return tree;
    }
    else{
        return searchMaxNode(tree->right);
    }
}

Node* searchMinNode(Node* tree){
    if (tree == NULL) return NULL;

    if (tree->left == NULL)
        return tree;
    else
        return searchMinNode(tree->left);
}

Node* deleteNode(Node* tree, Node* parent, string targetName){
    if (tree == NULL) return NULL;

    Node* removedNode = NULL;

    if (tree->name > targetName)
        removedNode = deleteNode(tree->left, tree, targetName);
    else if (tree->name < targetName)
        removedNode = deleteNode(tree->right, tree, targetName);
    else if (tree->name == targetName){
        removedNode = tree;
        if (tree->left == NULL && tree->right == NULL) {
                if (parent->left == tree)
                parent->left = NULL;
                else if (parent->right == tree)
                parent->right = NULL;
        }
        else if (tree->left == NULL){
            Node* minNode = searchMinNode(tree->right);
            tree->name = minNode->name;
            deleteNode(tree->right, tree, minNode->name);
        }
        else if (tree->right == NULL) {
            Node* temp = tree->left;
            parent->left = temp;
        }
        else if (tree->left != NULL && tree->right != NULL) {
            Node* minNode = searchMaxNode(tree->left);
            tree->name = minNode->name;
            minNode = deleteNode(tree->left, tree, minNode->name);
        }

    }
    return removedNode;
}

// void printTotal(Node* tree) {
//     if (tree == NULL) return;

//     cout << tree->name << endl;
//     printTotal(tree->left);
//     printTotal(tree->right);
// }

void printLeaf(Node* tree){
    if (tree == NULL) return;

    if (tree->left == NULL && tree->right == NULL){
        printList.push_back(tree->name);
        return;
    }
    
    printLeaf(tree->left);
    printLeaf(tree->right);
}

void printDepth(Node* tree, int targetDepth, int depth){
    if (tree == NULL || targetDepth < depth) return;

    if (targetDepth == depth){
        printList.push_back(tree->name);
        return;
    }
    else{
        printDepth(tree->left, targetDepth, depth + 1);
        printDepth(tree->right, targetDepth, depth + 1);
    }
}

int main(){
    Node* rootNode = new Node("absolute Node");
    for (int i = 0; i < 100; i++) {
        string query; cin >> query;
        if (query == "+"){
            string newName; cin >> newName;
            Node* newNode = new Node(newName);

            insertNode(&rootNode->left, newNode);
        }
        if (query == "-"){
            string targetName; cin >> targetName;
            deleteNode(rootNode->left, rootNode, targetName);
        }
        if (query == "leaf"){
            printList.clear();
            printLeaf(rootNode->left);

            sort(printList.begin(), printList.end());
            for (auto it : printList)
                cout << it << " ";
            cout << '\n';
        }
        if (query == "depth"){
            printList.clear();
            int targetDepth; cin >> targetDepth;
            printDepth(rootNode->left, targetDepth, 1);
            if (printList.size() == 0){
                cout << "NO\n";
            }
            else{
                sort(printList.begin(), printList.end());
                for (auto it : printList)
                    cout << it << " ";
                cout << '\n';
            }
        }
        if (query == "quit")
            break;
    }
}