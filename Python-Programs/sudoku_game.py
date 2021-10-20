import time

import pygame
from pygame.locals import *

pygame.init()

global size

size = (height, width) = (600, 600)
screen = pygame.display.set_mode((600, 700), 0, 32)
bg = (239, 239, 239)
screen.fill((bg))

question = [
    [7, 8, 0, 4, 0, 0, 1, 2, 0],
    [6, 0, 0, 0, 7, 5, 0, 0, 9],
    [0, 0, 0, 6, 0, 1, 0, 7, 8],
    [0, 0, 7, 0, 4, 0, 2, 6, 0],
    [0, 0, 1, 0, 5, 0, 9, 3, 0],
    [9, 0, 4, 0, 6, 0, 0, 0, 5],
    [0, 7, 0, 3, 0, 0, 0, 1, 2],
    [1, 2, 0, 0, 0, 7, 4, 0, 0],
    [0, 4, 9, 2, 0, 6, 0, 0, 7],
]
question1 = [
    [0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0],
]
board = question


def main():
    global board
    firstTime = True
    a = True
    newWidth = width / 9
    while True:

        for event in pygame.event.get():
            if event.type == QUIT:
                print(board)
                exit()

            if firstTime:
                print("elo")
                drawBoard()
                returnBoard(question)

                firstTime = False

            if event.type == pygame.KEYDOWN:
                x, y = keyPress()
                key = keyInput()
                if key == "ESCAPE":
                    deleteNum(x, y)
                    board[y][x] = 0
                elif key == "R":
                    if findEmpty(board):
                        solve(board)

                if not key == "ESCAPE":
                    if board[y][x] == 0:

                        if not emptyValid(board, key, x, y):
                            pygame.draw.rect(
                                screen,
                                (255, 0, 0),
                                (x * newWidth + 10, y * newWidth + 10, 50, 50),
                                3,
                            )
                        board[y][x] = int(key)
                        printNum(key, x, y)
        pygame.display.flip()
        pygame.display.update()


def solve(bo):
    newWidth = width / 9
    find = findEmpty(bo)
    if not find:
        return True
    else:
        row, col = find

    for i in range(1, 10):
        if valid(bo, i, (row, col)):
            pygame.draw.rect(
                screen,
                (101, 196, 100),
                (col * newWidth + 10, row * newWidth + 10, 50, 50),
                3,
            )

            board[row][col] = i
            returnBoard(bo)

            pygame.display.update()
            pygame.time.delay(20)

            if solve(bo):
                return True

            bo[row][col] = 0
            deleteNum(col, row)
            pygame.display.update()
            pygame.time.delay(50)

    return False


def returnBoard(bo):

    for i in range(0, 9):
        for j in range(0, 9):
            if bo[i][j] != 0:
                printNum(str(bo[i][j]), j, i)


def drawBoard():

    # Drawing Board
    newWidth = width / 9
    pygame.draw.rect(screen, (7, 7, 7), (0, 0, 600, 600), 2)

    pygame.font.init()

    myfont = pygame.font.SysFont("Comic Sans MS", 30)
    textsurface = myfont.render("Press 'R' to auto solve", False, (0, 0, 0))
    screen.blit(textsurface, (150, 620))

    myfont1 = pygame.font.SysFont("Arial.ttf", 20)
    textsurface1 = myfont1.render(
        "Hover over blank space and press number to enter \n Escape to remove",
        False,
        (0, 0, 0),
    )
    screen.blit(textsurface1, (25, 610))

    for i in range(1, 9):
        if i % 3 == 0:
            pygame.draw.line(
                screen, (7, 7, 7), (newWidth * i, 0), (newWidth * i, 600), 3
            )
            pygame.draw.line(
                screen, (7, 7, 7), (0, newWidth * i), (600, newWidth * i), 3
            )
        else:
            pygame.draw.line(
                screen, (7, 7, 7), (newWidth * i, 0), (newWidth * i, 600), 2
            )
            pygame.draw.line(
                screen, (7, 7, 7), (0, newWidth * i), (600, newWidth * i), 2
            )
        i = i + 1


def keyPress():
    x = 0
    y = 0
    newWidth = width / 9
    if pygame.key.get_pressed():  # KeyPress
        (mouse_x, mouse_y) = pygame.mouse.get_pos()  # Get Coords
        for i in range(0, 9):
            if mouse_x > (newWidth * (i)):
                x = i  # row index
            if mouse_y > (newWidth * (i)):
                y = i  # col index
        return (x, y)  # row, col from index 0


def keyInput():

    key_input = pygame.key.get_pressed()
    if key_input[pygame.K_1]:
        return "1"
    if key_input[pygame.K_2]:
        return "2"
    if key_input[pygame.K_3]:
        return "3"
    if key_input[pygame.K_4]:
        return "4"
    if key_input[pygame.K_5]:
        return "5"
    if key_input[pygame.K_6]:
        return "6"
    if key_input[pygame.K_7]:
        return "7"
    if key_input[pygame.K_8]:
        return "8"
    if key_input[pygame.K_9]:
        return "9"
    if key_input[pygame.K_ESCAPE]:
        return "ESCAPE"
    if key_input[pygame.K_r]:
        return "R"


def findEmpty(bo):
    for i in range(0, 9):
        for j in range(0, 9):
            if bo[i][j] == 0:
                return i, j


def valid(bo, num, pos):

    # Check Row
    for i in range(len(bo[0])):
        if bo[pos[0]][i] == num and pos[1] != i:
            return False

    # Check Col
    for i in range(len(bo)):
        if bo[i][pos[1]] == num and pos[0] != i:
            return False

    # Check box
    box_x = pos[1] // 3
    box_y = pos[0] // 3

    for i in range(box_y * 3, box_y * 3 + 3):
        for j in range(box_x * 3, box_x * 3 + 3):
            if bo[i][j] == num and (i, j) != pos:
                return False

    return True


def emptyValid(bo, num, x, y):
    if num != "ESCAPE":
        num = int(num)
    ans = 1
    if bo[y][x] == 0:
        ans = 0
    for i in range(0, 9):  # Col and Row
        if bo[y][i] == num:
            ans = 1
        if bo[i][x] == num:
            ans = 1

    box_x = x // 3
    box_y = y // 3

    for i in range(box_x * 3, (box_x * 3) + 3):
        for j in range(box_y * 3, (box_y * 3) + 3):
            if bo[j][i] == num:
                ans = 1

    if ans == 0:
        return True
    else:
        return False


def printNum(num, x, y):
    global board

    newWidth = width / 9
    font = pygame.font.SysFont("Arial.ttf", 40)
    img = font.render(str(num), True, (7, 7, 7))

    offset = 23
    screen.blit(
        img, ((newWidth * x) + offset, (newWidth * y) + offset)
    )  # add font to screen


def deleteNum(x, y):
    global board
    bg = (239, 239, 239)
    newWidth = width / 9

    pygame.draw.rect(screen, bg, (x * newWidth + 5, y * newWidth + 5, 60, 60))


main()
