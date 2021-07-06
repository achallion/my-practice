section .text

    global _start

pname:

    ;enter
    push ebp;
    mov ebp,esp;

    mov eax, 4
    mov ebx, 1
    mov ecx, msg
    mov edx, mlen
    int 0x80

    
    leave;
    ret;


_start:

    mov ecx, 5;

cpname:
    push ecx;
    call pname;
    pop ecx;
    loop cpname;


    mov eax, 1;
    mov ebx, 0;
    int 0x80;




section .data
    msg db  "BHav"
    mlen    equ $-msg