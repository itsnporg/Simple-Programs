main(){
  var n = "name";
  var s = 'surname';
  var p = 'it\'s is raining';

  var raw=r'I\n fine';  //raw string

  print(n);
  print(s);
  print(p);
  print(raw);

  print('My name is $n $s'); //String interpolation within quotation

  var multiline='''
  double
  line
  string
  ''';
  print(multiline);

}
