from tkinter import *
import random, colour_code, auto_algo, time

class Chief(Frame):
    
    def __init__(self):
        Frame.__init__(self)
        self.timer =0
        self.grid()
        self.flag = []
        self.situ = "not over"
        self.master.title('Krish Avalani - 2048 AUTO SOLVER')
        self.score =0
        self.movcount =0
        self.cellgri = []
        self.grid_og()
        self.matrixx = fresh(colour_code.length)
        self.oldmat = []
        self.upgrid()


    def navi(self):
        auto_algo.highscore = 0
        auto_algo.GRIDS.clear()
        grids = []

        grids = auto_algo.bestmove(self.matrixx,0,[],self.score,[])
        
        i = 0
        while(i<len(grids)):
            self.matrixx = grids[i]
            self.upgrid()
            i+=1
        self.score = auto_algo.tots(self.matrixx)

        self.situ = game_state(self.matrixx)
        if self.flag == self.matrixx:
            print(self.timer)
            self.timer+=0.3
            if self.timer >10:
                self.situ = "lose"
        else:
            self.timer =0

        self.flag = self.matrixx

        
        if self.situ == 'lose':
            self.cellgri[1][1].configure(text="You", bg=colour_code.white)
            self.cellgri[1][2].configure(text="Lose!", bg=colour_code.white)
            return
        
        self.movcount+=1
        self.upgrid()
    
    def upgrid(self):
        for i in range(colour_code.length):
            for j in range(colour_code.length):
                new_number = self.matrixx[i][j]
                if new_number == 0:
                    self.cellgri[i][j].configure(text="",bg=colour_code.cells)
                else:
                    self.cellgri[i][j].configure(
                        text=str(new_number),
                        bg=colour_code.cellmap[new_number],
                        fg=colour_code.cellfont[new_number]
                    )
        self.update()


    def grid_og(self):
        background = Frame(self, bg=colour_code.back,width=colour_code.size, height=colour_code.size)
        background.grid()

        for i in range(colour_code.length):
            rows = []
            for j in range(colour_code.length):
                cell = Frame(background,bg=colour_code.cells,width=colour_code.size / colour_code.length,height=colour_code.size / colour_code.length)
                cell.grid(row=i,column=j,padx=colour_code.thickness,pady=colour_code.thickness)
                t = Label(master=cell,text="",bg=colour_code.cells,justify=CENTER,font=colour_code.font,width=8,height=4)
                t.grid()
                rows.append(t)
            self.cellgri.append(rows)


    def topsq(self):
        maxt = 0
        for i in range(0,colour_code.length):
            for j in range(0,colour_code.length):
                if self.matrixx[i][j] >maxt:
                    maxt = self.matrixx[i][j]
        return maxt

    
    def backtoog(self):
        self.matrixx.clear()
        self.matrixx = fresh(colour_code.length)
        self.situ = "not over"
                
    
    def nextsq(self):
        index = (gen(), gen())
        while self.matrixx[index[0]][index[1]] != 0:
            index = (gen(), gen())
        self.matrixx[index[0]][index[1]] = 2


def twoplus(mat):
    a = random.randint(0, len(mat)-1)
    b = random.randint(0, len(mat)-1)
    while mat[a][b] != 0:
        a = random.randint(0, len(mat)-1)
        b = random.randint(0, len(mat)-1)
    mat[a][b] = 2
    return mat

def fresh(n):
    matrixx = []
    for i in range(n):
        matrixx.append([0] * n)
    matrixx = twoplus(matrixx)
    matrixx = twoplus(matrixx)
    return matrixx

def game_state(mat):
    # zero entry checking
    i = 0
    while (i<len(mat)):
        for j in range(len(mat[0])):
            if mat[i][j] == 0:
                return 'not over'
        i+=1
    # similar cells touching
    i = 0
    while(i<len(mat)-1):
        # runduction in order to check the row on right and below
        for j in range(len(mat[0])-1):
            if mat[i][j] == mat[i+1][j] or mat[i][j+1] == mat[i][j]:
                return 'not over'
        i+=1

    # look for left and right entry in last row
    for k in range(len(mat)-1): 
        if mat[len(mat)-1][k] == mat[len(mat)-1][k+1]:
            return 'not over'
    # look for up and down entry in last column
    for j in range(len(mat)-1):
        if mat[j][len(mat)-1] == mat[j+1][len(mat)-1]:
            return 'not over'
    return 'lose'

    return game, done

def gen():
    return random.randint(0, colour_code.length - 1)

            
def main():

    game_grid = Chief()
    f = open("results_logs.txt","w+")
    f.close()
    for i in range(0,100):
        start = time.time()
        while not game_grid.situ=="lose":
            game_grid.navi()
        f = open("results_logs.txt","a")
        string = ("Game Number: "+ str(i+1) + "\nFinal Score: " + str(game_grid.score) + "\nHighest Tile Achieved: " + str(game_grid.topsq())+ "\nTime of Execution: " + str(round(time.time()-start,2))+"s")
        f.write(string)
        f.write('\n')
        f.write("-------------------------------------------------------------")
        f.write('\n')
        f.close()
        time.sleep(10)
        game_grid.backtoog()



main()
    
