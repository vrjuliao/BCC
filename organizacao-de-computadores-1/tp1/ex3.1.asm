# x12 - beginning of first vector
# x13 - beginning of second vector
# x14 - vectors length in decimal base

# x11 - return 0 if the vectors is not a permutation of each other, or return 1 otherwise
VERIFY_PERMUTATION:
	#save registers data
    addi sp, sp, -20
    sw x5, 0(sp)
    sw x6, 4(sp)
    sw x7, 8(sp)
    sw x28, 12(sp)
    sw x29, 16(sp)
    
    add x11, x0, x0
    
    # x5 - load first vector elements
    # x6 - load second vector elements
    # x7 - used by to access memory positions
    # x28 - index to increment and verify the first vector
    # x29 - index to increment and verify the second vector
    slli x28, x14, 2 # multiplying by 4

    #create 2 new sort vecotor copying the two parameters vectors
    