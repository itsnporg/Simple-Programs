package main

import "fmt"

func add(a int, b int, c int) {
	fmt.Printf("The sum of %v, %v, and %v is %v", a, b, c, a+b+c)
}
func main() {
	add(10, 20, 30)

}
