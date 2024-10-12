section .data
    str db 'racecar', 0
    len equ $ - str
    msg1 db 'Palindrome', 0
    msg2 db 'Not a palindrome', 0

section .text
    global _start

_start:
    mov eax, 1  
    
compare_loop:
    cmp eax, ebx
    jae is_palindrome

    mov dl, [str + eax]
    mov dh, [str + ebx]
    cmp dl, dh
    jne not_palindrome
    
    inc eax
    dec ebx
    jmp compare_loop

is_palindrome:
    mov eax, 4
    mov ebx, 1
    mov ecx, msg1
    mov edx, 10
    int 0x80

    jmp exit_program

not_palindrome:
    mov eax, 4
    mov ebx, 1
    mov ecx, msg2
    mov edx, 17
    int 0x80

exit_program:
    mov eax, 1
    xor ebx, ebx
    int 0x80
