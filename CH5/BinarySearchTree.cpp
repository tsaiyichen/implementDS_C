#include "BinarySearchTree.hpp"
#include "BinaryTree.hpp"
#include <iostream>

using namespace std;

treenode_t* BinarySearchTree::insertNode(treenode_t *root, int x) {
    if(root == nullptr){
        treenode_t *temp = new treenode_t(to_string(x));
        return temp;
    }
    if(x > stoi(root->data))
        root->rchild = insertNode(root->rchild, x);
    else if(x < stoi(root->data))
        root->lchild = insertNode(root->lchild, x);

    return root;
}

treenode_t *BinarySearchTree::deleteNode(treenode_t *root, int x) {
    if(root == nullptr) return nullptr;
    if(x > stoi(root->data))
        root->rchild = deleteNode(root->rchild, x);
    else if(x < stoi(root->data))
        root->lchild = deleteNode(root->lchild, x);
    else{
        if(root->lchild == nullptr && root->rchild == nullptr){
            //root is leaf node
            delete root;
            return nullptr;
        }else if(root->lchild != nullptr && root->rchild != nullptr){
            //root is degree-2 node
            treenode_t* replace = minNode(root->rchild);
            root->data = replace->data;
            root->rchild = deleteNode(root->rchild, stoi(replace->data));
            /*
             * treenode_t* replace = maxNode(root->lchild);
             * root->data = replace->data;
             * root->lchild = deleteNode(root->lchild, stoi(replace->data);
             */
        }else{
            //root is degree-1 node
            treenode_t *temp;
            if(root->lchild) temp = root->lchild;
            else temp = root->rchild;
            delete root;
            return temp;
        }
    }
    return root;
}

string BinarySearchTree::minNode() {
    return minNode(this->root)->data;
}
string BinarySearchTree::maxNode() {
    return maxNode(this->root)->data;
}
void BinarySearchTree::deleteNode(int x) {
    this->root = deleteNode(this->root, x);
}
treenode_t* BinarySearchTree::minNode(treenode_t* root){
    if(root->lchild == nullptr) return root;
    else return minNode(root->lchild);
}
treenode_t* BinarySearchTree::maxNode(treenode_t *root) {
    if(root->rchild == nullptr) return root;
    else return maxNode(root->rchild);
}
void BinarySearchTree::insertNode(int x) {
    root = insertNode(root, x);
}
BinarySearchTree::BinarySearchTree(int arr[], int len): BinaryTree() {
    for(int i = 0; i < len; i++){
        int current = arr[i];
        insertNode(current);
    }
}

bool BinarySearchTree::searchNode(treenode_t *root, int x) {
    if(root == nullptr) return false;
    if(x > stoi(root->data)) return searchNode(root->rchild, x);
    if(x < stoi(root->data)) return searchNode(root->lchild, x);
    return true;
}

void BinarySearchTree::searchNode(int x) {
    if(searchNode(this->root, x)){
        cout << "search for " << x << " is successful." << endl;
    }else{
        cout << "search for " << x << " is unsuccessful." << endl;
    }
}
