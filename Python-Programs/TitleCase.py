## eg THIS IS THE TITLE
## Result : This Is The Title


def title_case(title, minor_words=""):
    titleArr = title.lower().split(" ")
    minorArr = minor_words.lower().split(" ")
    titleArr[0] = titleArr[0].capitalize()
    newArr = []

    for i in range(len(titleArr)):
        if i == 0:
            newArr.append(titleArr[i].capitalize())
        else:
            if titleArr[i] in minorArr:
                newArr.append(titleArr[i])
            else:
                newArr.append(titleArr[i].capitalize())

    return " ".join(newArr).strip()
