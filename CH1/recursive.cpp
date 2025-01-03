#include <iostream>

using namespace std;

int factorial_recursive(int n){
    if(n == 0) return 1;
    else return factorial_recursive(n - 1) * n;
}

int factorial_iterative(int n){
    int total = 1;
    for(int i = 2; i <= n; i++){
        total *= i;
    }
    return total;
}

int fib_recursive(int n){
    if(n <= 1) return n;
    else return fib_recursive(n - 1) + fib_recursive(n - 2);
}

int fib_iterative(int n){
    int a = 0;
    int b = 1;
    int c;
    for(int i = 2; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int combination_recursive(int n, int r){
    //C(n, r) e.g. C(5, 2) = 10
    if(n == r || r == 0) return 1;
    else return combination_recursive(n - 1, r - 1) + combination_recursive(n - 1, r);
}

int combination_iterative(int n, int r){
    //C(n, r) e.g. C(5, 2) = 10
    int ans = 1;
    int k = ((n - r) > r) ? r : (n - r);
    for(int i = 1; i <= k; i++){
        ans *= (n - i + 1);
    }
    for(int i = 1; i <= k; i++){
        ans /= i;
    }
    return ans;
}

int GCD_recursive(int m, int n){
    if(m % n == 0) return n;
    else return GCD_recursive(n, m % n);
}
int GCD_iterative(int m, int n){
    int k = (m < n) ? m : n;
    int GCD = 1;
    for(int i = 2; i <= k; i++){
        if(m % i == 0 && n % i == 0) GCD = i;
    }
    return GCD;
}

int Exp_BigOhN(int x, int n){
    //e.g. Exp(2, 5) = 2^5 = 32
    if(n == 0) return 1;
    else return Exp_BigOhN(x, n - 1) * x;
}

int Exp_BigOhLogN(int x, int n){
    int k = (n % 2 == 0) ? 1 : x;
    if(n == 0) return 1;
    else return Exp_BigOhLogN(x, n / 2) * Exp_BigOhLogN(x, n / 2) * k;
}

void TowerOfHanoi(char a, char b, char c, int n){
    if(n == 1){
        printf("move disk 1 from %c to %c\n", a, c);
        return;
    }
    TowerOfHanoi(a, c, b, n - 1);
    printf("move disk %d from %c to %c\n", n, a, c);
    TowerOfHanoi(b, a, c, n - 1);
}

void swap(string &s, int a, int b){
    char temp = s[a];
    s[a] = s[b];
    s[b] = temp;
}

void printAllPermutation(string str, int start, int end, int n){
    if(start == end){
        cout << str << endl;
        return;
    }
    for(int i = start; i <= end; i++){
        swap(str, start, i);
        printAllPermutation(str, start + 1, end, n);
        swap(str, start, i);
    }
}