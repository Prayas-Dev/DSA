#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

vector<int> reverseArray(int a_count, const vector<int>& a){
    vector<int> reversedArray(a_count);

    for(int i=0;i<a_count;i++){
        reversedArray[i]=a[a_count - 1 - i];
    }
    return reversedArray;
}
int main(){
    vector<int> a = {1,2,3,4,5};
    int a_count = a.size();

    vector<int> reversed = reverseArray(a_count,a);

    cout<<"Reversed Array : ";
    for(int i=0;i<reversed.size();i++){
        cout<<reversed[i]<<" ";
    }
    cout<<endl;

    return 0;
}