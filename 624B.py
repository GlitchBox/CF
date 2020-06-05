
import numpy as np
import sys

def ifSorted(n:int, m:int, a:list, p:list):
    maxLeft = 0 #this stores the max from the left of the unswappable position
    currentMax = a[0]

    i = 1
    while i<n:

        #if the position before the current position is unswappable
        #make the current max the max from the left of the left most unswappable position
        #left most unswappable position is the left most index of p with 0 in it
        if p[i-1]==0:
            maxLeft = currentMax

        if maxLeft>a[i]:
            return False

        currentMax = max(a[i], currentMax)
        i+=1

    return True
if __name__ == "__main__":
    lines = sys.stdin.readlines()
    t = int(lines[0])

    for case in range(t):
        index = case*3 + 1

        n,m = map(int, lines[index].split())
        a = [int(x) for x in lines[index+1].split()]
        temp = [int(x) for x in lines[index+2].split()]
        p = np.zeros(n)

        for pos in temp:
            p[pos - 1] = 1
        ret = ifSorted(n, m, a, p)
        if ret:
            print("YES")
        else:
            print("NO")

    # print(a)
    # print(p)

 


