
class Num{
  int num =100;
}

main(){

  int nu = 1+2;
  print(nu);

  nu = 1 -2;
  print(nu);

  double mo = 6.2 % 3;
  print(mo);

  //relational == >= <= !=
  if (nu == -1){
    print('Negative');
  }

  nu*=nu;  //nu = nu*nu;
  print(nu);

  //unary opertor
  ++nu;
  nu ++;
  nu +=1;
  print(nu);

  //logical && or || or !=
  if (nu > 0 && nu < 10){
    print('good');
  }

  //Null Aware Operator
  //(?.),(??),(??=)
  var a = Num();  //object value
  int number;
  if(a !=null){
    number = a.num;
  }
  print(number);

  var o;
  int nume;
  number = o?.num;  //null check without if condition
  print(nume);

  int nulll;
  var obj;
  nulll =obj?.num;  //obj?.num ?? 0; denotes default value 0.
                    //null ??= 100; denoes 100 is assigned if null.
  print(nulll);


  //Ternary operator
  int x =100;
  var result = x%2==0 ?'Even':'Odd';
  print(result);
}
