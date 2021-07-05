global _start

section .text

_start:
    mov eax, 0
    mov ebx, 1
    xchg eax,ebx
    xchg eax, [var1]

    ret

section .data

    var1    dw  54
    array   dw  1,2,3