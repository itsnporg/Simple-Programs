import pygame
import random
import math

pygame.init()

screen = pygame.display.set_mode((800, 600))
pygame.display.set_caption("Snake game")
icon_path = "scared.png"
icon = pygame.image.load(icon_path)
pygame.display.set_icon(icon)
clock = pygame.time.Clock()
apple_path = "apple.png"
apple = pygame.image.load(apple_path)
apple_x = random.randint(100, 700)
apple_y = random.randint(100, 500)
pause_path = "pause-outlined-big-symbol.png"
pause = pygame.image.load(pause_path)
restart_path = "update-arrow.png"
restart = pygame.image.load(restart_path)
sound_path = "volume.png"
sound = pygame.image.load(sound_path)
mute_path = "mute.png"
mute = pygame.image.load(mute_path)
back_path = "back-button.png"
back = pygame.image.load(back_path)
setting_path = "settings.png"
setting = pygame.image.load(setting_path)
font_go = pygame.font.SysFont("comicsansms", 80)
legends = "legends never die.wav"

running = True
fps = 30
secured_score = 0
intro_condition = True
pause_condition = False
over = False
menu_condition = True
label_condition = True
label_chossed = "Easy"
sound_condition = True
sound_chossed = True


def is_collision(x1, y1, x2, y2):
    distance = math.sqrt(math.pow(x2 - x1, 2) + math.pow(y2 - y1, 2))
    if distance <= 25:
        return True
    else:
        return False


def write_score(large_font, x, y, colour):
    score = large_font.render("Score : " + str(secured_score), True, colour)
    screen.blit(score, (x, y))


def draw_snake(colour, snake_list, snake_size):
    for x, y in snake_list:
        pygame.draw.rect(screen, colour, pygame.Rect(x, y, snake_size, snake_size))


def game_over_text():
    text = font_go.render("Game Over", True, (255, 0, 0))
    screen.blit(text, (200, 115))


def button(colour, x1, y1, w, h, large_font, text, colour_text, x2, y2, width=0):
    pygame.draw.rect(screen, colour, pygame.Rect(x1, y1, w, h), width)
    name = large_font.render(text, True, colour_text)
    screen.blit(name, (x2, y2))


def label():
    global label_condition, intro_condition, menu_condition, running, label_chossed
    while label_condition:
        screen.fill((255, 255, 255))
        large_font = pygame.font.SysFont("comicsansms", 65)
        name = large_font.render("Label", True, (0, 0, 0))
        screen.blit(name, (320, 10))
        large_font = pygame.font.SysFont("comicsansms", 32)
        button((255, 0, 0), 340, 125, 140, 70, large_font, "Hard", (0, 0, 0), 370, 135)
        button((255, 255, 0), 340, 225, 140, 70, large_font, "Medium", (0, 0, 0), 355, 235)
        button((0, 255, 0), 340, 325, 140, 70, large_font, "Easy", (0, 0, 0), 370, 335)

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                intro_condition = False
                menu_condition = False
                running = False
            if event.type == pygame.MOUSEBUTTONUP:
                if event.button == 1:
                    mx, my = pygame.mouse.get_pos()
                    if (mx >= 340) and (mx <= 480) and (my >= 125) and (my <= 195):
                        print("Hard")
                        label_chossed = "Hard"
                        label_condition = False
                    if (mx >= 340) and (mx <= 480) and (my >= 225) and (my <= 295):
                        print("Medium")
                        label_chossed = "Medium"
                        label_condition = False
                    if (mx >= 340) and (mx <= 480) and (my >= 325) and (my <= 395):
                        print("Easy")
                        label_chossed = "Easy"
                        label_condition = False
        pygame.display.update()


def sound_state():
    global sound_condition, intro_condition, menu_condition, running, label_condition, sound_chossed
    while sound_condition:
        screen.fill((255, 255, 255))
        large_font = pygame.font.SysFont("comicsansms", 65)
        name = large_font.render("Sound", True, (0, 0, 0))
        screen.blit(name, (300, 10))
        large_font = pygame.font.SysFont("comicsansms", 32)
        button((0, 255, 0), 340, 125, 120, 70, large_font, "On", (0, 0, 0), 375, 135)
        button((255, 0, 0), 340, 225, 120, 70, large_font, "Off", (0, 0, 0), 370, 235)

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                intro_condition = False
                menu_condition = False
                running = False
            if event.type == pygame.MOUSEBUTTONUP:
                if event.button == 1:
                    mx, my = pygame.mouse.get_pos()
                    if (mx >= 340) and (mx <= 460) and (my >= 125) and (my <= 195):
                        print("on")
                        sound_condition = False
                        sound_chossed = True
                    if (mx >= 340) and (mx <= 460) and (my >= 225) and (my <= 295):
                        print("Off")
                        sound_condition = False
                        sound_chossed = False
        pygame.display.update()


def menu():
    global menu_condition, running, intro_condition, over, secured_score, label_condition, sound_condition
    global pause_condition
    while menu_condition:
        screen.fill((255, 255, 255))
        large_font = pygame.font.SysFont("comicsansms", 65)
        name = large_font.render("Setting", True, (0, 0, 0))
        screen.blit(name, (300, 10))
        large_font = pygame.font.SysFont("comicsansms", 32)
        button((0, 0, 255), 340, 125, 120, 70, large_font, "Level", (0, 0, 0), 360, 135)
        # button((0, 255, 0), 340, 175, 120, 70, large_font, )
        pygame.draw.rect(screen, (255, 255, 0), pygame.Rect(340, 225, 120, 70))
        screen.blit(sound, (380, 244))
        pygame.draw.rect(screen, (0, 255, 0), pygame.Rect(340, 325, 120, 70))
        screen.blit(restart, (380, 344))
        button((255, 0, 0), 340, 425, 120, 70, large_font, "Exit", (0, 0, 0), 365, 435)
        screen.blit(back, (20, 20))

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                intro_condition = False
                menu_condition = False
                running = False
            if event.type == pygame.MOUSEBUTTONUP:
                if event.button == 1:
                    mx, my = pygame.mouse.get_pos()
                    if (mx >= 340) and (mx <= 460) and (my >= 125) and (my <= 195):
                        print("labelled")
                        label_condition = True
                        label()
                    if (mx >= 340) and (mx <= 460) and (my >= 225) and (my <= 295):
                        print("Sound")
                        sound_condition = True
                        sound_state()
                    if (mx >= 340) and (mx <= 460) and (my >= 325) and (my <= 395):
                        secured_score = 0
                        over = True
                        running = True
                        menu_condition = False
                        game_loop()
                    if (mx >= 340) and (mx <= 460) and (my >= 425) and (my <= 495):
                        intro_condition = False
                        menu_condition = False
                        running = False
                        pause_condition = False
                    if (mx >= 20) and (mx <= 52) and (my >= 20) and (my <= 52):
                        menu_condition = False
        pygame.display.update()


def intro():
    global running, intro_condition

    while intro_condition:
        screen.fill((255, 255, 255))
        large_font = pygame.font.SysFont("comicsansms", 65)
        name = large_font.render("Snake Game", True, (0, 0, 0))
        screen.blit(name, (220, 200))
        large_font = pygame.font.SysFont("comicsansms", 32)
        button((0, 255, 0), 140, 450, 100, 70, large_font, "Play", (0, 0, 0), 160, 460)
        # button((0, 0, 255), 340, 450, 120, 70, large_font, "Menu", (0, 0, 0), 360, 460)
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
                        menu()
                    if (mx >= 560) and (mx <= 660) and (my >= 450) and (my <= 520):
                        intro_condition = False
                        running = False
        pygame.display.update()


def pause_game():
    global pause_condition, running, over, menu_condition
    while pause_condition:
        screen.fill((255, 255, 255))
        large_font = pygame.font.SysFont("comicsansms", 100)
        name = large_font.render("Paused", True, (0, 0, 0))
        screen.blit(name, (250, 200))
        large_font = pygame.font.SysFont("comicsansms", 32)
        pygame.draw.rect(screen, (0, 255, 0), pygame.Rect(140, 450, 100, 70))
        screen.blit(pause, (174, 469))
        # button((0, 0, 255), 340, 450, 120, 70, large_font, "Menu", (0, 0, 0), 360, 460)
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
                        menu_condition = True
                        menu()
                    if (mx >= 560) and (mx <= 660) and (my >= 450) and (my <= 520):
                        pause_condition = False
                        running = False
                        over = True
        pygame.display.update()


def game_over(highscore, result):
    global running, over, secured_score, menu_condition
    while not over:
        with open("highscore", "w") as f:
            f.write(str(highscore))
        screen.fill((255, 255, 255))
        large_font = pygame.font.SysFont("comicsansms", 50)
        game_over_text()
        write_score(large_font, 300, 235, (0, 255, 0))
        large_font = pygame.font.SysFont("comicsansms", 32)
        if result:
            score = large_font.render("Hurrah! You beat the Highscore", True, (0, 255, 0))
            screen.blit(score, (180, 320))
        pygame.draw.rect(screen, (0, 255, 0), pygame.Rect(140, 450, 100, 70))
        screen.blit(restart, (174, 469))
        # button((0, 0, 255), 340, 450, 120, 70, large_font, "Menu", (0, 0, 0), 360, 460)
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
                        secured_score = 0
                        over = True
                        running = True
                        game_loop()
                    if (mx >= 340) and (mx <= 460) and (my >= 450) and (my <= 520):
                        menu_condition = True
                        menu()
                    if (mx >= 560) and (mx <= 660) and (my >= 450) and (my <= 520):
                        over = True
                        running = False
        pygame.display.update()


def game_loop():
    global running, fps, apple, apple_x, apple_y, over
    global secured_score, pause_condition, label_chossed, sound_chossed
    snake_x = random.randint(100, 700)
    snake_y = random.randint(100, 500)
    velocity_x = 0
    velocity_y = 0
    snake_size = 30
    speed = 10
    snake_list = []
    snake_length = 1
    result = False
    with open("highscore", "r") as f:
        highscore = f.read()
    if label_chossed == "Hard":
        speed = 20
    if label_chossed == "Medium":
        speed = 15
    if label_chossed == "Easy":
        speed = 10
    if sound_chossed:
        pygame.mixer.init()
        pygame.mixer.music.load(legends)
        pygame.mixer.music.play()

    while running:
        screen.fill((0, 120, 0))
        screen.blit(apple, (apple_x, apple_y))
        pygame.draw.polygon(screen, (255, 255, 255), ((20, 20), (20, 40), (35, 30)))

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.MOUSEBUTTONDOWN:
                mx, my = pygame.mouse.get_pos()
                if (mx >= 20) and (mx <= 35) and (my >= 20) and (my <= 30):
                    pause_condition = True
                    pause_game()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_RIGHT:
                    velocity_x = speed
                    velocity_y = 0
                if event.key == pygame.K_LEFT:
                    velocity_x = -speed
                    velocity_y = 0
                if event.key == pygame.K_UP:
                    velocity_y = -speed
                    velocity_x = 0
                if event.key == pygame.K_DOWN:
                    velocity_y = speed
                    velocity_x = 0

        snake_x += velocity_x
        snake_y += velocity_y

        collision = is_collision(snake_x, snake_y, apple_x, apple_y)
        if collision:
            secured_score += 1
            apple_x = random.randint(100, 700)
            apple_y = random.randint(100, 500)
            snake_length += 5
        large_font = pygame.font.SysFont("comicsansms", 32)
        score = large_font.render("HI : " + highscore, True, (255, 255, 255))
        screen.blit(score, (670, 10))
        if secured_score > int(highscore):
            highscore = str(secured_score)
            result = True

        write_score(large_font, 320, 10, (255, 255, 255))

        head = [snake_x, snake_y]
        snake_list.append(head)
        if len(snake_list) > snake_length:
            del snake_list[0]
        draw_snake((0, 0, 255), snake_list, snake_size)
        # : -1 means excluding last element and showing others
        if head in snake_list[: - 1]:
            over = False
            game_over(highscore, result)
            del snake_list
            snake_x = random.randint(100, 700)
            snake_y = random.randint(100, 500)
            snake_list = []
        if (snake_x <= 1) or (snake_x >= 799) or (snake_y <= 1) or (snake_y >= 599):
            print("game_over")
            over = False
            game_over(highscore, result)
            del snake_list
            snake_x = random.randint(100, 700)
            snake_y = random.randint(100, 500)
            snake_list = []
        pygame.display.update()
        clock.tick(fps)


intro()
game_loop()
pygame.quit()
quit()
