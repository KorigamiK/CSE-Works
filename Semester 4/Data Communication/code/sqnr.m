% Program to Compute SQNR of Uniform Quantization and Plot the SQNR vs. Quantization Levels
close all; clc;

% Signal Parameters
N = 10000;                  % Number of samples in the signal
f = 1;                      % Signal frequency
Fs = 1000;                  % Sampling frequency
t = (0:N - 1) / Fs;         % Time vector
x = sin(2 * pi * f * t);    % Signal

% Quantization Parameters
L = 2:20;                   % Number of quantization levels to try
b = log2(L);                % Number of bits to represent each level
Delta = 2 ./ (L - 1);       % Step size of the quantization levels
SQNR = zeros(length(L), 1); % To store the Signal to Quantization Noise Ratio (SQNR) for each quantization level

% Uniform Quantization
for i = 1:length(L)
    q = round(x / Delta(i)) * Delta(i); % Quantize the signal
    % Compute the SQNR
    noise = x - q;
    signal_power = sum(x .^ 2) / N;
    noise_power = sum(noise .^ 2) / N;
    SQNR(i) = 10 * log10(signal_power / noise_power);
end

% Plot the SQNR vs. Quantization Levels
figure;
plot(b, SQNR, 'b-o', 'LineWidth', 2);
xlabel('Number of Bits');
ylabel('Signal to Quantization Noise Ratio (dB)');
grid on;
