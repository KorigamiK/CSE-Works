clc; close all;

F1 = 25;
F2 = 5;
A = 3;
t = 0:0.001:1;
x = A * sin(2 * pi * F1 * t) + A / 2;
u = (A / 2) * square(2 * pi * F2 * t, 50) + A / 2;
v = x .* u;
subplot(3, 1, 1);
plot(t, x);
title('carrier signal');
grid on;

subplot(3, 1, 2);
plot(t, u);
title('square signal');
grid on;

subplot(3, 1, 3);
plot(t, v);
title('ASK signal');
grid on;
