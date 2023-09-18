.text
	.align 4
	.globl procesar
	.type	procesar, @function
	.data
	cero: .byte 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	uno:  .byte 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
	
procesar:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi

# Aqui has de introducir el codigo
    movl $0, %eax
    movl 8(%ebp), %ebx
    movl 12(%ebp), %ecx
    movl 16(%ebp), %esi
    
    imul %esi, %esi
    
for:
    cmpl %eax, %esi
    jle endfor
    
    movdqa (uno), %xmm1
    movdqa (%ebx), %xmm0
    
    pand %xmm1, %xmm0
    movdqa %xmm0, (%ecx)
    
    movdqa (cero), %xmm1
    pcmpgtb %xmm1, %xmm0
    movdqa %xmm0, (%ecx)    #el resultat de pcmpgtb sera 0 (false) o 255 (true) per cada bit
    
    addl $16, %ebx
    addl $16, %ecx
    incl %eax
    jmp for
    
endfor:

# El final de la rutina ya esta programado

	emms	# Instruccion necesaria si os equivocais y usais MMX
	popl	%edi
	popl	%esi
	popl	%ebx
	movl %ebp,%esp
	popl %ebp
	ret
