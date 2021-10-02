//core functionality defined under dart:core package
import 'dart:core'; //automatically imported

import 'dart:io';

main(){
  stdout.writeln('What is your name?');
  String? name = stdin.readLineSync();

  print('Your name is $name'); //string interpolation to get value 
}
