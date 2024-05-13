def ReplaceVowels(string):
    """
    ReplaceVowels function returns a string replacing all 
    vowels that appear 3 times in a row.

    Parameters:
    - string (str): The input string to be processed.

    Returns:
    - str: The modified string with 3 consecutive vowels replaced by underscores.
    """
    
    vowels = ['aaa', 'eee', 'iii', 'ooo', 'uuu']
    
    for sequence in vowels:
        if sequence in string:
            string = string.replace(sequence, '_')
    
    return string

my_string = 'aaahelooo'
print(ReplaceVowels(my_string))
