/* Author: Aastha Agrawal
 * Infix to postfix
 * Assuming a valid string
 */

#include<bits/stdc++.h>
using namespace std;

bool isOperand(char ch){
    if(ch=='+' ||ch=='-' || ch=='*' || ch=='/' || ch=='^' )
        return true;
    else
        return false;
}

int priority(char ch){
    switch(ch){
        case '+':return 1;
        case '-':return 1;
        case '*':return 2;
        case '/':return 2;
        case '^':return 3;
    }
}

void toPostfix(string exp){
    int i=0;
    stack<char> st;
    while(exp[i]!='\0'){
        if(exp[i]=='(')
            st.push(exp[i]);
        else if(exp[i]==')'){
            while(st.top()!='('){
                cout<<st.top();
                st.pop();
            }
            st.pop();
        }
        else if(!isOperand(exp[i]))
            cout<<exp[i];
        else{
            if(st.empty()){
                st.push(exp[i]);
            }
            else{
                if(priority(exp[i])<priority(st.top())){
                    int prior=priority(exp[i]);
                    while(prior<priority(st.top())){
                        cout<<st.top();
                        st.pop();
                    }
                    st.push(exp[i]);
                }
                else
                    st.push(exp[i]);
            }
        }
        i++;
    }
    while(st.empty()==false){
        cout<<st.top();
        st.pop();
    }
}

int main() {
    string iExp="a+b*c+d*e+f";
    toPostfix(iExp);
	return 0;
}
