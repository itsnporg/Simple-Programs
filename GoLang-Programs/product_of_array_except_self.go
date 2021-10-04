package main

import "fmt"

func main() { 
	fmt.Println("This program will print an array with elements at the same index which has product of all elements except itself!")
	numsLength := 0
	fmt.Println("Enter the number of inputs in array")
    fmt.Scanln(&numsLength)
    fmt.Println("Enter the inputs")

    nums := make([]int, numsLength)
    for i := 0; i < numsLength; i++ {
        fmt.Scanln(&nums[i])
    }

	ans := make([]int,len(nums))
    for i := range ans {
        ans[i] =1
    }
    mul :=nums[0]
    for i :=1;i<len(ans);i++ {
        ans[i] = ans[i]* mul
        mul = mul* nums[i]
    }
    mul =nums[len(ans)-1]
    for i :=len(ans) -2;i>=0;i-- {
        ans[i] = ans[i]* mul
        mul = mul* nums[i]
    }

	fmt.Println("The output is:")
    fmt.Println(ans)
}