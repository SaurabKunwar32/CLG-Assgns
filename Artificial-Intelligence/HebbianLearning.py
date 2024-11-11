import numpy as np
from sklearn.base import BaseEstimator, ClassifierMixin

class HebbianLearning(BaseEstimator, ClassifierMixin):
    def __init__(self, input_size, learning_rate=0.1):
        self.weights = np.random.randn(input_size)  # Random initialization of weights
        self.bias = np.random.randn()                # Random initialization of bias
        self.learning_rate = learning_rate           # Set learning rate

    def activation(self, x):
        return np.where(x >= 0, 1, 0)                # Step activation function

    def fit(self, X, y=None):
        for inputs in X:
            output = self.activation(np.dot(inputs, self.weights) + self.bias)  # Calculate output
            self.weights += self.learning_rate * inputs * output  # Update weights
            self.bias += self.learning_rate * output              # Update bias
        return self

    def predict(self, X):
        return self.activation(np.dot(X, self.weights) + self.bias)  # Predict outputs

# Example usage
if __name__ == "__main__":
    # Training data for AND gate
    X = np.array([[1, 0], [1, 1], [1, 1], [0, 1]])  # Input vectors
    y = np.array([1, 0, 1, 1])                        # Target outputs for AND gate

    model = HebbianLearning(input_size=2, learning_rate=0.1)
    model.fit(X)

    print("Weights:", np.round(model.weights, 1))    # Output learned weights
    print("Bias:", round(model.bias, 1))              # Output learned bias

    predictions = model.predict(X)                     # Predict using the model
    for input_vec, pred in zip(X, predictions):
        print(f"Input: {input_vec}, Predicted Output: {pred}")  # Display inputs and predictions