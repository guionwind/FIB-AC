 .text
	.align 4
	.globl Insertar
	.type Insertar,@function
Insertar:
        pushl %ebp
        movl %esp, %ebp
        
        pushl %ebx
        
        subl $12, %esp
        movl $0, -4(%ebp)            # i = 0
        movl $-1, -12(%ebp)          # lug = -1
        
do1:    movl -4(%ebp), %ebx          # ebx = i
        imull $12, $ebx, $edx
        movl 8(%ebp), %ecx  
        movl 4(%ecx, %edx), %ecx     # ecx = v[i].k
        
if1:    cmpl 16(%ebp), %ecx 
        jge else
        movl %ebx, -12(%ebp)    
        jmp if2
        
else1:  incl %ebx
        movl %ebx, -4(%ebp)
        
while1: cmpl $0x80000000, %ecx
        jne do1
        
if2:    cmpl $0x80000000, %ecx
        jne while2
        movl %ebx, -12(%ebp) 

while2: cmpl $0x80000000, %ecx
        jeq endwhile2
        incl %ebx
        jmp while2
        
for:   



