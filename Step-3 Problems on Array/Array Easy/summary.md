# Array Algorithms and Their Time Complexity

## (1) Largest Element in an Array

**Time Complexity:** O(n)

## (2) Second Largest Element in an Array

**Time Complexity:** O(n)

## (3) Check Whether the Array is Sorted or Not

- **Nested Loop Traversal:**
  - **Time Complexity:** O(n²)
- **Single Traversal Logic:**
  - **Time Complexity:** O(n)

## (4) Remove Duplicates from a Sorted Array

### Using Sets
- **Time Complexity:** O(n)
- **Space Complexity:** O(n)

### Two Pointer Approach
(i --> represents the position of the last unique element found so far, j --> traverses the array and finds the unique element)
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

## (5) Left/Right Rotate the Array by One Place

- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

## (6) Left/Right Rotate the Array by 'd' Places (rotations d = d % n)

### Approach 1:
- Take the first d elements in a vector, arrange the rest of the elements at the start of the array & place the vector elements immediately after arranging the rest elements.
- **Time Complexity:** O(n)
- **Space Complexity:** O(d)

### Approach 2 (Recursive Approach):
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

## (7) Move the Zeroes to the End of the Array

**Two Pointer Approach:** (i --> determines the correct position of non-zero element, j --> traverses the array and finds the non-zero element, and in the last adds the rest of the elements with value 0)
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

## (8) Linear Search

- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

## (9) Union/Intersection of Two Sorted Arrays (Two Pointer Approach)

- **Time Complexity:** O(n + m)
- **Space Complexity:** O(1)

## (10) Find the Missing Number

### Approaches:

- **Bruteforce:** O(n²)
- **Better Approach (Hashing):** O(n)
- **Better Best Approach (Sum Formula):** O(n)
- **Best Approach (XOR Operation):** O(n)

## (11) Find the Max Consecutive Ones

- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

## (12) Find the Numbers That Appear Once While Other Numbers Appear Twice

### Approaches:

- **Bruteforce (Nested For-Loops):** O(n²)
- **Better Option (Hashing):** O(n)
- **Best Option (XOR Operation):** O(n)

## (13) Find the Longest Subarray Whose Sum is Exactly K

The approach leverages the **prefix sum technique** with a hash map for efficient lookup.

- **Maintain a running sum (prefixSum).**
- If at any index `i`, `prefixSum` itself equals `K`, update `maxLen`.
- Check if `(prefixSum - K)` exists in the hash map, indicating a valid subarray ending at `i`.
- If found using the `find` function, update `maxLen` as `i - prefixMap[prefixSum - K]`.
- If `prefixSum` is not already present in the map, store its first occurrence to maximize the length of future valid subarrays.

- **Time Complexity:** O(n)
- **Space Complexity:** O(n)
