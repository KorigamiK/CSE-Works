% Program to Compute SNR of Non-Uniform Quantization and Plot the SNR vs. Quantization Levels
close all; clc;

% Signal Parameters
N = 10000;                  % Number of samples in the signal
f = 1;                      % Signal frequency
Fs = 1000;                  % Sampling frequency
t = (0:N - 1) / Fs;         % Time vector
x = sin(2 * pi * f * t);    % Signal

% Quantization Parameters
L = 2:20;                       % Number of quantization levels to try
b = log2(L);                    % Number of bits to represent each level
Delta = 2 ./ (L - 1);           % Step size of the quantization levels
SQNR = zeros(length(L), 1);     % To store the Signal to Quantization Noise Ratio (SQNR) for each quantization level

% Non-Uniform Quantization
for i = 1:length(L)
    q = zeros(size(x));
    % Compute quantization levels
    V = [- (L(i) - 1) / 2:1:(L(i) - 1) / 2] * Delta(i);
    % Quantize the signal
    for j = 1:N
        [val, index] = min(abs(x(j) - V));
        q(j) = V(index);
    end

    % Compute the SQNR
    noise = x - q;
    signal_power = sum(x .^ 2) / N;
    noise_power = sum(noise .^ 2) / N;
    SQNR(i) = 10 * log10(signal_power / noise_power);
end

% Plot the SNR vs. Quantization Levels
figure;
plot(b, SQNR, 'b-o', 'LineWidth', 2);
xlabel('Number of Bits');
ylabel('Signal to Quantization Noise Ratio (dB)');
grid on;
