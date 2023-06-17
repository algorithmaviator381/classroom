import math

sum_list = [0]
coefficient_list = []
my_table = []

def main():
    #x=[0, 60, 120, 240, 300]
    #x=[0, 30, 60, 90, 120, 150, 180, 210, 240, 270, 300, 330]
    #x = list(map(float, input().split()))

    x=[0, 30, 60, 90, 120, 150]
    print("\nX = ",x)
    print("\nEnter values of Y seperated by a space : ")
    y = list(map(float, input().split()))

    harmonic=int(input("\nHow many harmonics do you require for your analysis : "))

    my_table = genreate_harmonic_analysis_table(x,y,harmonic)
    print_table(my_table)
    print_summations(my_table)

def r2d(num):
    return num*math.pi/180

def genreate_harmonic_analysis_table(x,y,harmonic=3):
    tbl=[]
    cols = 2 + harmonic*2
    tbl = [ [0 for i in range(cols)] for j in range(6)]

    for r in range(len(tbl)):
        tbl[r][0]=x[r]
        tbl[r][1]=y[r]
        for c in range(len(tbl[r])):
            current_colum=2

            for i in range(harmonic):
                tbl[r][current_colum] = y[r]*math.cos(r2d((i+1)*x[r]))
                current_colum+=1
                
            for i in range(harmonic):
                tbl[r][current_colum] = y[r]*math.sin(r2d((i+1)*x[r]))
                current_colum+=1
                
    return tbl

def print_table(tbl):
    print()
    harmonic = int((len(tbl[0])-2)/2)
    print("X\t\tY\t\t",end="")

    print("Ycosx\t\t",end="")
    for i in range(harmonic-1):
        print("Ycos" + str(i+2) + "x\t\t",end="")

    print("Ysinx\t\t",end="")
    for i in range(harmonic-1):
        print("Ysin" + str(i+2) + "x\t\t",end="")
    
    for i in tbl:
        print("\n")
        for j in i:
            print(round(j,2),end="\t\t")

def print_summations(tbl):
    harmonic = int((len(tbl[0])-2)/2)
    current_colum=3

    def summation_of_col(col):
        sum=0
        for i in range(6):
            sum = sum + tbl[i][col]
        return round(sum,2)

    for i in range(harmonic*2+1):
        sum_list.append(summation_of_col(i+1))

    print("\n\n\n")
    print("Here are the summations of colums of the harmonic table, curated for you :")
    print("Y       = ",sum_list[1])

    print("Ycosx   = ",sum_list[2])
    for i in range(harmonic-1):
        print("Ycos" + str(i+2) + "x  = ",sum_list[current_colum])
        current_colum+=1

    print("Ysinx   = ",sum_list[current_colum])
    current_colum+=1
    for i in range(harmonic-1):
        print("Ysin" + str(i+2) + "x  = ",sum_list[current_colum])
        current_colum+=1

    current_colum=3
    coefficient_list=list(map(lambda x:round(x*2/6,2),sum_list))
    print("\n")
    print("Coefficinets :")
    print("a0   = ",coefficient_list[1])

    for i in range(harmonic):
        print("a" + str(i+1) + "  = ",coefficient_list[current_colum-1])
        current_colum+=1

    for i in range(harmonic):
        print("b" + str(i+1) + "  = ",coefficient_list[current_colum-1])
        current_colum+=1


if __name__ == main():
    main()