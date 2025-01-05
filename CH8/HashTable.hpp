#ifndef IMPLEMENTDS_C_HASHTABLE_HPP
#define IMPLEMENTDS_C_HASHTABLE_HPP
#include <iostream>
using namespace std;
class HashTable {
private:
    int arr[10];
    int hashFunction(int n);
    int secondFunction(int n);
    string OFH;
public:
    HashTable(string overflowHandling);
    void insertKey(int x);
    void deleteKey(int x);
    int searchKey(int x);
    void printTable();
};


#endif //IMPLEMENTDS_C_HASHTABLE_HPP
