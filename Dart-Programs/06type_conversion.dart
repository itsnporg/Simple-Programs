main(){
//Sting=>int
var one = int.parse('1');  //parsing integer from string
assert(one==1);

//String=>double
var two =double.parse('2.0');
assert(two==2); //verify


//int => String
String oneString = 1.toString();
assert(oneString=='1');

//double => String
String piString = 3.14159.toStringAsFixed(2);
assert(piString == '3.14');
}

//Type test
//if (x is int){}
