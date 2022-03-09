# p2
# 01010000 00010000 00000000 00000001 = 80.16.0.1.
# 01010000000100000000000000000001
.data
	buffer: .space 33 # binary code
	message: .asciiz "\nvalor: "
.text
	la $t0, buffer 	# get buffer address
	move $a0, $t0	# pass to a0
	li $v0, 8
	li $a1, 33
	syscall
	li $v0, 4
	la $a0, message
	syscall
	la $a0, buffer
	syscall
	li $v0, 10
	syscall
	
