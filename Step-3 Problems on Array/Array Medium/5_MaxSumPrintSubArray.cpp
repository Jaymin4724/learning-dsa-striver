#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> maxSubarray(const vector<int> &arr)
{
    int maxi = INT_MIN; // maximum sum
    int sum = 0;

    int tempStart = 0;
    int start = -1, end = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (sum == 0)
            tempStart = i; // starting index
        sum += arr[i];
        if (sum > maxi)
        {
            maxi = sum;
            start = tempStart;
            end = i;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }

    // return the subarray:
    if (start == -1 || end == -1)
        return {};
    return vector<int>(arr.begin() + start, arr.begin() + end + 1);
}

int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> subarray = maxSubarray(arr);

    cout << "The subarray is: [";
    for (int i = 0; i < subarray.size(); i++)
    {
        cout << subarray[i];
        if (i < subarray.size() - 1)
            cout << " ";
    }
    cout << "]" << endl;

    return 0;
}
