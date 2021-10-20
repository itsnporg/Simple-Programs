const createNode = require("./create_node");

class AnimalTree {
  constructor() {
    this.root = new createNode("Duck");
  }

  returnRoot() {
    return this.root;
  }
}

function getTreeRoot() {
  let tree = new AnimalTree();
  return tree;
}

module.exports = getTreeRoot;
