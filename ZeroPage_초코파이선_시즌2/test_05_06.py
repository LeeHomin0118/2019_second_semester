class Count:
    def __init__(self, n):
        self.now=0
        self.stop=n
    
    def __iter__(self):
        return self

    def __next__(self):
        if self.now < self.stop:
            self.now+=1
            return self.now
        else:
            return StopIteration

for i in Count(3):
    print(i)