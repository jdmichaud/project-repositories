.name "ceci e\0st un pu&&%^$#&^ de nom de ouf ki prends de la place"


		.comment	"no comment 23 159806 24wh5t bnjrt g"

debut:	ll	r2, 0x612f+074-end+fin	# Debut du programme
	xor	r1, r1
	mov	r1, r2
	ll	r5, boucle-fin
	ll	r6, fils-b
	ll	r7, debut-end
boucle:	live	1
	dec	r1, 1
:fin	bz	r5

a:b	fork			# On cree un fils
	bz	r6
	die			# Le pere meurt, c triste ...
	
fils:	stat	r15, 0765	# On demande des stat au fils
	swp	r3, r4
	jmp	r7		# On recommence
:end
	mov	r5 , r9
	swp	r12  , r5
	not	r7, r1
	and	r1, r1
	or	r2 , r3
	rol	r8, 546+654
	asr	r10, 014
	add	r5, r8
	sub		r7, r0
	rsb	r6   , r0
	neg r4, r1
	inc r6  , 1
	dec r9 , 0xb
	lsl	r11, 42 #magic number
	lsr		r13, 87
	lp	1+8-0xa
	bnz	r5
	bz	r6
	ld	r4 , [r8]
	st				 [r2]    , r5
	lc r0, 7-5+02
	fork
	push    r7
	pop r3
	fl	r8, [r9]
	write r9
