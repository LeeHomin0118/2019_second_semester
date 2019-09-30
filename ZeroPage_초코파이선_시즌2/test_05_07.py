def count(n):
    x=[i+1 for i in range(n)]
    yield from x

for i in count(3):
    print(i)