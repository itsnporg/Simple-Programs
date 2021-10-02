import 'dart:math';

//author - @swrnv//

void main() {
  print(getRandomString(5)); // 5GKjb
  print(getRandomString(10)); // LZrJOTBNGA
  print(getRandomString(15)); // PqokAO1BQBHyJVK
}

const _chars = 'AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz1234567890';
Random _rnd = Random();

String getRandomString(int length) => String.fromCharCodes(Iterable.generate(
    length, (_) => _chars.codeUnitAt(_rnd.nextInt(_chars.length))));
