# Quicksort

Averages O(n lg n), worst case is O(n^2) (to be seen how often we'll trigger the
        exponential runtime. It may only apply to some pathological case).

Sorts in-place (advantage for limited memory)

## Divide and Conquer

1. (Divide) Partition an array A[p..r] into two subarrays: A[p..q - 1] and A[q + 1..r]
   such that A[q] is greater than every element before, and smaller than every
   element coming after.
2. (Conquer) Sort each subarray A[p..q - 1] and A[q + 1..r] by calling quicksort
   recursively over those ranges
3. (Combine) Arrays are already sorted. No additional work needed.


## Pseudocode
```
Quicksort(A, p ,r)
    if p < r
        q = Partition(A, p ,r)
        Quicksort(A, p, q - 1)
        Quicksort(A, q + 1, r)
```

```
Partition(A, p ,r)
    x = A[r]
    i = p - 1
    for j = p to r - 1
        if A[j] <= x
            i = i + 1 // pushing the limit of our new partition
                      // by building a collection of elements that
                      // maintain our invariant (are less than
                      // everything to the right of the partition
            exchange A[j] with A[i]
    exchange A[i + 1] with A[r]
    return i + 1
```

## Invariants

[p, p + 1, p + 2, ... , k, ..., i, i + 1, i + 2, ... , j - 1, j, r]

For any array index `k`
1. if p <= k <= i, then A[k] <= x
2. if i + 1 <= k <= j - 1, then A[k] > x
3. if k = r, then A[k] = x

A[r] becomes our pivot element
as we move along A, elements less than the partition element are
shifted into the left-most partition, while elements greater than A[r]
are shifted into the right.

[ <= x ] [ > x ] [ unvisited (unrestricted) ] [ pivot element ]

**Initialization** 
This is cheating, but we say that when `i = p - 1` and `j = p`, then we 
trivially satisfy the first two conditions (there are no elements).

Setting `x = A[r]` satisfies the third condition

**Maintenance**
In each iteration of the loop, we maintain three sets of entries up to the
current value of `j`. Given the swap action, we can assert that for i <= j,
A[i] <= x, and A[j] > x, satisfying the first two conditions.

Any value less than x, when encountered in the loop, will be swapped into the
first set.

**Termination**
When the loop ends, j = r. Given how the sets are maintained in each iteration
(and how we swap the partition into its proper index once the loop has finished)
we can say the sets are properly ordered when we're finished.

