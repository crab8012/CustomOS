#include "framebuffer.h"

/** printf:
 *  Writes a string a given length to the framebuffer
 * 
 *  @param str The string to be printed
 *  @param len The length of the string to be printed.
 */
void write_string(const char* str, int size){
    for(int i = 0; i < size; i++){
        fb_move_cursor(i);
        fb_write_cell(i, str[i], 'F', '0');
    }
}