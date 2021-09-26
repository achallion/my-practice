section .text

global _Z9fibonaccii

_Z9fibonaccii:

    push ebp;
    mov ebp, esp;
    push edx;
    push esi;
    ; initialize
    mov dword [prev], 0x00000000;
    mov dword [cur], 0x00000001;
    mov byte [it], 0x01; 
    mov eax, dword [ebp + 8]; // n = 3
    mov byte [n], al;

getfib:

    xor edx,edx;
    mov dl, byte [n];
    cmp byte [it] , dl;
    jg loopend; 
    mov eax,dword [prev];
    add eax, dword [cur];
    mov esi, dword [cur];
    mov dword [prev], esi;
    mov dword [cur] , eax;
    inc byte [it];
    jmp getfib;

loopend:
    pop esi;
    pop edx;
    mov eax, dword [cur];
    pop ebp;
    ret;

section .bss
    it resb 1
    prev resd 1
    cur resd 1
    n resb 1