global _start

section .text

_start:
    mov eax, 4;
    mov ebx, 1;
    mov ecx, chhh;
    mov edx, 1;
    int 0x80;

    mov eax, 1;
    int 0x80;

section .data
    
    chhh    DB  'H'
