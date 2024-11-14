#include <iostream>
#include <climits>

using namespace std;

int bruteforce(int arr[], int n)
{
    int maxSum = INT_MIN;
    for (int st = 0; st < n; st++)
    {
        int currSum = 0;
        for (int end = st; end < n; end++)
        {
            currSum += arr[end];
            maxSum = max(currSum, maxSum);
        }
    }
    return maxSum;
}

int kadanesalgorithm(int arr[],int n){
    int currSum=0, maxSum=INT_MIN;

    for(int st=0;st<n;st++){
        currSum+=arr[st];
        maxSum=max(currSum,maxSum);

        if(currSum<0){
            currSum=0;
        }
    }
    return maxSum;
}

int main()
{
    // brute force
    int arr[7] = {3, -4, 5, 4, -1, 7, -8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Sum of Max Sub array by brute force : " << bruteforce(arr, n)<<endl;     // O(n^2)
    cout<<"Sum of Max Sub array by kadanesalgorithm : "<<kadanesalgorithm(arr,n);

    return 0;
}