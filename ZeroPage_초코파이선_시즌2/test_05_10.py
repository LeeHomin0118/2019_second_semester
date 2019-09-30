def trace(func):
    def wrapper(a, b):
        r=func(a, b)
        print("%d+%d=%d" %(a, b, r))
        return r
    return wrapper

@trace
def add(a, b):
    return a+b
add(10, 5)