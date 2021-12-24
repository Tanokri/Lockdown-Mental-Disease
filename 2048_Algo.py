import random, copy
import numpy as np
import copy
from itertools import product

lenow = 4
scorep = 0
highscore = 0
perc2 = 90
runs = 7
GRIDS = []
topg = None

mov = ["up", "right", "down", "left"]
depth = 5

arrangements = product(mov, repeat=depth)

templ = [[0.150, 0.121, 0.102, 0.0999], [0.0997, 0.088, 0.076, 0.0724], [0.0606, 0.0562, 0.0371, 0.0161],
         [0.0125, 0.0099, 0.0057, 0.0033]]


def bestmove(grid, dep, movestodo, currentscore, grids):
    dep += 1
    placeholder = [x[:] for x in grid]
    global GRIDS

    if dep != depth:
        i = 0
        length_mov = len(mov)
        for i in mov:
            grid = move(i, grid, currentscore)[0]

            movestodo.append(i)

            if grid != placeholder:
                grid = newgrid(grid, True)[0]
                tempGrid = []
                tempGrid = copy.deepcopy(grids)

                tempGrid.append(grid)
                grids = copy.deepcopy(bestmove(grid, dep, movestodo, currentscore, tempGrid.copy()))

                tempGrid.clear()
            movestodo.pop()
            grid = [x[:] for x in placeholder]


    else:
        global highscore
        global topg

        SCORE = evalgrid(grid)

        if highscore < SCORE:
            highscore = SCORE
            topg = grid
            GRIDS = copy.deepcopy(grids)

        return GRIDS
    return GRIDS


def move(lrud, grid, score):
    if lrud == "left" or lrud == "right":

        for i in range(lenow):
            if lrud == "right":
                grid[i] = grid[i][::-1]

            for j in range(grid[i].count(0)):
                grid[i].append(grid[i].pop(grid[i].index(0)))

            for k in range(0, lenow - 1):

                if grid[i][k] == grid[i][k + 1]:
                    score += grid[i][k] * 2
                    grid[i][k] = grid[i][k] * 2
                    grid[i].remove(grid[i][k + 1])
                    grid[i].append(0)

            if lrud == "right": grid[i] = grid[i][::-1]
        return grid, score

    else:
        col = [grid[j][i] for i in range(0, lenow) for j in range(0, lenow)]
        tempgrid = [col[i * lenow:((i + 1) * lenow)] for i in range(lenow)]

        for i in range(lenow):

            if lrud == "down":
                tempgrid[i] = tempgrid[i][::-1]

            for j in range(tempgrid[i].count(0)):
                tempgrid[i].append(tempgrid[i].pop(tempgrid[i].index(0)))

            for element in range(0, lenow - 1):
                if tempgrid[i][element] == tempgrid[i][element + 1]:
                    score += grid[i][element] * 2
                    tempgrid[i][element] = tempgrid[i][element] * 2
                    tempgrid[i].remove(tempgrid[i][element + 1])
                    tempgrid[i].append(0)

            if lrud == "down":
                tempgrid[i] = tempgrid[i][::-1]

        for row in range(lenow):
            for column in range(lenow):
                grid[row][column] = tempgrid[column][row]

        return grid, score


def tots(grid):
    global scorep
    scorep = sum(map(sum, grid))
    return scorep


def tilegen():
    randnum = random.randint(1, 100)
    if randnum < perc2:
        number = 2
    else:
        number = 4
    return number


def evalgrid(grid):
    return np.sum(np.array(grid) * templ)


def display(*grids):
    for grid in grids:
        print(np.array(grid))


def checking(grid):
    gridArr = []

    for lrud in mov:
        temp = [x[:] for x in grid]
        gridArr.append(move(lrud, temp, scorep))

    for potentialGrid in gridArr:
        if grid != potentialGrid[0]:
            return False
    return True


def newgrid(grid, state):
    count = 0
    for i in range(lenow):
        count += grid[i].count(0)

    if not count:
        if checking(grid):
            return grid, True

    if state == True:
        while True:
            row = random.randint(0, lenow - 1)
            column = random.randint(0, lenow - 1)
            if grid[row][column] == 0:
                grid[row][column] = tilegen()
                return grid, False
    return grid, False
