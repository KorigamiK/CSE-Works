x = []
n = int(input("Enter no. of Elements: "))
for i in range(0, n, 1):
    a = int(input("Enter any No. "))
    x.append(a)

for i in range(0, n - 1, 1):
    pos = i
    em = x[i]
    for j in range(i + 1, n, 1):
        if x[j] < em:
            em = x[j]
            pos = j
        t = x[i]
        x[i] = x[pos]
        x[pos] = t

print(*x, sep=' ')
