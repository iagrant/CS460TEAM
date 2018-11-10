readDouble:
	li $v0, 7 #Load register with code to read a double
	syscall #Read in the double
	