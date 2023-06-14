import numpy as np

def main():
    x = np.array([0, 30, 60, 90, 120, 150])
    y = np.array([1,2,3,4,5,6])
    print("\nX = ",x)
    print("\nEnter values of Y seperated by a space : ")
    # y = np.array(list(map(float, input().split())))
    print("\nY = ",y)
    
    harmonic=int(input("\nHow many harmonics do you require for your analysis: "))

    my_table = genreate_harmonic_analysis_table(x,y,harmonic)
    print(my_table)
    print(coefficients)

def r2d(num):
    return num*np.pi/180

def r2d(num):
    return num*np.pi/180

x = np.array([0, 30, 60, 90, 120, 150])
y = np.array([1,2,3,4,5,6])

def genreate_harmonic_analysis_table(x,y,harmonic=3):
    tbl = np.ones((6,2+2*harmonic), dtype='float32')
    
    tbl[:,0]=np.round(x,2)
    tbl[:,1]=np.round(y,2)

    for i in range(2*harmonic):
        if i<harmonic:
            temp = np.round(np.cos((i+1)*r2d(x)),2)
            temp=np.multiply(temp,tbl[:,1])
            tbl[:,i+2]=temp
        else:
            temp = np.round(np.sin((i-2)*r2d(x)),2)
            temp=np.multiply(temp,tbl[:,1])
            tbl[:,i+2]=temp
            
    return tbl

print(genreate_harmonic_analysis_table(x,y,harmonic=3))

def genrate_summations(tbl):
    hrm = tbl.shape[1]-1
    sum_tbl=np.full(hrm,1,dtype='float32')

    for i in range(hrm):
        sum_tbl[i]=np.round(np.sum(tbl[:,i+1]),2)

    sum_tbl = np.reshape(sum_tbl,(hrm,1))
    return sum_tbl

tbl = genreate_harmonic_analysis_table(x,y,3)
coefficients = np.round(genrate_summations(tbl)/3,2)

if __name__ == main():
    main()