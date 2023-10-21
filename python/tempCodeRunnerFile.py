def calculateChocolatesForSakahiMane(money):
    chocolates = money

    while chocolates >= 3:
        new_chocolates = chocolates // 3
        chocolates += new_chocolates
        wrappers = new_chocolates
        chocolates -= wrappers * 2

    return chocolates

money = 21
result = calculateChocolatesForSakahiMane(money)
print(f"You can get {result} chocolates for {money} rupees.")
