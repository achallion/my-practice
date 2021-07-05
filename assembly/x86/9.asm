section .text

global _start

_start:
    jmp Begin

NEVER_EXECUTE:
    mov eax,0x10
    xor ebx,ebx

Begin:
    mov eax,5

Printhw:
    push eax;

    mov eax,4
    mov ebx,1
    mov ecx,msg
    mov edx,mlen
    int 0x80;


    pop eax;
    dec eax;
    jnz Printhw;

    mov eax,1;
    mov ebx,0xa;
    int 0x80


section .data
    
    msg db  "Hello World!\n"
    mlen    equ $-msg 
