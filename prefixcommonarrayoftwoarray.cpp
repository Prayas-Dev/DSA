#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class SolutionOne{                          // O(n^3) O(1)
    public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B){
        vector<int>ans;
        for(int i=0;i<A.size();i++){
            int count=0;
            for(int A_i=0;A_i<=i;A_i++){
                for(int j=0;j<=i;j++){
                    if(A[A_i]==B[j]){
                        count++;
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};

class SolutionTwo{                      // O(n^2) O(n)
    public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B){
        int n=A.size();
        vector<int>ans;
        vector<bool> isPresentA(n+1,false);
        vector<bool> isPresentB(n+1,false);

        for(int i=0;i<n;i++){
            isPresentA[A[i]]=true;
            isPresentB[B[i]]=true;
            int count=0;
            for(int i=1;i<=n;i++){
                if(isPresentA[i]==true && isPresentB[i]==true){
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};

class SolutionThree{                    // O(n) 0(n)
    public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B){
        int n=A.size();

        vector<int>result(n);

        unordered_map<int,int> mp;

        int count=0;
        for(int i=0;i<n;i++){
            mp[A[i]]++;
            if(mp[A[i]]==2){
                count++;
            }
            mp[B[i]]++;
            if(mp[B[i]]==2){
                count++;    
            }
            result[i]=count;
        }
        return result;
    }
};

int main(){
    // SolutionOne sol1;
    // SolutionTwo sol2;
    SolutionThree sol3;
    vector<int>A={1,3,2,4};
    vector<int>B={3,1,2,4};
    // vector<int>ans=sol1.findThePrefixCommonArray(A,B);
    // vector<int>ans=sol2.findThePrefixCommonArray(A,B);
    vector<int>ans=sol3.findThePrefixCommonArray(A,B);
    for(auto ele:ans){
        cout<<ele<<" ";
    }
    cout<<endl;

    return 0;
}