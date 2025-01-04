#include <iostream>
#include "BinaryTree.hpp"
#include "BinarySearchTree.hpp"
using namespace std;

int main(){
    string bt1Arr[10] = {"A", "B", "C", "D", "E", "", "G", "", "", "H"};
    int arrayLength = sizeof(bt1Arr) / sizeof(bt1Arr[0]);
    BinaryTree bt1(bt1Arr, arrayLength);
    cout << "BT1: " << endl;
    bt1.inorder_traversal();
    bt1.postorder_traversal();
    bt1.preorder_traversal();
    bt1.levelorder_traversal();
    BinaryTree bt2(bt1);
    cout << "BT2: " << endl;
    bt2.inorder_traversal();
    bt2.postorder_traversal();
    bt2.preorder_traversal();
    bt2.levelorder_traversal();
    cout << "BT1 vs BT2: " <<  bt1.isEqual(bt2) << " (same: 1, different: 0)" << endl;
    cout << "the number of total nodes of BT1: " << bt1.countTotalNodes() << endl;
    cout << "the number of total \"leaf\" nodes of BT1: " << bt1.countLeafNodes() << endl;
    cout << "the number of total \"degree-1\" nodes of BT1: " << bt1.countDegree1Nodes() << endl;
    cout << "the number of total \"degree-2\" nodes of BT1: " << bt1.countDegree2Nodes() << endl;
    cout << "this tree height: " << bt1.countHeight() << endl;
    bt1.swapTree();
    cout << "After swap: inorder traversal = ";
    bt1.inorder_traversal();
    cout << "After swap: postorder traversal = ";
    bt1.postorder_traversal();
    string express[11]{"-", "-", "+", "9", "*", "6", "2", "", "", "1", "2"};
    BinaryTree expBT(express, 11);
    expBT.postorder_traversal();
    cout << "evalution result: " << expBT.expressionEvaluation() << endl;
    string express2[15]{"*", "-", "+", "4", "3", "5", "/", "", "", "", "", "", "", "6", "3"};
    BinaryTree expBT2(express2, 15);
    expBT2.postorder_traversal();
    cout << "evalution result: " << expBT2.expressionEvaluation() << endl;

    cout << "-------------------BST-------------------" << endl;
    int bstArr[9] = {10, 33, 15, 8, 4, 5, 6, 26, 40};
    BinarySearchTree bst1(bstArr, 9);
    bst1.inorder_traversal();
    bst1.insertNode(37);
    bst1.inorder_traversal();
    bst1.deleteNode(26);
    bst1.inorder_traversal();
    cout << "max: " << bst1.maxNode() << endl;
    cout << "min: " << bst1.minNode() << endl;
    bst1.searchNode(33);
    bst1.searchNode(54);
}