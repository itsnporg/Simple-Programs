package main

import "fmt"

func main() {
	fmt.Print("Enter a character: ")
	var val byte
	fmt.Scanf("%c", &val)

	fmt.Printf("Character value: %c", val)
	fmt.Printf("\nASCII value: %d", val)
}
