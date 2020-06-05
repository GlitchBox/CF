
if __name__=="__main__":

    bucketList = []
    b=1
    indexNo=1
    while b<=2000000000:
        e = b + indexNo-1
        bucketList.append({"b":b, "e":e})
        b = e + 1
        indexNo += 1

    indexNo = len(bucketList)
    # print(bucketList)

    T = int(input())

    while T>0:
        n,k = map(int, input().split())

        begin = 0
        end = indexNo-1
        bucketNo = -1
        while begin<=end:
            mid = (begin+end)//2
            if bucketList[mid]["b"]<=k and bucketList[mid]["e"]>=k:
                bucketNo = mid+1
                break
            elif bucketList[mid]["e"]<k:
                begin = mid + 1
            else:
                end = mid - 1

        # print(bucketNo)
        # print(bucketList[0:5])
        returnString = "a"*n
        returnList = list(returnString)
        returnList[n-1-bucketNo] = "b"
        returnList[n-1-(k-bucketList[bucketNo-1]["b"])] = "b"
        returnString = "".join(returnList)
        print(returnString)

        T-=1
