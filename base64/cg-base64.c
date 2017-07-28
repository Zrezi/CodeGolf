#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#define _ int
#define s size_t
#define w uint8_t
#define Z(x) ((w)(n>>x)&63)
#define Y if(i/t)
#define U return 1
#define S 66
static const w D[]={S,S,S,S,S,S,S,S,S,S,64,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,62,S,S,S,63,52,53,54,55,56,57,58,59,60,61,S,S,S,65,S,S,S,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,S,S,S,S,S,S,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S};
static const w Q[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
_ d(char *k, s l, w *o, s *t){char *e=k+l;char i=0;uint32_t b=0;s n=0;while(k<e){w c=D[*k++];switch(c){case 64:continue;case 66:U;case 65:k=e;continue;default:b=b<<6|c;i++;if(i&4){if((n+=3)>*t)U;*(o++)=(b>>16)&255;*(o++)=(b>>8)&255;*(o++)=b&255;b=0,i=0;}}}if(i==3){if((n+=2)>*t)U;*(o++)=(b>>10)&255;*(o++)=(b>>2)&255;}else if(i==2) {if(++n>*t)U;*(o++)=(b>>4)&255;}*t=n;*o=0;return 0;}
_ e(const void *b, s l, char *r, s t){const w *d=(const w*)b;s i=0,x;int32_t n=0;_ p=l%3;w e,f,g,h;for(x=0;x<l;x+=3){n=((uint32_t)d[x])<<16;n+=(x+1<l)?((uint32_t)d[x+1])<<8:0;n+=(x+2<l)?d[x+2]:0;e=Z(18);f=Z(12);g=Z(6);h=Z(0);Y U;r[i++]=Q[e];Y U;r[i++]=Q[f];if((x+1)<l){Y U;r[i++]=Q[g];}if((x+2)<l){Y U;r[i++]=Q[h];}}if(p){for(;p<3;p++){Y U;r[i++]='=';}}Y U;r[i]=0;return 0;}
_ main(){const char *v="Testing Base64 Encode";printf("Original: %s\n", v);getchar();s size=strlen(v);char o[1000];e(v,size,o,1000);printf("Encoded: %s",o);getchar();s n=1000;w *b=(w*)malloc(n);d(o,strlen(o),b,&n);printf("Decoded: %s\n",b);getchar();free(b);return 0;}