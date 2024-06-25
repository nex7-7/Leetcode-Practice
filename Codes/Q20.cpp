#include <iostream>
using namespace std;

class Stack {
private:

    int top = -1;
    int size;
    char* arr;

public:

    Stack(int s){
        size = s;
        arr = new char[size];
    }
    
    bool isEmpty(){
        if(top == -1)
            return true;
        else
            return false;
    }

    bool isFull(){
        if(top == size - 1)
            return true;
        else
            return false;
    }

    void push(char ele){
        if(!isFull()){
            top++;
            arr[top] = ele;
        }
    }

    char pop(){
        char ret = '0';
        if(!isEmpty()){
            ret = arr[top];
            top --;
        }
        return ret;
    }
};

class Solution {
public:
    bool isValid(string s) {

        int size = s.length();
        bool valid = false;

        if(size > 1){
            Stack st(size);
            char ele;

            char open[3] = {'(','{','['}; 
            char close[3] = {')','}',']'}; 

            valid = true;

            for(int i = 0; i < size; i++){
                int j = 0;
                bool type = false;
                for(j; j < 3; j++){
                    if(s[i] == close[j]){
                        type = true;
                        break;
                    }
                }
                if(type){
                    ele = st.pop();
                    if(ele != open[j]){
                        valid = false;
                        break;
                    }
                }
                else
                    st.push(s[i]);
            }

            if(!st.isEmpty()){
                valid = false;
            }
        }

        return valid;
    }
};

// int main(){
//     Solution sol;
//     bool a = sol.isValid("()");
//     cout<<a;
//     return 0;
// }