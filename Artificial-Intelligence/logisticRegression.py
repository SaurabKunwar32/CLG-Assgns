from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
import numpy as np

# Input features: age and salary
x = np.array([
    [30, 150000],
    [45, 130000],
    [89, 120000],
    [5, 50000],
    [30, 110000],
    [45, 90000],
    [89, 80000],
    [5, 35000],
    [30, 70000],
    [45, 45000]
])

# Target labels (0 or 1)
y = np.array([1, 1, 0, 1, 1, 1, 0, 1, 0, 1])

# Split the dataset into training (80%) and testing (20%) sets
xtrain, xtest, ytrain, ytest = train_test_split(x, y, test_size=0.2, random_state=42)

# Create and train the logistic regression model
model = LogisticRegression()
model.fit(xtrain, ytrain)

# Predict on the test set
y_pred = model.predict(xtest)

# Calculate the accuracy of the model
accuracy = accuracy_score(ytest, y_pred)
print(f"Accuracy of the model: {accuracy:.2f}")

# New data point for prediction
xnew = np.array([[33, 95000]])
new_prediction = model.predict(xnew)

# Print the prediction for the new data point
print(f"Prediction for input {xnew[0]}: {new_prediction[0]}")
