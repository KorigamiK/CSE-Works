% Generate random numbers
data = randn(1000, 1);

% Create histogram
histogram(data, 20, 'Normalization', 'pdf');
hold on;

% Calculate mean and standard deviation
mu = mean(data);
sigma = std(data);

% Define x values for Gaussian curve
x = linspace(min(data), max(data), 100);

% Calculate y values for Gaussian curve
y = normpdf(x, mu, sigma);

% Overlay Gaussian curve
plot(x, y, 'LineWidth', 2);

% Add title and labels
title('Histogram of Random Data with Gaussian Fit');
xlabel('Data Value');
ylabel('Probability Density');

% Turn off hold
hold off;
