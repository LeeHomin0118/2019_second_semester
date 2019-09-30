try: 
    n=int(input())
    res=100//n
    if res==50:
        raise Exception('50이라 에러.')
except Exception as e:
    print(e)
#except ValueError:
#    print('숫자를 입력하세요.')
#except ZeroDivisionError:
#    print('0이 아닌 값을 입력하세요.')
except:
    print("뭔지는 모르겠지만 에러가 남.")
else:
    print(res)
finally:
    print('끝')