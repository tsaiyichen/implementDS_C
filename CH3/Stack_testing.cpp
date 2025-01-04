#include "Stack_Array.hpp"
#include "Stack_LL.hpp"
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<char, int> ProcedureTable {};

void initTable(){
    ProcedureTable['('] = 0;
    ProcedureTable['+'] = 10;
    ProcedureTable['-'] = 10;
    ProcedureTable['*'] = 20;
    ProcedureTable['/'] = 20;
}
void infix_to_postfix(string expression){
    Stack_Array stack;
    initTable();
    for(int i = 0; i < expression.size(); i++){
        char x = expression[i];
        if(x >= 'a' && x <= 'z'){
            cout << x;
            continue;
        }else{
            char top = stack.peek();
            if(x == ')') {
                while (top != '(') {
                    cout << char(stack.pop());
                    top = stack.peek();
                }
                stack.pop();
                continue;
            }
            if(x == '(' || stack.isEmpty() || ProcedureTable.at(x) > ProcedureTable.at(top)){
                stack.push(x);
            }else{
                    do{
                        cout << char(stack.pop());
                        top = stack.peek();
                    }while(!stack.isEmpty() && ProcedureTable.at(x) <= ProcedureTable.at(top));
                    stack.push(x);


            }
        }
    }
    while(!stack.isEmpty()){
        cout << char(stack.pop());
    }
}
int postfixEvaluation(string expression){
    //Caution: not work for double(divided)
    Stack_Array stack;
    for(int i = 0; i < expression.size(); i++){
        char x = expression[i];
        if(x >= '0' && x <= '9'){
            stack.push(x - '0');
        }else{
            int n1 = stack.pop();
            int n2 = stack.pop();
            int res;
            switch (x) {
                case '+':
                    res = n2 + n1;
                    break;
                case '-':
                    res = n2 - n1;
                    break;
                case '*':
                    res = n2 * n1;
                    break;
                case '/':
                    res = n2 / n1;
                    break;
            }
            stack.push(res);
        }
    }

    return stack.peek();
}
int main(){
    infix_to_postfix("a+b*c-d/e");
    cout << endl;
    infix_to_postfix("(a*b+c)+d/(e+f)");
    cout << endl;
    cout << postfixEvaluation("912*-62+-") << endl;
}