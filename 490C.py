n=0
k=0

def reducedString(s:str):

    alphabetList = []
    index = 0
    while index<26:
        alphabetList.append(0)
        index += 1
    index = 0

    #count how many of each character there are in the string
    while index<n:
        # print(ord(s[index])-ord('a'))
        alphabetList[ord(s[index]) - ord('a')] += 1

        index+=1

    charsDeleted = 0
    index = 0

    #remove k characters from the string
    while(charsDeleted<k):
        if(alphabetList[index]>0):
            toBeDeleted = min(k - charsDeleted, alphabetList[index])
            charsDeleted += toBeDeleted
            alphabetList[index] -= toBeDeleted
        index += 1

    #print(alphabetList)
    #build the list of characters that remain after deletion
    index = n-1
    resultList = []
    while(index>-1):
        if(alphabetList[ord(s[index]) - ord('a')]>0):
            resultList.append(s[index])
            alphabetList[ord(s[index]) - ord('a')] -= 1
        index -= 1

    l = 0
    r = len(resultList) - 1
    while(l<r):
        tmp = resultList[l]
        resultList[l] = resultList[r]
        resultList[r] = tmp

        l+=1
        r-=1

    res = "".join(resultList)
    return res

if __name__ == "__main__":
    n,k = map(int, input().split())

    s = input()

    res = reducedString(s)
    print(res)
