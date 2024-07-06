# This is a sample Python script.
import copy


# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.


def print_hi(name):
    # Use a breakpoint in the code line below to debug your script.
    print(f'Hi, {name}')  # Press Ctrl+F8 to toggle the breakpoint.

def rotate( matrix):
    copy_image = []
    copy_image = copy.deepcopy(matrix)

    for i in range(0, len(matrix)):
        for j in range( len(matrix[i]) - 1 , -1, -1  ):
            matrix [ len(matrix [i] ) - 1 - j] [ len(matrix[i]) - 1-  i  ]   = copy_image[i][j]

    return  matrix

# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    image = [[1,2,3],[4,5,6],[7,8,9]]
    ans = rotate(image)
    print(ans)



# See PyCharm help at https://www.jetbrains.com/help/pycharm/
