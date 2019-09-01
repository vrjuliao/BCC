# x12 register contains the function parameter
FACTORIAL:
    # grant persistent data in registers
    addi sp, sp, -8
    sw x5, 0(sp)
    sw x6, 4(sp)

    add x11, x0, x0 

    # return 0 if parameter is less than zero
    blt x12, x0, END

    addi x11, x0, 1
    # return 1 if parameter is equals zero
    beq x12, x0, END
    
    addi x6, x12, 1
    addi x5, x0, 1
    
    LOOP:
        mul x11, x11, x5
        addi x5, x5, 1
        blt x5, x6, LOOP
    
    END:
    # print interger
    addi a0, x0, 1
    ecall
    
    lw x6, 4(sp)
    lw x5, 0(sp)
    addi sp, sp, 8