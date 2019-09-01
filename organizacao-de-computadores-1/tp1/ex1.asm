# x12 register contains the function parameter
# the value that needs verifications should be putted on X12 register
IS_ODD:
    andi x11, x12, 1
    # print interger
    addi x10, x0, 1
    ecall