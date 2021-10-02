void main() {
  //type inference variables
  var name = 'NAME';
  String surname = 'SURNAME';
  print(name + ' ' + surname);

  const acc = 0; //int constant
  const b = true; //boolean constant
  const str = 'string'; //string constant
  print(b);
  print(str);
  print(acc.runtimeType);
}

/*
 * int
 * double
 * String
 * bool
 * dynamic  - dynamic type(change at runtime)
 */
