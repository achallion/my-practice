extern printf
extern exit
extern addnum

section .text

global main

main:

    push 5
    push 6
    call addnum
    ; eax has 11 as sum


    ;add esp, 0x8
    pop ebx;
    pop ebx;

    push eax;
    push msg;
    call printf

    push 0
    call exit

section .data

    msg db "Value is : %d",0xA;
