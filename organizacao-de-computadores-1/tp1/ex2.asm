.data
    input:.word 7 # User input

.text
main:
    la x5, input
    lw x12, 0(x5)
    jal x1, FACTORIAL
    addi a1, x10, 0 # a1 will stores the result
    addi a0, x0, 1 # Making ecall be the output
    ecall # Printing the result
    jal zero, END

# x12 register contains the function parameter
FACTORIAL:
    # grant persistent data in registers
    addi sp, sp, -8
    sw x5, 0(sp)
    sw x6, 4(sp)

    add x10, x0, x0 

    # return 0 if parameter is less than zero
    blt x12, x0, END_FACTORIAL

    addi x10, x0, 1
    # return 1 if parameter is equals zero
    beq x12, x0, END_FACTORIAL
    
    addi x6, x12, 1
    addi x5, x0, 1
    
    LOOP:
        mul x10, x10, x5
        addi x5, x5, 1
        blt x5, x6, LOOP
    
END_FACTORIAL:
    lw x6, 4(sp)
    lw x5, 0(sp)
    addi sp, sp, 8
    jalr x0, 0(x1)

END: