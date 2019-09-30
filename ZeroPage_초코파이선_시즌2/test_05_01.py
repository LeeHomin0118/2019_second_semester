class person:
    def hello(self):
        print('hello world')

class homin(person):
    def study(self):
        print('hominstudying')

Homin=homin()
Homin.hello()
Homin.study()
print(issubclass(homin, person))
