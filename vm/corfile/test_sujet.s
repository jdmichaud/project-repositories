.name    "zork"
.comment "just a basic living program"
	lc   r1, live-w+1
:w	st   [r1], r0
	lc   r2, live-j
live:	live 0
:j	bz   r2
