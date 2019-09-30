class Person:
    def __init__(self):
        print('Person __init__')

class Homin(Person):
    def __init__(self):
        super().__init__()
        print('Homin __init__')

homin=Homin()