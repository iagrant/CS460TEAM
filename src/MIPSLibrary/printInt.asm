printInt:
	li $v0,1 #System Code to print an int
	li $a0, 13 #loading a0 with value to print.
	syscall #print the int