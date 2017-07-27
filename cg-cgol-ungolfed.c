#include<time.h>
#include<stdlib.h>
#include<curses.h>
#define _ int
#define L for(_ i=1920;i--;)
#define U o[i]
#define Z(j,k)(c[j+k*h])
_ c[1920],o[1920],i,h=80;

_ n(_ x,_ y){_ q=((~-x)+h)%h,w=(-~x)%h,e=((~-y)+24)%24,t=(-~y)%24;return Z(q,e)+Z(q,y)+Z(q,t)+Z(x,e)+Z(x,t)+Z(w,e)+Z(w,y)+Z(w,t);}

_ main()
{
	initscr(),resize_term(24,h),srand(time(NULL));
	L{c[i]=rand()%2?1:0;U=0;}
	while(1){
		clear();
		L{_ q=n(i%h,i/h);(c[i])?((q<2)?U=0:(q<4)?U=1:U=0):(q==3)?U=1:0;}
		L{c[i]=U,mvaddch(i/h,i%h,(c[i]?48:32));}
		if(getch()<9){endwin();break;}
	}
	return 0;
}