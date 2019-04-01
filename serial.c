#include "io.h"     /* io.h was implemented previously */

/* The I/O ports */

/* All the I/O ports are calculated relative to their data port. This is because
 * all serial ports (COM1, COM2, COM3, COM4) have their ports in the same
 * order, but they start at different values.
 */

#define SERIAL_COM1_BASE                0x3F8       /* COM1 base port */

#define SERIAL_DATA_PORT(base)          (base)
#define SERIAL_FIFO_COMMAND_PORT(base)  (base + 2)
#define SERIAL_LINE_COMMAND_PORT(base)  (base + 3)
#define SERIAL_MODEM_COMMAND_PORT(base) (base + 4)
#define SERIAL_LINE_STATUS_PORT(base)   (base + 5)

/* The I/O port commands */

/* SERIAL_LINE_ENABLE_DLAB:
 * Tells the serial port to expect first the highest 8 bits on the data port,
 * then the lowest 8 bits will follow
 */
#define SERIAL_LINE_ENABLE_DLAB         0x80

/** serial_configure_baud_rate:
 *  Sets the speed of the data being sent. The default speed of a serial port is 115200 bits per second. The default speed of a
 *  serial port is 115200 bits per second. The argument is a divisor of the number, hence the resulting speed becomes
 *  (115200 / divisor) bits per second.
 * 
 *  @param com      The COM port to configure
 *  @param divisor  The divisor
 */
void serial_configure_baud_rate(unsigned short com, unsigned short divisor){
    outb(SERIAL_LINE_COMMAND_PORT(com), SERIAL_LINE_ENABLE_DLAB);
    outb(SERIAL_DATA_PORT(com), (divisor >> 8) & 0x00FF);
    outb(SERIAL_DATA_PORT(com), divisor & 0x00FF);
}

/** serial_is_transmit_fifo_empty(unsigned int com)
 *  Checks whether the transmit FIFO queue is not empty or not fit the given
 *  COM port.
 * 
 * @param com The COM port
 * @return 0 if the transmit FIFO queue is not empty
 *         1 if the transmit FIFO queue is empty
 */
int serial_is_transmit_fifo_empty(unsigned int com){
    /* 0x20 = 0010 0000 */
    return inb(SERIAL_LINE_STATUS_PORT(com)) & 0x20;
}

/** serial_write(insigned int com, unsigned int data)
 *  Waits until the FIFO queue is empty and then transmit the data
 *  
 *  @param com  The COM port
 *  @param data The data to write
 */
void serial_write(unsigned int com, unsigned int data)
{
    while (!is_transmit_fifo_empty(com)) {
        /* wait and try again */
    }
    outb(DATA_PORT(com), data);
}