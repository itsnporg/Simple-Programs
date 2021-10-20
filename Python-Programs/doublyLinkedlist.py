from typing import Any


class Node:
    def __init__(self, data=None, next=None, prev=None) -> None:
        self.data = data
        self.next = next
        self.prev = prev


class List:
    def __init__(self) -> None:
        self.head = None
        self.count = 0

    def append(self, data) -> None:
        if self.head is None:
            node = Node(data=data, next=None, prev=None)
            self.head = node
            self.count += 1
            return
        current = self.head
        while current.next:
            current = current.next
        node = Node(data=data, next=None, prev=current)
        current.next = node
        self.count += 1

    def prepend(self, data) -> None:
        if self.head is None:
            node = Node(
                data=data,
                prev=None,
            )
            self.head = node
            self.count += 1

        else:
            node = Node(data=data, prev=None, next=self.head)
            self.head.prev = node
            self.head = node
            self.count += 1

    def print(self) -> None:
        current = self.head
        counter = 0
        print("[", end="")
        while current:
            print(f" {current.data}, ", end="")
            counter += 1
            current = current.next
        print("]")

    def get(self, index: int) -> Any:
        if self.count - 1 < index:
            raise Exception("list index out of range")
        itr = self.head
        count = 0
        while itr:
            if index == count:
                return itr
            count += 1
            itr = itr.next

    def __len__(self) -> int:
        return self.count

    def delete(self, index) -> None:
        if self.count - 1 < index:
            raise Exception("list index out of range")
        itr = self.head
        count = 0
        while itr:
            if count == index:
                itr.next.prev = itr.prev
                itr.prev.next = itr.next
                del itr
                return
            count += 1
            itr = itr.next
        self.count -= 1


if __name__ == "__main__":
    list1 = List()
    list1.prepend(1)  # adding value at the beginning of the list
    list1.append(23)  # adding value at last of the list
    list1.append([2131])
    list1.prepend(3)
    list1.print()  # printing all the data of the list
    print(list1.get(2).data)  # getting node from a specific index
    list1.delete(2)  # deleting node from a specific index
    print(list1.get(2).data)
    list1.print()
