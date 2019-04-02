#include "framebuffer.h"

/** printf:
 *  Writes a string a given length to the framebuffer
 * 
 *  @param str The string to be printed
 */
void printf(const char *str){
    int i = 0;
    while(str[i] != 0x00){
        fb_write_cell(i*2, str[i], 'B', '0');
        i++;
    }
}
/*
void printf(char* str){
    int size  = sizeof(str)/sizeof(str[0]);
    for(int i = 0; i < size; i++){
        fb_write_cell(i*2, str[i], 'B', '0');
    }
}
*/
/** testColors:
 *  Prints out the color code for the foreground and background characters
 */
void testColors(){
    fb_write_cell(0, '0', '0', '0');
    fb_write_cell(2, '1', '1', '0');
    fb_write_cell(4, '2', '2', '0');
    fb_write_cell(6, '3', '3', '0');
    fb_write_cell(8, '4', '4', '0');
    fb_write_cell(10, '5', '5', '0');
    fb_write_cell(12, '6', '6', '0');
    fb_write_cell(14, '7', '7', '0');
    fb_write_cell(16, '8', '8', '0');
    fb_write_cell(18, '9', '9', '0');
    fb_write_cell(20, 'A', 'A', '0');
    fb_write_cell(22, 'B', 'B', '0');
    fb_write_cell(24, 'C', 'C', '0');
    fb_write_cell(26, 'D', 'D', '0');
    fb_write_cell(28, 'E', 'E', '0');
    fb_write_cell(30, 'F', 'F', '0');

    fb_write_cell(40, '0', '0', '0');
    fb_write_cell(42, '1', '0', '1');
    fb_write_cell(44, '2', '0', '2');
    fb_write_cell(46, '3', '0', '3');
    fb_write_cell(48, '4', '0', '4');
    fb_write_cell(50, '5', '0', '5');
    fb_write_cell(52, '6', '0', '6');
    fb_write_cell(54, '7', '0', '7');
    fb_write_cell(56, '8', '0', '8');
    fb_write_cell(58, '9', '0', '9');
    fb_write_cell(60, 'A', '0', 'A');
    fb_write_cell(62, 'B', '0', 'B');
    fb_write_cell(64, 'C', '0', 'C');
    fb_write_cell(66, 'D', '0', 'D');
    fb_write_cell(68, 'E', '0', 'E');
    fb_write_cell(70, 'F', '0', 'F');
}