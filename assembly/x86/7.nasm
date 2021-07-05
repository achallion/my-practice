global _start

section .text

_start:
    mov eax, 4
    mov ebx, 1
    mov ecx, askage
    mov edx, lenask
    int 0x80

    mov eax, 3
    mov ebx, 0
    mov ecx, var1
    mov edx, 2
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov ecx, [var1]
    sub ecx, '0'
    mov [var1], ecx
    mov ecx, var1
    mov edx, 1
    int 0x80

    mov eax, 1
    int 0x80

section .data

    askage db 'What is Your Age : '
    lenask equ $ - askage


section .bss

    var1 resw 1