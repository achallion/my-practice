section .text

global _start

phw:
    mov eax, 4;
    mov ebx, 1;
    mov ecx, msg;
    mov edx, mlen;
    int 0x80;
    ret;


_start:
    mov ecx, 5;

phw_call:
    push ecx;
    call phw;
    pop ecx;
    loop phw_call;

    mov eax, 1;
    mov ebx, 0;
    int 0x80;


section .data

    msg db  "Hello World! "
    mlen    equ $-msg