.name "toto"
.comment "tata"
	
die # 2
live 0 # 4
mov r0, r15 # 8
swp r5, r8 # 12
not r1, r2 # 16
and r6, r7 # 20
lab1:	 # 20
or r8,r9 # 24
xor r1,r0 # 28
rol r8, 5+3-2-5-5 # 32   ----> -4
asr r0, lab1-lab2+8 # 36
:lab2 # 40
add r1,r13 # 40
lab3:lab4 # 40:44
sub r0, r2 # 44
rsb r1,r2 # 48
neg r1, r2 # 52
inc r1, lab3-lab4+0-0+1-1+8-lab1 # 56 --> -16
dec r8, -0 # 60
lsl r3,-1 # 64
lsr r0, 8 # 68
lp 0 # 70
bnz r5 # 72
bz r1 # 74
ld r1, [r5] # 77
st [r3], r0 # 80
lc r0, 8+2 # 84
ll r1, 5+6+8+9+lab1-lab2+0x3f-012 # 90 --->75
fork # 92
push r6 # 95
pop r8 # 98
jmp r0 # 101
fl r2, [r8] # 105
write r0 # 108
stat r0, 5+6-lab1 # 112 ---> -25
