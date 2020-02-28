
problemList = []
n = 0
k = 0

def FindMax(l:int, r:int):

    ret = 0
    side = l
    twoSidesBlocked = 0

    while l<=r:
        if(side==l and problemList[l]<=k):
            ret += 1
            l += 1
            side = l
            twoSidesBlocked = 0
        elif (side==l):
            if twoSidesBlocked == 1:
                break
            side = r
            twoSidesBlocked += 1
        elif (side==r and problemList[r]<=k):
            ret += 1
            r -= 1
            side = r
            twoSidesBlocked = 0
        elif(side==r):
            if twoSidesBlocked == 1:
                break
            side = l
            twoSidesBlocked += 1



    return ret

if __name__ == "__main__":

    n,k = map(int,input().split())
    #k = input()
    n = int(n)
    k = int(k)

    problemList = list(map(int,input().split()))
    #print(problemList)

    result = FindMax(0, n-1)
    print(result)
    #print(problemList)
