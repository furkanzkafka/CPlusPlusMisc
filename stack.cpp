#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string exp) {
    //creating an empty stack
   stack<char> mystack;
   char x;

    //Scanning stack from left to right
   for (int i = 0; i < exp.length(); i++){
           //if(exp[i] == ' ' )continue;
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            mystack.push(exp[i]);
               continue;
           }

       if (mystack.empty()) {
           cout << "Invalid";
           return false;
       };

           switch (exp[i]) {
            case ')':{
                x = mystack.top();
                mystack.pop();
                if (x == '{' || x == '[') return false;
                break;
            }

               case '}':{
                x = mystack.top();
                mystack.pop();
                if (x == '(' || x == '[') return false;
                break;
            }

               case ']':{
                x = mystack.top();
                mystack.pop();
                if (x == '(' || x == '{') return false;
                break;
            }
           }
    }
    return (mystack.empty());
}

//Main driver function
int main() {
       string exp;
    //Prompt user to enter an expression
      cout<<"Enter an expression: ";
      cin >> exp;
       
       //Calling function isBalanced() to check whether expression is balanced or not
       if (isBalanced(exp)) cout <<"true\n";
       else cout <<"false\n";
    return 0;
}
