global _start


section .data

    %assign len 10
    %define wid db 'WIDTH'
    area equ len*wid
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
    %assign len 4
    mov eax, len
    mov ebx, STDOUT
    mov ecx, wid
    mov edx, len1
    int 0x80

    mov eax, len
    mov ebx, STDOUT
    mov ecx, msg2
    mov edx, len2
    int 0x80

    %assign len 1

    mov eax, len
    mov ebx, 0
    int 0x80