	.file	"lesson1.c"
	.text
	.section	.rodata
.LC0:
	.string	"%I64ld\n"
.LC1:
	.string	"%d\n"
.LC2:
	.string	"value: %d\n"
.LC3:
	.string	"1 = %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movb	$97, -55(%rbp)
	movabsq	$28489298891, %rsi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movw	$1, -54(%rbp)
	jmp	.L2
.L3:
	movswl	-54(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movzwl	-54(%rbp), %eax
	subl	$1, %eax
	movw	%ax, -54(%rbp)
.L2:
	cmpw	$0, -54(%rbp)
	jne	.L3
	movb	$65, -56(%rbp)
	jmp	.L4
.L5:
	movsbl	-56(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
.L4:
	movzbl	-56(%rbp), %eax
	movl	%eax, %edx
	subl	$1, %edx
	movb	%dl, -56(%rbp)
	testb	%al, %al
	jne	.L5
	movl	$0, %esi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, -52(%rbp)
	movq	$0, -48(%rbp)
	movq	$0, -40(%rbp)
	movq	$0, -32(%rbp)
	movq	$0, -24(%rbp)
	movq	$0, -16(%rbp)
.L6:
	movzbl	-55(%rbp), %eax
	cltq
	movl	-48(%rbp,%rax,4), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-52(%rbp), %eax
	leal	1(%rax), %edx
	movl	%edx, -52(%rbp)
	cmpl	$9, %eax
	jle	.L6
	movl	$0, %edi
	call	exit@PLT
	.cfi_endproc
.LFE5:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
