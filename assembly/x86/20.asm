extern printint;

section .text

global main

exiti:
    mov eax, 1;
    mov ebx, 0;
    int 0x80;

main:

    push dword [intvar];
    call printint;
    call exiti;


section .data
    intvar dd 40;
