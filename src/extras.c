#include <pebble.h>
#include "extras.h"

TextLayer *text_layer_init(GRect location, GTextAlignment alignment, int font){
	TextLayer *layer = text_layer_create(location);
	text_layer_set_text_color(layer, GColorWhite);
	text_layer_set_background_color(layer, GColorClear);
	text_layer_set_text_alignment(layer, alignment);
	switch(font){
		case 0:
			text_layer_set_font(layer, fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_DILLY_DOTS_42)));
			break;
		case 1:
			text_layer_set_font(layer, fonts_get_system_font(FONT_KEY_GOTHIC_18));
			break;
        case 2:
            text_layer_set_font(layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
            break;
        case 3:
            text_layer_set_font(layer, fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_CLIMACONS_50)));
            break;
	}
	return layer;
}

void on_animation_stopped(Animation *anim, bool finished, void *context){
    #ifdef PBL_COLOR
        //dust
    #else
        property_animation_destroy((PropertyAnimation*) anim);
    #endif
}
 
void animate_layer(Layer *layer, GRect *start, GRect *finish, int length, int delay){
    PropertyAnimation *anim = property_animation_create_layer_frame(layer, start, finish);
     
    animation_set_duration((Animation*) anim, length);
    animation_set_delay((Animation*) anim, delay);
     
	AnimationHandlers handlers = {
    	.stopped = (AnimationStoppedHandler) on_animation_stopped
    };
    animation_set_handlers((Animation*) anim, handlers, NULL);
     
    animation_schedule((Animation*) anim);
}

Animation *animate_layer_return(Layer *layer, GRect *start, GRect *finish, int length, int delay){
    PropertyAnimation *anim = property_animation_create_layer_frame(layer, start, finish);
     
    animation_set_duration((Animation*) anim, length);
    animation_set_delay((Animation*) anim, delay);
     
	AnimationHandlers handlers = {
    	.stopped = (AnimationStoppedHandler) on_animation_stopped
    };
    animation_set_handlers((Animation*) anim, handlers, NULL);
     
    animation_schedule((Animation*) anim);
    return (Animation*)anim;
}