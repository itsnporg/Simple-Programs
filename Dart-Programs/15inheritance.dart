//extends

class Vehicle {
  String model;
  int year;

  Vehicle(this.model, this.year) {
    //inheritance from vehicle class
    print(this.model);
    print(this.year);
  }

  void showOutput() {
    print(model);
    print(year);
  }
}

class Car extends Vehicle {
  double price;

  //model and year already existed due to inheritance , so we use super keyword to pass value to parent constructor
  Car(String model, int year, this.price) : super(model, year);

  void showOutput() {
    super.showOutput();
    print(this.price);
  }
}

void main() {
  var car1 = Car('Accord', 2014, 15000);
  car1.showOutput();
}
