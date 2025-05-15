#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> &arr, int size, int k)
{
    int left = 0, right = 0;
    int sum = 0;
    int maxlen = 0;

    while (right < size)
    {
        sum += arr[right];

        // Shrink the window from the left if the sum exceeds k
        while (sum > k && left <= right)
        {
            sum -= arr[left];
            left++;
        }

        // If sum == k, check and update maxlen
        if (sum == k)
        {
            maxlen = max(maxlen, right - left + 1);
        }

        // Move right pointer forward
        right++;
    }

    return maxlen;
}

int main()
{
    vector<int> arr = {1, 2, 1, 1, 1, 1, 2, 3}; // Example with non-negative elements
    int k = 5;
    int size = arr.size();
    int maxlen = longestSubarrayWithSumK(arr, size, k);
    cout << "Longest subarray length: " << maxlen << endl;
    return 0;
}
