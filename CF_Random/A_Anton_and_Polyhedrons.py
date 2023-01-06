x = input()
cnt=0
for i in range(1,x):
    s = input()
    if s=="Tetrahedron":
        cnt+=4
    elif s=="Cube":
        cnt+=6
    elif s=="Octahedron":
        cnt+=8
    elif s=="Dodecahedron":
        cnt+=12
    elif s=="Icosahedron":
        cnt+=20
print(cnt)