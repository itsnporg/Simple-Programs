//OOPS concept//

class Person {
  //property
  String name;
  int age;

  //constructor
  Person(String name, [int age = 12]) {
    //age is optional parameter with default value
    this.name = name;
    this.age = age;
  }

  //named constructor
  Person.guest() {
    name = "Guest";
    age = 22;
  }

  //method
  void showOutput() {
    print(name);
    print(age);
  }
}

void main() {
//object creation
  Person person1 = Person('TEST_PERSON_I');
  person1.showOutput();

  var person2 =
      Person('TEST_PERSON_II', 23); //default value replaces by passed value i.e.23
  person2.showOutput();

  var person3 = Person.guest();
  person3.showOutput();
}
