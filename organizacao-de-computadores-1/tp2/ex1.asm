.data
array: .word 1 2 3 4 5 6 7 8 9 10
array_size: .word 1

.text
main:
la x8, array
la x5, array_size
lw x6, 0(x5) #N
addi x9, x8, 0 # x = &array[0]
addi x10, x0, 0 # total = 0
addi x11, x0, 0 # i = 0
loop:
    lw x12, 0(x9) # x12 = array[i]
    add x10, x10,x12 # sum += array[i]
    addi x9, x9, 4 #&array[i++]
    addi x11, x11, 1 # i++
    blt x11 , x6 , loop

addi a1 , x10 , 0 # a1 will stores the result
addi a0 , x0 , 1 # Making ecall be the output
ecall # Printing the result
jal zero, end
end: