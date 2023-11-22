---
documentclass: homework
# For option documentation, see https://github.com/jez/latex-homework-class
classoption:
    - 11pt
    - largemargins
# Remove or change this line if you don't have the Menlo font installed
monofont: Iosevka Term
newtxmathoptions:
    - cmintegrals
    - cmbraces
colorlinks: true
linkcolor: RoyalBlue
urlcolor: RoyalBlue
header-includes:
    - '\newcommand{\hwname}{Kushagra lakhwani}'
    - '\newcommand{\hwemail}{\textit{2021UCI8036}}'
    - '\newcommand{\hwtype}{}'
    - '\newcommand{\hwnum}{}'
    - '\newcommand{\hwclass}{Artificial Intellignece \& Machine Learning}'
    - '\newcommand{\hwlecture}{}'
    - '\newcommand{\hwsection}{}'
---

\maketitle

# Assignment 2 {-}

\begin{centering}

    \Large
    A Comparative Analysis of Normalization Techniques: Scaling Insights

    % Normalization \textbf{vs} 0-1 Normalization (Min-Max Scaling) % \\ \textbf{vs}
    % Standardization 

    \vspace{0.5cm}

\end{centering}

In the realm of _**data preprocessing**_, normalization plays a crucial role in
enhancing the performance of machine learning algorithms. It is a technique
employed to bring disparate features onto a common scale, ensuring that no
single feature dominates the learning process. I will delve into the nuances of
normalization, focusing on the comparison between traditional
_**normalization**_, _**0-1 normalization**_ _(Min-Max scaling)_, and
_**standardization**_. As the head of the college magazine's tech section,
understanding these techniques is paramount for any tech enthusiast venturing
into the exciting world of data science and machine learning.

## Normalization

Normalization is a preprocessing technique that transforms features to a common
scale without distorting the differences in the ranges of values. The primary
goal is to make the data comparable and eliminate biases that may arise due to
the differing magnitudes of features. The formula for normalization is given by:

$$ X_{\text{normalized}} = \frac{X - \text{min}(X)} {\text{max}(X) -
\text{min}(X)} $$

Here, \(X_{\text{normalized}}\) represents the normalized value, \(X\) is the
original value, \(X_{\text{min}}\) is the minimum value in the feature, and
\(X_{\text{max}}\) is the maximum value in the feature.

\pagebreak

Consider a dataset with a 'Salary' feature ranging from 20,000 to 100,000. To
normalize the 'Salary' feature, we would apply the following formula:

```python
salary_normalized = (salary - 20000) / (100000 - 20000)
```

This would transform the 'Salary' feature to a range between 0 and 1.

## Standardization

Standardization, also known as _**Z-score**_ normalization, centers the data
into a distribution with a mean (\(\mu\)) of 0 and a standard deviation
(\(\sigma\)) of 1. The standardization formula is given by: . This is done by
subtracting the mean from each data point and then dividing by the standard
deviation.

$$ X_{\text{standardized}} = \frac{X - \mu}{\sigma} $$

This technique is particularly effective when dealing with algorithms that
assume a Gaussian distribution in the input data.

Consider the same dataset with a 'Salary' feature ranging from 20,000 to
100,000. To standardize the 'Salary' feature, we would apply the following
formula:

```python
salary_standardized = (salary - mean) / standard_deviation
```

This would transform the 'Salary' feature to a mean of 0 and a standard
deviation of 1.

\pagebreak

## Code

We can perform normalization and standardization using the scikit-learn library
in Python:

```python
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
```

\pagebreak

## Output

```py
Original Dataset:
[[1. 2. 3.]
 [4. 5. 6.]
 [7. 8. 9.]]

Normalized Data:
[[0.  0.  0. ]
 [0.5 0.5 0.5]
 [1.  1.  1. ]]

0-1 Normalized Data:
[[0.  0.  0. ]
 [0.5 0.5 0.5]
 [1.  1.  1. ]]

Standardized Data:
[[-1.22474487 -1.22474487 -1.22474487]
 [ 0.          0.          0.        ]
 [ 1.22474487  1.22474487  1.22474487]]
```

\pagebreak

## Comparative Analysis: When to Choose What

The choice between normalization and standardization depends on the nature of
the data and the requirements of the machine learning algorithm. Normalization
is suitable when the data follows a uniform distribution and the algorithm used
is sensitive to the scale of input features. On the other hand, standardization
is preferred when the data has a Gaussian distribution and the algorithm
benefits from a mean of 0 and a standard deviation of 1.

| Normalization (Min-Max Scaling)                                      | Standardization (Z-Score Scaling)                                               |
| -------------------------------------------------------------------- | ------------------------------------------------------------------------------- |
| Transforms the data to a specified range, typically between 0 and 1. | Centers the data around a mean of 0 and scales it to a standard deviation of 1. |
| `x_normalized = (x - min(X)) / (max(X) - min(X))`                    | `x_standardized = (x - μ) / σ`                                                  |
| Not sensitive to the absolute values of the features.                | Sensitive to the relative values of the features.                               |
| Uniform distribution, algorithms sensitive to absolute values.       | Gaussian distribution, algorithms sensitive to relative values.                 |
| Salary is normalized to the range 0 to 1.                            | Salary is centered around a mean of 0 and a standard deviation of 1.            |
| Preserves the original range of the data.                            | Easy to interpret, makes features comparable.                                   |
| Sensitive to outliers.                                               | Assumes Gaussian distribution.                                                  |

- **Normalization** is generally preferred when the data is assumed to have a
  uniform distribution or when the algorithm is sensitive to the absolute values
  of the features.

- **Standardization** is generally preferred when the data is assumed to have a
  Gaussian distribution or when the algorithm is sensitive to the relative
  values of the features.

\pagebreak

## Conclusion

Normalization and standardization are essential data preprocessing techniques
that can improve the performance of machine learning models. The choice between
the two methods depends on the specific algorithm and the characteristics of the
data. Understanding the strengths and weaknesses of each method is crucial for
selecting the most appropriate approach for a given task.

Whether opting for the simplicity of normalization, the bounded scale of 0-1
normalization, or the standardized distribution, the choice should align with
the characteristics of the dataset and the requirements of the algorithm at
hand.

In conclusion, the world of scaling techniques offers a palette of choices, each
with its unique strengths and applications. As tech enthusiasts, embracing and
mastering these techniques is not merely a choice but a key to unlocking the
true potential of data-driven technologies.
