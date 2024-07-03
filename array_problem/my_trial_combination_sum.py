



def combinationSum(  a, target):
    result = []

    def backtracking(a, target, start, path):

        if target < 0:
            return
        if target == 0:
            result.append(path)
            return

        for i in range(start, len(a)):
            backtracking(a, target - a[i], i, path + [a[i]])

    a.sort()
    backtracking(a, target, 0, [])
    return result




if __name__ == '__main__':


    a = [6,7 , 2 ,3]
    target = 7

    result  = combinationSum(a, target)
    print(result)

