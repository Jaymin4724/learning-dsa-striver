#include <bits/stdc++.h>
using namespace std;
// Bruteforce Approach --> using sets
// 1. Inserting elements into the `set` (UniqueArr):
//    - Each insertion into a `set` takes (O(log n)), and we are iterating through the entire array of size (n).
//    - This step takes (O(n log n)).

// 2. Iterating through the `set` to update the original array:
//    - Iterating through the `set` of size (k) (where (k) is the number of unique elements) takes (O(k)).
//    - Copying these elements into the `arr` takes (O(k)).
//    - Overall, this step takes (O(k)).

// Since (k leq n), the overall time complexity of the function is:
// (O(n log n) + O(n) = O(n log n)).

// So, the dominant term is (O(n log n)).

int RemoveDuplicatesFromSortedArray(vector<int> &arr)
{
    set<int> UniqueArr;
    for (auto i : arr)
    {
        UniqueArr.insert(i);
    }
    int j = 0;
    for (auto i : UniqueArr)
    {
        arr[j++] = i;
    }
    return UniqueArr.size();
}
int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 4, 4, 5, 5, 5};
    int sizeOfUniqueArray = RemoveDuplicatesFromSortedArray(arr);
    for (int i = 0; i < sizeOfUniqueArray; i++)
    {
        cout << arr[i] << " ";
    }
};