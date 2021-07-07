extern printf;
extern exit;

section .text

global main

main:

    push msg;
    call printf;
    add esp, 0x4;

    mov eax, 0x10
    call exit
    


section .data

    msg db "Hello World!\n",0xA,0x00
    mlen equ $-msg