class Node:
    def __init__(self, data):
        self.prev = None
        self.data = data
        self.next = None


class Doubly_Linked_List:
    def __init__(self):
        self.head = None

    def Add_at_front(self, new_data):
        new_node = Node(new_data)
        new_node.next = self.head
        new_node.prev = None
        if self.head is not None:
            self.head.prev = new_node
        self.head = new_node

    def Reverse_Linked_List(self):
        temp = self.head
        stack = []
        while temp is not None:
            stack.append(temp.data)
            temp = temp.next
        temp = self.head
        while temp is not None:
            temp.data = stack.pop()
            temp = temp.next

    def Display(self):
        temp = self.head
        while temp:
            print(temp.data, end=" ")
            temp = temp.next


if __name__ == "__main__":
    L_list = Doubly_Linked_List()
    L_list.Add_at_front(5)
    L_list.Add_at_front(7)
    L_list.Add_at_front(9)
    L_list.Add_at_front(8)
    L_list.Add_at_front(1)
    L_list.Add_at_front(2)
    print("\nOriginal Linked List: ")
    L_list.Display()
    print("\nReverse Linked List: ")
    L_list.Reverse_Linked_List()
    L_list.Display()
