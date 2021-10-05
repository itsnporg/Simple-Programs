C = 3
M = 3
boat = "L"

visited = []


def cross(state, path):
    if state in visited:
        return
    if state[1] > 0 and state[0] > state[1]:
        return
    if M - state[1] > 0 and C - state[0] > M - state[1]:
        return
    if state == [0, 0, "R"]:
        print("start")
        for step in path:
            print(step)
        print("Stop\n")
        return

    visited.append(state[:])

    if state[2] == "L":
        if state[0] >= 1:
            cross([state[0] - 1, state[1], "R"], path[:] + ["One cannible goes right"])

        if state[0] >= 2:
            cross([state[0] - 2, state[1], "R"], path[:] + ["Two cannibles go right"])
        if state[0] >= 1 and state[1] >= 1:
            cross(
                [state[0] - 1, state[1] - 1, "R"],
                path[:] + ["One cannible and one missionary go right"],
            )
        if state[1] >= 1:
            cross(
                [state[0], state[1] - 1, "R"], path[:] + ["One missionaries goes right"]
            )
        if state[1] >= 2:
            cross(
                [state[0], state[1] - 2, "R"], path[:] + ["Two missionaries go right"]
            )

    if state[2] == "R":
        if C - state[0] >= 1:
            cross([state[0] + 1, state[1], "L"], path[:] + ["One cannible goes left"])
        if C - state[0] >= 2:
            cross([state[0] + 2, state[1], "L"], path[:] + ["Two cannibles go left"])
        if C - state[0] >= 1 and M - state[1] >= 1:
            cross(
                [state[0] + 1, state[1] + 1, "L"],
                path[:] + ["One cannible and one missionary go left"],
            )
        if M - state[1] >= 1:
            cross([state[0], state[1] + 1, "L"], path[:] + ["One missionary goes left"])
        if M - state[1] >= 2:
            cross([state[0], state[1] + 2, "L"], path[:] + ["Two missionaries go left"])


cross([3, 3, "L"], [])
