class Person:
    def hello(self):
        print('Person __init__')

class Homin(Person):
    def hello(self):
        super().hello()
        print('Homin __init__')

homin=Homin()
homin.hello()