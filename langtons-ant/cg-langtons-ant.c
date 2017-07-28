#include<curses.h>
#define C(x) attron(COLOR_PAIR(x))
#define L for(int i=1920;i--;)
int p=1000,d=2,m[1920];
int main(){initscr(),curs_set(0),start_color(),resize_term(24,80),init_pair(1,0,0),init_pair(2,7,7),init_pair(3,4,6);L{m[i]=0;}while(1){(m[p]<0)?(d++,d%=4):(d--,d+=4,d%=4);m[p]=~m[p];p+=(d==3)?80:((d==2)?-1:((d==1)?-80:1));L{C(m[i]+2);mvaddch(i/80,i%80,' ');}C(3);mvaddch(p/80,p%80,'@');refresh();if(getch()<9){endwin();break;}}return 0;}