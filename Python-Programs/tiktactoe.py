import random
import time

# displays playing boards


def display_board(board):
    print("\n" * 100)
    print("Layout of the Tic Tac Toe")
    print(" 7 | 8 | 9 ")
    print("-----------")
    print(" 4 | 5 | 6 ")
    print("-----------")
    print(" 1 | 2 | 3 \n\n\n\n")

    print("Actual Game")
    print(" {} | {} | {} ".format(board[7], board[8], board[9]))
    print("-----------")
    print(" {} | {} | {} ".format(board[4], board[5], board[6]))
    print("-----------")
    print(" {} | {} | {} ".format(board[1], board[2], board[3]))


# get the player input for chosing X or O


def player_input():
    marker = ""
    while marker != "X" and marker != "x" and marker != "O" and marker != "o":
        marker = input("Player1, what do you want to take 'X' of 'O' : ")

    player1 = marker.upper()
    if marker == "X" or marker == "x":
        player2 = "O"
    else:
        player2 = "X"

    return (player1, player2)


# place the player's marker on the board at given position


def place_marker(board, marker, position):
    board[position] = marker


# check if a player won the match


def win_check(board, mark):
    if board[1] == board[2] == board[3]:
        marker = board[1]
    elif board[1] == board[4] == board[7]:
        marker = board[1]
    elif board[1] == board[5] == board[9]:
        marker = board[1]
    elif board[2] == board[5] == board[8]:
        marker = board[2]
    elif board[3] == board[6] == board[9]:
        marker = board[3]
    elif board[3] == board[5] == board[7]:
        marker = board[3]
    elif board[4] == board[5] == board[6]:
        marker = board[4]
    elif board[7] == board[8] == board[9]:
        marker = board[7]
    else:
        marker = " "

    return marker == mark


def choose_first():
    turn = random.randint(0, 1)
    if turn == 0:
        print("Player 1 will go first")
        return True
    else:
        print("Player 2 will go first")
        return False


def space_check(board, position):
    return board[position] == " "


def full_board_check(board):
    return (
        board[1] != " "
        and board[2] != " "
        and board[3] != " "
        and board[4] != " "
        and board[5] != " "
        and board[6] != " "
        and board[7] != " "
        and board[8] != " "
        and board[9] != " "
    )


def player_choice(board):
    move = 0
    time.sleep(0.2)
    while move < 1 or move > 9:
        try:
            move = int(input("Enter postision of your move (1-9) : "))
        except:
            print("Enter Valid Input")
    if space_check(board, move):
        return move
    else:
        return False


def replay():
    play = ""
    while play.lower() != "yes" and play.lower() != "no":
        play = input("Do you want to play again 'Yes' or 'No' : ")
        play = play.lower()
    return play == "yes"


print("Hello buddy welcome!")
time.sleep(0.2)
while True:
    player1_marker, player2_marker = player_input()
    board = ["#", " ", " ", " ", " ", " ", " ", " ", " ", " "]
    display_board(board)
    game_on = True
    turn = choose_first()
    ch = input("Press Enter to Start Game")

    while game_on:
        display_board(board)
        if full_board_check(board):
            game_on = False
            print("Game is Draw")
        elif turn:
            print("Player 1 Turn:")
            turn = False
            position = False
            while position is False:
                position = player_choice(board)
            if space_check(board, position):
                place_marker(board, player1_marker, position)
            if win_check(board, player1_marker):
                game_on = False
                display_board(board)
                print("Winner is Player 1")
        else:
            print("Player 2 Turn:")
            turn = True
            position = False
            while position is False:
                position = player_choice(board)
            if space_check(board, position):
                place_marker(board, player2_marker, position)
            if win_check(board, player2_marker):
                game_on = False
                display_board(board)
                print("Winner is Player 2")

    if not replay():
        break
