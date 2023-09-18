 .text
	.align 4
	.globl Asignar
	.type Asignar,@function
Asignar:
        pushl %ebp
        movl %esp, %ebp
    
        movl 24(%ebp), %eax         # eax = pos
        imull $12, %eax             # struct size = 12
        movl 8(%ebp), %ecx          # ecx = @v
        
        movb 12(%ebp), %dl          # dl = X.c
        movb %dl, (%ecx, %eax)      # v[pos].c = X.c
        
        movl 16(%ebp), %edx         # edx = X.k
        movl %edx, 4(%ecx, %eax)    # v[pos].k = X.k
        
        movl 20(%ebp), %edx         # edx = X.m
        movl %edx, 8(%ecx, %eax)    # v[pos].k = X.m

        movl %ebp, %esp
        popl %ebp
