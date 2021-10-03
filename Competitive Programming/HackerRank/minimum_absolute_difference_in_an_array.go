package main

import (
	"fmt"
	"sort"
)

// link to problem: https://www.hackerrank.com/challenges/minimum-absolute-difference-in-an-array?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=greedy-algorithms
// Problem description:
// The absolute difference is the positive difference between two values a and b, is written |a-b| or |b-a| and they are equal.
// If a = 3 and b = 2, |3-2| = |2-3| = 1. Given an array of integers, find the minimum absolute difference between any two elements in the array.

func minimumAbsoluteDifference(arr []int32) int32 {
	// Write your code here
	var f foo
	f = arr
	temp := Abs(f[0] - f[1])

	sort.Sort(f)

	for i := 0; i < len(f)-1; i++ {
		if Abs(f[i]-f[i+1]) < temp {
			temp = Abs(f[i] - f[i+1])
		}
	}

	return temp
}

// Abs returns the absolute value of x.
func Abs(x int32) int32 {
	if x < 0 {
		return -x
	}
	return x
}

//type foo that implements Sort for int32 type
type foo []int32

func (f foo) Len() int {
	return len(f)
}

func (f foo) Less(i, j int) bool {
	return f[i] < f[j]
}

func (f foo) Swap(i, j int) {
	f[i], f[j] = f[j], f[i]
}

func main() {
	fmt.Println(minimumAbsoluteDifference([]int32{3, -7, 0}))
	fmt.Println(minimumAbsoluteDifference([]int32{-59, -36, -13, 1, -53, -92, -2, -96, -54, 75}))
	fmt.Println(minimumAbsoluteDifference([]int32{1, -3, 71, 68, 17}))
}
