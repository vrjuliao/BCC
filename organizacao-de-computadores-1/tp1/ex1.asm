.data
    input:.word 7 # User input

.text
main:
    la x5, input
    lw x12, 0(x5)
    jal x1, IS_ODD
    addi a1, x10, 0 # a1 will stores the result
    addi a0, x0, 1 # Making ecall be the output
    ecall # Printing the result
    jal zero, END

# x12 register contains the function parameter
# the value that needs verifications should be putted on X12 register
IS_ODD:
    andi x10, x12, 1
    jalr x0, 0(x1)
END: