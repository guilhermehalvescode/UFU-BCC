	.data
mensagem: .asciiz "Numero de discos? "
msg1: .asciiz "\nMove "
msg2: .asciiz " da haste "
msg3: .asciiz " vai para a haste "
	
	.text
main:
	li $v0, 4
	la $a0, mensagem
	syscall
	li $v0, 5
	syscall
	
	add $a0, $v0, $zero
	li $a1, 'a'
	li $a2, 'b'
	li $a3, 'c'
	
	jal torrehanoi
	
	li $v0, 10
	syscall
	
torrehanoi:
	addi $sp, $sp, -20
	sw $ra, 0($sp)
	sw $s0, 4($sp)
	sw $s1, 8($sp)
	sw $s2, 12($sp)
	sw $s3, 16($sp)
	
	add $s0, $a0, $zero
	add $s1, $a1, $zero
	add $s2, $a2, $zero
	add $s3, $a3, $zero
	
	addi $t1, $zero, 1
	beq $s0, $t1, saida
	
	# recursão caso 1
	addi $a0, $s0, -1
	add $a1, $s1, $zero
	add $a2, $s3, $zero
	add $a3, $s2, $zero
	jal torrehanoi
	j saida
	
recursao2:
	addi $a0, $s0, -1
	add $a1, $s3, $zero
	add $a2, $s2, $zero
	add $a3, $s1, $zero
	jal torrehanoi
	
exit:
	lw $ra, 0($sp)
	lw $s0, 4($sp)
	lw $s1, 8($sp)
	lw $s2, 12($sp)
	lw $s3, 16($sp)
	
	addi $sp, $sp, 20
	
	jr $ra
	
saida:
	li $v0, 4
	la $a0, msg1
	syscall
	li $v0, 1
	add $a0, $s0, $zero
	syscall
	li $v0, 4
	la $a0, msg2
	syscall
	li $v0, 11
	add $a0, $s1, $zero
	syscall
	li $v0, 4
	la $a0, msg3
	syscall
	li $v0, 11
	add $a0, $s2, $zero
	syscall
	beq $s0, $t1, exit
	j recursao2
