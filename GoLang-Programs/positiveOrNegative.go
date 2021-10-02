package main

import "fmt"

func main() {
	var num int = 0

	fmt.Printf("Enter a number: ")
	fmt.Scanf("%d", &num)

	if num >= 0 {
		fmt.Printf("It's a positive number")
	} else {
		fmt.Printf("It's a negative number")
	}
}
