import random
import pandas as pd
[w1,w2,w3,w4,w5,w6] = [-0.014, 4.255, 0.028, -1.269, 3.2, -1.034]
vals = []
for i in range(200):
    x1 = random.randint(30,120)
    x2 = random.randint(1, 2)
    x3 = random.randint(3,10)
    x4 = random.randint(1,2)
    x5 = random.randint(0,1)
    x6 = random.randint(1,4)
    eq = w1*x1+w2*x2+w3*x3+w4*x4+w5*x5+w6*x6
    vals.append([x1,x2,x3,x4,x5,x6,eq])
df = pd.DataFrame(vals,columns=['Column1','Column2','Column3','Column4','Column5','Column6','Column7'])
df.to_csv('dataset.csv',index=False)