#include "HashTable.hpp"
#include <iostream>

using namespace std;

HashTable::HashTable(string overflowHandling) {
    OFH = overflowHandling;
    for(int i = 0; i < 10; i++){
        //no data, init
        arr[i] = -1;
    }
}

int HashTable::hashFunction(int n) {
    return n % 10;
}

int HashTable::secondFunction(int n) {
    return 7 - (n % 7);
}

void HashTable::insertKey(int x) {
    int hashAddress = hashFunction(x);
    if(arr[hashAddress] == -1){
        arr[hashAddress] = x;
        return;
    }else{
        //overflow
        if(OFH == "linear"){
            int index = (hashAddress + 1) % 10;
            while(index != hashAddress){
                if(arr[index] == -1){
                    //have space
                    arr[index] = x;
                    return;
                }
                index = (index + 1) % 10;
            }
            cout << "table full." << endl;
        }else if(OFH == "quadratic"){
            int exp = 1;
            int index = (hashAddress + exp * exp) % 10;
            while(exp <= 5){
                if(arr[index] == -1){
                    //have space
                    arr[index] = x;
                    return;
                }
                exp++;
                index = (hashAddress + exp * exp) % 10;
            }
            printf("can't put %d inside\n", x);
        }else{ //double hashing
            int slot = secondFunction(x);
            int k = 1;
            int index = (hashAddress + k * slot) % 10;
            while(k <= 10){
                if(arr[index] == -1){
                    //have space
                    arr[index] = x;
                    return;
                }
                k++;
                index = (hashAddress + k * slot) % 10;
            }
            printf("can't put %d inside\n", x);
        }
    }
}

void HashTable::deleteKey(int x) {
    if(searchKey(x) == -1) return;
    arr[searchKey(x)] = -1;
}

int HashTable::searchKey(int x) {
    int hashAddress = hashFunction(x);
    if(arr[hashAddress] == x){
        return hashAddress;
    }else if(arr[hashAddress] == -1){
        cout << "No data " << x << endl;
        return -1;
    }else{//overflow in other bucket, opening addressing mode
        if(OFH == "linear"){
            int index = (hashAddress + 1) % 10;
            while(index != hashAddress){
                if(arr[index] == x){
                    //found
                    return index;
                }
                index = (index + 1) % 10;
            }
            cout << "No data " << x << endl;
            return -1;
        }else if(OFH == "quadratic"){
            int exp = 1;
            int index = (hashAddress + exp * exp) % 10;
            while(exp <= 5){
                if(arr[index] == x){
                    //found
                    return index;
                }
                exp++;
                index = (hashAddress + exp * exp) % 10;
            }
            cout << "No data " << x << endl;
            return -1;
        }else{ //double hashing
            int slot = secondFunction(x);
            int k = 1;
            int index = (hashAddress + k * slot) % 10;
            while(k <= 10){
                if(arr[index] == x){
                    //found
                    return index;
                }
                k++;
                index = (hashAddress + k * slot) % 10;
            }
            cout << "No data " << x << endl;
            return -1;
        }

    }
}

void HashTable::printTable() {
    for(int i = 0; i < 10; i++){
        printf("#%d, %d\n", i, arr[i]);
    }
}
