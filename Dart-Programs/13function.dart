//function
void main() {
  showOutput(square(2));
  showOutput(square(2.5));

  print(cube(3));
}

dynamic square(var num) {
  //return any type of output i.e. integer as well as doubles
  return num * num;
}

void showOutput(var msg) {
  print(msg);
}

//Arrow function =>
dynamic cube(var num) => num * num * num; //automatically return

//Anonymous function  like lambda or closure
/* var list = ['apple','bar'];
   list.forEach(item){
   print(item);
}  
*/
