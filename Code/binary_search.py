l = []
n = int(input("Enter no. of Elements: "))
for i in range(0, n, 1):
    a = int(input("Enter any no. "))
    l.append(a)
l.sort()
print(*l, sep=' ')

x = int(input("Enter the Value to be Searched: "))
flag = 0
beg = 0
back = n - 1
while beg <= back:
    mid = (beg + back) // 2
    if l[mid] == x:
        flag = 1
        break
    elif x > l[mid]:
        beg = mid + 1
    else:
        back = mid - 1
if flag == 1:
    print("Found at", mid, "index")
else:
    print("Not Found")
