package main
 
import (
    "fmt"	
)   
 func join(ins []rune, c rune) (result []string) {
    for i := 0; i <= len(ins); i++ {
        result = append(result, string(ins[:i])+string(c)+string(ins[i:]))
    }
    return
}
 
func permutations(testStr string) []string {
    var n func(testStr []rune, p []string) []string
    n = func(testStr []rune, p []string) []string{
        if len(testStr) == 0 {
            return p
        }else {
            result := []string{}
            for _, e := range p {
                result = append(result, join([]rune(e), testStr[0])...)
            }
            return n(testStr[1:], result)
        }
    }
 
    output := []rune(testStr)
    return n(output[1:], []string{string(output[0])})
}
 
func main() {   
    d := permutations("ABCD")
    fmt.Print(d)
}