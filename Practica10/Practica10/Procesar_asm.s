.text
	.align 4
	.globl procesar
	.type	procesar, @function
procesar:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi

# Aqui has de introducir el codigo
    movl $0, %eax
    movl 8(%ebp), %eax
    movl 12(%ebp), %ebx
    movl 16(%ebp), %esi
    imull %esi, %esi
    addl %eax, %esi
    
for:
    cmpl %eax, %esi
    jle endfor
    
    movb (%eax), %dl
    and $1, %dl
    #movb %dl, (%ebx)
    
if:
    cmpb $0, %dl
    je else
    movb $255, (%ebx)
    jmp endif
    
else:
    movb $0, (%ebx)
    
endif:
    incl %eax
    incl %ebx
    jmp for
    
endfor:

# El final de la rutina ya esta programado

	popl	%edi
	popl	%esi
	popl	%ebx
	movl %ebp,%esp
	popl %ebp
	ret
