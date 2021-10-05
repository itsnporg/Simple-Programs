import json
from datetime import date, datetime, time

date_format = "%m/%d/%Y"
time_format = "%H:%M:%S"


class Library:
    def __init__(self) -> None:
        with open("books.txt", "r") as f:
            lines = f.readlines()
        lines = list(map(lambda x: x.strip("\n").split(","), lines))
        id_list = range(1, len(lines) + 1)
        self.id_list = id_list
        self.books = dict(zip(id_list, lines))

    def reset(self):
        self.__init__()

    def validate_id(self, book_id):
        return book_id in self.id_list

    # DISPLAY
    header = f"|{'ID':^6}|{'Book Name':^30}|{'Author':^25}|{'Stock':^7}|{'Price':^7}|"

    def get_body(self, book_id):
        book = self.books.get(book_id)
        return f"|{book_id:^6}|{book[0]:^30}|{book[1]:^25}|{book[2]:^7}|{book[3]:^7}|"

    def display_books(self):
        header = self.header
        books = self.books
        print(header)
        print("_" * len(header) + "\n")
        for i in range(1, len(books) + 1):
            print(self.get_body(i))

    # LEND

    def decrease_stock(self, book_id):
        books = self.books
        stock = int(books.get(book_id)[2])
        if stock < 1:
            print("\nNot enough stock\n")
            return False
        else:
            book_index = book_id - 1
            with open("books.txt", "r") as f:
                lines = f.readlines()
            stock -= 1
            lines[
                book_index
            ] = f"{books[book_id][0]},{books[book_id][1]},{stock},{books[book_id][3]}\n"
            with open("books.txt", "w") as f:
                f.writelines(lines)
            return True

    def get_lend_log(self, book_id, name):
        return json.dumps(
            {
                "id": book_id,
                "borrower_name": name,
                "book_name": self.books[book_id][0],
                "time": datetime.now().strftime(time_format),
                "date": date.today().strftime(date_format),
                "returned": False,
            }
        )

    def store_lend_log(self, book_id, name):
        with open("lends.txt", "a") as f:
            f.writelines(f"{self.get_lend_log(book_id, name)}\n")
            print("\nBOOK LENT\n")

    def lend_book(self):
        book_id = int(input("Enter book ID to lend: "))
        if self.validate_id(book_id) and self.decrease_stock(book_id):
            name = input("\nEnter your name: ")
            self.store_lend_log(book_id, name)
            self.reset()
        else:
            print("\nPlease enter a correct ID\n")
            self.lend_book()

    # END LEND

    # RETURN

    def check_marked_returned(self, book_id, name):
        with open("lends.txt", "r") as f:
            lines = [json.loads(x) for x in f.readlines()]
        for lend in lines:
            if (
                lend.get("borrower_name") == name
                and lend.get("id") == book_id
                and lend.get("returned") == False
            ):
                lend["returned"] = True
                check = True
                break
            else:
                check = False
        if check:
            dump = [f"{json.dumps(x)}\n" for x in lines]
            with open("lends.txt", "w") as f:
                f.writelines(dump)
        return check

    def increase_stock(self, book_id):
        books = self.books
        stock = int(books.get(book_id)[2])
        book_index = book_id - 1
        with open("books.txt", "r") as f:
            lines = f.readlines()
        stock += 1
        lines[
            book_index
        ] = f"{books[book_id][0]},{books[book_id][1]},{stock},{books[book_id][3]}\n"
        with open("books.txt", "w") as f:
            f.writelines(lines)

    def calculate(self, book_id, name):
        with open("lends.txt", "r") as f:
            lines = f.readlines()
        if lines:
            lines = [json.loads(x) for x in lines]
            for lend in lines:
                if lend.get("borrower_name") == name and lend.get("id") == book_id:
                    price = self.books[book_id][3]
                    lend_date = datetime.strptime(lend["date"], date_format).date()
                    date_difference = (date.today() - lend_date).days
                    if date_difference >= 10:
                        fine = (date_difference - 10) * 2
                        price = int(price) + fine
                        print(f"\nYou will have to pay {price} including fine {fine}\n")
                        return price
                    else:
                        print(
                            f"\nYou will have to pay {price}. Thank you for returning in time"
                        )
                        return price
        else:
            print("\nCANNOT RETURN WITHOUT LENDS\n")

    def get_return_log(self, book_id, name):
        paid_price = self.calculate(book_id, name)
        return json.dumps(
            {
                "id": book_id,
                "borrower_name": name,
                "book_name": self.books[book_id][0],
                "time": datetime.now().strftime(time_format),
                "date": date.today().strftime(date_format),
                "paid_price": paid_price,
            }
        )

    def store_return_log(self, book_id, name):
        with open("returns.txt", "a") as f:
            f.writelines(f"{self.get_return_log(book_id,name)}\n")
            print("\nBook returned.\n")

    def return_book(self):
        book_id = int(input("Enter book ID to return: "))
        name = input("\nEnter your name: ")
        if self.validate_id(book_id) and self.check_marked_returned(book_id, name):
            self.increase_stock(book_id)
            self.store_return_log(book_id, name)
            self.reset()
        else:
            print("\nPlease enter a correct ID\n")
            self.return_book()

    # END RETURN


library = Library()


def main():

    print(
        """
    Select and option!!!
    1. Display all books
    2. Request a borrow
    3. Return a book
    4. Main Menu
    5. Exit
    """
    )
    user_input = input("Enter an option: ")

    if user_input == "5":
        return False

    elif user_input == "4":
        main()

    elif user_input == "1":
        library.display_books()

    elif user_input == "2":
        library.lend_book()

    elif user_input == "3":
        library.return_book()

    else:
        print("\n Please enter valid option \n")
        return False


while True:
    check = main()
    if check == False:
        break
