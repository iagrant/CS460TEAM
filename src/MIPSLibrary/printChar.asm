printChar:
	li $v0, 11 #System code to print a char
	li $a0, 'F' #Loading a0 with the char to print
	syscall #print the char