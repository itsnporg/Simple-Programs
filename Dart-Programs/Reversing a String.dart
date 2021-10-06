// Write a program (using functions!) that asks the user for a long string 
// containing multiple words. Print back to the user the same string, except 
// with the words in backwards order.

// For example, say I type the string:

//   My name is coderaman07
// Then I would see the string:

//   coderaman07 is name My


import 'dart:io';

void main() {
  stdout.write("Please give a sentence: ");
  String sentence = stdin.readLineSync();

  reverseSentence(sentence);
}

void reverseSentence(String sentence) {
  /* Split the sentence into a list of words
  Reverse the list, then join the words back */
  String a = sentence.split(" ").reversed.toList().join(" ");
  print(a);
}