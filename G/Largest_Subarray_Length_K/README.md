Array X is greater than array Y if the first non-matching element in both arrays has a greater value in X than in Y.

For example, for arrays X and Y such that:

$X=[1,2,4,3,5]$

$Y=[1,2,3,4,5]$

X is greater than Y because the first element that does not match is larger in X (i.e. for X[2] and Y[2], X[2]>Y[2]).

A contiguous subarray is defined by an interval of the indices. In other words, a contiguous subarray is a subarray which has consecutive indexes.

Write a funtion that, given a zero-indexed array A consisting of N integers and an integer K, returns the largest contiguous subarray of length K from all the contiguous subarrays of length K.

For example, given array A and K=4 such that:

$A=[1,4,3,2,5]$

the function should return [4,3,2,5], because there are two subarrays of size 4:

$[1,4,3,2]$

$[4,3,2,5]$

and the largest subarray is [4,3,2,5].

Assume that:
- $1\le K\le N\le 100$;
- $1\le A[J]\le 1000$;

given an array A contains N distince integers.

In your solution, focus on correctness. The performance of your solution will not be the primary focus of the assessment.



