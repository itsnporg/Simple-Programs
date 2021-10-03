import random
from tkinter import *
from tkinter import messagebox

root = Tk()
root.iconbitmap("D:\\Projects\\Python\\Tkinter\\tic_tac_toe\\icon.ico")
root.title("Tic Tac Toe Game")
root.resizable(0, 0)

wincombos = [
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8],
    [0, 3, 6],
    [1, 4, 7],
    [2, 5, 8],
    [0, 4, 8],
    [2, 4, 6],
]

AI = "X"
HUMAN = "O"


# def check_win():
def update_board(index, text):
    global board
    board[int(index / 3)][index % 3] = str(text)


def check_win():
    win_list_AI = [AI, AI, AI]
    win_list_HUMAN = [HUMAN, HUMAN, HUMAN]
    for combo in wincombos:
        comp_list = []
        for index in combo:
            comp_list.append(board[int(index / 3)][index % 3])
        if comp_list == win_list_AI:
            return [AI, combo]
        elif comp_list == win_list_HUMAN:
            return [HUMAN, combo]
    return [False, None]


def check_board_cell_empty(index):
    if board[int(index / 3)][index % 3] == "":
        return True
    return False


def random_comp_player():
    global buttons, count
    count = count + 1
    comp_choice = random.randint(0, 8)

    while not check_board_cell_empty(comp_choice):
        comp_choice = random.randint(0, 8)

    buttons[comp_choice]["text"] = AI
    # generate random number
    update_board(comp_choice, AI)

    player_win = check_game_end()
    if player_win[0] == AI:
        print(player_win, AI)
        game_end(AI, True, player_win[1])

    elif player_win[0] == "Tie":
        print("tie")
        game_end(None, False, None)


def game_end(char, status, win_combo):
    global buttons
    if status == True:
        for combo in win_combo:
            buttons[combo]["bg"] = "lightgreen"
        messagebox.showinfo("Winner! ", f"{char} has won :D")
        init()
        ai_player()

    elif status == False:
        messagebox.showinfo("Draw! ", "Game has Drawn :3")
        init()
        ai_player()


def handle_click(b, index):
    global count, buttons
    if check_board_cell_empty(index):
        count = count + 1
        b["text"] = HUMAN
        update_board(index, HUMAN)

        player_win = check_game_end()
        if player_win[0] == HUMAN:
            game_end(HUMAN, True, player_win[1])

        elif player_win[0] == "Tie":
            print("tie")
            game_end("", False, None)

        else:
            ai_player()


def check_game_end():
    global buttons, count
    result = None
    char_win = check_win()

    if char_win[0] == HUMAN:
        result = HUMAN
        return [HUMAN, char_win[1]]
    elif char_win[0] == AI:
        result = AI
        return [AI, char_win[1]]

    if result == None:
        if count >= 9:
            result = "Tie"
            return [result, None]
        return [None, None]


def minimax(board, is_maximizing):
    score_table = {"X": 1, "O": -1, "Tie": 0}
    result = check_game_end()
    if result[0] != None:
        return score_table[result[0]]

    if is_maximizing:
        best_score = float("-inf")
        for i in range(3):
            for j in range(3):
                if board[i][j] == "":
                    board[i][j] = AI
                    score = minimax(board, False)
                    board[i][j] = ""
                    best_score = max(score, best_score)
        return best_score
    else:
        best_score = float("inf")
        for i in range(3):
            for j in range(3):
                if board[i][j] == "":
                    board[i][j] = HUMAN
                    score = minimax(board, True)
                    board[i][j] = ""
                    best_score = min(score, best_score)
        return best_score


def ai_player():
    global board, count
    count = count + 1
    best_score = float("-inf")
    best_move = 0
    for i in range(3):
        for j in range(3):
            if board[i][j] == "":
                board[i][j] = AI
                score = minimax(board, False)
                board[i][j] = ""
                if score > best_score:
                    best_score = score
                    best_move = i * 3 + j

    update_board(best_move, AI)
    buttons[best_move]["text"] = AI

    player_win = check_game_end()
    if player_win[0] == AI:
        print(player_win, AI)
        game_end(AI, True, player_win[1])

    elif player_win[0] == "Tie":
        print("tie")
        game_end(None, False, None)


def init():
    global board, count, x_turn, buttons
    count = 0
    x_turn = True
    board = [
        ["", "", ""],
        ["", "", ""],
        ["", "", ""],
    ]

    b0 = Button(
        root,
        text=" ",
        font=("Indie Flower", 40),
        height=2,
        width=7,
        bg="white",
        command=lambda: handle_click(b0, 0),
    )
    b1 = Button(
        root,
        text=" ",
        font=("Indie Flower", 40),
        height=2,
        width=7,
        bg="white",
        command=lambda: handle_click(b1, 1),
    )
    b2 = Button(
        root,
        text=" ",
        font=("Indie Flower", 40),
        height=2,
        width=7,
        bg="white",
        command=lambda: handle_click(b2, 2),
    )
    b3 = Button(
        root,
        text=" ",
        font=("Indie Flower", 40),
        height=2,
        width=7,
        bg="white",
        command=lambda: handle_click(b3, 3),
    )
    b4 = Button(
        root,
        text=" ",
        font=("Indie Flower", 40),
        height=2,
        width=7,
        bg="white",
        command=lambda: handle_click(b4, 4),
    )
    b5 = Button(
        root,
        text=" ",
        font=("Indie Flower", 40),
        height=2,
        width=7,
        bg="white",
        command=lambda: handle_click(b5, 5),
    )
    b6 = Button(
        root,
        text=" ",
        font=("Indie Flower", 40),
        height=2,
        width=7,
        bg="white",
        command=lambda: handle_click(b6, 6),
    )
    b7 = Button(
        root,
        text=" ",
        font=("Indie Flower", 40),
        height=2,
        width=7,
        bg="white",
        command=lambda: handle_click(b7, 7),
    )
    b8 = Button(
        root,
        text=" ",
        font=("Indie Flower", 40),
        height=2,
        width=7,
        bg="white",
        command=lambda: handle_click(b8, 8),
    )

    buttons = [b0, b1, b2, b3, b4, b5, b6, b7, b8]

    b0.grid(row=0, column=0)
    b1.grid(row=0, column=1)
    b2.grid(row=0, column=2)
    b3.grid(row=1, column=0)
    b4.grid(row=1, column=1)
    b5.grid(row=1, column=2)
    b6.grid(row=2, column=0)
    b7.grid(row=2, column=1)
    b8.grid(row=2, column=2)


init()
ai_player()

root.mainloop()

#  def check_game_end(char, status):
#     global buttons, count
#     if (status == True):
#         char_win = check_win(char)
#         if (char_win[0]):
#             win_combo = char_win[1]
#             for combo in win_combo:
#                 buttons[combo]["bg"] = "lightgreen"
#             messagebox.showinfo("Winner!", f"{char} Won! :D")
#             init()
#             return True
#         return False

#     if status == False:
#         if count >= 9:
#             messagebox.showinfo("Draw", "Game Drawn! :P")
#             init()
#             return True
#         return False
