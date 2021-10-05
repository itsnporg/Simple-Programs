//Function to calculate the fibonacci of n numbers with recursion
fn fibonacci_recursive(n: i64) -&gt; i64 {
    if n &lt; 2 {
        return n;
    }
    return fibonacci_recursive(n - 1) + fibonacci_recursive( n - 2);
}
