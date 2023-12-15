mainstring = input("Enter a string: ")

wordlist = mainstring.split()
maxlen = 0
longestword = ""
for i in wordlist:
    if len(i) > maxlen:
        maxlen = len(i)
        longestword = i
print ("the longest word is", longestword)

freqchar = input("Enter the character whose frequency you want to find: ")
freq = 0
if len(freqchar)!=1:
    print ("Enter a single character!")
else:
    for i in mainstring:
        if i == freqchar:
            freq+=1
    print ("frequency of",freqchar,"is",freq)

revstring = ""
for i in mainstring:
    revstring = i + revstring
if revstring == mainstring:
    print (mainstring,"is a palindrome")
else:
    print (mainstring,"is not a palindrome")

substr = input("Enter the substring whose first occurence you want to find: ")
index = 0
for i in range(len(mainstring) - len(substr) + 1):
    if mainstring[i:i+len(substr)] == substr:
        index = i
        break
print ("Index of first occurence of", substr,"is", index)

checkedwords = []
for i in wordlist:
    icount = 0
    for j in wordlist:
        if j not in checkedwords:
            if j == i:
                icount+=1
    if i not in checkedwords:
        checkedwords.append(i)
        print (i,"occurs",icount,"times in the string")