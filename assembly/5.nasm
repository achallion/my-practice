global _start


section .data

    len equ 10
    wid equ 20
    area equ 10*20
    STDIN equ 0
    STDOUT equ 1
    SYS_EXIT equ 1
    SYS_WRITE equ 4
    msg1 db 'HI DOBI',0xA,0xD
    len1 equ $ - msg1
    msg2 db 'NO BE'
    len2 equ $ - msg2

section .text

_start:
    mov eax, SYS_WRITE
    mov ebx, STDOUT
    mov ecx, msg1
    mov edx, len1
    int 0x80

    mov eax, SYS_WRITE
    mov ebx, STDOUT
    mov ecx, msg2
    mov edx, len2
    int 0x80


    mov eax, SYS_EXIT
    mov ebx, 0
    int 0x80