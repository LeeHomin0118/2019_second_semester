import re
print(re.sub('0\d{1,2}-\d{3,4}-\d{4}', 'x', '010-9142-8488 - 10-777-8488'))
print(re.sub('ng', 'x', 'Chung_Ang Univ.', 10))
print(re.search('Hello', 'Hello World!'))