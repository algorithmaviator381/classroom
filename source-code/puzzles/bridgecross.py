X=[1,2,5,10]

pairs = [(x,y) for x in X for y in X if x!=y]

def pair(x,y):
    return max(x,y)

print(pairs)