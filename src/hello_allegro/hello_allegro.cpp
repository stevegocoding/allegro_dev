#include <stdio.h>

#include "allegro5/allegro.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"

int main()
{
	al_init();
	al_init_font_addon();
	al_init_ttf_addon(); 
	ALLEGRO_DISPLAY *display = al_create_display( 640, 480 );
	ALLEGRO_FONT *font = al_load_font( "./data/fonts/um.ttf", 12, 0 );
	al_clear_to_color( al_map_rgb( 50,10,70 ) );
	al_draw_text( font, al_map_rgb( 255, 255, 255 ), 640/2, ( 480/4 ), ALLEGRO_ALIGN_CENTRE, "'Hello Allegro!" );
	al_flip_display();
	al_rest( 10.0 );
	al_destroy_display( display );
	return 0;
}