#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution{
    public:
    bool isValid(string s){
        int n = s.length();

        if(n%2!=0){
            return false;
        }
        stack<char>open;

        for(char &ch:s){
            if(ch=='('){
                open.push('(');
            }
            else if(ch=='{'){
                open.push('{');
            }
            else if(ch=='['){
                open.push('[');
            }
            else if(ch==')'){
                if(!open.empty() && open.top()=='('){
                    open.pop();
                }
                else{
                    return false;
                }
            }
            else if(ch=='}'){
                if(!open.empty() && open.top()=='{'){
                    open.pop();
                }
                else{
                    return false;
                }
            }
            else if(ch==']'){
                if(!open.empty() && open.top()=='['){
                    open.pop();
                }
                else{
                    return false;
                }
            }
        }
        return open.empty();
    }
};

int main(){
    Solution sol;

    string s="({[]})";
    cout<<sol.isValid(s);

    return 0;
}