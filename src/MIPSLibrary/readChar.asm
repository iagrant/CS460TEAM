readChar:
	li $v0, 12 #System code to read in a char
	syscall #Read in the char