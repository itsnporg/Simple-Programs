/*
 * for loop
 * for-in loop
 * for-each loop
 * while loop
 * do-while loop
 */

void main(){
  //for
  for (var i=1;i<4;i++){
    print(i);
  }
  //for-in
  var numbers = [2,3,1];
  for (var n in numbers){
    print('--$n');
  }
  //for-each
  numbers.forEach((n) => print(n));
  //while
  int i =4;
  while(i>0){
    print('while:$i');
    i-=1;
  }

}

// break : to terminate loop
// continue : to contine loop without further actions in the loop
