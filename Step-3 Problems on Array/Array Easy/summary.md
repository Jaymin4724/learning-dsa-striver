(1) largest element in an array

**Time Complexity:** O(n)

(2) second largest element in an array

**Time Complexity:** O(n)

(3) check whether the array is sorted or not (nested loop traversal & single traversal logic)

**Time Complexity (Nested Loop):** O(n²)

**Time Complexity (Single Traversal):** O(n)

(4) remove duplicates from a sorted array

1. using sets

**Time Complexity:** O(n)

**Space Complexity:** O(n)

2. 2 pointer approach (i --> represent the position of last unique element found so far, it also determines where the next unique element will be placed, j --> traverse the array and find the unique element)

**Time Complexity:** O(n)

**Space Complexity:** O(1)

(5) left/right rotate the array by one place

**Time Complexity:** O(n)

**Space Complexity:** O(1)

(6) left/right rotate the array by 'd' places (rotations d = d%n)

1. take first d elements in a vector, arrange rest elements to the starting of the array & place the vector elements immediately after arranging the rest elements

**Time Complexity:** O(n)

**Space Complexity:** O(d)

2. recursive approach

**Time Complexity:** O(n)

**Space Complexity:** O(1)

(7) move the zeroes to the end of the array

2 pointer approach (i --> determines the correct position of non-zero element, j --> traverse the array and find the non-zero element, and in the last add rest elements with value 0)

**Time Complexity:** O(n)

**Space Complexity:** O(1)

(8) linear search

**Time Complexity:** O(n)

**Space Complexity:** O(1)

(9) union/intersection of two sorted arrays (2 pointer approach)

**Time Complexity:** O(n + m)

**Space Complexity:** O(1)

(10) find the missing number

(bruteforce -> n², better approach --> hashing, better best approach --> sum of n elements logic, best approach --> xor operation from 1 to N and xor operation of array elements (index 0 to n-1) and xor of both the answers -> you will get the answer)

**Time Complexity (Bruteforce):** O(n²)

**Time Complexity (Hashing):** O(n)

**Time Complexity (Sum Formula):** O(n)

**Time Complexity (XOR):** O(n)

(11) find the max consecutive ones !!

**Time Complexity:** O(n)

**Space Complexity:** O(1)

(12) find the numbers that appear once and other numbers twice

bruteforce: nested for-loops --> better option: hashing --> best option: xor operation

**Time Complexity (Bruteforce):** O(n²)

**Time Complexity (Hashing):** O(n)

**Time Complexity (XOR):** O(n)

(13) **Given an array that contains positive, negative, and zero elements, we need to find the longest subarray whose sum is exactly K.**

The approach to finding the longest subarray with sum K leverages the prefix sum technique with a hash map for efficient lookup.

As we traverse the array, we maintain a running sum (prefixSum). If at any index i, prefixSum itself equals K, it means the subarray from the start to i has the required sum, so we update maxLen.

Otherwise, we check if (prefixSum - K) exists in the hash map, which indicates that a subarray ending at i sums to K.

If found using the find function, we update maxLen as i - prefixMap[prefixSum - K], representing the length of the subarray with sum K.

If prefixSum is not already present in the map, we store its first occurrence to maximize the length of future valid subarrays.

**Time Complexity:** O(n)

**Space Complexity:** O(n)
