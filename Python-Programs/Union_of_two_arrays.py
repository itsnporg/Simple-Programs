def doUnion(a, n, b, m):
    s = set()
    for i in range(n + m):
        if i < n:
            s.add(a[i])
        if i < m:
            s.add(b[i])
    print(s)
    return len(s)


a = [1, 2, 3, 4, 5]
b = [1, 2, 3]
print(doUnion(a, len(a), b, len(b)))
