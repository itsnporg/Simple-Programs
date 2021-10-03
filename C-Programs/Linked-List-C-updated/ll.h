
struct Node{
    int data;
    struct Node * next;
};

void traversal(struct Node * ptr);

// Insert related functions
struct Node * InsertionAtFirst(struct Node * head, int data);
struct Node * InsertionAtIndex(struct Node * head, int data, int index);
struct Node * InsertionAtEnd(struct Node * head, int data);
struct Node * InsertionAfterNode(struct Node * head, struct Node * prevNode, int data);

// Delete related functions
struct Node * DeleteFromFirst(struct Node * head);
struct Node * DeleteFromIndex(struct Node * head, int index);
struct Node * DeleteFromEnd(struct Node * head);
struct Node * DeleteaValue(struct Node * head, int value);
