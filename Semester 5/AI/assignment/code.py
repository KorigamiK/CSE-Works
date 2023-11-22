# Importing necessary libraries
import numpy as np
from sklearn.preprocessing import MinMaxScaler, StandardScaler

# Creating a sample dataset
data = np.array([[1.0, 2.0, 3.0], [4.0, 5.0, 6.0], [7.0, 8.0, 9.0]])

# Print the original dataset
print("Original Dataset:")
print(data)

# 1. Normalization
normalized_data = (data - np.min(data, axis=0)) / (
    np.max(data, axis=0) - np.min(data, axis=0)
)
print("\nNormalized Data:")
print(normalized_data)

# 2. 0-1 Normalization (Min-Max Scaling)
scaler = MinMaxScaler()
min_max_scaled_data = scaler.fit_transform(data)
print("\n0-1 Normalized Data:")
print(min_max_scaled_data)

# 3. Standardization
scaler = StandardScaler()
standardized_data = scaler.fit_transform(data)
print("\nStandardized Data:")
print(standardized_data)
