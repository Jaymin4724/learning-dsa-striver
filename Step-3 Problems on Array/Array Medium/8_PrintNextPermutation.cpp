// Next Permutation
// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

// For example,
// for arr = [1,2,3], all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
// The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
// Given an array of integers nums, find the next permutation of nums.

// The replacement must be in place and use only constant extra memory.
#include <bits/stdc++.h>
using namespace std;

// BruteForce Approach
// Time Complexity: O(N! * N), where N is the size of the array (generating all permutations)
// Space Complexity: O(N! * N), for storing all permutations
void NextPermutationBruteForce(vector<int> &nums)
{
    // (1) Generate all permutations of the array and store them in a container (e.g., vector).
    // (2) Sort the container to ensure lexicographical order.
    // (3) Find the current permutation in the container.
    // (4) Replace nums with the next permutation in the container if it exists,
    //     otherwise replace nums with the first (smallest) permutation.
}

// Better Approach
// TC: O(N), where N is the size of the array (std::next_permutation is linear)
// SC: O(1), in-place
void NextPermutationBetter(vector<int> &nums)
{
    next_permutation(nums.begin(), nums.end());
}

// Optimal Approach
// TC : O(n)
// SC : O(1)
void NextPermutationOptimal(vector<int> &nums)
{
    int n = nums.size();
    int idx = -1;

    // Step 1: Find the first decreasing element from the end
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            idx = i;
            break;
        }
    }

    // Step 2: If no such element, reverse the whole array
    if (idx == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    // Step 3: Find the element just larger than nums[idx]
    for (int i = n - 1; i > idx; i--)
    {
        if (nums[i] > nums[idx])
        {
            swap(nums[i], nums[idx]);
            break;
        }
    }

    // Step 4: Reverse the part after idx
    reverse(nums.begin() + idx + 1, nums.end());
}

int main()
{
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {1, 2, 3};
    vector<int> nums3 = {1, 2, 3};

    cout << "Original: ";
    for (int num : nums1)
        cout << num << " ";
    cout << endl;

    NextPermutationBetter(nums2);
    cout << "After Better: ";
    for (int num : nums2)
        cout << num << " ";
    cout << endl;

    NextPermutationOptimal(nums3);
    cout << "After Optimal: ";
    for (int num : nums3)
        cout << num << " ";
    cout << endl;

    return 0;
}