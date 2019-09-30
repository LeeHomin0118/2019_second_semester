def trace(func):
    def wrapper():
        print("시작")
        func()
        print("끝")
    return wrapper

@trace
def hello():
    print("Hello World")
hello()