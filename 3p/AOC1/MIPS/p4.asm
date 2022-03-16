power:
        addiu   $sp,$sp,-40
        sw      $31,36($sp)
        sw      $fp,32($sp)
        move    $fp,$sp
        sw      $4,40($fp)
        sw      $5,44($fp)
        lw      $2,44($fp)
        nop
        bne     $2,$0,left2
        nop

        li      $2,1                        
        mtlo    $2
        b       left3
        nop

left2:
        lw      $2,44($fp)
        nop
        andi    $2,$2,0x1
        beq     $2,$0,left4
        nop

        lw      $2,44($fp)
        nop
        addiu   $2,$2,-1
        move    $5,$2
        lw      $4,40($fp)
        jal     power
        nop

        move    $3,$2
        lw      $2,40($fp)
        nop
        mult    $3,$2
        b       left3
        nop

left4:
        lw      $2,44($fp)
        nop
        srl     $2,$2,1
        move    $5,$2
        lw      $4,40($fp)
        jal     power
        nop

        sw      $2,24($fp)
        lw      $2,24($fp)
        nop
        mult    $2,$2
left3:
        mflo    $2
        move    $sp,$fp
        lw      $31,36($sp)
        lw      $fp,32($sp)
        addiu   $sp,$sp,40
        jr      $ra
        nop

main:
        addiu   $sp,$sp,-32
        sw      $31,28($sp)
        sw      $fp,24($sp)
        move    $fp,$sp
        li      $5,2                        
        li      $4,4                        
        jal     power
        nop

        move    $2,$0
        move    $sp,$fp
        lw      $31,28($sp)
        lw      $fp,24($sp)
        addiu   $sp,$sp,32
        jr      $ra
        nop