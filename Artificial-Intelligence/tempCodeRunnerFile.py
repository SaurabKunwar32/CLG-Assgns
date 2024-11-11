import numpy as np 

# Define matrices X and Y
X = np.matrix([[1, 2],
               [1, 4]])
Y = np.matrix([[6],
               [5]])

# Compute the transpose of matrix X
transpose = np.transpose(X)
print("Transpose of X:\n", transpose)

# Calculate transpose(X) * X
transpose_and_X = transpose * X
print("Transpose of X multiplied by X:\n", transpose_and_X)

# Calculate the determinant of the resulting matrix
determinant = np.linalg.det(transpose_and_X)
print("Determinant of the resulting matrix:", determinant)

# Check if the matrix is invertible
if determinant != 0:
    # Calculate the inverse of the matrix using numpy's linalg.inv method
    inverse_of_A = np.linalg.inv(transpose_and_X)
    
    print("Inverse of (Transpose(X) * X):\n", inverse_of_A)
    
    # Compute the product of the inverse matrix and the transpose of X
    final = inverse_of_A * transpose
    print("Product of Inverse and Transpose:\n", final)
    
    # Compute the final result by multiplying with matrix Y
    result = final * Y
    print(f'Final result:\n{result}')
    
else:
    print("Determinant is zero or negative (non-invertible matrix).")