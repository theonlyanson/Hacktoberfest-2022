from tkinter import *
from random import randint

class Path:
    def __init__(self,root):
        ##OTHER FUNCTIONS##
        def cr(can,x,y):
            r=4
            can.create_oval(x-r,y-r,x+r,y+r,fill='#FFFFFF',outline='#FFFFFF')

        def factorial(n):
            x=1
            for i in range(1,n+1):
                x=x*i
            return x
        def dis(x,y,x2,y2):
            d=((x-x2)**2+(y-y2)**2)**0.5
            return d
        buff=200
        self.lx=600
        self.ly=600
        self.can=Canvas(root,width=self.lx+buff,height=self.ly+buff,bg='#000000')
        self.can.pack()
        ##DOTS##
        self.siz=9
        sizf=factorial(self.siz)
        self.it=(1/sizf)*100
        self.a=[]
        for i in range(self.siz):
            self.a.append(i)
        self.px=[]
        self.py=[]
        self.bco=[]
        self.cco=[]
        for i in range(self.siz):
            x=randint(0+buff/2,self.lx+buff/2)
            y=randint(0+buff/2,self.ly+buff/2)
            self.px.append(x)
            self.py.append(y)
            cr(self.can,x,y)
        self.perd=0
        tot=0
        for i in range(len(self.a)-1):
            s=self.a[i]
            tot+=dis(self.px[self.a[i]],self.py[self.a[i]],self.px[self.a[i+1]],self.py[self.a[i+1]])
        self.small=tot
        for i in range(len(self.a)-1):
            self.bco.append(self.can.create_line(self.px[self.a[i]],self.py[self.a[i]],self.px[self.a[i+1]],self.py[self.a[i+1]],fill='#00FF00',width=5))
            self.cco.append(self.can.create_line(self.px[self.a[i]],self.py[self.a[i]],self.px[self.a[i+1]],self.py[self.a[i+1]],fill='#BB00BB',width=3))
        self.per=self.can.create_text(400,720,text='0.0%',fill='#FFFFFF')
    def next(self):
        def dis(x,y,x2,y2):
            d=((x-x2)**2+(y-y2)**2)**0.5
            return d

        def swap(a,x,y):
            temp=a[x] ; a[x]=a[y] ; a[y]=temp
            return a

        def cut(a,x):
            z=[]
            for i in range(x+1):
                z.append(a[i])
            return z

        def rev(a,x):
            z=[]
            for i in range(x+1,len(a)):
                z.append(a[i])
            z.reverse()
            a=cut(a,x)
            a+=z
            return a

        def lexi(a):
            x=-1
            for i in range(len(a)-1):
                if a[i]<a[i+1]:
                    if x==-1:
                        x=i
                    elif i>x:
                        x=i
            if x==-1:
                return False
            for i in range(x+1,len(a)):
                if a[x]<a[i]:
                    y=i
            a=swap(a,x,y)
            a=rev(a,x)    
            return a


        def condis(a,px,py):
            tot=0
            for i in range(len(a)-1):
                tot+=dis(px[a[i]],py[a[i]],px[a[i+1]],py[a[i+1]])
            return tot
        self.a=lexi(self.a)
        if self.a!=False:
            x=condis(self.a,self.px,self.py)

            if x<self.small:
                self.small=x
                self.b=list(self.a)
                self.crb=self.con(self.b,self.px,self.py,'#00FF00',self.small)
            else:
                self.crn=self.con(self.a,self.px,self.py,'#BBBBBB',self.small)
        else:
            global m
            m=False

    def con(self,a,px,py,b,small):
        if b=='#00FF00':
            for i in range(len(a)-1):
                self.can.coords(self.bco[i],px[a[i]],py[a[i]],px[a[i+1]],py[a[i+1]])
        else:
            for i in range(len(a)-1):
                self.can.coords(self.cco[i],px[a[i]],py[a[i]],px[a[i+1]],py[a[i+1]])
        self.perd+=self.it
        self.can.itemconfig(self.per, text=('Length',round(small,0),'Complete',round(self.perd,2),'%'))



# initialize root Window and canvas
root = Tk()
root.title("Traveling Sales Person")

'''
#SETTINGS WINDOW
sett = Tk()
sett.title('Settings')
siz= StringVar()
ent= Entry(sett,textvariable=siz)
ent.grid(1,0)
label1=Label(sett,text='Number of nodes:')
label1.grid(0,0)
'''


# create two path objects and animate them
path=Path(root)
m=True
while m!=False:
    path.next()
    root.update_idletasks()
    root.update()

root.mainloop()
