.data
	input_array_1:.word 7, 8, 6# User input
	input_array_2:.word 6, 7, 8 # User input
	input_length_arrays:.word 3 # User input

.text
main:
	la x12, input_array_1
	la x13, input_array_2
	la x5, input_length_arrays
	lw x14, 0(x5)
	jal x1, PERMUTATION
	addi a1, x10, 0 # a1 will stores the result
	addi a0, x0, 1 # Making ecall be the output
	ecall # Printing the result
	jal zero, END

PERMUTATION:
	#save registers data
	addi sp, sp, -24
	sw x5, 0(sp)
	sw x6, 4(sp)
	sw x7, 8(sp)
	sw x28, 12(sp)
	sw x29, 16(sp)
	sw x1, 16(sp)

	#save data in stack to call others functions
	addi sp, sp, -8
	sw x12, 0(sp)
	sw x13, 4(sp)
    
	add x13, x14, x0
	jal x1, SELECTION_SORT
	lw x12, 4(sp)
	jal x1, SELECTION_SORT
	lw x13, 0(sp)
	addi sp, sp, 8
    
	slli x7, x14, 2
	add x7, x7, x12
	addi x5, x12, 0
	addi x6, x13, 0
    
	addi x10, x0, 1
	LOOP_LINEAR:
    	
		lw x28, 0(x5)
		lw x29, 0(x6)
		addi x5, x5, 4
		addi x6, x6, 4
		bne x29, x28, RETURN_ZERO
		blt x5, x7, LOOP_LINEAR
		beq x0, x0, END_FUNCTION
	
	RETURN_ZERO:
		add x10, x0, x0
	beq x0, x0, END_FUNCTION
    
	# x12 -> array address, x13 -> length 
	SELECTION_SORT:
		#save registers data
		addi sp, sp, -20
		# array browsers
		sw x5, 0(sp)
		sw x6, 4(sp)
		#x7 = Biggest element
		sw x7, 8(sp)
		#x28 = LOOP_2 browser
		sw x28, 12(sp)
		#x29 = Biggest element address
		sw x29, 16(sp)
    
		slli x5, x13, 2
		add x5, x5, x12
		LOOP_1:
			addi x5, x5, -4
			add x6, x12, x0
			lw x7, 0(x6)
			add x28, x7, x0
			add x29, x6, x0
			LOOP_2:
				addi x6, x6, 4
				blt x5, x6, END_LOOP_2
				lw x28, 0(x6)
				blt x28, x7, LOOP_2
				add x7, x28, x0
				add x29, x6, x0 
				beq x0, x0, LOOP_2
			END_LOOP_2:
			lw x7, 0(x29)
			lw x28, 0(x5)
			sw x7, 0(x5)
			sw x28, 0(x29)
			bne x5, x12, LOOP_1

		lw x5, 0(sp)
		lw x6, 4(sp)
		lw x7, 8(sp)
		lw x28, 12(sp)
		lw x29, 16(sp)
		addi sp, sp, 20
		jalr x0, 0(x1)

	END_FUNCTION:
		lw x5, 0(sp)
		lw x6, 4(sp)
		lw x7, 8(sp)
		lw x28, 12(sp)
		lw x29, 16(sp)
		lw x1, 20(sp)
        addi sp, sp, 20
	jalr x0, 0(x1)
END: