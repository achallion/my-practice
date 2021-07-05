section .text

global _start

_start:
    mov ecx,5;

Loop_here:

    push ecx;

    mov eax, 4
    mov ebx, 1
    mov ecx, msg
    mov edx, mlen
    int 0x80
    pop ecx;

    loop Loop_here

    mov eax, 1
    mov ebx, 16
    int 0x80


section .data
    msg db  "Hello World! "
    mlen    equ $-msg