flag = 0
x = []
for i in range(0, 5, 1):
    x.append(int(input("Enter No. ")))

print(*x, sep=' ')

y = int(input("Enter any No. "))

for i in range(0, 5, 1):
    if x[i] == y:
        flag = 1
        break
if flag == 1:
    print("Found")
else:
    print("Not Found")
