fn main() {
  let a = 4;
  let b: i32 = 25;

  let c = add(a,  b);
  println!("a + b = {}", c);
}

fn add(i: i32, j: i32) -> i32 {
  i + j
}
