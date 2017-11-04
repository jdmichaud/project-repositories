.name "Une simple torpille"
.comment "Ce n'est qu'un torpille."
        lp  3
        ll  r1, 0x0150
        add r0, r1
        rol r0, 0x0004
        ll  r1, 0x0006
        ll  r2, 0x2350
        ll  r3, 0x0007
        ll  r4, 0x0455
        ll  r5, 0x0008
        st  [r1], r0
        st  [r3], r2
        st  [r5], r4