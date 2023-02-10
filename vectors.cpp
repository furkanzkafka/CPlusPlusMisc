// Furkan Ozddemir

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool stack_parantheses(string test_input) {
   // implementing variables and objects
   stack<char> stack_1;
   char parantheses_check;

   for (int i = 0; i < test_input.length(); i++){
       // Checking if input meets the criteria that was given
       if (test_input[i] == '(' || test_input[i] == '{' || test_input[i] == '[') {
            stack_1.push(test_input[i]);
               continue;
        }
       
       // Returning false if input doesn't meet the criteria
       if (stack_1.empty()){
           cout << "Invalid entry or input starts with closed parantheses or braces\n";
           return false;
       }
       
       // Checking open parantheses or braces that is matching closed parantheses
       // if its matching the top of the stack will be saved to parantheses_check
       // variable and will be pop from the stack. Otherwise, function will be return false
       switch (test_input[i]) {
           case ')':{
               parantheses_check = stack_1.top();
               stack_1.pop();
               if (parantheses_check == '{' || parantheses_check == '[') return false;
               break;
           }
           case '}':{
               parantheses_check = stack_1.top();
               stack_1.pop();
               if (parantheses_check == '(' || parantheses_check == '[') return false;
               break;
           }
           case ']':{
               parantheses_check = stack_1.top();
               stack_1.pop();
               if (parantheses_check == '(' || parantheses_check == '{') return false;
               break;
           }
        }
    }
    
    // Returning true if all member of the input matches through
    // that is given by the criteria so the stack will be empty
    if(stack_1.empty()){
        cout << test_input << " is True...\n";
            return true;
    }
    else{
        cout << test_input << " is False...\n";
            return false;
    }
}
    

template <typename T>
void bubble_sort(vector<T> &input_array) {
    // Getting size of the array
    int array_size = input_array.size();
    
    // Checking all member of the array from begining 0 to its size.
    for (int i = 0; i < array_size - 1; i++) {
        // Comparing the numbers next to each other and swapping
        for (int j = 0; j < array_size - 1 - i; j++) {
            if (input_array[j] > input_array[j + 1]) {
                swap(input_array[j], input_array[j + 1]);
            }
        }
    }
}

void print_bubble_sort(vector<int> array_1){
    for (size_t i=0;  i <array_1.size();  i++) {
        cout<<array_1[i]<<" ";
    }
  cout<<endl;
}

//Main driver function
int main() {
    
    string assigment_check;
    cout<<"Please enter which assigment would you like to test: (Type: S(Stack) / V(Vector),  ";
    cin >> assigment_check;
    
    // Calling Stack or Vector assigment by user input
    if(assigment_check == "S" || assigment_check == "s"){
        // Calling the function test case 1 ready
        string test_case_1 = "(a[()9])";
        stack_parantheses(test_case_1);
        // Calling the function test case 2 ready
        string test_case_2 = "(((([t(k7)]";
        stack_parantheses(test_case_2);
        // Calling the function test case 3 ready
        string test_case_3 = "){(ab)[]}(";
        stack_parantheses(test_case_3);
        // Calling the function test case 4 ready
        string test_case_4 = "(3)(m)[{}]";
        stack_parantheses(test_case_4);
        // Calling the function test case 5 ready
        string test_case_5 = "(n)([()]2{5})";
        stack_parantheses(test_case_5);
        
        // Calling the function with user input
        string user_input;
        cout<<"Enter an test input: ";
        cin >> user_input;
        stack_parantheses(user_input);
    }
    else if (assigment_check == "V" || assigment_check == "v"){
        // Test case 1
        vector<int> vector_array_1 {1,2,3,4,5,6,7};
        // Test case 2
        vector<int> vector_array_2 {7,6,5,4,3,2,1};
        // Test case 3
        vector<int> vector_array_3 {7,1,5,2,4,3,6};
        // Test case 4
        vector<int> vector_array_4 {5,1,4,7,3,2,9,8,10};
        
        // Caling print function before calling sort function and after
        cout << "Array before sort: \n";
        print_bubble_sort(vector_array_1);
        bubble_sort(vector_array_1);
        cout << "Array after sort: \n";
        print_bubble_sort(vector_array_1);
        
        // Caling print function before calling sort function and after
        cout << "Array before sort: \n";
        print_bubble_sort(vector_array_2);
        bubble_sort(vector_array_2);
        cout << "Array after sort: \n";
        print_bubble_sort(vector_array_2);
        
        // Caling print function before calling sort function and after
        cout << "Array before sort: \n";
        print_bubble_sort(vector_array_3);
        bubble_sort(vector_array_3);
        cout << "Array after sort: \n";
        print_bubble_sort(vector_array_3);
        
        // Caling print function before calling sort function and after
        cout << "Array before sort: \n";
        print_bubble_sort(vector_array_4);
        bubble_sort(vector_array_4);
        cout << "Array after sort: \n";
        print_bubble_sort(vector_array_4);
    }
    
    return 0;
}
