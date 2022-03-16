# p2
# 01010000 00010000 00000000 00000001 = 80.16.0.1.
# 01010000000100000000000000000001
.data
	buffer: .space 34 # binary code
	text: .asciiz "\nO IP e: "
	point: .byte  '.'
.text
main:
	# Read String
	la $t0, buffer 	# get buffer address
	move $a0, $t0	# pass to a0
	li $v0, 8
	li $a1, 34
	syscall
	la $a0, text
	li $v0, 4
	syscall
loop:
	move $s0, $zero
	lbu $t1, 0($t0)
	beq $t1, 10, exit
	seq $t9, $t1, 49
	add $s0, $s0, $t9
	
	sll $s0, $s0, 1
	lbu $t1, 1($t0)
	seq $t9, $t1, 49
	add $s0, $s0, $t9
	
	sll $s0, $s0, 1
	lbu $t1, 2($t0)
	seq $t9, $t1, 49
	add $s0, $s0, $t9
	
	sll $s0, $s0, 1
	lbu $t1, 3($t0)
	seq $t9, $t1, 49
	add $s0, $s0, $t9

	sll $s0, $s0, 1	
	lbu $t1, 4($t0)
	seq $t9, $t1, 49
	add $s0, $s0, $t9
	
	sll $s0, $s0, 1
	lbu $t1, 5($t0)
	seq $t9, $t1, 49
	add $s0, $s0, $t9
	
	sll $s0, $s0, 1
	lbu $t1, 6($t0)
	seq $t9, $t1, 49
	add $s0, $s0, $t9
	
	sll $s0, $s0, 1
	lbu $t1, 7($t0)
	seq $t9, $t1, 49
	add $s0, $s0, $t9
	
	move $a0, $s0	# pass to a0
	li $v0, 1
	syscall
	la $a0, point
	lb $a0, 0($a0)
	li $v0, 11
	syscall
	
	addi $t0, $t0, 8
	j loop
	
exit:
	li $v0, 10
	syscall