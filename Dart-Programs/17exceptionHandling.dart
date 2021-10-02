// throw, try ,catch , finally

int mustGetMoreThanZero(int val) {
  if (val <= 0) {
    throw Exception('Value must be greater than zero');
  }
  return val;
}

void verify(var val) {
  var valueVerification;

  try {
    valueVerification = mustGetMoreThanZero(val);
  } catch (e) {
    print(e);
  } finally {
    if (valueVerification == null) {
      print('value is not accepted');
    } else {
      print('value verification: $valueVerification');
    }
  }
}

main() {
  verify(10);
  verify(0);
}
