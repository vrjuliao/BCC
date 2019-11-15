sd x29, 12(x16)
ld x29, 8(x16)
sub x17, x15, x14
nop # prevent conflict with MEM stage of [sd x29, 12(x16)]
nop # prevent conflict with MEM stage of [ld x29, 8(x16)]
beqz x17, label
add x15, x11, x14
sub x15, x30, x14