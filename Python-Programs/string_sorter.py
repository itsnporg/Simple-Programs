def stringSorter(string):
    """Sorts string using simple loops"""
    lst = list(string)
    sorted_str = ""
    while lst:
        for i in lst:
            l = min(lst)
            sorted_str += l
            lst.remove(l)
    return sorted_str


def stringSorted_R(string):
    """Sorts string using recursion"""
    if len(string) == 0:
        return ""
    else:
        l = min(string)
        return l + stringSorted_R(string.replace(l, "", 1))
