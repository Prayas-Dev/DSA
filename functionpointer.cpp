#include<iostream>

using namespace std;

bool compare(int a,int b){
    return a<b;
}

void sortArray(int arr[],int size, bool(*comp)(int,int)){
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(!comp(arr[i],arr[j])){
                swap(arr[i],arr[j]);
            }
        }
    }
}

int main(){
    int arr[]={34,12,45,67};
    int size=sizeof(arr)/sizeof(arr[0]);

    cout<<"Original Array : ";

    for(auto ele:arr){
        cout<<ele<<" ";
    }
    cout<<endl;

    sortArray(arr,size,compare);

    cout<<"Array after sorting : ";

    for(auto ele:arr){
        cout<<ele<<" ";
    }
    cout<<endl;
}