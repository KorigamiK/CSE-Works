% BPSK Bit Error Rate Calculation
clc;

% Define the parameters
N = 10 ^ 6; % number of bits to transmit
Eb_N0_dB = 0:2:10; % Eb/N0 values in dB
ip = rand(1, N) > 0.5; % generating 0,1 with equal probability
s = 2 * ip - 1; % BPSK modulation
n = 1 / sqrt(2) * (randn(1, N) + 1i * randn(1, N)); % white gaussian noise, 0dB variance

for ii = 1:length(Eb_N0_dB)
    % Channel model - AWGN
    y = sqrt(10 ^ (Eb_N0_dB(ii) / 10)) * s + n;
    % Demodulation
    y_cap = real(y) > 0;
    % Counting the errors
    error(ii) = size(find(ip - y_cap), 2);
end

simulatedBER = error / N; % simulated BER
theoryBER = 0.5 * erfc(sqrt(10 .^ (Eb_N0_dB / 10))); % theoretical BER

% plot
close all
figure
semilogy(Eb_N0_dB, theoryBER, 'bs-', 'LineWidth', 2);
hold on
semilogy(Eb_N0_dB, simulatedBER, 'mx-', 'LineWidth', 2);
axis([0 10 10 ^ -5 0.5])
grid on
legend('theory', 'simulation');
xlabel('Eb/N0, dB')
ylabel('Bit Error Rate')
title('Bit error probability curve for BPSK modulation')
