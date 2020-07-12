#include "zmienne.h"

menu::menu()
{
    frame=0;
}

menu::~menu()
{
}

void menu::load()
{
    bufor = create_bitmap(640, 480);
    bufor2 = create_bitmap(640, 480);
    tlo_menu = load_bmp("tlo_menu.bmp",default_palette);
    menu1 = load_bmp("menu1.bmp",default_palette);
    menu3 = load_bmp("menu3.bmp",default_palette);
    menu4 = load_bmp("menu4.bmp",default_palette);
    menu6 = load_bmp("menu6.bmp",default_palette);

}
void menu::destroy2()
{
    destroy_bitmap(bufor);
    destroy_bitmap(bufor2);
    destroy_bitmap(tlo_menu);
    destroy_bitmap(menu1);
    destroy_bitmap(menu3);
    destroy_bitmap(menu4);
    destroy_bitmap(menu6);
}
void menu::menu_tlo()
{
	clear_to_color(bufor2, makecol(255,0,255));
	masked_blit(tlo_menu, bufor2, 0,0,0,0, tlo_menu->w, tlo_menu->h);
	masked_blit(menu1, bufor2, 0,0,300,30, menu1->w, menu1->h);
	masked_blit(menu3, bufor2, 0,0,310,230, menu3->w, menu3->h);
}
void menu::menu_glowne()
{
    waz *wezyk;

    while(1)
    {
        menu::menu_tlo();
		rest(100);
		if (key[KEY_UP]) frame--;
		if (frame < 0) frame = 1;
		if (key[KEY_DOWN]) frame++;
		if( frame > 1) frame = 0;
		clear_to_color(bufor, makecol(150, 150, 150));
		masked_blit( bufor2, bufor, 0,0,0,0, 640, 480);

		if(frame == 0) 
		{ 
			draw_sprite(bufor, menu4, 300, 30); 
			if(key[KEY_ENTER])
			{
				wezyk = new waz();
				wezyk->loadw();
				wezyk->losuj();
				wezyk->glowa();
				masked_blit(bufor2,screen,0,0,0,0, 640, 480);
			}
		}
		else if(frame == 1) 
		{ 
			draw_sprite(bufor, menu6, 310, 230); 
			if(key[KEY_ENTER]) 
				exit(1);
		}
		masked_blit(bufor, screen, 0,0,0,0, bufor->w,bufor->h);
	}
}