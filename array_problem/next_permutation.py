
def nextpermutation(l):
    n = len(l)


    for i in range(n-1, 0, -1):
        right = l[i]
        left = l[i-1]

        if left < right:
            l[i:] = l[n-1: i-1: -1]
            k = i
            while l[k] <= left:
                k += 1
            l[i-1] = l[k]
            l[k] = left
            return


    l.reverse()



if __name__ == '__main__':
    #l = [1, 8, 7, 7, 6, 5, 4, 3, 10, 2   ]
    l = [2, 3, 5 , 2,2, 8, 7, 7, 6, 5, 4 , 3, 2, 2]
    #l = [3,2,1]

    nextpermutation(l)

    print(l)
