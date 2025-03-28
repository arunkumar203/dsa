#include <bits/stdc++.h>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Function to convert infix expression to postfix
string infixToPostfix(string s) {
    stack<char> st;  // Stack for operators
    string postfix = "";

    for (char c : s) {
        // If character is an operand, add it to the output
        if (isalnum(c)) {
            postfix += c;
        }
        // If '(' push to stack
        else if (c == '(') {
            st.push(c);
        }
        // If ')' pop and output from stack until '(' is found
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // Pop '('
        }
        // If operator, pop higher precedence operators before pushing
        else {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop all remaining operators
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

// Driver function
int main() {
    string infix = "A+B*(C^D-E)";
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << infixToPostfix(infix) << endl;
    return 0;
}

//infix to prefix
#include <bits/stdc++.h>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Function to convert infix to postfix
string infixToPostfix(string s) {
    stack<char> st;
    string postfix = "";

    for (char c : s) {
        if (isalnum(c)) {
            postfix += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // Remove '('
        }
        else {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

// Function to convert infix to prefix
string infixToPrefix(string infix) {
    // Step 1: Reverse the infix expression
    reverse(infix.begin(), infix.end());

    // Step 2: Swap '(' and ')'
    for (char &c : infix) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }

    // Step 3: Convert to postfix
    string postfix = infixToPostfix(infix);

    // Step 4: Reverse postfix to get prefix
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

// Driver function
int main() {
    string infix = "(A-B/C)*(A/K-L)";
    cout << "Infix: " << infix << endl;
    cout << "Prefix: " << infixToPrefix(infix) << endl;
    return 0;
}




// postfix to infix
#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string postfixToInfix(string postfix) {
    stack<string> st;
    
    for (char c : postfix) {
        if (isalnum(c)) { 
            // Operand: Push as a string
            st.push(string(1, c));
        } else if (isOperator(c)) { 
            // Operator: Pop two elements
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();
            
            // Form the infix expression and push back
            string expr = "(" + op1 + c + op2 + ")";
            st.push(expr);
        }
    }

    // The final result is in the stack
    return st.top();
}

int main() {
    string postfix = "ABC*+D/";
    cout << "Postfix: " << postfix << endl;
    cout << "Infix: " << postfixToInfix(postfix) << endl;
    return 0;
}







//prefix to infix
#include <bits/stdc++.h>
using namespace std;
string prefixToInfix(string prefix) {
    stack<string> st;
    
    // Process the prefix expression from right to left
    for (int i = prefix.size() - 1; i >= 0; i--) {
        char c = prefix[i];

        if (isalnum(c)) { 
            // Operand: Push as a string
            st.push(string(1, c));
        } else if (isOperator(c)) { 
            // Operator: Pop two elements
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            
            // Form the infix expression and push back
            string expr = "(" + op1 + c + op2 + ")";
            st.push(expr);
        }
    }

    // The final result is in the stack
    return st.top();
}

int main() {
    string prefix = "*+AB-CD";
    cout << "Prefix: " << prefix << endl;
    cout << "Infix: " << prefixToInfix(prefix) << endl;
    return 0;
}




//postfix to prefix
#include <bits/stdc++.h>
using namespace std;

// Function to convert Postfix to Prefix
string postfixToPrefix(string postfix) {
    stack<string> st;
    
    for (char c : postfix) {
        if (isalnum(c)) {  // If operand, push to stack
            string op(1, c);
            st.push(op);
        } else {  // If operator, pop two elements
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            
            string newExp = c + op2 + op1; // Form prefix expression
            st.push(newExp);
        }
    }
    
    return st.top(); // Final prefix expression
}

// Driver code
int main() {
    string postfix = "ABC*+D-";
    cout << "Postfix: " << postfix << endl;
    cout << "Prefix: " << postfixToPrefix(postfix) << endl;
    return 0;
}





//pre to post
#include <bits/stdc++.h>
using namespace std;

// Function to check if the character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to convert Prefix to Postfix
string prefixToPostfix(string prefix) {
    stack<string> st;
    
    // Traverse the prefix expression from right to left
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];

        // If the character is an operand, push it to the stack
        if (isalnum(c)) {
            string op(1, c); // Convert character to string
            st.push(op);
        }
        // If the character is an operator
        else if (isOperator(c)) {
            // Pop two operands from the stack
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            
            // Concatenate operands in Postfix order (operand1 operand2 operator)
            string exp = op1 + op2 + c;
            
            // Push the resulting expression back to the stack
            st.push(exp);
        }
    }
    
    // The final result in the stack is the postfix expression
    return st.top();
}

// Driver Code
int main() {
    string prefix = "*+AB-CD";  // Example: Prefix expression
    cout << "Prefix Expression: " << prefix << endl;
    cout << "Postfix Expression: " << prefixToPostfix(prefix) << endl;
    return 0;
}





