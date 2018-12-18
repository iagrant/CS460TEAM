# Print new line to stdout
printNewLine:

    addi $v0 $zero 11
    addi $a0 $zero 10
    syscall

    jr $ra
