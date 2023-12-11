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
    - '\usepackage{url}'
    - '\newcommand{\hwname}{Kushagra lakhwani}'
    - '\newcommand{\hwemail}{\textit{2021UCI8036}}'
    - '\newcommand{\hwtype}{}'
    - '\newcommand{\hwnum}{}'
    - '\newcommand{\hwclass}{Artificial Intellignece \& Machine Learning}'
    - '\newcommand{\hwlecture}{}'
    - '\newcommand{\hwsection}{}'
nocite: |
  @*
bibliography: refs.bib
---

\maketitle

# Assignment {-}

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
single feature dominates the learning process.

I will explore the intricacies of normalization, emphasizing the distinctions
among conventional _**normalization**_, _**0-1 normalization**_ _(Min-Max
scaling)_, and _**standardization**_.

## The need for Normalization

There are a number of reasons that we use normalization techniques and _Gaussian
Distributinos_ in our data preprocessing.

1. **Common Occurrence in Nature:** Many natural phenomena follow a normal
   distribution. Examples include the distribution of heights, weights, IQ
   scores, and errors in measurements. Therefore, is a good approximation of the
   true distribution.

2. **Central Limit Theorem (CLT):** At its core, the Central Limit Theorem
   posits that the cumulative (or mean) of numerous independent and identically
   distributed random variables, irrespective of their initial distribution,
   will tend toward an approximate normal distribution. This theorem holds
   paramount significance in statistics as it enables the derivation of
   population inferences from sample data.

3. **Statistical Inference:** Normal distributions are mathematically
   well-behaved, making statistical inference more straightforward. For example,
   when dealing with confidence intervals and hypothesis testing, assuming
   normality simplifies calculations and allows for the use of common
   statistical tests such as z-tests and t-tests.

4. **Parameter Estimation:** In many statistical models, parameters are
   estimated using maximum likelihood estimation (MLE) or other techniques. When
   the underlying distribution is normal, the MLE estimates have desirable
   properties, making them easy to interpret and work with.

5. **Data Transformation:** Normalizing data (making it follow a normal
   distribution) is a common preprocessing step in data analysis. Some
   statistical methods, such as linear regression, assume that the residuals are
   normally distributed. Therefore, normalizing data helps meet these
   assumptions.

6. **Quality Control:** In quality control and manufacturing processes, normal
   distributions are often used to model variations in product characteristics.
   This helps in setting tolerance limits and making decisions about the quality
   of products.

7. **Machine Learning Algorithms:** Some machine learning algorithms, like those
   based on Gaussian processes or certain clustering techniques, assume
   normality in the underlying data. Understanding the normal distribution is
   crucial for these algorithms.

8. **Risk Assessment and Finance:** In finance, the normal distribution is often
   used to model the distribution of returns on investments. This is a
   simplification, but it provides a useful framework for risk assessment and
   portfolio management.

They simplify statistical analysis, facilitate hypothesis testing, and are basis
for statistical and machine learning techniques. However, it's crucial to note
that not all datasets follow a normal distribution, and it's essential to assess
the appropriateness of assuming normality in a given context.

## Normalization: Feature Scaling

Feature scaling is a crucial preprocessing technique aimed at standardizing the
scale of different features without altering the inherent intervals between
their values. The primary objective is to render the data comparable, mitigating
biases that may emerge due to varying magnitudes across features. The
normalization formula, a key tool in this process, is expressed as:

\[ X_{\text{normalized}} = \frac{X - \text{min}(X)}{\text{max}(X) -
\text{min}(X)} \]

In this equation, \(X_{\text{normalized}}\) signifies the normalized value,
\(X\) represents the original value, \(X_{\text{min}}\) denotes the minimum
value within the feature, and \(X_{\text{max}}\) signifies the maximum value
within the feature.

To illustrate, consider a dataset featuring a 'Salary' attribute ranging from
20,000 to 100,000. Applying the normalization formula to 'Salary' involves the
following computation:

```python
salary_normalized = (salary - 20000) / (100000 - 20000)
```

This transforms the 'Salary' feature into a standardized range between 0 and 1,
facilitating a more meaningful comparison across diverse features.##
Standardization

## Standardization

Standardization, also known as _**Z-score**_ normalization, centers the data
into a distribution with a standard deviation (\(\sigma\)) of 1 and a mean
(\(\mu\)) equal to 0. This is done by subtracting the mean from each data point
and then dividing by the standard deviation. The standardization formula is
given by:

$$ X_{\text{standardized}} = \frac{X - \mu}{\sigma} $$

This technique is particularly effective when dealing with data that assumes a
Gaussian distribution in the input data.

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
data = np.array([
    [5.1, 6.0, 6.0], 
    [7.3, 3.1, 6.5], 
    [2.0, 8.6, 8.5]
])

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
[[5.1 6.  6. ]
 [7.3 3.1 6.5]
 [2.  8.6 8.5]]

Normalized Data:
[[0.58490566 0.52727273 0.        ]
 [1.         0.         0.2       ]
 [0.         1.         1.        ]]

0-1 Normalized Data:
[[0.58490566 0.52727273 0.        ]
 [1.         0.         0.2       ]
 [0.         1.         1.        ]]

Standardized Data:
[[ 0.13798878  0.04451411 -0.9258201 ]
 [ 1.14990648 -1.24639507 -0.46291005]
 [-1.28789526  1.20188096  1.38873015]]
```

\pagebreak

## Comparative Evaluation: Selecting the Appropriate Scaling Method

The choice between standardization and normalization hinges on the inherent
characteristics of the data and the specific requirements of the machine
learning algorithm in use. The decision is nuanced and depends on various
factors that influence the scaling approach.

**Normalization**, specifically Min-Max Scaling, proves effective in scenarios
where the data adheres to a uniform distribution, and the machine learning
algorithm's performance is notably impacted by the scale of input features.
Utilizing the formula:

\[ x_{\text{normalized}} = \frac{x - \text{min}(X)}{\text{max}(X) -
\text{min}(X)} \]

this method transforms the data to a specified range, typically between 0 and 1.
It is particularly suitable for situations where the algorithm is not sensitive
to the absolute values of the features.

**Standardization**, or Z-Score Scaling, is the preferred choice when dealing
with data that follows a Gaussian distribution. This method ensures that the
data is centered around a mean of 0 and scaled to a standard deviation of 1,
offering advantages to algorithms sensitive to the relative values of features.
The standardization formula:

\[ x_{\text{standardized}} = \frac{x - \mu}{\sigma} \]

provides a means to center the data and standardize it effectively. This
approach is beneficial for algorithms that rely on the assumption of a Gaussian
distribution and prioritize sensitivity to relative feature values.

\pagebreak

### Comparison Summary:

| **Normalization (Min-Max Scaling)**                                                   | **Standardization (Z-Score Scaling)**                                        |
| ------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------- |
| Transforms data to a specified range (usually 0 to 1).                                | Centers data around a mean of 0 and scales it to a standard deviation of 1.  |
| \( x_{\text{normalized}} = \frac{x - \text{min}(X)}{\text{max}(X) - \text{min}(X)} \) | \( x_{\text{standardized}} = \frac{x - \mu}{\sigma} \)                       |
| Not sensitive to the absolute values of features.                                     | Sensitive to the relative values of features.                                |
| Appropriate for uniform distribution; algorithms sensitive to absolute values.        | Suitable for Gaussian distribution; algorithms sensitive to relative values. |
| e.g., Salary is normalized to the range 0 to 1.                                       | e.g., Salary is centered around a mean of 0 and a standard deviation of 1.   |
| Preserves the original range of the data.                                             | Easy to interpret, facilitates feature comparability.                        |
| May be sensitive to outliers.                                                         | Assumes Gaussian distribution.                                               |

## Conclusion

In summary, **Normalization** is favored when assuming a uniform distribution or
dealing with algorithms sensitive to absolute values, while **Standardization**
is the go-to choice for Gaussian distribution assumptions and algorithms
sensitive to relative values. These methods are complementary, making the
selection dependent on the specific characteristics of the data and the nuances
of the machine learning task at hand.## Conclusion

Normalization and standardization are essential data preprocessing techniques
which improve the performance of machine learning models. The choice between the
two methods depends on the specific algorithm and the characteristics of the
data. Understanding the strengths and weaknesses of each method is crucial for
selecting the most appropriate approach for a given task.

Whether opting for the simplicity of normalization, the bounded scale of 0-1
normalization, or the standardized distribution, the choice is made according to
the features of the dataset and the specific requirements of the algorithm at
hand.

In conclusion, scaling techniques offers a palette of choices, each with its
unique strengths and applications. As tech enthusiasts, embracing and mastering
these techniques is not merely a choice but a key to unlocking the true
potential of data-driven technologies.

## \LARGE Bibliography {-}
