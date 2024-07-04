



def combination_sum(a, target):
    a.sort()
    #print(a)
    result = []
    def backtracking( target, path, start):


        if target < 0:
            return
        if target == 0:
            result.append(path)
            return
        else:
            for i in range (start, len(a)):
                if i > start and a[i] == a[i-1]:
                    continue
                backtracking( target - a[i], path + [a[i] ], i +1)



    backtracking( target, [], 0)
    return  result

if __name__ == '__main__':
    a = [10, 1, 2, 7, 6, 1, 5]
    target = 8

    r = combination_sum(a, target)
    print(r)