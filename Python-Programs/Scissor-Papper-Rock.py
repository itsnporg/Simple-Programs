import random

import pygame

pygame.init()

screen = pygame.display.set_mode((800, 600))
pygame.display.set_caption("Scissor-Paper-Rock game")
icon_path = "1200px-Rock-paper-scissors.svg.png"
icon = pygame.image.load(icon_path)
pygame.display.set_icon(icon)
scissor_path = "scissors.png"
stone_path = "stone.png"
paper_path = "document.png"
scissor = pygame.image.load(scissor_path)
stone = pygame.image.load(stone_path)
paper = pygame.image.load(paper_path)
background_path = "4882066.jpg"
background = pygame.image.load(background_path)
background = pygame.transform.scale(background, (800, 600))
restart_path = "update-arrow.png"
restart = pygame.image.load(restart_path)
pause_path = "pause-outlined-big-symbol.png"
pause = pygame.image.load(pause_path)
setting_path = "settings.png"
setting = pygame.image.load(setting_path)


box_x1 = 0
box_y1 = 0
box_x2 = 0
box_y2 = 0
user_choice = 0
computer_choice = 0
winner = ""


def write_score(large_font, x, y):
    global winner, running
    if winner == "You":
        score = large_font.render(winner + " win", True, (0, 255, 0))
        screen.blit(score, (x, y))
    else:
        score = large_font.render("You lose", True, (255, 0, 0))
        screen.blit(score, (x, y))


def draw_box(x1, y1, x2, y2, colour):
    pygame.draw.rect(screen, colour, pygame.Rect(x1, y1, x2, y2), 5)


def computer(computer_choice2):
    global box_x1, box_y1, box_x2, box_y2, condition4, condition5, condition6
    if computer_choice2 == 1:
        condition4 = True
        box_x1 = 127
        box_y1 = 132
        box_x2 = 114
        box_y2 = 114
        red = (255, 0, 0)
        draw_box(box_x1, box_y1, box_x2, box_y2, red)
    if computer_choice2 == 2:
        condition5 = True
        box_x1 = 559
        box_y1 = 132
        box_x2 = 114
        box_y2 = 114
        red = (255, 0, 0)
        draw_box(box_x1, box_y1, box_x2, box_y2, red)
    if computer_choice2 == 3:
        condition6 = True
        box_x1 = 343
        box_y1 = 340
        box_x2 = 114
        box_y2 = 114
        red = (255, 0, 0)
        draw_box(box_x1, box_y1, box_x2, box_y2, red)


def computer_turn():
    computer_choice1 = random.randint(1, 3)
    while computer_choice1 == user_choice:
        computer_choice1 = random.randint(1, 3)
    print(user_choice, computer_choice1)
    computer(computer_choice1)
    return computer_choice1


running = True
condition1 = False
condition2 = False
condition3 = False
condition4 = False
condition5 = False
condition6 = False
intro_condition = True
over = False
pause_condition = False


def button(colour, x1, y1, w, h, large_font, text, colour_text, x2, y2, width=0):
    pygame.draw.rect(screen, colour, pygame.Rect(x1, y1, w, h), width)
    name = large_font.render(text, True, colour_text)
    screen.blit(name, (x2, y2))


def intro():
    global running, intro_condition

    while intro_condition:
        screen.fill((255, 255, 255))
        large_font = pygame.font.SysFont("comicsansms", 65)
        name = large_font.render("Scissor-Paper-Rock", True, (0, 0, 0))
        screen.blit(name, (100, 200))
        large_font = pygame.font.SysFont("comicsansms", 32)
        button((0, 255, 0), 140, 450, 100, 70, large_font, "Play", (0, 0, 0), 160, 460)
        pygame.draw.rect(screen, (0, 0, 255), pygame.Rect(340, 450, 120, 70))
        screen.blit(setting, (380, 469))
        button((255, 0, 0), 560, 450, 100, 70, large_font, "Exit", (0, 0, 0), 580, 460)

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                intro_condition = False
                running = False
            if event.type == pygame.MOUSEBUTTONUP:
                if event.button == 1:
                    mx, my = pygame.mouse.get_pos()
                    if (mx >= 140) and (mx <= 240) and (my >= 450) and (my <= 520):
                        intro_condition = False
                    if (mx >= 340) and (mx <= 460) and (my >= 450) and (my <= 520):
                        print("Menu")
                    if (mx >= 560) and (mx <= 660) and (my >= 450) and (my <= 520):
                        intro_condition = False
                        running = False
        pygame.display.update()


def pause_game():
    global pause_condition, running, over
    while pause_condition:
        screen.fill((255, 255, 255))
        large_font = pygame.font.SysFont("comicsansms", 100)
        name = large_font.render("Paused", True, (0, 0, 0))
        screen.blit(name, (250, 200))
        large_font = pygame.font.SysFont("comicsansms", 32)
        pygame.draw.rect(screen, (0, 255, 0), pygame.Rect(140, 450, 100, 70))
        screen.blit(pause, (174, 469))
        pygame.draw.rect(screen, (0, 0, 255), pygame.Rect(340, 450, 120, 70))
        screen.blit(setting, (380, 469))
        button((255, 0, 0), 560, 450, 100, 70, large_font, "Exit", (0, 0, 0), 580, 460)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pause_condition = False
                running = False
                over = True
            if event.type == pygame.MOUSEBUTTONUP:
                if event.button == 1:
                    mx, my = pygame.mouse.get_pos()
                    if (mx >= 140) and (mx <= 240) and (my >= 450) and (my <= 520):
                        pause_condition = False
                    if (mx >= 340) and (mx <= 460) and (my >= 450) and (my <= 520):
                        print("Menu")
                    if (mx >= 560) and (mx <= 660) and (my >= 450) and (my <= 520):
                        pause_condition = False
                        running = False
                        over = True
        pygame.display.update()


def game_over():
    global running, over
    while not over:
        screen.fill((255, 255, 255))
        large_font = pygame.font.SysFont("comicsansms", 100)
        write_score(large_font, 210, 150)
        large_font = pygame.font.SysFont("comicsansms", 32)
        pygame.draw.rect(screen, (0, 255, 0), pygame.Rect(140, 450, 100, 70))
        screen.blit(restart, (174, 469))
        pygame.draw.rect(screen, (0, 0, 255), pygame.Rect(340, 450, 120, 70))
        screen.blit(setting, (380, 469))
        button((255, 0, 0), 560, 450, 100, 70, large_font, "Exit", (0, 0, 0), 580, 460)

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                over = True
                running = False
            if event.type == pygame.MOUSEBUTTONUP:
                if event.button == 1:
                    mx, my = pygame.mouse.get_pos()
                    if (mx >= 140) and (mx <= 240) and (my >= 450) and (my <= 520):
                        # over = True
                        game_loop()
                    if (mx >= 340) and (mx <= 460) and (my >= 450) and (my <= 520):
                        print("Menu")
                    if (mx >= 560) and (mx <= 660) and (my >= 450) and (my <= 520):
                        over = True
                        running = False
        pygame.display.update()


def game_loop():
    global running, condition1, condition2, condition3, condition4, condition5, condition6
    global box_x1, box_x2, box_y1, box_y2, user_choice, winner, computer_choice, over, pause_condition
    while running:

        screen.fill((255, 255, 255))
        screen.blit(background, (0, 0))
        pygame.draw.polygon(screen, (255, 255, 255), ((20, 20), (20, 40), (35, 30)))
        large_font = pygame.font.SysFont("comicsansms", 32)
        button((0, 0, 0), 200, 5, 400, 70, large_font, "Player vs Computer", (255, 255, 255), 250, 15, width=5)
        screen.blit(scissor, (152, 157))
        screen.blit(stone, (584, 157))
        screen.blit(paper, (368, 365))

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
                over = True
            if event.type == pygame.MOUSEBUTTONUP:
                if event.button == 1:
                    mx, my = pygame.mouse.get_pos()
                    if (mx >= 20) and (mx <= 35) and (my >= 20) and (my <= 30):
                        pause_condition = True
                        pause_game()
                    if (mx >= 152) and (mx <= 216) and (my >= 157) and (my <= 221):
                        print("Scissor is pressed")
                        condition1 = True
                        user_choice = 1
                        computer_choice = computer_turn()
                    if (mx >= 584) and (mx <= 648) and (my >= 157) and (my <= 221):
                        print("Stone is pressed")
                        condition2 = True
                        user_choice = 2
                        computer_choice = computer_turn()
                    if (mx >= 368) and (mx <= 432) and (my >= 365) and (my <= 429):
                        print("Paper is pressed")
                        condition3 = True
                        user_choice = 3
                        computer_choice = computer_turn()

        if (user_choice == 1) and (computer_choice == 2):
            winner = "Computer"
            user_choice = 0
            computer_choice = 0
            game_over()

        elif user_choice == 1 and computer_choice == 3:
            winner = "You"
            user_choice = 0
            computer_choice = 0
            game_over()

        elif user_choice == 2 and computer_choice == 3:
            winner = "Computer"
            user_choice = 0
            computer_choice = 0
            game_over()

        elif user_choice == 2 and computer_choice == 1:
            winner = "You"
            user_choice = 0
            computer_choice = 0
            game_over()

        elif user_choice == 3 and computer_choice == 1:
            winner = "Computer"
            user_choice = 0
            game_over()

        elif user_choice == 3 and computer_choice == 2:
            winner = "You"
            user_choice = 0
            computer_choice = 0
            game_over()

        pygame.display.update()


intro()
game_loop()
pygame.quit()
