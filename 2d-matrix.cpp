#include<iostream>

using namespace std;

int main(){
	int arr[3][3];
	cout<<"Enter the elements in the matrix : ";
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cin>>arr[i][j];
		}
		cout<<endl;
	}
	
	cout<<"Printing the row-wise sum"<<endl;
	
		for(int i=0;i<3;i++){
		int sum=0;
		for(int j=0;j<3;j++){
			sum+=arr[i][j];
		}
		cout<<sum<<endl;
	}
		
	
	cout<<"Printing the column-wise sum"<<endl;
	for(int i=0;i<3;i++){
		int sum=0;
		for(int j=0;j<3;j++){
			sum+=arr[j][i];
		}
		cout<<sum<<endl;
	}
	
	return 0;
}