while(1):
    try:
        tmp = eval(input())
    except:
        exit()
    res = 0
    tmp2 = tmp
    for i in range(tmp):
        if tmp > i:
            res += i*i
            tmp -= i
        else:
            res += i*tmp
            print(tmp2,res)
            break
