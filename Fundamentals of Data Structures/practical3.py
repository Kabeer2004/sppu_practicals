def input_matrix():
    rows = int(input("Enter the number of rows: "))
    cols = int(input("Enter the number of columns: "))
    
    matrix = [[int(input(f"Enter element at position ({i + 1}, {j + 1}): ")) for j in range(cols)] for i in range(rows)]
    
    return matrix

def add_matrices(matrix1, matrix2):
    result = []
    for i in range(len(matrix1)):
        row = []
        for j in range(len(matrix1[0])):
            row.append(matrix1[i][j] + matrix2[i][j])
        result.append(row)
    return result

def subtract_matrices(matrix1, matrix2):
    result = []
    for i in range(len(matrix1)):
        row = []
        for j in range(len(matrix1[0])):
            row.append(matrix1[i][j] - matrix2[i][j])
        result.append(row)
    return result

def multiply_matrices(matrix1, matrix2):
    result = []
    for i in range(len(matrix1)):
        row = []
        for j in range(len(matrix2[0])):
            element = 0
            for k in range(len(matrix2)):
                element += matrix1[i][k] * matrix2[k][j]
            row.append(element)
        result.append(row)
    return result

def transpose_matrix(matrix):
    result = []
    for j in range(len(matrix[0])):
        row = []
        for i in range(len(matrix)):
            row.append(matrix[i][j])
        result.append(row)
    return result

def display_matrix(matrix, label):
    print(f"\n{label}:")
    for row in matrix:
        print(row)

# Input matrices
print("Enter Matrix A:")
A = input_matrix()

print("\nEnter Matrix B:")
B = input_matrix()

# Display original matrices
display_matrix(A, "Matrix A")
display_matrix(B, "Matrix B")

# Display addition, subtraction, multiplication, and transpose
display_matrix(add_matrices(A, B), "Addition of A and B")
display_matrix(subtract_matrices(A, B), "Subtraction of A and B")
display_matrix(multiply_matrices(A, B), "Multiplication of A and B")
display_matrix(transpose_matrix(A), "Transpose of A")
display_matrix(transpose_matrix(B), "Transpose of B")
