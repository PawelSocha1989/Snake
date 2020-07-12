#include "zmienne.h"
waz::waz()
{
x = 100;
y = 100;
frame2 = 0;
ogon_h=30;
ogon_w=30;
glowa1_w=30;
glowa1_h=30;
rozmiar=0;
xx=0;
yy=0;
tx=1;
ty=1;
dodano=false;
}

waz::~waz()
{
}
void waz::loadw()
{
    bufor2= create_bitmap(640,480);
    bufor = create_bitmap(640,480);
    glowa1 = load_bmp("glowa1.bmp",default_palette);
    glowa2 = load_bmp("glowa2.bmp",default_palette);
    glowa3 = load_bmp("glowa3.bmp",default_palette);
    glowa4 = load_bmp("glowa4.bmp",default_palette);
    koniecgry = load_bmp("koniecgry.bmp",default_palette);
    ogon = load_bmp("ogon.bmp",default_palette);
}
void waz::losuj()
{
    clear_to_color(bufor, makecol(0,0,0));
    xx = rand() %  600;
    yy = rand() %  400;
    masked_blit(ogon,bufor,0,0,xx,yy,ogon_w,ogon_h);
}

void waz::destroy3()
{
    destroy_bitmap(glowa1);
    destroy_bitmap(glowa2);
    destroy_bitmap(glowa3);
    destroy_bitmap(glowa4);
    destroy_bitmap(koniecgry);
}
void waz::oblicz(int x, int y,int s)
{
if( ((ogony[0].x-x)>30) || ((x-ogony[0].x)>30) || ((ogony[0].y-y)>30) || ((y-ogony[0].y)>30) )
{
waz::sogon tempik[100];
tempik[0]=ogony[rozmiar-1];
for(int i=1;i<rozmiar;i++)
	tempik[i]=ogony[i-1];

switch (s)
        {
          case 3:
            x+=10;
            break;
          case 7:
            x-=10;
            break;
        case 5:
            y+=10;
            break;
        case 1:
        y-=10;
        break;
        };
    tempik[0].x=x;
    tempik[0].y=y;
for(int i=0;i<rozmiar;i++)
	ogony[i]=tempik[i];
}
}
waz::sogon waz::dodajogon(waz::sogon ble)
{
    waz::sogon t;
    t.x=ble.x;
    t.y=ble.y;
    dodano=true;
    waz::losuj();
    return t;
}
bool waz::kolizja1(int x1,int y1,int s1,int w1,int x2,int y2,int s2,int w2)
{
     if( x2<=x1+s1 && x2>x1 && y2>=y1 && y2<=y1+w1) return true; else
     if( x2<=x1+s1 && x2>x1 && y2+w2>=y1 && y2+w2<=y1+w1) return true; else
     if( x2+s2<=x1+s1 && x2+s2>x1 && y2>=y1 && y2<=y1+w1) return true; else
     if( x2+s2<=x1+s1 && x2+s2>x1 && y2+w2>=y1 && y2+w2<=y1+w1) return true;
     else return false;
};
bool waz::kolizja2(int x,int y)
{
for(int i=1;i<rozmiar;i++)
	if( ((ogony[i].x+30)>x) && ((ogony[i].x-30)<x) && ((ogony[i].y+30)>y) && ((ogony[i].y-30)<y) )
		return true;
	return false;
};
bool waz::glowa()
{
    bool end=false;
    while(!key[KEY_ESC])
{
    rest(3);
if( key[KEY_LEFT]) { frame2=3;}
if( key[KEY_RIGHT]){ frame2=7;}
if( key[KEY_UP])   { frame2=5;}
if( key[KEY_DOWN]){ frame2=1;}
if( frame2 > 8) frame2=0;


clear_to_color(bufor2, makecol(0,0,0));
masked_blit(bufor,bufor2,0,0,0,0,640,480);
if( frame2<2 ) {tmp = glowa1; y++; }
if(end)
{
    rest(3000);
    return false;
}
if((y+1)>=420){clear_to_color(bufor2, makecol(0,0,0)); masked_blit( koniecgry, bufor2, 0,0, 200, 200, koniecgry->w,koniecgry->h); end=true;}

else if( frame2>=2 && frame2<4) {tmp = glowa2; x--;}

if( (x+1)<0){clear_to_color(bufor2, makecol(0,0,0)); masked_blit(koniecgry, bufor2, 0,0, 200, 200, koniecgry->w,koniecgry->h);end=true;}

else if( frame2>=4 && frame2<6) {tmp =glowa3; y--;}

if( (y+1)<0){clear_to_color(bufor2, makecol(0,0,0)); masked_blit(koniecgry, bufor2, 0,0, 200, 200, koniecgry->w,koniecgry->h);end=true;}

else if(frame2>=6 && frame2<8) {tmp = glowa4; x++;}

if((x+1)>=640){ clear_to_color(bufor2, makecol(0,0,0)); masked_blit(koniecgry, bufor2, 0,0, 200, 200, koniecgry->w,koniecgry->h);end=true;}

if( kolizja1( xx,yy,ogon_w,ogon_h,x,y,glowa1_w,glowa1_h)==true)
{ if(rozmiar!=0){ogony[rozmiar]=dodajogon(ogony[rozmiar-1]);}
else {sogon t; t.x=30; t.y=30; ogony[rozmiar]=dodajogon(t); }
rozmiar++;}

masked_blit(tmp, bufor2, 0,0, x, y, glowa1_w,glowa1_h);
if(rozmiar!=0)
    oblicz(x,y,frame2);
for(int i=0;i<rozmiar;i++)
masked_blit(ogon,bufor2,0,0,ogony[i].x,ogony[i].y, ogon_w,ogon_h);
textprintf_ex(bufor2,font,200,40,makecol(255,255,255),-1,"%d",rozmiar);


if(kolizja2(x,y)&&(rozmiar!=2))
{
clear_to_color(bufor2, makecol(0,0,0));
masked_blit(koniecgry, bufor2, 0,0, 200, 200, koniecgry->w,koniecgry->h);
end=true;
}
masked_blit(bufor2,screen,0,0,0,0,640,480);
}}
