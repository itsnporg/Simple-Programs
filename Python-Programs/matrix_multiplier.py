def matrix_multiplier(mat1, mat2):
    """Multiplies Two matrix of any size"""

    # empty list for storing multiplied rows
    multiplied_matrix = []
    for row1 in mat1:

        # list for adding multiplied value
        rows = []
        for col2 in zip(*mat2):
            sum1 = 0
            for (a, b) in zip(row1, col2):
                sum1 += a * b
            rows.append(sum1)
        multiplied_matrix.append(rows)
    return multiplied_matrix


mat1 = [[1, 2, 1], [5, 6, 2], [5, 6, 2]]

mat2 = [[1, 2], [9, 10], [2, 1]]
print(matrix_multiplier(mat1, mat2))
