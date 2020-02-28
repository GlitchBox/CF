size = 0

def decrypt(s: str):
    divList = []

    div = 2
    while div*div <= size:
        if size%div == 0:
            div1 = int(size/div)
            divList.append(div)
            if div!=div1:
                divList.append(div1)
        div += 1

    divList.append(size)
    divList.sort()
    #print(divList)

    sList = list(s)

    for d in divList:
        b = 0
        e = d-1

        while b<e:
            tmp = sList[b]
            sList[b] = sList[e]
            sList[e] = tmp

            b+=1
            e-=1

    s = "".join(sList)

    return s

if __name__ == "__main__":
    #print("Hello")
    size = input()
    size = int(size)

    s = input()

    res = decrypt(s)
    print(res)
