package main

import (
	"fmt"
)

var strarray = []string{"java", "python", "golang", "ruby", "ocaml"}

func main() {
	for index, data := range strarray {
		fmt.Println(index, data)
	}
}
