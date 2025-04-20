#include <ncurses.h>
#include "../include/window_functions.hpp"

WINDOW *create_new_window(int height, int width, int start_y, int start_x){

	WINDOW *local_window; 
	local_window = newwin(height,width,start_y,start_x); 
	box(local_window,0,0);
	wrefresh(local_window); 
	return local_window; 
}


