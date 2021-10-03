import random
from tkinter import *
from tkinter import messagebox

root = Tk()
root.title("Minesweeper")
root.resizable(0, 0)
root.iconbitmap("D:\\Projects\\Python\\Tkinter\\minesweeper\\icon.ico")
mine_character = u"\u2738"


def handle_click(btn_index, dim):
    global buttons, board, mine_locations, score_label, score

    if board[int(btn_index / dim)][btn_index % dim] == mine_character:
        for location in mine_locations:
            buttons[location]["text"] = mine_character
        game_over(False)
    elif board[int(btn_index / dim)][btn_index % dim] == " ":
        flood_fill_uutil_find_mine(int(btn_index / dim), btn_index % dim, dim)

    elif buttons[btn_index]["bg"] == "black":
        buttons[btn_index]["bg"] = "white"
        buttons[btn_index]["fg"] = "black"
        buttons[btn_index]["text"] = board[int(btn_index / dim)][(btn_index % dim)]
        score = score + 1
        score_label["text"] = score
    if game_win(dim):
        for location in mine_locations:
            buttons[location]["text"] = mine_character

        for index, btn in enumerate(buttons):
            btn["bg"] = "white"
            btn["fg"] = "black"
            btn["text"] = board[int(index / dim)][(index % dim)]
        game_over(True)


def game_win(dim):
    count = 0
    for btn in buttons:
        if btn["bg"] == "white":
            count = count + 1
    if count >= dim * dim - dim * 2:
        return True
    return False


def check_if_has_neighbour(i, j, dim):
    top = i - 1
    bottom = i + 1
    left = j - 1
    right = j + 1
    if top != -1 and top < dim:
        if board[top][j] == mine_character:
            return True
    if right != -1 and right < dim:
        if board[i][right] == mine_character:
            return True
    if bottom != -1 and bottom < dim:
        if board[bottom][j] == mine_character:
            return True
    if left != -1 and left < dim:
        if board[i][left] == mine_character:
            return True
    if top != -1 and top < dim and left != -1 and left < dim:
        if board[top][left] == mine_character:
            return True
    if top != -1 and top < dim and right != -1 and right < dim:
        if board[top][right] == mine_character:
            return True
    if bottom != -1 and bottom < dim and left != -1 and left < dim:
        if board[bottom][left] == mine_character:
            return True
    if bottom != -1 and bottom < dim and right != -1 and right < dim:
        if board[bottom][right] == mine_character:
            return True
    return False


def flood_fill_uutil_find_mine(i, j, dim):
    global buttons, score, score_label
    if (
        i == -1
        or j == -1
        or i >= dim
        or j >= dim
        or board[i][j] == mine_character
        or buttons[i * dim + j]["bg"] == "white"
    ):
        return
    if check_if_has_neighbour(i, j, dim):
        buttons[i * dim + j]["bg"] = "white"
        buttons[i * dim + j]["fg"] = "black"
        buttons[i * dim + j]["text"] = board[i][j]
        score = score + 1
        score_label["text"] = score
        return
    else:

        score = score + 1
        score_label["text"] = score

        buttons[i * dim + j]["bg"] = "white"
        buttons[i * dim + j]["fg"] = "black"
        buttons[i * dim + j]["text"] = board[i][j]

        flood_fill_uutil_find_mine(i - 1, j, dim)  # top
        flood_fill_uutil_find_mine(i + 1, j, dim)  # bottom
        flood_fill_uutil_find_mine(i, j + 1, dim)  # right
        flood_fill_uutil_find_mine(i, j - 1, dim)  # left

        flood_fill_uutil_find_mine(i + 1, j + 1, dim)  # bottom right
        flood_fill_uutil_find_mine(i + 1, j - 1, dim)  # bottom left

        flood_fill_uutil_find_mine(i - 1, j + 1, dim)  # top right
        flood_fill_uutil_find_mine(i - 1, j - 1, dim)  # top lfr

        pass
    pass


def game_over(status):
    title = ""
    message = ""
    if status:
        title = "Game Over"
        message = "You Won! Congratulations"
    else:
        title = "Game Over"
        message = "You Were Bombed"
    messagebox.showinfo(title=title, message=message)
    init()


def generate_mines(dim):
    options = []
    for n in range(dim * 2):
        value = random.randint(0, dim * dim - 1)
        while value in options:
            value = random.randint(0, dim * dim - 1)
        options.append(value)

    return options


def set_neighbour(dim):
    global board
    for i in range(dim):
        for j in range(dim):
            mine_count = 0
            top = i - 1
            bottom = i + 1
            left = j - 1
            right = j + 1
            if top != -1 and top < dim:
                if board[top][j] == mine_character:

                    mine_count = mine_count + 1

            if right != -1 and right < dim:
                if board[i][right] == mine_character:
                    mine_count = mine_count + 1

            if bottom != -1 and bottom < dim:
                if board[bottom][j] == mine_character:
                    mine_count = mine_count + 1

            if left != -1 and left < dim:
                if board[i][left] == mine_character:
                    mine_count = mine_count + 1

            if top != -1 and top < dim and left != -1 and left < dim:
                if board[top][left] == mine_character:
                    mine_count = mine_count + 1

            if top != -1 and top < dim and right != -1 and right < dim:
                if board[top][right] == mine_character:
                    mine_count = mine_count + 1

            if bottom != -1 and bottom < dim and left != -1 and left < dim:
                if board[bottom][left] == mine_character:
                    mine_count = mine_count + 1

            if bottom != -1 and bottom < dim and right != -1 and right < dim:
                if board[bottom][right] == mine_character:
                    mine_count = mine_count + 1

            if board[i][j] != mine_character and mine_count != 0:
                board[i][j] = mine_count
                # buttons[i*dim+j]["text"] = mine_count


def create_board(dim, mine_locations):
    global buttons, board
    buttons = []
    board = []

    for i in range(dim):
        row = []
        for j in range(dim):
            row.append(" ")
            btn_text = " "
            btn_index = i * dim + j
            btn = Button(
                root,
                text=btn_text,
                bg="black",
                fg="white",
                width=4,
                height=2,
                font=("Raleway Bold", 12),
                command=lambda btn_index=btn_index: handle_click(btn_index, dim),
            )
            # if btn_index in mine_locations:
            #     btn["text"] = mine_character
            buttons.append(btn)
        board.append(row)

    for index in mine_locations:
        board[int(index / dim)][index % dim] = mine_character


def init():
    global buttons, score, score_label, mine_locations
    dim = 15
    score = 0

    mine_locations = generate_mines(dim)
    create_board(dim, mine_locations)
    set_neighbour(dim)

    score_label = Label(root, text=score, bg="black", fg="white")
    score_label.grid(row=0, column=0, sticky=EW, columnspan=dim)
    for index, btn in enumerate(buttons):
        row = int((index / dim) + 1)
        col = index % dim
        btn.grid(row=row, column=col)


init()

root.mainloop()
