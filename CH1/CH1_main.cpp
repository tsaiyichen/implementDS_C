#include "recursive.cpp"
#include <iostream>

using namespace std;

int main(){
    cout << "5! = " << factorial_recursive(5) << endl;
    cout << "6! = " << factorial_iterative(6) << endl;

    cout << "F5: " << fib_recursive(5) << endl;
    cout << "F6: " << fib_iterative(6) << endl;

    cout << "C(5, 2) = " << combination_recursive(5, 2) << endl;
    cout << "C(8, 4) = " << combination_iterative(8, 4) << endl;

    cout << "GCD(119, 35) = " << GCD_recursive(119, 35) << endl;
    cout << "GCD(45, 30) = " << GCD_iterative(45, 30) << endl;

    cout << "3^5 = " << Exp_BigOhN(3, 5) << endl;
    cout << "4^3 = " << Exp_BigOhLogN(4, 3) << endl;

    TowerOfHanoi('a', 'b', 'c', 3);
    printAllPermutation("abc", 0, 2, 3);
}