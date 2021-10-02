# we are given a 2d matrix of 0s and 1s where 0 represents water and 1 represents land.
# any chunk of land disconnected from the borders(edges) of matrix is considered an island.
# The task is to remove all the islands from the matrix.

# Example
# [1, 0, 0, 0, 0, 0]		[1, 0, 0, 0, 0, 0]
# [0, 1, 0, 1, 1, 1]		[0, 0, 0, 1, 1, 1]
# [0, 0, 1, 0, 1, 0]	=>	[0, 0, 0, 0, 1, 0]
# [1, 1, 0, 0, 1, 0]		[1, 1, 0, 0, 1, 0]
# [1, 0, 1, 1, 0, 0]		[1, 0, 0, 0, 0, 0]
# [1, 0, 0, 0, 0, 1]		[1, 0, 0, 0, 0, 1]


def isValid(row, col, matrix):
    return row >= 0 and row < len(matrix) and col >= 0 and col < len(matrix[0])


def scan(matrix, row, col, res):

    if not isValid(row, col, matrix):
        return

    if matrix[row][col] == 0:
        return

    if res[row][col] == 1:
        return

    res[row][col] = 1

    scan(matrix, row, col + 1, res)
    scan(matrix, row + 1, col, res)
    scan(matrix, row, col - 1, res)
    scan(matrix, row - 1, col, res)


def removeIslands(matrix):

    m = len(matrix)
    n = len(matrix[0])

    res = []
    for i in range(m):
        res.append([0] * n)

    for i in range(n):
        scan(matrix, 0, i, res)
        scan(matrix, m - 1, i, res)

    for i in range(m):
        scan(matrix, i, 0, res)
        scan(matrix, i, m - 1, res)

    return res


matrix = [
    [1, 0, 0, 0, 0, 0],
    [0, 1, 0, 1, 1, 1],
    [0, 0, 1, 0, 1, 0],
    [1, 1, 0, 0, 1, 0],
    [1, 0, 1, 1, 0, 0],
    [1, 0, 0, 0, 0, 1],
]

result = removeIslands(matrix)
for r in result:
    print(r)
