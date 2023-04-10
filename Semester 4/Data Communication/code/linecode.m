function [x, T] = linecode(type, inbits, Tb, A)
    % This function is used to generate line coding for the input bits
    % RZ, Unipolar NRZ, Polar RZ, Ppolar NRZ, Manchester, and
    % Bipolar NRZ.
    % INPUT:
    % type = string accepting the type of coding as
    % 'uninrz'
    % 'unirz'
    % 'polnrz'
    % 'plorz'
    % 'manchester'
    % 'ami'
    % inbits = input bits row vector
    % Tb = Bit time period
    % A = Amplitude of the coding
    % Ts = Sampling time
    % OUTPUT:
    % x = Output line coding row vector
    % T = time vector
    %---Checking input arguments
    if nargin < 4, A = 1; end
    if nargin < 3, Tb = 1e-9; end
    if nargin < 2, inbits = [1 0 1 0]; end
    if nargin < 1, type = 'uninrz'; end
    %---Implementation starts here
    Rb = 1 / Tb; %---Bit rate
    Fs = 4 * Rb;
    N = length(inbits); %---Bit Length of input bits
    tTb = linspace(0, Tb); %---interval of bit time period
    x = [];

    switch lower(type)
        case 'uninrz'

            for k = 1:N
                x = [x A * inbits(k) * ones(1, length(tTb))];
            end

        case 'unirz'

            for k = 1:N
                x = [x A * inbits(k) * ones(1, length(tTb) / 2)
                     0 * inbits(k) * ones(1, length(tTb) / 2)];
            end

        case 'polrz'

            for k = 1:N
                c = ones(1, length(tTb) / 2);
                b = zeros(1, length(tTb) / 2);
                p = [c b];
                x = [x ((-1) ^ (inbits(k) + 1)) * (A / 2) * p];
            end

        case 'polnrz'

            for k = 1:N
                x = [x ((-1) ^ (inbits(k) +1)) * A / 2 * ones(1, length(tTb))];
            end

        case 'manchester'

            for k = 1:N
                c = ones(1, length(tTb) / 2);
                b = -1 * ones(1, length(tTb) / 2);
                p = [c b];
                x = [x ((-1) ^ (inbits(k) + 1)) * A / 2 * p];
            end

        case 'ami'
    end

    T = linspace(0, N * Tb, length(x)); %---Time vector for n bits

    %Main File:
    clc;
    close all;
    a = input('Bit stream [1 0 1 0]:', 's');
    A = 1; %---Amplitude
    Tb = 10e-6; %---Bit time period
    %---Get Unipolar NRZ
    [x, t] = linecode('uninrz', a, Tb, A);
    figure(1);
    subplot(5, 1, 1);
    plot(t, x, 'LineWidth', 2);
    grid on;
    title(['Unipolar NRZ line coding for ', num2str(a)]);
    xlabel('Time in sec');
    ylabel('Amplitude');
    axis([0, max(t), min(x) - A, max(x) + A]);
    %---Get Unipolar RZ
    [x, t] = linecode('unirz', a, Tb, A);
    subplot(5, 1, 2);
    plot(t, x, 'LineWidth', 2);
    grid on;
    title(['Unipolar RZ line coding for ', num2str(a)]);
    xlabel('Time in sec');
    ylabel('Amplitude');
    axis([0, max(t), min(x) - A, max(x) + A]);
    %---Get Polar RZ
    [x t] = linecode('polrz', a, Tb, A);
    subplot(5, 1, 3);
    plot(t, x, 'LineWidth', 2);
    grid on;
    title(['Polar RZ line coding for ', num2str(a)]);
    xlabel('Time in sec');
    ylabel('Amplitude');
    axis([0, max(t), min(x) - A, max(x) + A]);
    %---Get Polar NRZ
    [x, t] = linecode('polnrz', a, Tb, A);
    subplot(5, 1, 4);
    plot(t, x, 'LineWidth', 2);
    grid on;
    title(['Polar NRZ line coding for ', num2str(a)]);
    xlabel('Time in sec');
    ylabel('Amplitude');
    axis([0, max(t), min(x) - A, max(x) + A]);
    %---Get Manchester
    [x, t] = linecode('manchester', a, Tb, A);
    subplot(5, 1, 5);
    plot(t, x, 'LineWidth', 2);
    grid on;
    title(['Manchester line coding for ', num2str(a)]);
    xlabel('Time in sec');
    ylabel('Amplitude');
    axis([0, max(t), min(x) - A, max(x) + A]);
