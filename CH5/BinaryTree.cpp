#include "BinaryTree.hpp"
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

BinaryTree::BinaryTree(string arr[], int size) {
    if (size == 0) {
        root = nullptr;
        return;
    }

    queue<q_t> q;
    root = new treenode_t(arr[0]);
    q.push(q_t(root, 0));

    while (!q.empty()) {
        q_t qtTemp = q.front();
        q.pop();

        treenode_t* current = qtTemp.node;
        int num = qtTemp.index;
        int NL = 2 * num + 1;
        int NR = 2 * (num + 1);

        if (NL < size && !arr[NL].empty()) {
            treenode_t* nodeL = new treenode_t(arr[NL]);
            current->lchild = nodeL;
            q.push(q_t(nodeL, NL));
        }
        if (NR < size && !arr[NR].empty()) {
            treenode_t* nodeR = new treenode_t(arr[NR]);
            current->rchild = nodeR;
            q.push(q_t(nodeR, NR));
        }
    }
}

treenode_t *BinaryTree::getRoot() {
    return this->root;
}

treenode_t* BinaryTree::copyTree(treenode_t *root) {
    if(root == nullptr){
        return nullptr;
    }else{
        treenode_t* temp = new treenode_t(root->data);
        temp->lchild = copyTree(root->lchild);
        temp->rchild = copyTree(root->rchild);
        return temp;
    }
}

BinaryTree::BinaryTree(BinaryTree &bt) {
    this->root = copyTree(bt.getRoot());
}

void BinaryTree::inorder_traversal(treenode_t* root) {
    if(root == nullptr){
        return;
    }else{
        inorder_traversal(root->lchild);
        cout << " " << root->data << " ";
        inorder_traversal(root->rchild);
    }
}

void BinaryTree::postorder_traversal(treenode_t *root) {
    if(root == nullptr){
        return;
    }else{
        postorder_traversal(root->lchild);
        postorder_traversal(root->rchild);
        cout << " " << root->data << " ";
    }
}

void BinaryTree::preorder_traversal(treenode_t *root) {
    if(root == nullptr){
        return;
    }else{
        cout << " " << root->data << " ";
        preorder_traversal(root->lchild);
        preorder_traversal(root->rchild);
    }
}
void BinaryTree::levelorder_traversal(treenode_t *root){
    if(root == nullptr){
        return;
    }else{
        queue<treenode_t*> q;
        q.push(root);
        while(!q.empty()){
            treenode_t* current = q.front();
            q.pop();
            cout << " " << current->data << " ";
            if(current->lchild) q.push(current->lchild);
            if(current->rchild) q.push(current->rchild);
        }
    }
}
void BinaryTree::levelorder_traversal(){
    levelorder_traversal(this->root);
    cout << endl;
}

bool BinaryTree::isEqual(treenode_t *s, treenode_t *t) {
    bool res = false;
    if(s == nullptr && t == nullptr){
        res = true;
    }else if(s != nullptr && t != nullptr){
        if(s->data == t->data){
            if(isEqual(s->lchild, t->lchild)){
                if(isEqual(s->rchild, t->rchild)){
                    res = true;
                }
            }
        }
    }
    return res;
}

int BinaryTree::countTotalNodes(treenode_t *root) {
    if(root == nullptr) return 0;
    return countTotalNodes(root->lchild) + countTotalNodes(root->rchild) + 1;
}
int BinaryTree::countLeafNodes(treenode_t* root) {
    if(root == nullptr) return 0;
    if(root->lchild == nullptr && root->rchild == nullptr){
        return 1;
    }else{
        return countLeafNodes(root->lchild) + countLeafNodes(root->rchild);
    }
}

int BinaryTree::countDegree1Nodes(treenode_t* root) {
    if(root == nullptr) return 0;
    if(root->lchild && !(root->rchild)){
        return countDegree1Nodes(root->lchild) + 1;
    }else if(!(root->lchild) && root->rchild){
        return countDegree1Nodes(root->rchild) + 1;
    }else{
        return countDegree1Nodes(root->lchild) + countDegree1Nodes(root->rchild);
    }
}

int BinaryTree::countDegree2Nodes(treenode_t* root) {
    if(root == nullptr) return 0;
    if(root->lchild != nullptr && root->rchild != nullptr){
        return countDegree2Nodes(root->lchild) + countDegree2Nodes(root->rchild) + 1;
    }else{
        return countDegree2Nodes(root->lchild) + countDegree2Nodes(root->rchild);
    }
}

int BinaryTree::countHeight(treenode_t *root) {
    if(root == nullptr) return 0;
    return max(countHeight(root->lchild), countHeight(root->rchild)) + 1;
}

void BinaryTree::swapTree(treenode_t *root) {
    if(root == nullptr) return;
    swapTree(root->lchild);
    swapTree(root->rchild);
    treenode_t * temp = root->lchild;
    root->lchild = root->rchild;
    root->rchild = temp;
    return;
}

double BinaryTree::expressionEvaluation(treenode_t* root) {
    if(root == nullptr) return 0;
    if(root->lchild == nullptr && root->rchild == nullptr) //root is operand
        return stod(root->data);
    double x = expressionEvaluation(root->lchild);
    double y = expressionEvaluation(root->rchild);
    return op(x, y, root->data);
}

double BinaryTree::op(double x1, double x2, string op){

    if(op == "+") return x1 + x2;
    if(op == "-") return x1 - x2;
    if(op == "*") return x1 * x2;
    if(op == "/") return x1 / x2;
    if(op == "^") return pow(x1, x2);

    return INT_MIN;
}

double BinaryTree::expressionEvaluation() {
    return expressionEvaluation(this->root);
}
void BinaryTree::swapTree() {
    swapTree(this->root);
    return;
}

int BinaryTree::countHeight(){
    return countHeight(this->root);
}
int BinaryTree::countDegree2Nodes() {
    return countDegree2Nodes(this->root);
}

int BinaryTree::countDegree1Nodes() {
    return countDegree1Nodes(this->root);
}
int BinaryTree::countLeafNodes() {
    return countLeafNodes(this->root);
}
int BinaryTree::countTotalNodes() {
    return countTotalNodes(this->root);
}
bool BinaryTree::isEqual(BinaryTree &bt) {
    return isEqual(this->root, bt.getRoot());
}
void BinaryTree::preorder_traversal() {
    preorder_traversal(this->root);
    cout << endl;
}
void BinaryTree::inorder_traversal() {
    inorder_traversal(this->root);
    cout << endl;
}
void BinaryTree::postorder_traversal() {
    postorder_traversal(this->root);
    cout << endl;
}
