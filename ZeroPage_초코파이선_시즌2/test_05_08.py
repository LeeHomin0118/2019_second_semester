def cosum():
    try:
        total=0
        while True:
            x=(yield total)
            total+=x
    except:
        print("코루틴 종료")

co=cosum()
print(next(co))
print(co.send(3))
print(co.send(5))
co.close()