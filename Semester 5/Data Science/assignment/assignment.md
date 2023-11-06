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

<!-- LaTeX environment in a Markdown document! -->

# Assignment 2 {-}

_How many ways are there to rearrange the letters in the word "anagram"?_

_Solution._ We can choose an arrangement of the letters in "anagram" in two
steps. We first choose 3 of the 7 positions to be a's, then permute "ngrm" in
the remaining positions. Thus, we have \begin{align*} \binom{7}{3} 4!
\end{align*}

ways to choose an arrangement.
