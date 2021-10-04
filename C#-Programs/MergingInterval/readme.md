# Merging Interval

## Interval:

An interval is a time period with a start and an end. The start and end values are included within the intervals, i.e. [4,9] means the interval includes 4,5,6,7,8,9 i.e. 4 and 9 are included here.

## Merge distance

It is a value, when combined with two separate intervals allows
them to be merged if they overlap across the merge distance.

Examples

    • Given two intervals [1,5] and [10,15] and a merge distance of 5, the two intervals overlap across this merge distance allowing them to be merged to a new interval of [1,15].
    • Similarly given two intervals [1,5] and [11,15] and a merge distance of 5, you cannot merge these two intervals since they do not overlap across the merge distance.

## Problem:

Given a list of intervals [start, end] you have to merge them based on a specified merge distance. Your intervals are arriving in a particular order, as they arrive you should merge them according to the specified merge distance as each interval is received.

    ## Input:  The input is a list of intervals [start, end] and a merge distance.
    ## Output:  The output is a list of intervals [start, end] after merging.

        ## Example:
        Input: [[1,3],[2,6],[9,10],[15,18]] and merge distance = 2
        Output: [[1,6],[9,10],[15,18]]

        ## Example:
        Input: [[1,4],[4,5]] and merge distance = 0
        Output: [[1,4],[4,5]]

        ## Example:
        Input: [[1,4],[2,3]] and merge distance = 1
        Output: [[1,4]]
