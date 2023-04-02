data = randn(1000, 1); % Generate random numbers

histogram(data, 20, 'Normalization', 'pdf');
hold on;

mu = mean(data);
sigma = std(data);

x = linspace(min(data), max(data), 100); % Define x values for Gaussian curve
y = normpdf(x, mu, sigma); % Calculate y values for Gaussian curve

% Overlay Gaussian curve
plot(x, y, 'LineWidth', 2);

% Add title and labels
title('Histogram of Random Data with Gaussian Fit');
xlabel('Data Value');
ylabel('Probability Density');

hold off;
