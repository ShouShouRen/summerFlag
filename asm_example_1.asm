        global      _start

        section     .text
_start:
    mov     rax,1
    mov     rdi,1
    mov     rsi, message
    mov     rdx, 13
    syscall
    mov     rax, 60
    xor     rdi, rdi
    syscall

    section     .data
;message:    db          "Hello, World", 10
message:     db     72,101,108,108,111,44,32,87,111,114,108,100,10