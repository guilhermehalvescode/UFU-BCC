.text

main:
	jal getchar
	move $a0, $v0
	jal isdigit
	# Fim do programa
	#Não podemos utilizar $v0 para realizar uma syscall,
	#desse modo não finalizaremos o programa, por isso faremos um loop
    	#li $v0, 10
  	#syscall
	j exit
isdigit:
    sge $t1, $a0, 48
    sle $t2, $a0, 57
# $t3 armazena o retorno das funcoes: 0 ou 1
    and $v0, $t1, $t2
    jr $ra

getchar: # retorna char em $v0
	lw $v0, 0xffff0000
	andi $v0, $v0, 0x01
	beq $v0, $zero, getchar
	lw $v0, 0xffff0004
	jr $ra
exit: