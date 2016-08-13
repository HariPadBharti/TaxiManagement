#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<graphics.h>
#include<dos.h>
class driver{
char dname[10];
int phone_num;

public:
static int charge;
driver(char a[],int b){
strcpy(dname,a);
phone_num=b;
}
};
int driver::charge=200;
class car{
protected:
int rate;
int duration;
driver *d;
int night;
public:
virtual int fare()=0;
car(int a,int b,driver *c,int e){
rate=a;
duration=b;
d=c;
night=e;
}

};
class tour{
car *c[5];
int count;
static const int max;
public:
tour(){
count=0;
}


void addcar(car *c1);
int totalfare();
};
const int tour::max=5;
void tour::addcar(car *c1)
{
if(count<max){
c[count]=c1;
count++;

}

else
cout<<"beyond limit";
}
int tour::totalfare(){
int total=0;
int i;
int ff;
for(i=0;i<count;i++)
{
ff=c[i]->fare();
total=total+ff;
}
return(total);
}
class fourseater:public car{

public:
int fare();
fourseater(int a,int b,driver *c,int e):car(a,b,c,e){

}

};
int fourseater::fare(){
int p;
p=rate*duration+night*d->charge;
return p;
}

class sevenseater:public car{

public:
int fare();
sevenseater(int a,int b,driver *c,int e):car(a,b,c,e){}

};
int sevenseater::fare(){
int p;
p=rate*duration+night*d->charge;
return p;
}

class nineseater:public car{

public:
int fare();
nineseater(int a,int b,driver *c,int e):car(a,b,c,e){

}

};
int nineseater::fare(){
int p;
p=rate*duration+night*d->charge;
return p;
}
class bill
{
 float total;
 float tax;
 public:
 int cal(int a,int b,int c)
 {
  tax=0.125;
  total=((a+b+c)*tax)+(a+b+c);
  return total;
 }
};

class user{
int uid;
char uname[10];
int age;
char address[20];
int phone_num;
tour *t[3];
int count;
public:
user(int a,char b[],int c,char d[],int e){
count=0;
uid=a;
strcpy(uname,b);
age=c;
strcpy(address,d);
phone_num=e;
}
void addtour(tour *a){
if(count<3){
t[count]=a;
count++;
}
}
void getbill(){
bill bb;
cout<<"uid:"<<uid<<"\n";
cout<<"customer name:"<<uname<<"\n";
int x,y,z;
float tot;
if(count==0){
cout<<"no tour added"<<"\n";
}
if(count==1){
x=t[0]->totalfare();
y=0;
z=0;
tot=bb.cal(x,y,z);
cout<<"tour 1 "<<x<<"\n";
cout<<"total amount inclusive tax : "<<tot<<"\n";
}
if(count==2){
x=t[0]->totalfare();
y=t[1]->totalfare();
z=0;
tot=bb.cal(x,y,z);
cout<<"tour 1 "<<x<<"\n";
cout<<"tour 2 "<<y<<"\n";
cout<<"total amount inclusive tax"<<tot<<"\n";
}
if(count==3){
x=t[0]->totalfare();
y=t[1]->totalfare();
z=t[2]->totalfare();
tot=bb.cal(x,y,z);
cout<<"tour 1 "<<x<<"\n";
cout<<"tour 2 "<<y<<"\n";
cout<<"tour 3 "<<z<<"\n";
cout<<"total amount inclusive tax"<<tot<<"\n";
}

}
};


/*
class employee{
int eid;
char ename[10];
user *u[5];
public:
void adduser(int a,char b[],int c,char d[],int e){
for(i=0;i<5;i++){
if(u[i]==NULL){
user *u[i]=new user(a,b,c,d,e);
}
}
}
};
*/

void load()
{

 clrscr();
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"C:\Docume~1\TC\bin");
 for(int i=0;i<150;i++)
 {

  rectangle(200,200,500,250);
  //gotoxy(10,9);
  //textcolor(RED + BLINK);
  setcolor(RED);
  settextstyle(0,HORIZ_DIR,4);
  outtextxy(200,150,"Loading...");
  setcolor(WHITE);
  line(200+i+i,200,200+i+i,250);
  //gotoxy(10+i,10);
  //cprintf("||");
  delay(10);
 }
 for(i=0;i<15;i++)
 {
 delay(100);
 setcolor(i);
 settextstyle(0,HORIZ_DIR,2);
 outtextxy(200,350,"Press any key to continue");
 }
 getch();
 setcolor(15);
 cleardevice();
 setbkcolor(12);
 int jj=16;
 for(int j=0;j<=15;j++)
 {
 rectangle(10,10,630,470);
 settextstyle(0,HORIZ_DIR,4);
 delay(100);
 setcolor(jj);
 outtextxy(200,50,"WELCOME");
 outtextxy(205,100,"  TO   ");
 outtextxy(208,150," TAXI ");
 outtextxy(154,200,"MANAGEMENT");
 outtextxy(208,250,"SYSTEM");
 settextstyle(0,HORIZ_DIR,0);
 delay(100);
 setcolor(j);
 outtextxy(100,342,"==========");
 outtextxy(100,350,"CODED BY:-");
 outtextxy(100,358,"==========");
 outtextxy(100,368,"HARIPAD BHARTI    11103477");
 
 jj--;
 }
 getch();
}



void main()
{
load();
cleardevice();
//clrscr();
int x,y;
int choice;
int choice1;
int a;
char b[10];
int c;
char d[20];
int e;
cout<<"enter uid"<<"\n";
cin>>a;
cout<<"enter username"<<"\n";
cin>>b;
cout<<"enter age"<<"\n";
cin>>c;
cout<<"enter address"<<"\n";
cin>>d;
cout<<"enter phone number"<<"\n";
cin>>e;
user *u;
u=new user(a,b,c,d,e);
tour *t=new tour();
driver *d1=new driver("satish",1234);
driver *d2=new driver("sunil",9899);
driver *d3=new driver("sunny",9582);
while(1){
a:
cout<<"enter 1 to add tour "<<"\n";
cout<<"enter 2 to getbill"<<"\n";
cout<<"enter 3 to exit"<<"\n";
cout<<"enter choice"<<"\n";
cin>>choice1;
switch(choice1){
case 1:
u->addtour(t);
while(1){
cout<<"you can add at max 3 cars"<<"\n";
cout<<"enter 1 to add a fourseater car"<<"\n";
cout<<"enter 2 to add a sevenseater car"<<"\n";
cout<<"enter 3 to add a nineseater car"<<"\n";
cout<<"enter 4 to view to totalfare"<<"\n";
cout<<"enter 5 to go to previous menu"<<"\n";
cout<<"enter choice"<<"\n";
cin>>choice;
switch(choice){
case 1:
cout<<"Rate of a fourseater car is 8 R.s per km"<<"\n";
cout<<"enter total distance"<<"\n";
cin>>y;
cout<<"enter total nights"<<"\n";
cin>>x;
fourseater *c1=new fourseater(8,y,d1,x);
t->addcar(c1);
break;

case 2:
cout<<"Rate of a sevenseater car is 10 R.s per km"<<"\n";

cout<<"enter total distance"<<"\n";
cin>>y;
cout<<"enter total nights"<<"\n";
cin>>x;
sevenseater *c2=new sevenseater(10,y,d2,x);
t->addcar(c2);
break;

case 3:
cout<<"Rate of a nineseater car is 12 R.s per km"<<"\n";

cout<<"enter total distance"<<"\n";
cin>>y;
cout<<"enter total nights"<<"\n";
cin>>x;
nineseater *c3=new nineseater(12,y,d3,x);

t->addcar(c3);
break;

case 4:
x=t->totalfare();
cout<<"\n"<<x<<"\n";
break;

case 5:
goto a;
default : cout<<"\n ERROR:Wrong choice";
}
}

case 2:
u->getbill();
break;

case 3:
exit(1);
break;

default: cout<<"\nERROR:Wrong choice";
}
}
}


