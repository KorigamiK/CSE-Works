close all; clc;

% Define the message signal
t = linspace(0, 1, 1000);
fm = 1; % message signal frequency
Am = 1; % message signal amplitude
m = Am * sin(2 * pi * fm * t);

n_max = 4; % Define the maximum number of quantization levels

% Initialize vectors to store SQNR and number of quantization levels
sqnr = zeros(1, n_max);
levels = 1:n_max;

% Compute the SQNR for each quantization level
for i = 1:n_max
    L = 2 ^ i;
    delta = (max(m) - min(m)) / (L - 1);
    m_quantized = delta * round(m / delta);
    noise = m - m_quantized;
    power_m = sum(m .^ 2) / length(m);
    power_noise = sum(noise .^ 2) / length(noise);
    sqnr(i) = power_m / power_noise;
end

% Plot the message signal and the quantized signal for n=4
subplot(2, 1, 1);
plot(t, m, 'b', 'LineWidth', 2);
hold on;
plot(t, m_quantized, 'r', 'LineWidth', 2);
xlabel('Time (s)');
ylabel('Amplitude');
title('Message signal and Quantized signal');
legend('Message signal', 'Quantized signal');

% Plot the number of quantization levels vs. the SQNR
subplot(2, 1, 2);
plot(sqnr, levels, 'LineWidth', 2);
ylabel('Quantization levels');
xlabel('Signal to Quantisation Noise Ratio (dB)');
title('Number of quantization levels vs. SQNR');
