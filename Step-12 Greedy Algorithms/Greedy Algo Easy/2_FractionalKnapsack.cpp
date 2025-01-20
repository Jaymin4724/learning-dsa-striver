//? https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
//* Given two arrays, val[] and wt[], representing the values and weights of items, and an integer capacity representing the maximum weight a knapsack can hold, determine the maximum total value that can be achieved by putting items in the knapsack. You are allowed to break items into fractions if necessary.
//* Return the maximum value as a double, rounded to 6 decimal places.

// Input: val[] = [60, 100, 120], wt[] = [10, 20, 30], capacity = 50
// Output: 240.000000
// Explanation: Take the item with value 60 and weight 10, value 100 and weight 20 and split the third item with value 120 and weight 30, to fit it into weight 20. so it becomes (120/30)*20=80, so the total value becomes 60+100+80.0=240.0 Thus, total maximum value of item we can have is 240.00 from the given capacity of sack.

// Input: val[] = [60, 100], wt[] = [10, 20], capacity = 50
// Output: 160.000000
// Explanation: Take both the items completely, without breaking. Total maximum value of item we can have is 160.00 from the given capacity of sack.

// Input: val[] = [10, 20, 30], wt[] = [5, 10, 15], capacity = 100
// Output: 60.000000
// Explanation: In this case, the knapsack capacity exceeds the combined weight of all items (5 + 10 + 15 = 30). Therefore, we can take all items completely, yielding a total maximum value of 10 + 20 + 30 = 60.000000.

//* TC: O(nlogn)
//* SC: O(n)
#include <bits/stdc++.h>
using namespace std;

// Structure to represent an item with value, weight, and value-to-weight ratio
struct Item
{
    int value;
    int weight;
    // Constructor
    Item(int v, int w) : value(v), weight(w) {}
};

// Comparison function to sort items by their value-to-weight ratio in descending order
bool compare(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to calculate the maximum total value in the knapsack
double fractionalKnapsack(int capacity, vector<int> &val, vector<int> &wt)
{
    int n = val.size();
    vector<Item> items;

    // Populate the items vector with value and weight
    for (int i = 0; i < n; i++)
    {
        items.push_back(Item(val[i], wt[i]));
    }

    // Sort items by value-to-weight ratio
    sort(items.begin(), items.end(), compare);

    double sumVal = 0; // To store the total value in the knapsack
    int sumWt = 0;     // To store the total weight in the knapsack

    // Go through sorted items and add them to the knapsack
    for (auto i : items)
    {
        // If adding the full item doesn't exceed capacity, take it
        if (sumWt + i.weight <= capacity)
        {
            sumWt += i.weight;
            sumVal += i.value;
        }
        else
        {
            // If the item can't fit fully, take a fraction of it
            int remain = capacity - sumWt;
            sumVal += (double)(i.value * remain) / i.weight;
            break;
        }
    }

    // Return the maximum value, rounded to 6 decimal places
    return sumVal;
}

int main()
{
    // Example test cases
    vector<int> val = {60, 100, 120}; // Values of the items
    vector<int> wt = {10, 20, 30};    // Weights of the items
    int capacity = 50;                // Capacity of the knapsack

    // Function call and output
    cout << fixed << setprecision(6);
    cout << "Maximum value in Knapsack = " << fractionalKnapsack(capacity, val, wt) << endl;

    return 0;
}
