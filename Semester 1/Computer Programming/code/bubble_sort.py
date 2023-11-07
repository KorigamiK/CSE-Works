n = int(input("Enter No. of Digits: "))
x = []
for i in range(0, n, 1):
    x.append(int(input("Enter No. ")))
print(*x, sep=' ')

for i in range(0, n - 1, 1):
    for j in range(0, n - 1, 1):
        if x[j] > x[j + 1]:
            x[j], x[j + 1] = x[j + 1], x[j]
print(*x, sep=' ')  # sorted array
