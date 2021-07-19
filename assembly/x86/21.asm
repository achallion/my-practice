extern _Z9factoriali
extern printf
extern exit


section .text

global main

main:
    push dword [num];
    call _Z9factoriali;
    add esp,4;

    push eax;
    push msg;
    call printf;
    add esp,8;

    push 0;
    call exit;

section .data
    num dd 6;
    msg db "Factorial is : %d",0xA,0x00;