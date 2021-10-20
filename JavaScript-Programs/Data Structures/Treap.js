/**
 * Tree node
 */
class Node {
  constructor(value, left, right) {
    this.value = value;
    this.children = [left, right];
    this.size = 1;
    this.height = 1;
    this.key = Math.random();
  }

  /**
   * Computer the number of childnodes
   */
  resize() {
    this.size =
      (this.children[0] ? this.children[0].size : 0) +
      (this.children[1] ? this.children[1].size : 0) +
      1;
    this.height =
      Math.max(
        this.children[0] ? this.children[0].height : 0,
        this.children[1] ? this.children[1].height : 0
      ) + 1;
    return this;
  }

  /**
   * Zigzag rotate of tree nodes
   */
  rotate(side) {
    const temp = this.children[side];

    // Rotate
    this.children[side] = temp.children[1 - side];
    temp.children[1 - side] = this;

    this.resize();
    temp.resize();

    return temp;
  }
}

/**
 * Treap
 */
class Treap {
  constructor() {
    this.root = null;
  }

  /**
   * Insert new value into the subtree of `node`
   */
  _insert(node, value) {
    if (node === null) {
      return new Node(value, null, null);
    }

    // Passing to childnodes and update
    const side = ~~(value > node.value);
    node.children[side] = this._insert(node.children[side], value);

    // Keep it balance
    if (node.children[side].key < node.key) {
      return node.rotate(side);
    }
    return node.resize();
  }

  _find(node, value) {
    if (node === null) {
      // Empty tree
      return false;
    }
    if (node.value === value) {
      // Found!
      return true;
    }

    // Search within childnodes
    const side = ~~(value > node.value);
    return this._find(node.children[side], value);
  }

  _minimum(node) {
    if (node === null) {
      // Empty tree, returns Infinity
      return Infinity;
    }

    return Math.min(node.value, this._minimum(node.children[0]));
  }

  _maximum(node) {
    if (node === null) {
      // Empty tree, returns -Infinity
      return -Infinity;
    }

    return Math.max(node.value, this._maximum(node.children[1]));
  }

  _remove(node, value) {
    if (node === null) {
      // Empty node, value not found
      return null;
    }

    let side;

    if (node.value === value) {
      if (node.children[0] === null && node.children[1] === null) {
        // It's a leaf, set to null
        return null;
      }

      // Rotate to a subtree and remove it
      side = node.children[0] === null ? 1 : 0;
      node = node.rotate(side);
      node.children[1 - side] = this._remove(node.children[1 - side], value);
    } else {
      side = ~~(value > node.value);
      node.children[side] = this._remove(node.children[side], value);
    }
    return node.resize();
  }

  insert(value) {
    this.root = this._insert(this.root, value);
  }

  find(value) {
    return this._find(this.root, value);
  }

  minimum() {
    return this._minimum(this.root);
  }

  maximum() {
    return this._maximum(this.root);
  }

  remove(value) {
    this.root = this._remove(this.root, value);
  }

  size() {
    return this.root ? this.root.size : 0;
  }

  height() {
    return this.root ? this.root.height : 0;
  }
}


