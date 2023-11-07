---
documentclass: homework
# For option documentation, see https://github.com/jez/latex-homework-class
classoption:
    - 11pt
    - largemargins
# Remove or change this line if you don't have the Menlo font installed
monofont: Menlo
newtxmathoptions:
- cmintegrals
- cmbraces
colorlinks: true
linkcolor: RoyalBlue
urlcolor: RoyalBlue
header-includes:
    - '\newcommand{\hwname}{Kushagra lakhwani}'
    - '\newcommand{\hwemail}{2021UCI8036}'
    - '\newcommand{\hwtype}{}'
    - '\newcommand{\hwnum}{}'
    - '\newcommand{\hwclass}{Data Science}'
    - '\newcommand{\hwlecture}{}'
    - '\newcommand{\hwsection}{}'
---

\maketitle

# Assignment 1 {-}

## $Q_1$ Explain the use of decision trees in data science.

__Answer.__ Decision trees are a fundamental tool in the field of data science.
They are versatile and intuitive machine learning algorithms used for both
_classification_ and _regression_ tasks. Decision trees work by recursively
splitting the dataset into subsets based on the most significant attribute at
each node. These splits create a tree-like structure of decisions, where each
internal node represents a decision based on a specific feature, and each leaf
node represents the predicted outcome.

- **Decision Making:** Decision trees are excellent for decision-making
  processes. They allow data scientists to visualize decisions and understand
  the implications of each choice.

- **Feature Importance:** By evaluating which features are used for splitting
  nodes, data scientists can prioritize features for further analysis.

- **Non-Linear Relationships:** Decision trees can capture non-linear
  relationships between features and the target variable. Unlike linear models,
  decision trees can model complex patterns in the data.

- **Handling Missing Values:** Decision trees can handle missing values in the
  dataset. They can make decisions even if some values are missing for certain
  features.

- **Interpretability:** Decision trees are easy to interpret and explain to
  non-experts. The visual representation of a tree structure simplifies complex
  decision-making processes.

- **Ensemble Methods:** Decision trees serve as the building blocks for powerful
  ensemble methods like Random Forest and Gradient Boosting. These methods
  combine multiple decision trees to improve predictive performance.

  ![](./decisiontree.png)

  ## $Q_2$ Take any real-life problem related to data science and solve it using a decision tree to solve  in _Python_.

  __Answer__. Predicting the _ICS UCI_ Balance-Scale dataset using decision trees.


```py
# Importing the required packages
import numpy as np
import pandas as pd
from sklearn.metrics import confusion_matrix
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import accuracy_score
from sklearn.metrics import classification_report

# Function importing Dataset
def importdata():
    balance_data = pd.read_csv(
        'https://archive.ics.uci.edu/ml/machine-learning-'+
        'databases/balance-scale/balance-scale.data',
        sep= ',', header = None)
# Printing the dataswet shape
    print ("Dataset Length: ", len(balance_data))
    print ("Dataset Shape: ", balance_data.shape)
# Printing the dataset obseravtions
    print ("Dataset: ",balance_data.head())
    return balance_data

# Function to split the dataset
def splitdataset(balance_data):
# Separating the target variable
    X = balance_data.values[:, 1:5]
    Y = balance_data.values[:, 0]
# Splitting the dataset into train and test
    X_train, X_test, y_train, y_test = train_test_split(
    X, Y, test_size = 0.3, random_state = 100)
    return X, Y, X_train, X_test, y_train, y_test

# Function to perform training with giniIndex.
def train_using_gini(X_train, X_test, y_train):
    # Creating the classifier object
    clf_gini = DecisionTreeClassifier(criterion = "gini",
        random_state = 100,max_depth=3, min_samples_leaf=5)
    # Performing training
    clf_gini.fit(X_train, y_train)
    return clf_gini

# Function to perform training with entropy.
def tarin_using_entropy(X_train, X_test, y_train):
# Decision tree with entropy
    clf_entropy = DecisionTreeClassifier(
    criterion = "entropy", random_state = 100,
    max_depth = 3, min_samples_leaf = 5)
# Performing training
    clf_entropy.fit(X_train, y_train)
    return clf_entropy

# Function to make predictions
def prediction(X_test, clf_object):
# Predicton on test with giniIndex
    y_pred = clf_object.predict(X_test)
    print("Predicted values:")
    print(y_pred)
    return y_pred

# Function to calculate accuracy
def cal_accuracy(y_test, y_pred):
    print("Confusion Matrix: ", confusion_matrix(y_test, y_pred))
    print ("Accuracy : ", accuracy_score(y_test,y_pred)*100)
    print("Report : ", classification_report(y_test, y_pred))

# Driver code
def main():
# Building Phase
    data = importdata()
    X, Y, X_train, X_test, y_train, y_test = splitdataset(data)
    clf_gini = train_using_gini(X_train, X_test, y_train)
    clf_entropy = tarin_using_entropy(X_train, X_test, y_train)
# Operational Phase
    print("Results Using Gini Index:")
# Prediction using gini
    y_pred_gini = prediction(X_test, clf_gini)
    cal_accuracy(y_test, y_pred_gini)
    print("Results Using Entropy:")
# Prediction using entropy
    y_pred_entropy = prediction(X_test, clf_entropy)
    cal_accuracy(y_test, y_pred_entropy)

# Calling main function
if __name__=="__main__":
    main()
```


<!-- LaTeX environment in a Markdown document! -->

# Assignment 2 {-}

_How many ways are there to rearrange the letters in the word "anagram"?_

_Solution._ We can choose an arrangement of the letters in "anagram" in two
steps. We first choose 3 of the 7 positions to be a's, then permute "ngrm" in
the remaining positions. Thus, we have \begin{align*} \binom{7}{3} 4!
\end{align*}

ways to choose an arrangement.
