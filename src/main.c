#include <allegro.h>
int main() {
    allegro_init();
    install_keyboard();
    set_color_depth(24);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,640,480,0,0);
    set_palette(default_palette);
	//Kod powyżej będziemy używać zawsze do naszego projektu
    clear_to_color(screen, makecol(0,255,0)); //ustawianie koloru tła
 
    readkey(); // Program oczekuje na dowolny klawisz
 
    allegro_exit();
    return 0;
}
END_OF_MAIN();
