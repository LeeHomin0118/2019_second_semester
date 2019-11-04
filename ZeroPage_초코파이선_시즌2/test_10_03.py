write_object=open('test.txt', 'w')
write_object.write('Hello World\n'*10)
write_object.close()
with open('test.txt', 'r') as read_object:
    print(read_object.read())
with open('test.txt', 'r') as read_object:
    while True:
        line=read_object.readline()
        if line=='':
            break
        print(line)
with open('test.txt', 'r') as read_object:
    print(read_object.readlines())