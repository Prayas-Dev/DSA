#include<iostream>
#include<string>
#include<cctype>

using namespace std;

class Solution{
        bool isAlphaNum(char ch){
            if((tolower(ch)>='a' && tolower(ch)<='z') ||
            (ch>='0' && ch<='9')){
                return true;
            }
            return false;
        }
    public:
        bool isPalindrome(string str){
            int st=0,end=str.length()-1;
            while(st<end){
                if(!isAlphaNum(str[st])){
                    st++;continue;
                }
                if(!isAlphaNum(str[end])){
                    end--;continue;
                }
                if(tolower(str[st])!=tolower(str[end])){
                    return false;
                }
                st++;end--;
            }
            return true;
        }
};

int main(){
    Solution sol;
    string str="Le34el";
    if(sol.isPalindrome(str)){
        cout<<"String is valid Palindrome"<<endl;
    }
    else{
        cout<<"String is not valid Palindrome"<<endl;
    }

    return 0;
}