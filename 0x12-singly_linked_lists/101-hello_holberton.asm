section .data
    hello db "Hello, Holberton", 0   ; Null-terminated string for printf

section .text
    global main
    extern printf

main:
    ; Save callee-saved registers (optional, depending on platform's calling convention)
    push rbx
    push rbp
    push r12
    push r13
    push r14
    push r15

    ; Call printf
    lea rdi, [hello]    ; Load the address of the string into rdi (1st argument)
    xor rax, rax        ; Clear RAX (to indicate no vector registers used, not a variadic function)
    call printf        ; Call the printf function

    ; Restore callee-saved registers (optional, depending on platform's calling convention)
    pop r15
    pop r14
    pop r13
    pop r12
    pop rbp
    pop rbx

    ; Return from main (optional)
    xor rax, rax
    ret

