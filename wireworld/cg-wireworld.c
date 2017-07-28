#include<curses.h>
#include<stdlib.h>
#include<string.h>
#define _ int
const _ f=24,g=80;
#define L for(_ i=f*g;i--;)
_ m[f*g],n[f*g];
#define Z(j,k)(m[j+k*g]==1?1:0)
_ Q(_ x,_ y){_ q=((~-x)+g)%g,w=(-~x)%g,e=((~-y)+f)%f,t=(-~y)%f;return Z(q,e)+Z(q,y)+Z(q,t)+Z(x,e)+Z(x,t)+Z(w,e)+Z(w,y)+Z(w,t);}
_ main(_ z,char **x){initscr(),clear(),refresh(),curs_set(0),start_color(),resize_term(f,g),init_pair(1,7,7),init_pair(2,6,6),init_pair(3,4,4),init_pair(4,0,0);L{m[i]=n[i]=0;}_ s=0;for(_ i=1;i<z;i++){if(!strcmp(x[i],"-")){s++;s%=3;continue;}_ o=atoi(x[i]);if(o<0||o>f*g-1){break;}m[o]=(s&1)?1:(s&2?2:3);}while(1){L{attron(COLOR_PAIR(-~m[i]));mvaddch(i/g,i%g,' ');}L{n[i]=m[i]?(m[i]==1?2:(m[i]==2?3:(Q(i%g,i/g)==1?1:(Q(i%g,i/g)==2?1:3)))):0;}L{m[i]=n[i];}if(getch()<9){endwin();break;}}return 0;}