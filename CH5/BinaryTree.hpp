#ifndef IMPLEMENTDS_C_BINARYTREE_HPP
#define IMPLEMENTDS_C_BINARYTREE_HPP
#include <iostream>

using namespace std;

struct treenode_t {
    string data;
    treenode_t *lchild = nullptr;
    treenode_t *rchild = nullptr;

    explicit treenode_t(string s){data = s;}
};

struct q_t {
    treenode_t* node;
    int index;

    q_t(treenode_t* n, int i) : node(n), index(i) {}
};


class BinaryTree {
protected:
    treenode_t* root = nullptr;
    void inorder_traversal(treenode_t *root);
    void postorder_traversal(treenode_t *root);
    void preorder_traversal(treenode_t *root);
    void levelorder_traversal(treenode_t *root);
    treenode_t* copyTree(treenode_t *root);
    bool isEqual(treenode_t *s, treenode_t *t);
    int countTotalNodes(treenode_t *root);
    int countLeafNodes(treenode_t *root);
    int countDegree1Nodes(treenode_t* root);
    int countDegree2Nodes(treenode_t *root);
    int countHeight(treenode_t* root);
    void swapTree(treenode_t* root);
    double expressionEvaluation(treenode_t* root);
    double op(double x1, double x2, string op);
public:
    BinaryTree() = default;
    BinaryTree(string arr[], int size);
    BinaryTree(BinaryTree &bt);
    treenode_t* getRoot();
    void inorder_traversal();
    void postorder_traversal();
    void preorder_traversal();
    void levelorder_traversal();
    bool isEqual(BinaryTree &bt);
    int countTotalNodes();
    int countLeafNodes();
    int countDegree1Nodes();
    int countDegree2Nodes();
    int countHeight();
    void swapTree();
    double expressionEvaluation();
};


#endif //IMPLEMENTDS_C_BINARYTREE_HPP
