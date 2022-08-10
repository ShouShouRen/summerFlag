        global      _start

        section     .text
_start:
    mov rax, 1
    mov rbx, rax
    mov rcx, message
    lea r8, [rcx+1]
    mov dl, [r8]
    mov dl, 102
    mov [r8], defl

    section   .data
message: db 72,101,108,108,111,44,32,87,111,114,108,100,10