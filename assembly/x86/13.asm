section .text

global _start

print:

    push ebp;
    mov ebp, esp
    mov eax, 4
    mov ebx, 1
    int 0x80;

    leave;
    ret;


_start:

    mov ecx, srclen;
    lea esi, [source]
    lea edi, [dest]

    cld;
    rep movsb;    

    ; Print Hello World
    mov ecx, dest;
    mov edx, srclen;
    call print;

    ; Compare 2 Strings
    mov ecx, srclen;
    lea esi, [source];
    lea edi, [dest];
    repe cmpsb

    jz both_eq
    mov ecx, rslt2;
    mov edx, rslt2len;
    jmp lets_print;
both_eq:
    mov ecx, rslt1;
    mov edx, rslt1len;

lets_print:
    call print;

Exit:
    mov eax, 1
    mov ebx, 0
    int 0x80

section .data
    source db "Hello World!",0xA
    srclen equ $-source

    cmpar db "Hello"

    rslt1 db "Strings Are Equal",0xA
    rslt1len equ $-rslt1

    rslt2 db "Strings Are Not Equal",0xA
    rslt2len equ $-rslt2

section .bss
    dest resb 100