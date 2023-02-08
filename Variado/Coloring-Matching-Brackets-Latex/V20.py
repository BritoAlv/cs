#!/usr/bin/env python
# coding: utf-8

# In[1]:
'''
quiero añadir soporte para stackrel y vert.
'''
# 

ta = str(input("Pon el nombre del .tex: "))
tb = str(input("Pon el nombre del resultado "))
with open(f"{ta}.tex", "r") as s:
    f = s.readlines()
    print("El archivo ha sido leido")


# In[2]:


def splitlista(s):
    lista = []
    for line in s:
        for caracter in line:
            lista.append(caracter)
    return lista


f = splitlista(f)
print("El archivo ha sido splitt")


# In[3]:


def loca(lista, string):  # string es una lista
    fix = []
    for caracter in lista:
        fix.append(caracter)
    a = 0
    for caracter in fix:
        b = 0
        if caracter == string[0]:
            b = 1
            for i in range(1, len(string)):
                if fix[a + i] == string[i]:
                    b = b + 1
            if b == len(string):
                # fix[a] = string[0]
                # fix[a+1] = string[1]
                # ....
                # fix[a+ len(string) - 1] = string[len(string) - 1]
                for i in range(1, len(string)):
                    fix[a] = fix[a] + string[i]
                for i in range(1, len(string)):
                    del fix[a + 1]
        a = a + 1
    return fix


# \biggl[
f = loca(f, ["\\", '{'])
f = loca(f, ["\\", '}'])
f = loca(f, ["\\", "["])
f = loca(f, ["\\", "]"])
f = loca(f, ["\\", "b", "e", "g", "i", "n", "{", "a", "l", "i", "g", "n", "}"])
f = loca(f, ["\\", "b", "e", "g", "i", "n", "{", "a", "l", "i", "g", "n", "*", "}"])
f = loca(f, ["\\", "e", "n", "d", "{", "a", "l", "i", "g", "n", "}"])
f = loca(f, ["\\", "e", "n", "d", "{", "a", "l", "i", "g", "n", "*", "}"])
f = loca(f, ["$", "$"])
f = loca(f, ["\\", "l", "e", "f", "t", "("])
f = loca(f, ["\\", "r", "i", "g", "h", "t", ")"])
f = loca(f, ["\\", "b", "i", "g", "g", "l", "["])
f = loca(f, ["\\", "b", "i", "g", "g", "r", "]"])
f = loca(f, ["\\", "B", "i", "g", "g", "l", "["])
f = loca(f, ["\\", "B", "i", "g", "g", "r", "]"])
f = loca(f, ["\\", "b", "i", "g", "l", "["])
f = loca(f, ["\\", "b", "i", "g", "r", "]"])
f = loca(f, ["\\", "B", "i", "g", "l", "["])
f = loca(f, ["\\", "B", "i", "g", "r", "]"])
f = loca(f, ["\\", "v", "e", "r", "t"])
f = loca(f, ["\\", "m", "i", "d"])
f = loca(f, ["\\", "w", "e", "d", "g", "e"])
f = loca(f, ["\\", "l", "o", "r"])
f = loca(f, ["\\", "v", "d", "a", "s", "h"])
print("Se han unido los strings importantes")

# In[4]:


booleans = []
# 1 es $
# 2 es $$
# 3 es \\[, \\] 
# 4 es \\begin{align}, \\end{align}
# 5 es \\begin{align*}, \\end{align*}
for item in f:
    if item == "$":
        booleans.append(1)
    elif item == "$$":
        booleans.append(2)
    elif item == "\\[" or item == "\\]":
        booleans.append(3)
    elif item == "\\begin{align}" or item == "\\end{align}":
        booleans.append(4)
    elif item == "\\begin{align}" or item == "\\end{align}":
        booleans.append(5)
    else:
        booleans.append(0)
print("Se han creado los booleaans")


# In[5]:


def dolar(t):
    cant1left = 0
    cant2left = 0
    cant3left = 0
    cant4left = 0
    cant5left = 0
    cant1right = 0
    cant2right = 0
    cant3right = 0
    cant4right = 0
    cant5right = 0
    a = 0
    for number in booleans:
        if a < t:
            if number == 1:
                cant1left = cant1left + 1
            if number == 2:
                cant2left = cant2left + 1
            if number == 3:
                cant3left = cant3left + 1
            if number == 4:
                cant4left = cant4left + 1
            if number == 5:
                cant5left = cant5left + 1
        if a > t:
            if number == 1:
                cant1right = cant1right + 1
            if number == 2:
                cant2right = cant2right + 1
            if number == 3:
                cant3right = cant3right + 1
            if number == 4:
                cant4right = cant4right + 1
            if number == 5:
                cant5right = cant5right + 1

        a = a + 1
    if cant1left % 2 == 1 and cant1right % 2 == 1:
        return True
    if cant2left % 2 == 1 and cant2right % 2 == 1:
        return True
    if cant3left % 2 == 1 and cant3right % 2 == 1:
        return True
    if cant4left % 2 == 1 and cant4right % 2 == 1:
        return True
    if cant5left % 2 == 1 and cant5right % 2 == 1:
        return True
    else:
        return False


# In[6]:


def tracker(s, a, b):
    count = 0
    for item in s:
        if int(item) > a and int(item) < b:
            count = count + 1
    return int(count)


def least(a, s):
    t = 0
    for item in s:
        if int(item) > a:
            return int(t)
        t = t + 1


# In[7]:


def emppar(s):
    parleft = "("
    parright = ")"
    parlefts = []
    parrights = []
    a = 0
    for item in s:
        if dolar(a):
            if item == parleft:
                parlefts.append(a)
            if item == parright:
                parrights.append(a)
        a = a + 1
    tuplas = []
    for position in parlefts:
        q = int(least(position, parrights))
        t = int(tracker(parlefts, position, parrights[q]))
        tuplas.append((position, parrights[q + t]))
    return tuplas


par = emppar(f)
print("Se identificaron los paréntesis")


# In[8]:


def emplla(s):
    llaleft = "["
    llaright = "]"
    llalefts = []
    llarights = []
    a = 0
    for item in s:
        if dolar(a):
            if item == llaleft:
                llalefts.append(a)
            if item == llaright:
                llarights.append(a)
        a = a + 1
    tuplas = []
    for position in llalefts:
        q = int(least(position, llarights))
        t = int(tracker(llalefts, position, llarights[q]))
        tuplas.append((position, llarights[q + t]))
    return tuplas


lla = emplla(f)
print("Se identificaron las llaves")


# In[9]:


def empcor(s):
    corleft = "\\{"
    corright = "\\}"
    corlefts = []
    corrights = []
    a = 0
    for item in s:
        if dolar(a):
            if item == corleft:
                corlefts.append(a)
            if item == corright:
                corrights.append(a)
        a = a + 1
    tuplas = []
    for position in corlefts:
        q = int(least(position, corrights))
        t = int(tracker(corlefts, position, corrights[q]))
        tuplas.append((position, corrights[q + t]))
    return tuplas


cor = empcor(f)
print("Se identificaron los corchetes")


# In[10]:


def empbigpar(s):
    bigleft = "\\left("
    bigright = "\\right)"
    biglefts = []
    bigrights = []
    a = 0
    for item in s:
        if dolar(a):
            if item == bigleft:
                biglefts.append(a)
            if item == bigright:
                bigrights.append(a)
        a = a + 1
    tuplas = []
    for position in biglefts:
        q = int(least(position, bigrights))
        t = int(tracker(biglefts, position, bigrights[q]))
        tuplas.append((position, bigrights[q + t]))
    return tuplas


par = empbigpar(f)


def empBigcor(s):
    bigleft = "\\Bigl["
    bigright = "\\Bigr]"
    biglefts = []
    bigrights = []
    a = 0
    for item in s:
        if dolar(a):
            if item == bigleft:
                biglefts.append(a)
            if item == bigright:
                bigrights.append(a)
        a = a + 1
    tuplas = []
    for position in biglefts:
        q = int(least(position, bigrights))
        t = int(tracker(biglefts, position, bigrights[q]))
        tuplas.append((position, bigrights[q + t]))
    return tuplas


Big = empBigcor(f)


def empbigcor(s):
    bigleft = "\\bigl["
    bigright = "\\bigr]"
    biglefts = []
    bigrights = []
    a = 0
    for item in s:
        if dolar(a):
            if item == bigleft:
                biglefts.append(a)
            if item == bigright:
                bigrights.append(a)
        a = a + 1
    tuplas = []
    for position in biglefts:
        q = int(least(position, bigrights))
        t = int(tracker(biglefts, position, bigrights[q]))
        tuplas.append((position, bigrights[q + t]))
    return tuplas


big = empbigcor(f)


def empBiggcor(s):
    bigleft = "\\Biggl["
    bigright = "\\Biggr]"
    biglefts = []
    bigrights = []
    a = 0
    for item in s:
        if dolar(a):
            if item == bigleft:
                biglefts.append(a)
            if item == bigright:
                bigrights.append(a)
        a = a + 1
    tuplas = []
    for position in biglefts:
        q = int(least(position, bigrights))
        t = int(tracker(biglefts, position, bigrights[q]))
        tuplas.append((position, bigrights[q + t]))
    return tuplas


Bigg = empBiggcor(f)


def empbiggcor(s):
    bigleft = "\\biggl["
    bigright = "\\biggr]"
    biglefts = []
    bigrights = []
    a = 0
    for item in s:
        if dolar(a):
            if item == bigleft:
                biglefts.append(a)
            if item == bigright:
                bigrights.append(a)
        a = a + 1
    tuplas = []
    for position in biglefts:
        q = int(least(position, bigrights))
        t = int(tracker(biglefts, position, bigrights[q]))
        tuplas.append((position, bigrights[q + t]))
    return tuplas


bigg = empbiggcor(f)

# In[11]:


listacolores = ["GoogleBlue",
                "GoogleGreen",
                "GoogleYellow",
                "GoogleRed",
                "MaterialRed500",
                "MaterialPink500",
                "MaterialPurple500",
                "MaterialDeepOrange500",
                "MaterialBlue500",
                "MaterialIndigo500",
                "MaterialTeal500",
                "MaterialGreen500",
                "MaterialLime500",
                "MaterialYellow500",
                "MaterialAmber500",
                "MaterialBrown500",
                "MaterialCyan500",
                "MaterialLightBlue500",
                "MaterialLightGreen500",
                "MaterialOrange500",
                "MaterialGrey500",
                "MaterialBlueGrey500",
                "MaterialRed800",
                "MaterialPink800",
                "MaterialPurple800",
                "MaterialDeepOrange800",
                "MaterialBlue800",
                "MaterialIndigo800",
                "MaterialTeal800",
                "MaterialGreen800",
                "MaterialLime800",
                "MaterialYellow800",
                "MaterialAmber800",
                "MaterialBrown800",
                "MaterialCyan800",
                "MaterialLightBlue800",
                "MaterialLightGreen800",
                "MaterialOrange800",
                "MaterialGrey800",
                "MaterialBlueGrey800",
                "MaterialRed800",
                "MaterialPink800",
                "MaterialPurple800",
                "MaterialDeepOrange800",
                "MaterialBlue800",
                "MaterialIndigo800", ]

# In[12]:


import random as rd


# In[13]:


def faq(s, tuplass):
    r = []
    for item in s:
        r.append(item)
    for item in tuplass:
        t = rd.choice(listacolores)
        r[item[0]] = r"\textcolor{" + f"{t}" + "}" + "{" + f"{s[item[0]]}" + "}"
        r[item[1]] = r"\textcolor{" + f"{t}" + "}" + "{" + f"{s[item[1]]}" + "}"
    return r


def sign(s):
    r = []
    asd = 0
    for item in s:
        r.append(item)
        if dolar(asd):
            if item == "+":
                r[-1] = r"\textcolor{MaterialRed900}{+}"
            elif item == "-":
                r[-1] = r"\textcolor{MaterialBlue900}{-}"
            elif item == "=":
                r[-1] = r"\textcolor{MaterialYellow900}{=}"
            elif item == "\\vert":
                r[-1] = r"\textcolor{MaterialPurple900}{\vert}"
            elif item == "\\mid":
                r[-1] = r"\textcolor{MaterialPurple900}{\mid}"
            elif item == "\\wedge":
                r[-1] = r"\textcolor{MaterialRed900}{\wedge}"
            elif item == "\\lor":
                r[-1] = r"\textcolor{MaterialBlue900}{\lor}"
            elif item == "\\vdash":
                r[-1] = r"\textcolor{MaterialPurple900}{\vdash}"
        asd = asd + 1

    return r


# In[14]:


def comeback(s):
    e = ""
    for item in s:
        e = e + item
    b = e.split("\n")
    return b


# In[15]:


x = faq(f, lla)
print("Done with llaves")
y = faq(x, cor)
print("Done with corchetes")
z = faq(y, par)
print("Done with parentesis")
z = faq(z, big)
z = faq(z, bigg)
z = faq(z, Big)
z = faq(z, Bigg)
tt = sign(z)
t = comeback(tt)
print("Regresando a la normalidad")
with open(f"{tb}.tex", "w") as rt:
    for line in t:
        rt.write(line + "\n")

# In[ ]:


# In[ ]:
