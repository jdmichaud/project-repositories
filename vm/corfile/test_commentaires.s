#
#	TEST :	COMMENTAIRES
#
.name "Pandemonium de commentaires"
.comment "On va bien se marrer : le prog ne doit pas faire d'erreur"

	# Un classique, pour la route
	live	# Un en plein milieu, pour le fun
	1
	lc	# Un autre
	r0, 42
	lc	r1, 1 # Un normal, pas rigolo
	lc	r2 # Un milieu pas joli
	, 144
	lc	r15, loop
# Un en debut de ligne, pour le cas ou
loop:#Un juste apres un label, pour voir
	st	[r2], r0
	add	r2, r0
	sub	r0 # Plusieurs au milieu
	# Hop
	# Hop
	, r1
	bnz	r15
	die
# Et pour finir, un petit commentaire termine par EOF