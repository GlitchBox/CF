

if __name__=="__main__":
    t = int(input())

    while t>0:
        n,m = map(int, input().split())
        scoreList = [int(x) for x in input().split()]
        # print(n," ",m)
        # print(scoreList)

        target = m - scoreList[0]

        if target==0:
            print(m)
        else:
             i=1
             currentSum = 0
             while i<n and currentSum<target:
                 currentSum += scoreList[i]
                 i+=1

             if currentSum<target:
                print(currentSum+scoreList[0])
             else:
                print(m)

        t-=1
