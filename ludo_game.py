from random import *

def gen_arr(n):
    arr = []
    for i in range(n):
        row = []
        for j in range(n):
            row.append(" ")
        arr.append(row)
    arr[0][0] = "!"
    for i in range(n):
        for j in range(n):
            if(i==(n-1)/2):
                arr[i][j] = "D"
                if j==0 or j==n-1:
                    arr[i][j] = "*"
                arr[i+1][j] = "*"
                arr[i-1][j] = "*"
            elif(j==(n-1)/2):
                arr[i][j] = "D"
                if i==0 or i==n-1:
                    arr[i][j] = "*"
                arr[i][j+1] = "*"
                arr[i][j-1] = "*"
            if(i==(n-1)/2)and(j==(n-1)/2):
                arr[i][j] = "X"
                arr[i-1][j] = "D"
    return arr

def set_figure(arr,n):
    k =int((n-1)/2)
    arr[0][k+1] = "A"
    arr[n-1][k-1] = "B"
    return arr

def gen_hod():
    ran = randint(1, 6)
    print(ran)
    return ran

def move(arr, tah, hod, n):
    global x
    global y
    global b
    global m
    global figurky_a
    global figurky_b
    k = int((n-1)/2)
    p= True
    for i in range(n):
        for j in range(n):
            if(arr[i][j]==tah):
                if(i==k):
                    if(j>0 and j<n-1):
                        continue
                    else:
                        b=y=i
                        m=x=j
                elif(j==k):
                    if(i>0 and i<n-1):
                        continue
                    else:
                        b=y=i
                        m=x=j
                else:
                    b=y=i
                    m=x=j
    arr[y][x] = '*'
    while(hod>0):
        if tah == 'A':
            if (x + 1==((n-1) / 2)+1) and (y == 0):
                if hod <= (n - 3) / 2:
                    if(arr[y+hod][x]=='D'):
                        arr[y][x] = '*'
                        arr[y + hod][x] = 'A'
                        figurky_a-=1
                        hod = 0
                        if figurky_a > 0:
                            arr[0][k+1]='A'
                        p = False
                    else:
                        hod=0
                        arr[b][m]='A'
                else:
                    hod=0
                    arr[b][m]='A'

        elif tah == 'B':
            if(y == n - 1)and(x - 1 == ((n - 1) / 2) - 1) :
                if hod <= (n - 3) / 2 :
                    if arr[y-hod][x]=='D':
                        arr[y][x] = '*'
                        arr[y - hod][x] = 'B'
                        figurky_b-=1
                        hod = 0
                        if figurky_b > 0:
                            arr[n-1][k-1] = 'B'
                        p =False
                    else:
                        hod=0
                        arr[b][m]='B'
                else:
                    hod=0
                    arr[b][m]='B'
        if p:
            if x==((n-1)/2)+1:  #zmena smeru okolo y osy z prava
                if y==0:    #vrchny start
                    y+=1
                    hod-=1
                    if hod==0:
                        if arr[y][x] != tah:
                            dump(tah, arr, n, k, y, x)
                        arr[y][x] = tah
                elif y==((n-1)/2)-1:    #prvy kvadrant lavy dolny roh
                    x+=1
                    hod -= 1
                    if hod==0:
                        if arr[y][x] != tah:
                            dump(tah, arr, n, k, y, x)
                        arr[y][x] = tah
                elif y==((n-1)/2)+1:    #treti kvadrant lavy horny roh
                    y+= 1
                    hod -= 1
                    if hod==0:
                        if arr[y][x] != tah:
                            dump(tah, arr, n, k, y, x)
                        arr[y][x] = tah
                elif y==n-1:            #treti kvadrant lavy dolny roh
                    x-= 1
                    hod -= 1
                    if hod==0:
                        if arr[y][x] != tah:
                            dump(tah, arr, n, k, y, x)
                        arr[y][x] = tah
                else:                   #rovnobezne s osou y mimo rohov
                    y+= 1
                    hod -= 1
                    if hod==0:
                        if arr[y][x] != tah:
                            dump(tah, arr, n, k, y, x)
                        arr[y][x] = tah
            elif x == ((n - 1) / 2) -1:  # zmena smeru dole na y osy
                if y == n-1:  # spodny start
                    y -= 1
                    hod -= 1
                    if hod==0:
                        if arr[y][x] != tah:
                            dump(tah, arr, n, k, y, x)
                        arr[y][x] = tah
                elif y == ((n - 1) / 2) - 1:  # druhy kvadrant pravy dolny roh
                    y-= 1
                    hod -= 1
                    if hod==0:
                        if arr[y][x] != tah:
                            dump(tah, arr, n, k, y, x)
                        arr[y][x] = tah
                elif y == ((n - 1) / 2) + 1:  # stvrty kvadrant pravy dolny roh
                    x-= 1
                    hod -= 1
                    if hod==0:
                        if arr[y][x] != tah:
                            dump(tah, arr, n, k, y, x)
                        arr[y][x] = tah
                elif y == 0:                  # druhy kvadrant pravy horny roh
                    x+= 1
                    hod -= 1
                    if hod==0:
                        if arr[y][x] != tah:
                            dump(tah, arr, n, k, y, x)
                        arr[y][x] = tah
                else:       # rovnobezne s osou y mimo rohov
                    y -= 1
                    hod -= 1
                    if hod==0:
                        if arr[y][x] != tah:
                            dump(tah, arr, n, k, y, x)
                        arr[y][x] = tah
            elif x==0:      #lava strana
                if y==((n-1)/2)+1:      #stvrty kvadrant lavy horny roh
                    y -= 1
                    hod -= 1
                    if hod==0:
                        if arr[y][x] != tah:
                            dump(tah, arr, n, k, y, x)
                        arr[y][x] = tah
                elif y == ((n - 1) / 2) -1: #lavy start
                    x += 1
                    hod -= 1
                    if hod==0:
                        if arr[y][x] != tah:
                            dump(tah, arr, n, k, y, x)
                        arr[y][x] = tah
                else:       #po lavej strane
                    y -= 1
                    hod -= 1
                    if hod==0:
                        if arr[y][x] != tah:
                            dump(tah, arr, n, k, y, x)
                        arr[y][x] = tah
            elif x==n-1:    #prava strana
                if y == ((n - 1) / 2) + 1: #pravy start
                    x-= 1
                    hod -= 1
                    if hod==0:
                        if arr[y][x] != tah:
                            dump(tah, arr, n, k, y, x)
                        arr[y][x] = tah
                elif y ==((n-1)/2)-1:   #prvy kvadrant pravy dolny roh
                    y += 1
                    hod -= 1
                    if hod==0:
                        if arr[y][x] != tah:
                            dump(tah, arr, n, k, y, x)
                        arr[y][x] = tah
                else:       #po pravej strane
                    y += 1
                    hod -= 1
                    if hod==0:
                        if arr[y][x] != tah:
                            dump(tah, arr, n, k, y, x)
                        arr[y][x] = tah
            elif y==((n-1)/2)-1: #okolo x z vrchu
                x+=1
                hod-=1
                if hod == 0:
                    if arr[y][x] != tah:
                        dump(tah, arr, n, k, y, x)
                    arr[y][x] = tah
            elif y ==((n-1)/2)+1: #okolo x zo spodu
                x -= 1
                hod -= 1
                if hod == 0:
                    if arr[y][x] != tah:
                        dump(tah, arr, n, k, y, x)
                    arr[y][x] = tah
            elif x==(n-1)/2 and y == n-1:
                x -= 1
                hod -= 1
                if hod == 0:
                    if arr[y][x] != tah:
                        dump(tah, arr, n, k, y, x)
                    arr[y][x] = tah
            elif y == 0 and x==(n-1)/2:
                x+=1
                hod-=1
                if hod==0:
                    if (arr[y][x] != tah):
                        dump(tah, arr, n, k, y, x)
                    arr[y][x]= tah

    return arr

def dump(tah,arr,n,k,y,x):
    if arr[y][x] != tah:
        if tah == "A":
            if arr[y][x] == 'B':
                arr[y][x] = 'A'
                arr[n - 1][k - 1] = 'B'
        else:
            if arr[y][x] == 'A':
                arr[y][x] = 'B'
                arr[0][k + 1] = 'B'

while(1):
    global figurky_a
    global figurky_b
    tah = "A"
    n = int(input("Zadaj hraciu plochu(neparne cislo mensie rovne ako 15): "))
    figurky_a = figurky_b = int((n-3)/2)
    pole = gen_arr(n)
    pole = set_figure(pole,n)
    for i in range(n):
        for j in range(n):
            print(pole[i][j], end=' ')
        print()
    while(1):
        hod = gen_hod()
        pole = move(pole, tah, hod, n)
        if tah=='A':
            tah='B'
        else:
            tah='A'
        for i in range(n):
            for j in range(n):
                print(pole[i][j], end=' ')
            print()
        if figurky_a==0 or figurky_b==0:
            print("Koniec")
            if figurky_a==0:
                print("Vyhral hrac A")
            else:
                print("Vyhral hrac B")
            break
    break
