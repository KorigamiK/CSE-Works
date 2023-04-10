% Define parameters
fs = 100; % Sampling frequency
f = 10; % Signal frequency
A = 1; % Signal amplitude
bits = 8; % Number of bits per sample

% Generate sinusoidal signal
t = 0:1 / fs:1 - 1 / fs; % Time vector
x = A * sin(2 * pi * f * t); % Original signal

% Sample the signal
Ts = 1 / fs; % Sampling interval
n = 0:Ts:1 - Ts; % Sample times
xs = A * sin(2 * pi * f * n); % Sampled signal

% Encode signal
L = 2 ^ bits; % Number of quantization levels
partition = linspace(-A, A, L + 1); % Quantization levels
codebook = linspace(-A + A / L, A - A / L, L); % Codebook
index = zeros(1, length(xs)); % Preallocate index vector

for i = 1:length(xs)
    [~, ind] = min(abs(xs(i) - partition)); % Find closest quantization level
    index(i) = ind - 1; % Subtract 1 to get 0-based index
end

code = dec2bin(index, bits); % Convert to binary

% Decode signal
index_hat = bin2dec(code); % Convert binary to decimal
xq_hat = codebook(index_hat + 1); % Reconstructed quantized signal
t_hat = 0:1 / fs:1 - 1 / fs; % Time vector for reconstructed signal
x_hat = interp1(n, xq_hat, t_hat, 'linear'); % Reconstructed signal

% Demodulate signal
demod = zeros(1, length(code) * bits); % Preallocate demodulated signal

for i = 1:length(code)
    demod((i - 1) * bits + 1:i * bits) = str2double(code(i, :)); % Convert to serial binary stream
end

demod = reshape(demod, bits, length(demod) / bits)'; % Reshape into matrix
demod = bin2dec(num2str(demod)); % Convert binary to decimal
demod = demod - A; % Convert to original range

% Plot signals
subplot(5, 1, 1)
plot(t, x)
title('Original Signal')
xlabel('Time (s)')
ylabel('Amplitude')

subplot(5, 1, 2)
stem(n, xs)
title('Sampled Signal')
xlabel('Time (s)')
ylabel('Amplitude')

subplot(5, 1, 3)
stairs(1:length(code), index)
title('Encoded Signal')
xlabel('Sample')
ylabel('Quantization Index')

subplot(5, 1, 4)
plot(t_hat, x_hat)
title('Demodulated Signal')
xlabel('Time (s)')
ylabel('Amplitude')

subplot(5, 1, 5)
plot(n, xs, 'b-', n, xq_hat, 'r--')
title('Encoded and Reconstructed Signal')
xlabel('Time (s)')
ylabel('Amplitude')
legend('Original Signal', 'Reconstructed Signal', 'Location', 'south')

% Adjust spacing between subplots
set(gcf, 'Units', 'normalized', 'Position', [0.2 0.2 0.5 0.6])
set(gcf, 'DefaultAxesLooseInset', [0.1, 0.1, 0.1, 0.1])

% Save figure
saveas(gcf, 'pcm_no_quantization.pdf')
