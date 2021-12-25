# 202000300393 张骏羽 大数据20.2
# 2021.12.24 16:31
# 该实验直接运行即可，会自动生成分布矩阵
from matplotlib import pyplot as plt
import numpy as np
import random
import copy
# 解决中文字符问题
plt.rcParams["font.sans-serif"] = ["SimHei"]

a = [2, 1, 0]  # 2代表X，1代表Y，0代表空位
N = 55  # 模拟维度N*N，可随意调节
p = [0.37, 0.37, 0.26]  # 生成概率
array_N = []  # 空位列表，可供搬家选择
array_M = []  # 保存矩阵不同时期的状态(0,2,4,6,8,10)

# 获得每个位置是否满意
def Happiness(m, r, c):
    type = m[i][j]
    num = 0  # 记录同类型的个数
    if m[r-1][c-1] == type:
        num += 1
    if m[r-1][c] == type:
        num += 1
    if m[r-1][c+1] == type:
        num += 1
    if m[r][c-1] == type:
        num += 1
    if m[r][c+1] == type:
        num += 1
    if m[r+1][c-1] == type:
        num += 1
    if m[r+1][c] == type:
        num += 1
    if m[r+1][c+1] == type:
        num += 1

    if num >= 3:
        return True
    return False

if __name__ == '__main__':
    # 为简化运算，给矩阵形成一层包围，包围可以忽略不看,包围内部为X,Y,空位的分布矩阵
    matrix = np.random.choice(a, size=(N+2)**2, p=p).reshape(N+2, N+2)
    array_M.append(copy.copy(matrix))
    # 生成空位列表
    for i in range(1, N+1):
        for j in range(1, N+1):
            if matrix[i][j] == 0:
                array_N.append((i, j))
    # 记录空位数量
    n0 = len(array_N)
    # 进行10轮搬家实验，然后画出10轮之后的矩阵分布图
    for count in range(10):
        for i in range(1, N+1):
            for j in range(1, N+1):
                if not Happiness(matrix, i, j) and matrix[i][j] != 0:
                    seed = random.randrange(0, n0)
                    x, y = array_N.pop()
                    array_N.append((i, j))
                    matrix[x][y] = matrix[i][j]
                    matrix[i][j] = 0
        if count % 2 != 0:
            array_M.append(copy.copy(matrix))

    fig, axes = plt.subplots(2, 3)
    axes[0][0].matshow(array_M[0])
    axes[0][0].set_title('初始状态')
    axes[0][1].matshow(array_M[1])
    axes[0][1].set_title('运行2轮后')
    axes[0][2].matshow(array_M[2])
    axes[0][2].set_title('运行4轮后')
    axes[1][0].matshow(array_M[3])
    axes[1][0].set_title('运行6轮后')
    axes[1][1].matshow(array_M[4])
    axes[1][1].set_title('运行8轮后')
    axes[1][2].matshow(array_M[5])
    axes[1][2].set_title('运行10轮后')
    plt.show()
