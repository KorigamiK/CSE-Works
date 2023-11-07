import datetime

print('Today is:', datetime.datetime.now().strftime("%d-%m-%Y %H:%M"))


def func():
    try:
        1 / 0
    except ZeroDivisionError:
        print('Infinity expected')

    dict = {1: 123, 2: 12312}

    try:
        dict[3]
    except KeyError:
        print('Key is not present')

    try:
        print(x)
    except NameError:
        print('Name not found')

    L1 = L2 = [1, 2, 3]
    L1.append(L2)
    L2[1] = 90
    print(L1)


func()
