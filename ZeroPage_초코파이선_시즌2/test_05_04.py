from abc import *

class Person(metaclass=ABCMeta):
    @abstractmethod
    def hello(self):
        pass

class Homin(Person):
    def hello(self):
        super().hello()
        print('Homin __init__')

homin=Homin()
homin.hello()