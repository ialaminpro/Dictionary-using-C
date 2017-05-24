
#include<stdio.h>
#include<conio.h>
//#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MAX_LONG 2147483647
#define PI 3.1415926536

char buf[80];
void output(char *);
//void OUTPUT(long double &);

//REGS in_regs,out_regs;
init_mouse(){
//	in_regs.x.ax = 0;
//	int86(0x33,&in_regs,&out_regs);
//	return out_regs.x.ax;
	}
void show_mouse(){
//	in_regs.x.ax = 1;
//	int86(0x33,&in_regs,&out_regs);
	}
int mouse_press(){
//	in_regs.x.ax = 3;
//	int86(0x33,&in_regs,&out_regs);
//	return(out_regs.x.bx);
		}

int mouse_pos( int left, int right, int top,int bottom ) {
//	in_regs.x.ax = 3;
//	int86(0x33,&in_regs,&out_regs);
//	return((out_regs.x.cx>left && out_regs.x.cx<right) &&
//	       (out_regs.x.dx>top  && out_regs.x.dx<bottom));
		}

char str[]="By Mr.Iech Setha student year I scholarship(2001-2002), department Computer Science of RUPP (Royal University of Phnom Penh).";

//void run(int &j1,int &leng){
	   settextstyle(0,0,1); setcolor(15) ;
	   setfillstyle(1,0); bar(20,450,615,425);
	   for(int i=j1;i<leng;i++){
	     if(i<strlen(str)) {
		   sprintf(buf,"%c",str[i]);
		   outtextxy(570-8*(leng-j1)+8*(i-j1),440,buf);
				}}
		if(leng>60) j1++;
		if(leng<=strlen(str)+60) leng++;
		else { leng = j1 = 0; }
	     }

void OutPut( double &);

void drBox(int x,int y,int x1,int y1,int width,int color,int color1)
     { for(int i=0;i<width;i++)
	    { setcolor(color); line(x+i,y+i,x+i,y1-i);
			       line(x+i,y+i,x1-i,y+i);
	      setcolor(color1);line(x+i,y1-i,x1-i,y1-i);
			       line(x1-i,y+i,x1-i,y1-i); }
     }
void Box(){
	drBox(202,145,458,171,2,8,15);
	drBox(205,190,230,215,2,8,15);
	for(int i=0;i<3;i++)drBox(245+70*i,188,310+70*i,218,2,15,8);
	for(i=0;i<4;i++)    drBox(203,230+35*i,235,260+35*i,2,15,8);
	for(i=0;i<4;i++)
	for(int j=0;j<5;j++)drBox(250+40*j,230+35*i,285+40*j,260+35*i,2,15,8);
	}
void main(){
	  int gdriver = DETECT, gmode, errorcode;
	int i ,run1=0, run2=0;
	int a,k=0,l,i1=0,i2,k1=0 ,length , result=0,th=0,step;
	int d[30] , Back=0 ,index = 0, NamePoint=0,ind=0,mcl=0;
	long double p=0, b[2] = {0,0}, t ;
	char NumBer[30],*num[30],ch,buf[80];

	/* initialize graphics mode */
	initgraph(&gdriver, &gmode, "C:\\TC\\BGI");

	/* read result of initialization */
	errorcode = graphresult();

	if (errorcode != grOk)  /* an error occurred */
	{
	   printf("Graphics error: %s\n", grapherrormsg(errorcode));
	   printf("Press any key to halt:");
	   getch();
	   exit(1);             /* return with error code */
	}


	NumBer[index] = '\0' ;
	setbkcolor (0) ; settextstyle (1,HORIZ_DIR,2) ;
	setcolor (15) ;
	outtextxy (156,20,"ROYAL UNIVERSITY OF PHNOM PENH") ;
	setcolor (1) ;
	outtextxy (154,22,"ROYAL UNIVERSITY OF PHNOM PENH") ;
	setcolor (4) ;
	settextstyle (0,0,1) ; drBox (198,98,462,382,2,15,8) ;
	setfillstyle (1,7)   ; bar(200,100,460,380) ;
	setfillstyle (1,1)   ; bar(202,102,458,125) ;
	setcolor (1) ;
	char ss[90]  ;
	for (i=0 ; i<3 ; i++)
	for (int j=0 ; j<3 ; j++)
	    {
	    sprintf (ss,"%d",(1+j)+3*i) ;
	    outtextxy (265+40*j,242+35*(2-i),ss) ;
	    }
	outtextxy (265,347,"0")   ; outtextxy (297,347,"+/-") ;
	outtextxy (345,347,".")   ; outtextxy (415,313,"1/x") ;
	outtextxy (425,278,"x�")  ; outtextxy (421,243,"�")   ;
	setcolor (4)              ; outtextxy (250,200,"Bkspace") ;
	outtextxy (340,200,"CE")  ; outtextxy (414,200,"C")   ;
	outtextxy (208,243,"Bin") ; outtextxy (208,278,"log") ;
	outtextxy (208,313,"sin") ; outtextxy (208,348,"cos") ;
	outtextxy (385,347,"+")   ; outtextxy (385,313,"-")   ;
	outtextxy (385,278,"x")   ; outtextxy (385,243,"/")   ;
	outtextxy (425,347,"=")   ;
	setcolor (15) ;
	outtextxy (207,110,"Calculator") ;
	setfillstyle (1,7) ; bar (435,105,450,120) ;
	drBox (435,105,450,120,2,15,8) ;
	setcolor (0) ; outtextxy (440,109,"x") ;
	setfillstyle (1,15) ; bar(204,147,456,169) ;
	outtextxy (440,156,"0.") ;
   while(1)
	{t: Box(); show_mouse () ;
	  run(run1,run2);
	  delay(200);
	  if (mouse_pos(435,450,105,120))
		{if(mouse_press ()==1)
		 { while (mouse_press ()==1)
		     { drBox (435,105,450,120,2,8,15) ; }
		   if(mouse_pos(435,450,105,120)) goto stop;
		   else drBox (435,105,450,120,2,15,8);
		  }  /*Click to exit program*/
		}
	  while(kbhit()){
		ch=getch();
		if(ch>47 && ch<58){
		    if(ch==48) drBox(250,335,285,365,2,8,15) ;
		    if(ch==49) drBox(250,300,285,330,2,8,15) ;
		    if(ch==50) drBox(290,300,325,330,2,8,15) ;
		    if(ch==51) drBox(330,300,365,330,2,8,15) ;
		    if(ch==52) drBox(250,265,285,295,2,8,15) ;
		    if(ch==53) drBox(290,265,325,295,2,8,15) ;
		    if(ch==54) drBox(330,265,365,295,2,8,15) ;
		    if(ch==55) drBox(250,230,285,260,2,8,15) ;
		    if(ch==56) drBox(290,230,325,260,2,8,15) ;
		    if(ch==57) drBox(330,230,365,260,2,8,15) ;
		    delay(20); NumBer[index]=char(ch);
		    if(ch==48)!index ? index:index++;
		    else index++;
		    NumBer[index]='\0';
		    if(result) k = 0 ;
				}
		else if(ch==46){drBox(330,335,365,365,2,8,15) ;delay(20);
			 if(NamePoint==0) { NumBer[index]='.'; index++;
					    NumBer[index]='\0';}
			 else { sound(1000); delay(30); nosound();}
			 if(index==1){ NumBer[index]='.';
				       NumBer[index-1]='0';index++;
				       NumBer[index]='\0';}
			 NamePoint = 1;
			 if(result) k = 0 ;}
		else if(ch==27){ drBox(385,188,450,218,2,8,15) ;delay(20);
			 k = 0 ; i1 = 0 ; index = 0 ; NamePoint=0;
			 NumBer[index]='\0'; k1=0;
			 if(result) k = 0 ;
			   }
		else if(ch==42||ch==43||ch==45||ch==47){
			 if(ch==43){drBox(370,335,405,365,2,8,15); k=1;}
			 if(ch==45){drBox(370,300,405,330,2,8,15);k=2;}
			 if(ch==42){drBox(370,265,405,295,2,8,15);k=3;}
			 if(ch==47){drBox(370,230,405,260,2,8,15);k=4;}
			 delay(20);b[1]= !p ? _atold(NumBer) : p;
			 index = 0; NumBer[index]='\0' ;
			 NamePoint = 0 ; i1 = 0 ; k1=0;
			 result = 0;
			 goto tha; }
		else if(ch==8){ drBox(245,188,310,218,2,8,15) ;delay(20);
			 if(result==0)
			  { if (index>0) index-- ;
			    if(NumBer[index]=='.') NamePoint = 0 ;
			    NumBer[index] = NULL ; }
			 else goto tha ;
			   }
		else if(ch==13){drBox(410,335,445,365,2,8,15) ;delay(20);
			 i1++ ; index=0; NamePoint = 0 ;
			 if (i1==1 && k!=0)
			    { t = p ; p = b[1] ; b[1] = t ; }
			     if (k==1) p = p + b[1] ;
			     if (k==2) p = p - b[1] ;
			     if (k==3) p = p * b[1] ;
			     if (k==4) p = (double)p / b[1] ;
			 OUTPUT (p) ; index=0;
			 NumBer[index] = NULL ;
			 result = 1 ;
			 goto tha;
			 }
		else if(ch==107) goto stop;
		else goto tha;
		result = 0 ; p=_atold(NumBer);
		output(NumBer);
		tha:}

	  for(i=0;i<3;i++) for(j=0;j<3;j++)
	  if (mouse_pos(250+40*i,285+40*i,230+35*j,260+35*j)||
	      mouse_pos(250,285,335,365)||mouse_pos(330,365,335,365))
	      { if(mouse_press()==1)
		{while (mouse_press()==1)
		   {if(mouse_pos(250,285,335,365))
		     { drBox(250,335,285,365,2,8,15) ; ;
		       NumBer[index]='0'; NumBer[index+1]='\0';
		       if(result) k = 0 ; } /*Number 0*/
		    if (mouse_pos(250+40*i,285+40*i,230+35*j,260+35*j))
		     {  drBox(250+40*i,230+35*j,285+40*i,260+35*j,2,8,15) ;
			NumBer[index]=55-j*3+i; NumBer[index+1]='\0';
			if(result) k = 0 ; }
		    if (mouse_pos(330,365,335,365))
		     { drBox(330,335,365,365,2,8,15) ;
			 if(NamePoint==0) { NumBer[index]='.'; index=ind+1;
					    NumBer[index]='\0'; }
			 if(index==1){ NumBer[index]='.';
				       NumBer[index-1]='0';index+=1;
				       NumBer[index]='\0';
				       }
			 mcl = 1 ;if(result) k = 0 ;NamePoint=1; } /*Key '.'*/
				}
		if(Back==3) goto skip ;
		result=0 ;p=_atold(NumBer);
		output(NumBer);
	    if(NumBer[0]=='\0'||(NumBer[0]=='0'&&NumBer[1]!='.'))index = 0;
	    else {if(Back == 0){ if(mcl!=1) index++; }
		  else { if(index>0) index--; }}
	  skip:ind = index; Back = 0; mcl=0;}
		    }

	  if(mouse_pos(245,310,188,218)|| mouse_pos(385,450,188,218)||
	     mouse_pos(315,380,188,218))
	       {if(mouse_press()==1){
		while(mouse_press()==1){
		  if (mouse_pos(385,450,188,218)||mouse_pos(315,380,188,218))
		     {if(mouse_pos(385,450,188,218))
			 drBox(385,188,450,218,2,8,15);
		      if (mouse_pos(315,380,188,218))
			  drBox(315,188,380,218,2,8,15) ;
		      delay(20); k = 0 ; i1 = 0 ; index = 0 ;
		      NamePoint=0; NumBer[index]='\0'; k1=0 ; }
		    if (mouse_pos(245,310,188,218))
		     { drBox (245,188,310,218,2,8,15) ;
		       if (result==0) { Back = 1 ;
			   if(NumBer[index-1]=='.')  NamePoint = 0 ;
			    NumBer[index-1] = NULL ; }
		       else Back = 3 ;
			 } /*Click Back Space*/
			}
		if(Back==3) goto skip1 ;
		result = 0 ; p =_atold(NumBer);
		output(NumBer);
	    if(NumBer[0]=='\0'||(NumBer[0]=='0'&&NumBer[1]!='.'))index = 0;
	    else {if(Back == 0){ if(mcl!=1) index++; }
		  else { if(index>0) index--; }}
	  skip1:ind = index; Back = 0; mcl=0;}
		    }

	  for(i=0;i<4;i++)
	  if(mouse_pos(370,405,230+35*i,260+35*i))
	      { if (mouse_press()==1){i1 = 0 ;
	       while (mouse_press()==1)
	       {if (mouse_pos(370,405,230+35*i,260+35*i))
		 { drBox (370,230+35*i,405,260+35*i,2,8,15) ;
		   index = 0 ; k = 4-i ; NumBer[index]='\0' ;
		   NamePoint = 0 ; i1 = 0 ;k1=0; }  /*Click +, -, *, / */
		}
	   b[1]= !p ? _atold(NumBer) : p;
	   result = 0 ; }
		 }

     if (mouse_pos(290,325,335,365))
	   {if(mouse_press ()==1)
	   { k1++; length=strlen(NumBer);
	   while(mouse_press ()==1)
	   { drBox (290,335,325,365,2,8,15); }
       if(!result) {
	if(length)
	    {if(k1==1){
	       index=strlen(NumBer)+1;
	       NumBer[index]=NULL;
	      for(i=0;i<length;i++)
		NumBer[length-i]=NumBer[length-i-1];
		NumBer[0]='-';
		      }
	     if(k1==2) {
		for(i=0;i<strlen(NumBer);i++)
			NumBer[i]=NumBer[i+1];
			k1=0; index--;}
			}
	   p=_atold(NumBer); output(NumBer); }
       else { p = -p ; OUTPUT(p) ; k1 = 0 ;}
	   } drBox (290,335,325,365,2,15,8) ;
	   }  /* Click +/- */

	 for(i=0;i<2;i++) for(j=0;j<3;j++)
	  if(mouse_pos(410-207*i,445-210*i,230+35*(j+i),260+35*(i+j)))
	      {if (mouse_press()==1)
		{ i1=0 ;
		while (mouse_press()==1)
		{if(mouse_pos(410-207*i,445-210*i,230+35*(j+i),260+35*(i+j)))
		    {drBox(410-207*i,230+35*(j+i),445-210*i,260+35*(i+j),2,8,15);
		     th=(i*3)+(j+1);}
		 }
	       if (p>=0 && th==1) p = sqrt (p) ;
	       if (p!=0 && th==3) p = 1 / p ;
	       if (th==2) p = p * p ;
	       if (th==4 && p>0) p = log10 (p) ;
	       if (th==5) p = sin(PI * p / 180) ;
	       if (th==6) p = cos(PI * p / 180) ;
		    result = 1 ;
		    OUTPUT (p) ;
		    k = 0 ; i1 = 0 ; NamePoint=0;
		    index=0;  NumBer[index] = NULL ;
		    }
		    }

     /*Find binary number*/
      if (mouse_pos(203,235,230,260))
	{if (mouse_press ()==1)
	  { i1 = 0 ; step=0 ;
	  while(mouse_press ()==1)
	  {
	    drBox (203,230,235,260,2,8,15) ;}
	 setfillstyle (1,15) ; bar (204,147,456,169) ;
	 setcolor (0) ;
	 if (!p) { step = 1 ; d[0] = 0 ; }
	 if (p>MAX_LONG || p<0) goto b ;
	 while (p>0)
	  { d [step] = ((long)p) % 2 ;
	    p = (long)p / 2 ; step++ ; }
	 if (step>30) goto b ;
	for(i=step-1;i>=0;i--){
	     if (i) sprintf (ss,"%d",d[i]) ;
	     else sprintf (ss,"%d.",d[i]) ;
	   outtextxy (440-8*i,156,ss) ;
	    } goto c ;
       b:  outtextxy (440,156,"E.") ;  p = 0 ;
       c:  step = 0 ;
       result = 1; NamePoint  = 0 ;
       index = 0 ; NumBer[index] = NULL  ;  k = 0 ;
	} drBox (203,230,235,260,2,15,8) ;
	}

	if (mouse_pos(410,445,335,365))
	   { if (mouse_press ()==1)
	     {while (mouse_press ()==1)
		 { drBox (410,335,445,365,2,8,15) ; }
		 i1++ ; NamePoint = 0 ;
	      if (i1==1 && k!=0) { t = p ; p = b[1] ; b[1] = t ; }
		 if (k==1) p = p + b[1] ;
		 if (k==2) p = p - b[1] ;
		 if (k==3) p = p * b[1] ;
		 if (k==4) p = (double)p / b[1] ;
		 OUTPUT (p) ; index=0; ind=0;
		 NumBer[index] = NULL ;
		 result = 1 ;
		    }}
		     }
	     stop: closegraph();
		}  /* Click '=' key*/
void OUTPUT(long double &p){
		char *num="%.0Lf.";
		long double integer,fraction;
		long modul;int cha;
	setfillstyle (1,15) ; bar (204,147,456,169) ;
	setcolor (0) ;
	fraction = modfl(p,&integer) ;
	fraction = fabsl(fraction*1000000000) ;
	modul=((long)fraction+1)/10;
      if (p < pow(2,64) / 2 && p>-pow(2,64) / 2 && p!=0)
	 {
	 if((modul%100000000)==0)    cha=0;
	 else if((modul%10000000)==0)cha=2;
	 else if((modul%1000000)==0) cha=3;
	 else if((modul%100000)==0)  cha=4;
	 else if((modul%10000)==0)   cha=5;
	 else if((modul%1000)==0)    cha=6;
	 else if((modul%100)==0)     cha=7;
	 else if((modul%10)==0)      cha=8;
	 else cha=9;
	 num[2]=48+(!cha?0:cha-1);
	 sprintf (buf,num,p) ;
	 if ((p>(long)p && p<(long)p+1) || (p<(long)p && p>long(p)-1)){
	    if (p<-1) outtextxy(440 - 8 * (1+(int)log10(fabsl(p)))-8*cha,156,buf);
	    else if (p<0) !cha ? outtextxy(440 , 156 , "0."):
				 outtextxy(440 - 8*(cha+1),156,buf) ;
	    else if (p<1) outtextxy (440 - 8*cha,156,buf) ;
	    else   outtextxy (440 - 8  * ((int)log10(p)) -8*cha,156,buf) ;
		   }
	else
	    {sprintf (buf,"%.Lf.",p) ;
	     if (p>0)outtextxy (440 - 8 * (int)log10(fabsl(p)),156,buf) ;
	     else    outtextxy (440 - 8 * ((int)log10(fabsl(p)) + 1),156,buf) ;
		}}
	 else
	    {if (p!=0){ outtextxy (440,156,"E.") ; p = 0 ; }
	     else outtextxy (440,156,"0.") ;
	    }
	    }

void output (char NumStr[])
	{
	long double p;
	setfillstyle (1,15) ; bar (204,147,456,169) ;
	setcolor (0) ;
	if(strlen(NumStr)==0) outtextxy(440,156,"0.") ;
	if(strlen(NumStr)<19)
		{sprintf (buf,"%s.",NumStr) ;
		 outtextxy(440-8*(strlen(NumStr)-1),156,buf);}
	else outtextxy(440,156,"E.");
	    }
