//blueprint to create a node in the Animal Tree
class Node {
  constructor(text) {
    this.text = text;
    this.yes = undefined;
    this.no = undefined;
  }
}
module.exports = Node;
