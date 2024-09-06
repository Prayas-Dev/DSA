#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<vector<int>>matrix(3,vector<int>(3));
    cout<<"Enter the values of 3 by 3 matrix"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<"The matrix is : "<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Printing the wave pattern of the matrix : "<<endl;

    for(int i=0;i<3;i++){
        if(i%2==0){
            for(int j=0;j<3;j++){
                cout<<matrix[j][i]<<" ";
            }
            cout<<endl;
        }
        else{
            for(int j=2;j>=0;j--){
                cout<<matrix[j][i]<<" ";
            }
            cout<<endl;
        }
    }

    cout<<"Printing the wave pattern column wise matrix : "<<endl;

    for(int i=0;i<3;i++){
        if(i%2==0){
            for(int j=0;j<3;j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        else{
            for(int j=2;j>=0;j--){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}