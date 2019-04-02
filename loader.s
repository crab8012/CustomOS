global loader               ; Entry symbol for ELF

section .mbHeader
align 0x4
    MAGIC_NUMBER equ 0x1BADB002     ; Define the Magic Number constant
    FLAGS        equ 0x0            ; Multiboot Flags
    CHECKSUM     equ -MAGIC_NUMBER  ; Calculate the checksum
                                    ; (MAGIC_NUMBER + CHECKSUM + FLAGS = 0)
KERNEL_STACK_SIZE equ 4096  ; Size of stack in bytes

section .bss
align 0x4                     ; Align at 4 bytes
kernel_stack:               ; Label points to beginning of memory
    resb KERNEL_STACK_SIZE  ; Reserve stack for the kernel

section .text:              ;Start of the text (code) section
align 0x4                     ;The code must be 4 byte aligned
    dd MAGIC_NUMBER         ;Write the magic number to the machine code
    dd FLAGS                ;Write the flags to the machine code
    dd CHECKSUM             ;Write the checksum to the machine code

loader:                     ;The Loader label (Defined as entry point in linker script)
    mov esp, kernel_stack + KERNEL_STACK_SIZE ; Point esp to the start of the stack (end of memory area)
    
    ;extern sum_of_three     ; The function sum_of_three is defined elsewhere
    ;push dword 3            ; arg3
    ;push dword 2            ; arg2
    ;push dword 1            ; arg1
    ;call sum_of_three       ; Call the function. The result will be in eax
    
    extern kernel_main
    ;push eax
    call kernel_main

.loop:
    jmp .loop               ; Loop forever