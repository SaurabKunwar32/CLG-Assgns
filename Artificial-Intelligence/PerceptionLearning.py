import numpy as np
from sklearn.linear_model import Perceptron

# Training data for AND gate
# Inputs: [x1, x2]
X = np.array([[1, 0],
              [1, 1],
              [1, 0],
              [1, 0]])

# Outputs: AND gate truth table (0 or 1)
y = np.array([0, 1, 0, 1])

# Create the Perceptron model
model = Perceptron(max_iter=1000, eta0=0.1, random_state=42)

# Train the model on the AND gate data
model.fit(X, y)

# Display the learned weights and bias (intercept)
print("Learned weights:", model.coef_)
print("Learned bias (intercept):", model.intercept_)

# Test the model by predicting the outputs for the same input data
predictions = model.predict(X)

# Display the predictions for the AND gate inputs
for i, input_data in enumerate(X):
    print(f"Input: {input_data}, Predicted Output: {predictions[i]}, Actual Output: {y[i]}")