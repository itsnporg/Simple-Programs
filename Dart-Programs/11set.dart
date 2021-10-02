// set - unordered colletion of unique items.

main() {
  var halogens = {'flourine', 'clourine', 'flourine'};
  for (var x in halogens) {
    print(x);
  }

  Set<String> names = {}; //hashset if we define type.
  print(names.runtimeType);
}
