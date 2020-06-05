# a = "aabsx"
# b = "aabtx"
#
# print(a>b)

if __name__=="__main__":
    t = int(input())
    #print(t)
    while t>0:
        n =int(input())
        s = input()
        #print(n," ",s)

        stringList = []
        stringList.append({'k':1, 's':s})

        i=1
        while i<n:
            decisionVal = n-i
            firstPart = s[i:]
            lastPart = s[0:i]

            if decisionVal%2==1: #if i is odd
                lastPart = lastPart[::-1]

            stringList.append({'k': i+1, 's':firstPart+lastPart})

            i+=1

        #print(stringList)
        smallest = stringList[0]
        i=1
        while i<n:
            if stringList[i]['s']<smallest['s']:
                smallest = stringList[i]
            i+=1
        print(smallest['s'])
        print(smallest['k'])
        #print(stringList)

        t-=1
