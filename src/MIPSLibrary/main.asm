.text

main:

    #save $ra on stack
    addi $sp $sp -4
    sw   $fp 0($sp)
    move $fp $sp
    addi $sp $sp -4
    sw   $ra  -4($fp)

    #call sub-routine
    addi $a0 $zero 1
    jal printInt
    addi $a0 $zero 2
    jal printInt
    addi $a0 $zero 3
    jal printInt
    addi $a0 $zero 4
    jal printInt
    jal printNewLine

    #restore and shrink stack
    lw $ra  -4($fp)
    lw $fp   0($fp)
    addi $sp $sp 8

    jr $ra

#
