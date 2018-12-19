#prints a char and then a new line
printInt:

    #call print-int syscall
    sgt $v0 $zero 1
    syscall

    #print space 
    addi $v0 $zero 11
    addi $a0 $zero 32
    syscall

    jr $ra
