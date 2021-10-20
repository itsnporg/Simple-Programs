//collections
/* 1. list 
  2. set 
  3. map */

void main() {
  List names = ['Jack', "Jill"];
  print(names[0]);
  print(names.length);

  var ll = ['cat ', 1];
  print(ll);

  List<String> staticList = [
    'NAME',
    'SURNAME'
  ]; //list cannot contain other values than string

  for (var a in staticList) {
    print(a);
  }

  //List are mutable
  staticList[1] = 'Ss';
  print(staticList);

  //-> we can make list immutable by putting const
  List<String> name = const ['ss'];

  //  names2 = names; doesnot copy the list. They refer same list.
  //  If we want to copy list: names2= [...names];
}
