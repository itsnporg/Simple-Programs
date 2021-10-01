//map: key-value pairs

void main() {
  var name = {'sa': 'car', 'cc': 'pant', 1: 'ss'};
  print(name['cc']);
  print(name[1]);

  //empty map
  var mm = Map();
  mm['one'] = 'car';
  print(mm);
}
