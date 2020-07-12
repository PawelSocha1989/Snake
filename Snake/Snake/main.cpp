#include "zmienne.h"

BITMAP *bufor2;
BITMAP *bufor;

inline void init()
{
	allegro_init();
	set_color_depth(16);
	set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, 640, 480, 0, 0);
	install_timer();
	install_keyboard();
	install_mouse();
}

inline void deinit()
{
    menu des2;
    des2.destroy2();
    waz des3;
    des3.destroy3();
	clear_keybuf();
	allegro_exit();
}

int main()
{
	init();
	srand (static_cast<unsigned int>(clock()));
    menu men;
    waz los;
	while (!key[KEY_ESC])
	{
		men.load();
		los.loadw();
		los.losuj();
		men.menu_tlo();
		men.menu_glowne();
    }
	deinit();
	return 0;
}
END_OF_MAIN()
