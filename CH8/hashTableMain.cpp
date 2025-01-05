#include <iostream>
#include "HashTable.hpp"

using namespace std;

int main(){
    HashTable h("double hashing");

    while(true){
        int x;
        cout << "enter number to insert(-1 end): ";
        cin >> x;
        if(x == -1) break;
        h.insertKey(x);
    }

    while(true){
        int x;
        cout << "enter number to search(-1 end): ";
        cin >> x;
        if(x == -1) break;
        printf("data %d is in %d bucket.\n", x, h.searchKey(x));
    }

}