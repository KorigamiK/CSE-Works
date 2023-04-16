% BPSK Modulation with AWGN
clear;
clc;

b = input ('Enter the Bit stream:');
n = length(b);
t = 0:.01:n;
x = 1:1:(n + 1) * 100;

for i = 1:n

    if (b(i) == 0)
        b_p(i) = -1;
    else
        b_p(i) = 1;
    end

    for j = i:.1:i + 1
        bw(x(i * 100:(i + 1) * 100)) = b_p(i);
    end

end

bw = bw (100:end);
sint = sin(2 * pi * t);
st = bw .* sint;
subplot(3, 1, 1)
plot(t, bw)
grid on;
title('Input Binary Data');
axis([0 n -2 +2])
subplot(3, 1, 2)
plot(t, sint)
grid on;
title('Carrier Signal');
axis([0 n -2 +2])
subplot(3, 1, 3)
plot(t, st)
grid on;
title('PSK Modulated Signal');
axis([0 n -2 +2])
