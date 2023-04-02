% Define the parameters of the uniform distribution
a = 1; % Lower bound
b = 6; % Upper bound

% Generate 1000 random numbers from the uniform distribution
rng(1); % Set the random seed for reproducibility
X = a + (b - a) * rand([1, 1000]);

% Compute the mean and variance of the generated numbers
mu = mean(X);
sigma2 = var(X);

% Define the range of x values to plot
x = linspace(a - 1, b + 1, 1000);

% Compute the uniform distribution density function
f = ones(size(x)) ./ (b - a);

% Plot the uniform distribution density function
plot(x, f, 'LineWidth', 2);
hold on;

% Plot a vertical line at the mean value
ymin = 0;
ymax = max(f) * 1.5;
line([mu mu], [ymin ymax], 'Color', 'r', 'LineStyle', '--', 'LineWidth', 2);

% Set the plot limits and labels
xlim([a - 2, b + 2]);
ylim([ymin, ymax]);
xlabel('x');
ylabel('Probability density');
title('Uniform distribution');
legend(sprintf('Mean = %.2f\nVariance = %.2f', mu, sigma2));
