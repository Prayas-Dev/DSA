#include<iostream>
#include <vector>
using namespace std;

int binarysearch(vector<int>& nums, int k, int si, int ei) {
    if (si > ei) {
        return -1; // Element not found
    }

    int mid = si + (ei - si) / 2;

    // Check if the mid element is the target
    if (nums[mid] == k) {
        return mid; // Element found
    }

    // Determine which side is sorted
    if (nums[si] <= nums[mid]) { // Left half is sorted
        if (k >= nums[si] && k < nums[mid]) {
            return binarysearch(nums, k, si, mid - 1); // Search in the left half
        } else {
            return binarysearch(nums, k, mid + 1, ei); // Search in the right half
        }
    } else { // Right half is sorted
        if (k > nums[mid] && k <= nums[ei]) {
            return binarysearch(nums, k, mid + 1, ei); // Search in the right half
        } else {
            return binarysearch(nums, k, si, mid - 1); // Search in the left half
        }
    }
}

// Example usage
int main(){
vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
int k = 0;
int result = binarysearch(nums, k, 0, nums.size() - 1);
cout<<result<<endl;

return 0;
}