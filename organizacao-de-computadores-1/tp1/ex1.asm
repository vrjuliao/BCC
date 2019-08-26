# x12 register contains the function parameter
# the value that needs verifications should be putted on X12 register
IS_ODD:
	addi x5, x0, 1
	and a1, x12, x5 
    addi a0, x0, 1 # print interger
    ecall