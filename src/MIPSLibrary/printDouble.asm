printDouble:
	li $v0, 2 #System code to print a double
	
	la $t4, float1 #Loading f12 with 6.7
	l.s $f12,0($t4)
	syscall #print the double

.data
float1: .float 6.7
	