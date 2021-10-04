from typing import Any


class Node:
    def __init__(self, data=None, next=None) -> None:
        self.data = data
        self.next = next


class List:
    def __init__(self) -> None:
        self.head = None

    def prepend(self, data: Any) -> None:
        if self.head is None:
            node = Node(data=data, next=self.head)
            self.head = node
            return
        node = Node(data=data, next=self.head)
        self.head = node

    def append(self, data: Any) -> None:
        if self.head is None:
            node = Node(data=data, next=self.head)
            self.head = node
            return
        iterator = self.head
        while iterator.next:
            iterator = iterator.next
        node = Node(data=data, next=None)
        iterator.next = node

    def print(self) -> Any:
        iterator = self.head
        while iterator:
            print(iterator.data, end=",")
            iterator = iterator.next


if __name__ == "__main__":
    list1 = List()
    list1.append("a")
    list1.append("b")
    list1.prepend("k xa?")
    list1.append("c")
    list1.append("d")

    list1.print()
