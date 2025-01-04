//
// Created by eason on 2025/1/4.
//

#ifndef IMPLEMENTDS_C_BINARYSEARCHTREE_HPP
#define IMPLEMENTDS_C_BINARYSEARCHTREE_HPP
#include "BinaryTree.hpp"
#include <iostream>

using namespace std;


class BinarySearchTree: public BinaryTree {
public:
    BinarySearchTree(int arr[], int len);
    void insertNode(int x);
    void deleteNode(int x);
    string maxNode();
    string minNode();
    void searchNode(int x);
private:
    treenode_t* insertNode(treenode_t *root, int x);
    treenode_t* deleteNode(treenode_t *root, int x);
    treenode_t* minNode(treenode_t* root);
    treenode_t* maxNode(treenode_t *root);
    bool searchNode(treenode_t *root, int x);
};


#endif //IMPLEMENTDS_C_BINARYSEARCHTREE_HPP
