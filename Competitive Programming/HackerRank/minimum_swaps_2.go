package main

import (
	"fmt"
)

// link to problem: https://www.hackerrank.com/challenges/minimum-swaps-2/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays
// Problem description:
// You are given an unordered array consisting of consecutive integers  [1, 2, 3, ..., n] without any duplicates.
// You are allowed to swap any two elements. Find the minimum number of swaps required to sort the array in ascending order.

func minimumSwaps(arr []int32) int32 {
	var count int32 = 0
	var dict map[int32]int
	dict = map[int32]int{}

	// mapping array [10,20,30] into
	// map[int32]int{
	// 	10:1,
	// 	20:2,
	// 	30:3,
	// }
	for i := 1; i <= len(arr); i++ {
		dict[arr[i-1]] = i
	}

	// swap process
	for key, value := range dict {
		if int(key) != value {
			dict[arr[key-1]], dict[key] = dict[key], dict[arr[key-1]]
			arr[value-1], arr[key-1] = arr[key-1], arr[value-1]
			count++
		}
	}
	return count
}

func main() {
	fmt.Println(minimumSwaps([]int32{4, 3, 1, 2}))
	fmt.Println(minimumSwaps([]int32{2, 3, 4, 1, 5}))
	fmt.Println(minimumSwaps([]int32{1, 3, 5, 2, 4, 6, 7}))
	fmt.Println(minimumSwaps([]int32{8, 45, 35, 84, 79, 12, 74, 92, 81, 82, 61, 32, 36, 1, 65, 44, 89, 40, 28, 20, 97, 90, 22, 87, 48, 26, 56, 18, 49, 71, 23, 34, 59, 54, 14, 16, 19, 76, 83, 95, 31, 30, 69, 7, 9, 60, 66, 25, 52, 5, 37, 27, 63, 80, 24, 42, 3, 50, 6, 11, 64, 10, 96, 47, 38, 57, 2, 88, 100, 4, 78, 85, 21, 29, 75, 94, 43, 77, 33, 86, 98, 68, 73, 72, 13, 91, 70, 41, 17, 15, 67, 93, 62, 39, 53, 51, 55, 58, 99, 46}))
}
