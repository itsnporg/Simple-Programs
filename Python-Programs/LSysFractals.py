import turtle


def create_l_system(iters, axiom, rules):
    starting_axiom = axiom
    if iters == 0:
        return starting_axiom
    else:
        for i in range(iters):
            aux = []
            for letter in starting_axiom:
                if letter in rules:
                    aux.append(rules[letter])
                else:
                    aux.append(letter)
            starting_axiom = "".join(aux)

    return starting_axiom


def draw_l_systems(t, instructions, distance, angle):
    for letter in instructions:
        if letter == "F":
            t.forward(distance)
        elif letter == "+":
            t.right(angle)
        elif letter == "-":
            t.left(angle)


def fractal(iterations, axiom, rules, angle, length, x_offset, y_offset):

    instructions = create_l_system(iterations, axiom, rules)
    t = turtle.Turtle()
    wn = turtle.Screen()
    wn.setup(500, 500)
    t.speed(0)
    t.up()
    t.backward(x_offset)
    t.left(90)
    t.backward(y_offset)
    t.right(90)
    t.down()
    t.pensize(2)
    print(instructions)
    draw_l_systems(t, instructions, length, angle)
    t.hideturtle()
    wn.exitonclick()


if __name__ == "__main__":
    # Quadratic SnowFlake
    # fractal(4, "F--F", {"F":"F-F+F+F-F"}, 90, 5, 200, 0)

    # Koch-Snowflake
    fractal(3, "F--F--F", {"F": "F+F--F+F"}, 60, 3, 100, 100)

    # Quadratic-Koch-Island
    # fractal(2, "F+F+F+F", {"F":"F-F+F+FFF-F-F+F"}, 90, 5, 100, -100)
