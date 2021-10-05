import random


def jumble(s):
    for k in range(0, len(s)):
        i = random.randint(0, len(s) - 1)
        j = random.randint(0, len(s) - 1)
        if s[i] != " " and s[j] != " ":
            temp = s[i]
            s[i] = s[j]
            s[j] = temp
    return s


w = input("enter word:").lower()
wl = []
for index in range(0, len(w)):
    wl.append(w[index])
while len(wl) > 0:
    try:
        il = wl.index(" ")
        print(jumble(wl[0:il]), end=" ")
        del wl[0 : (il + 1)]
    except ValueError:
        print(jumble(wl))
        del wl[0 : len(wl)]
