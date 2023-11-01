height = 30
symbol = '*'

for i in range(height):
    for j in range(height-i):
        print(str(' '), end=' ')
    for j in range(i):
        print(symbol, end=' ')
    for j in range(i):
        print(symbol, end=' ')
    print()

for i in range(height):
    for j in range(i):
        print(str(' '), end=' ')
    for j in range(height-i):
        print(symbol, end=' ')
    for j in range(height-i):
        print(symbol, end=' ')
    print()