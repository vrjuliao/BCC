# distancia de 5 posicoes de memória entre os vetores, logo o max_length = 5
addi x14, x0, 3
addi x12, x0, 1024
addi x13, x0, 1536

#inserindo elementos nos vetores
# vetor 1
addi x5, x0, 1
sw x5, 0(x12)
addi x5, x5, 1
sw x5, 4(x12)
addi x5, x5, 1
sw x5, 8(x12)

# vetor 2
sw x5, 0(x13)
addi x5, x5, -1
sw x5, 4(x13)
addi x5, x5, -1
sw x5, 8(x13)


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
    
    FIRST_EXT_LOOP:
    	addi x28, x28, -4
    	add x7, x12, x28
    	lw x5, 0(x7)
    
    	slli x29, x14, 2 # multiplying by 4

        add x11, x0, x0
    	FIRST_IN_LOOP:
            addi x29, x29, -4
            add x7, x13, x29
            lw x6, 0(x7)

            beq x6, x5, FIRST_IS_EQUAL
            bne x29, x0, FIRST_IN_LOOP
            beq x0, x0, END
        
        FIRST_IS_EQUAL:
            addi x11, x0, 1
            bne x28, x0, FIRST_EXT_LOOP

    add x11, x0, x0
    slli x29, x14, 2 # multiplying by 4
    SECOND_EXT_LOOP:
        addi x29, x29, -4
        add x7, x13, x29
        lw x6, 0(x7)
    
        slli x28, x14, 2 # multiplying by 4

        add x11, x0, x0
        SECOND_IN_LOOP:
            addi x28, x28, -4
            add x7, x12, x28
            lw x5, 0(x7)

            beq x6, x5, SECOND_IS_EQUAL
            bne x28, x0, SECOND_IN_LOOP
            beq x0, x0, END
        
        SECOND_IS_EQUAL:
            addi x11, x0, 1
            bne x29, x0, SECOND_EXT_LOOP

    END:
        lw x5, 0(sp)
        lw x6, 4(sp)
        lw x7, 8(sp)
        lw x28, 12(sp)
        lw x29, 16(sp)
        addi sp, sp, 20

addi x10, x0, 1
ecall
