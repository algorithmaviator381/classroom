def replaveV(str):
    """
    replaceV function returns a string replacing all 
    vowels that appears consequently 3 times

    Parameters: (string str):
        str is a string datatype
    """

    vowels = ['aaa','eee','iii','ooo','uuu']
    
    for i in vowels:
        if i in str:
            str = str.replace(i,'_')
    return str

mysstring = 'aaahelooo'
print(help(replaveV))