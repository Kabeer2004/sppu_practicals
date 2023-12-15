def cricnbad(cric, bad):
    cricbad = []
    for i in cric:
        if i in bad:
            cricbad.append(i)
    return cricbad

def cricorbad(cric, bad):
    cricorbadarr = []
    for i in cric:
        if i not in bad:
            cricorbadarr.append(i)
    for i in bad:
        if i not in cric:
            cricorbadarr.append(i)
    return cricorbadarr

def neithercricnorbad(cric, bad, foot):
    neithercricnorbadarr = []
    for i in foot:
        if (i not in cric) and (i not in bad):
            neithercricnorbadarr.append(i)
    return len(neithercricnorbadarr)

def cricnfootbutnotbad(cric, foot, bad):
    cricfootnotbad = []
    for i in cric:
        if (i in foot) and (i not in bad):
            cricfootnotbad.append(i)
    return len(cricfootnotbad)

cric = ['a' , 'b', 'c', 'd', 'e', 'p']
bad = ['a', 'b', 'x', 'y']
football = ['a' , 'p', 'q' , 'b']

print ("Students who play cricket and badminton: ", cricnbad(cric,bad))
print ("Students who play either cricket or badminton but not both: ", cricorbad(cric, bad))
print ("Number of students who play neither cricket nor badminton: ", neithercricnorbad(cric, bad, football))
print ("Number of students who play cricket and football but not badminton: ", cricnfootbutnotbad(cric, football, bad))