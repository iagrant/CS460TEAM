##	.globl	main
##	.ent	main
main:
addiu	$sp,$sp-16
sw	$31,12($sp)

##main	16
####	int main(){
####	    int a=5;
##ASSIGN	iT_0	5
li	$8	5
##STORE	iT_0	A_4
sw	$8	8($sp)
####	    printInt(a);
##LOAD	iT_1	A_4
lw	$8	8($sp)
##ARGLOAD	iT_2	iT_1
move	$4	$8
##CALL	printInt
jal	printInt
