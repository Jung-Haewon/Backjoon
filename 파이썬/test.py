import sys
cnum=int(input())
clist=input()
cname=list(map(int,input().split()))

sindx=0
cnt=0

if clist[0] =='G':
    sindx=clist.find('H')
    cntsindx=clist.count('H')
    if clist[sindx:cname[sindx] + 1].count('H')!=cntsindx:
        print('0')
        sys.exit()
    for i in range(0,sindx):
        if clist[i] == 'G':
            if i == 0 and clist[:cname[0]].count('G')==clist.count('G'):
                cnt+=1
            elif sindx < cname[i]:
                cnt+=1
    print(cnt)

else:
    sindx=clist.find('G')
    cntsindx=clist.count('G')
    
    if clist[sindx:cname[sindx] + 1].count('G')!=cntsindx:
        print('0')
        sys.exit()
        
    for i in range(0,sindx):
        if clist[i] == 'H':
            if i == 0 and clist[0:cname[0]].count('H')==clist.count('H'):
                cnt+=1
            elif sindx < cname[i]:
                cnt+=1
    print(cnt)
