#include<iostream>
#include<vector>

using namespace std;

class SolutionOne {
public:
    bool doesValidArrayExist(vector<int>& derived) {
         int n = derived.size();
        if(n<1){
            return false;
        }
        int current = 1;

        for (int i = 0; i < n - 1; i++)
        {
            current ^= derived[i];
        }

        if (current ^ 1 == derived[n - 1])
        {
            return true;
        }
        else
        {
            current = 0;

            for (int i = 0; i < n - 1; i++)
            {
                current ^= derived[i];
            }

            if (current^0 == derived[n - 1])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
};

class SolutionTwo {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        if(n<1){
            return false;
        }

        int current = 0;

        for (int i = 0; i < n; i++)
        {
            current ^= derived[i];
        }

        if (current == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main(){
    SolutionOne sol1;
    SolutionTwo sol2;
    vector<int>derived={1,0};
    // int result=sol1.doesValidArrayExist(derived);
    int result=sol2.doesValidArrayExist(derived);

    if(result==0){
        cout<<"false";
    }
    else{
        cout<<"true";
    }

    return 0;
}