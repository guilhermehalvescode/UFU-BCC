    .data
str: .space 20
text: .asciiz "Insira uma string (20 char.): "
textInvalid: .asciiz "A string inserida e invalida."
textValid: .asciiz "A string inserida e valida. (rsrs xD)"

    .text
main:
    # Imprimindo text na tela
    li $v0, 4
    la $a0, text
    syscall
    # Obtendo input 1
    li $v0, 8
    la $a0, str
    li $a1, 20
    syscall
    la $s0, str
    # Chamando funcao que valida string
    jal floatValidate

floatValidate:
    lbu $t0, 0($s0)
    jal isSignal
    move $t4, $t3
    jal isDigit
    or $t5, $t4, $t3
    beqz $t5, invalid
    jal loopString
endLoop:
    addi $s0, $s0, 1
    lbu $t0, 0($s0)
    jal isDigit
    beqz $t3, invalid
    addi $s0, $s0, 1
    lbu $t0, 0($s0)
    seq $t7, $t0, 10 # check \n
    beq $t7, 1, invalid
    subi $s0, $s0, 1
    jal loopStringDecimal
endLoop1:
    addi $s0, $s0, 1
    lbu $t0, 0($s0)
    jal isSignal
    move $t4, $t3
    jal isDigit
    or $t5, $t4, $t3
    beqz $t5, invalid
    jal loopStringExpoente



loopString:
    addi $s0, $s0, 1
    lbu $t0, 0($s0)
    seq $t7, $t0, 10 # check \n
    beq $t7, 1, invalid
    jal isDigit
    move $t4, $t3
    jal isPoint
    or $t5, $t3, $t4
    beqz $t5, invalid
    beq $t3, 1, endLoop
    j loopString

loopStringDecimal:
    addi $s0, $s0, 1
    lbu $t0, 0($s0)
    seq $t7, $t0, 10 # check \n
    beq $t7, 1, valid
    jal isDigit
    move $t4, $t3
    jal isE
    or $t5, $t3, $t4
    beqz $t5, invalid
    beq $t3, 1, endLoop1
    j loopStringDecimal


loopStringExpoente:
    addi $s0, $s0, 1
    lbu $t0, 0($s0)
    seq $t7, $t0, 10 # check \n
    beq $t7, 1, valid
    jal isDigit
    beq $t3, 0, invalid
    j loopStringExpoente

isSignal:
    seq $t1, $t0, 43
    seq $t2, $t0, 45
# $t3 armazena o retorno das funcoes: 0 ou 1
    or $t3, $t1, $t2
    jr $ra
isDigit:
    sge $t1, $t0, 48
    sle $t2, $t0, 57
# $t3 armazena o retorno das funcoes: 0 ou 1
    and $t3, $t1, $t2
    jr $ra
isPoint:
# $t3 armazena o retorno das funcoes: 0 ou 1
    seq $t3, $t0, 46
    jr $ra

isE:
    seq $t1, $t0, 69
    seq $t2, $t0, 101
# $t3 armazena o retorno das funcoes: 0 ou 1
    or $t3, $t1, $t2
    jr $ra

invalid:
    # Imprimindo textInvalid na tela
    li $v0, 4
    la $a0, textInvalid
    syscall
    jal exit
valid:
    # Imprimindo textValid na tela
    li $v0, 4
    la $a0, textValid
    syscall
    jal exit

exit:
    # Fim do programa
    li $v0, 10
    syscall
