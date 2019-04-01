global loader               ; Entry symbol for ELF

MAGIC_NUMBER equ 0x1BADB002 ; Define the Magic Number constant
FLAGS        equ 0x0        ; Multiboot Flags
CHECKSUM     equ -MAGIC_NUMBER ; Calculate the checksum
                            ; (MAGIC_NUMBER + CHECKSUM + FLAGS = 0)

section .text:              ;Start of the text (code) section
align 4                     ;The code must be 4 byte aligned
    dd MAGIC_NUMBER         ;Write the magic number to the machine code
    dd FLAGS                ;Write the flags to the machine code
    dd CHECKSUM             ;Write the checksum to the machine code

loader:                     ;The Loader label (Defined as entry point in linker script)
    mov eax, 0xCAFEBABE     ; place the number 0xCAFEBABE into the register eax

.loop:
    jmp .loop               ; Loop forever

KERNEL_STACK_SIZE equ 4096  ; Size of stack in bytes

section .bss
align 4                     ; Align at 4 bytes
kernel_stack:               ; Label points to beginning of memory
    resb KERNEL_STACK_SIZE  ; Reserve stack for the kernel
    mov esp, kernel_stack + KERNEL_STACK_SIZE ; Point esp to the start of the stack (end of memory area)