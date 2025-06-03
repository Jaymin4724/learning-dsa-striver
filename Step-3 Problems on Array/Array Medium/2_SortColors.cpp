// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
// You must solve this problem without using the library's sort function.

// Example 1:
// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

// Example 2:
// Input: nums = [2,0,1]
// Output: [0,1,2]

// Constraints:
// n == nums.length
// 1 <= n <= 300
// nums[i] is either 0, 1, or 2.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Brute Force: Using sort
// Time Complexity: O(nlogn)
// Space Complexity: O(1)
void sortColorsBruteForce(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
}

// Better: Here we are using extra space
// Count the number of 0s, 1s, and 2s in the array
// and then fill the array with 0s, 1s, and 2s in order
// Time Complexity: O(n)
// Space Complexity: O(1)
// This is not optimal as we are using extra space
// and also we are traversing the array multiple times
// but it is better than brute force
void sortColorsBetter(vector<int> &nums)
{
    vector<int> arr(3, 0);
    for (auto i : nums)
    {
        arr[i]++;
    }
    int n = nums.size();
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        while (arr[k] == 0)
        {
            k++;
        }
        nums[i] = k;
        arr[k]--;
    }
}

//? Optimal: Dutch National Flag Algorithm (in-place)
// Time Complexity: O(n)
// Space Complexity: O(1)
// We will use three pointers: low, mid, and high
void sortColorsOptimal(vector<int> &nums)
{
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

void printVector(const vector<int> &nums)
{
    for (int num : nums)
        cout << num << " ";
    cout << endl;
}

int main()
{
    vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    vector<int> nums2 = nums1;
    vector<int> nums3 = nums1;

    sortColorsBruteForce(nums1);
    cout << "Brute Force: ";
    printVector(nums1);

    sortColorsBetter(nums2);
    cout << "Better: ";
    printVector(nums2);

    sortColorsOptimal(nums3);
    cout << "Optimal: ";
    printVector(nums3);

    return 0;
}