.data
_Prompt: .asciiz "Enter an integer:  "
_ret: .asciiz "\n"
.globl main
.text
main0:
  addi $sp,$sp,0
  jal main
  li $v0, 10
  syscall
read:
  li $v0,4
  la $a0,_Prompt
  syscall
  li $v0,5
  syscall
  jr $ra
write:
  li $v0,1
  syscall
  li $v0,4
  la $a0,_ret
  syscall
  move $v0,$0
  jr $ra
writef:
  li $v0,2
  syscall
  li $v0,4
  la $a0,_ret
  syscall
  move $v0,$0
  jr $ra

main:
  addi $sp, $sp, -100
  li $t3, 1
  sw $t3, 32($sp)
  lw $t3, 32($sp)
  sw $t3, 28($sp)
  li $t3, 0
  sw $t3, 40($sp)
  lw $t3, 40($sp)
  sw $t3, 36($sp)
  li.s $f3, 1.200000
  s.s $f3, 44($sp)
  lw $t3, 44($sp)
  s.s $f3, 12($sp)
  lw $a0, 12($sp)
  mtc1 $a0, $f12
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal writef
  lw $ra,0($sp)
  addi $sp, $sp, 4
  li.s $f3, 1.200000
  s.s $f3, 44($sp)
  li.s $f3, 1.100000
  s.s $f3, 48($sp)
  lw $t1, 44($sp)
  lw $t2, 48($sp)
  mtc1 $t1, $f1
  mtc1 $t2, $f2
  add.s $f3,$f1,$f2
  s.s $f3, 52($sp)
  lw $t3, 52($sp)
  s.s $f3, 12($sp)
  lw $a0, 12($sp)
  mtc1 $a0, $f12
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal writef
  lw $ra,0($sp)
  addi $sp, $sp, 4
  li $t3, 0
  sw $t3, 44($sp)
  li $t3, 0
  sw $t3, 48($sp)
  li $t3, 4
  sw $t3, 52($sp)
  lw $t1, 52($sp)
  lw $t2, 48($sp)
  mul $t3,$t1,$t2
  sw $t3, 56($sp)
  lw $t1, 56($sp)
  lw $t2, 44($sp)
  add $t3,$t1,$t2
  sw $t3, 44($sp)
  li $t1, 16
  lw $t2, 44($sp)
  add $t2, $t2, $t1
  sw $t2, 60($sp)
  lw $t1, 28($sp)
  lw $t2, 36($sp)
  sne $t1, $t1, $zero
  sne $t2, $t2, $zero
  and $t3,$t1,$t2
  sw $t3, 64($sp)
  lw $t3, 64($sp)
  lw $t1, 64($sp)
  lw $t2, 60($sp)
  add $t2, $t2, $sp
  sw $t3, ($t2)
  li $t3, 0
  sw $t3, 44($sp)
  li $t3, 0
  sw $t3, 48($sp)
  li $t3, 4
  sw $t3, 52($sp)
  lw $t1, 52($sp)
  lw $t2, 48($sp)
  mul $t3,$t1,$t2
  sw $t3, 56($sp)
  lw $t1, 56($sp)
  lw $t2, 44($sp)
  add $t3,$t1,$t2
  sw $t3, 44($sp)
  li $t1, 16
  lw $t2, 44($sp)
  add $t2, $t2, $t1
  sw $t2, 60($sp)
  lw $t4, 60($sp)
  add $t4, $t4, $sp
  lw $a0, ($t4)
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal write
  lw $ra,0($sp)
  addi $sp, $sp, 4
  li $t3, 0
  sw $t3, 44($sp)
  li $t3, 1
  sw $t3, 48($sp)
  li $t3, 4
  sw $t3, 52($sp)
  lw $t1, 52($sp)
  lw $t2, 48($sp)
  mul $t3,$t1,$t2
  sw $t3, 56($sp)
  lw $t1, 56($sp)
  lw $t2, 44($sp)
  add $t3,$t1,$t2
  sw $t3, 44($sp)
  li $t1, 16
  lw $t2, 44($sp)
  add $t2, $t2, $t1
  sw $t2, 60($sp)
  lw $t1, 28($sp)
  lw $t2, 36($sp)
  sne $t1, $t1, $zero
  sne $t2, $t2, $zero
  or $t3,$t1,$t2
  sw $t3, 64($sp)
  lw $t3, 64($sp)
  lw $t1, 64($sp)
  lw $t2, 60($sp)
  add $t2, $t2, $sp
  sw $t3, ($t2)
  li $t3, 0
  sw $t3, 44($sp)
  li $t3, 1
  sw $t3, 48($sp)
  li $t3, 4
  sw $t3, 52($sp)
  lw $t1, 52($sp)
  lw $t2, 48($sp)
  mul $t3,$t1,$t2
  sw $t3, 56($sp)
  lw $t1, 56($sp)
  lw $t2, 44($sp)
  add $t3,$t1,$t2
  sw $t3, 44($sp)
  li $t1, 16
  lw $t2, 44($sp)
  add $t2, $t2, $t1
  sw $t2, 60($sp)
  lw $t4, 60($sp)
  add $t4, $t4, $sp
  lw $a0, ($t4)
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal write
  lw $ra,0($sp)
  addi $sp, $sp, 4
  li $t3, 0
  sw $t3, 44($sp)
  lw $t3, 44($sp)
  sw $t3, 12($sp)
  li $t3, 2
  sw $t3, 44($sp)
  lw $t3, 44($sp)
  sw $t3, 16($sp)
  li $t3, 0
  sw $t3, 44($sp)
  li $t3, 2
  sw $t3, 48($sp)
  li $t3, 4
  sw $t3, 52($sp)
  lw $t1, 52($sp)
  lw $t2, 48($sp)
  mul $t3,$t1,$t2
  sw $t3, 56($sp)
  lw $t1, 56($sp)
  lw $t2, 44($sp)
  add $t3,$t1,$t2
  sw $t3, 44($sp)
  li $t1, 16
  lw $t2, 44($sp)
  add $t2, $t2, $t1
  sw $t2, 60($sp)
  lw $t1, 12($sp)
  lw $t2, 4($sp)
  mtc1 $t1, $f1
  mtc1 $t2, $f2
  li.s $f2, 0.0
  c.eq.s $f1, $f2
  cfc1 $t0, $31
  sne $t3, $t0, $zero
  sw $t3, 64($sp)
  lw $t3, 64($sp)
  lw $t1, 64($sp)
  lw $t2, 60($sp)
  add $t2, $t2, $sp
  sw $t3, ($t2)
  li $t3, 0
  sw $t3, 44($sp)
  li $t3, 2
  sw $t3, 48($sp)
  li $t3, 4
  sw $t3, 52($sp)
  lw $t1, 52($sp)
  lw $t2, 48($sp)
  mul $t3,$t1,$t2
  sw $t3, 56($sp)
  lw $t1, 56($sp)
  lw $t2, 44($sp)
  add $t3,$t1,$t2
  sw $t3, 44($sp)
  li $t1, 16
  lw $t2, 44($sp)
  add $t2, $t2, $t1
  sw $t2, 60($sp)
  lw $t4, 60($sp)
  add $t4, $t4, $sp
  lw $a0, ($t4)
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal write
  lw $ra,0($sp)
  addi $sp, $sp, 4
  li $t3, 0
  sw $t3, 44($sp)
  li $t3, 1
  sw $t3, 48($sp)
  li $t3, 4
  sw $t3, 52($sp)
  lw $t1, 52($sp)
  lw $t2, 48($sp)
  mul $t3,$t1,$t2
  sw $t3, 56($sp)
  lw $t1, 56($sp)
  lw $t2, 44($sp)
  add $t3,$t1,$t2
  sw $t3, 44($sp)
  li $t1, 16
  lw $t2, 44($sp)
  add $t2, $t2, $t1
  sw $t2, 60($sp)
  li $t3, 2
  sw $t3, 64($sp)
  li $t3, 3
  sw $t3, 68($sp)
  lw $t1, 64($sp)
  lw $t2, 68($sp)
  add $t3,$t1,$t2
  sw $t3, 72($sp)
  li $t3, 4
  sw $t3, 76($sp)
  li $t3, 5
  sw $t3, 80($sp)
  lw $t1, 76($sp)
  lw $t2, 80($sp)
  mul $t3,$t1,$t2
  sw $t3, 84($sp)
  li $t3, 2
  sw $t3, 88($sp)
  lw $t1, 84($sp)
  lw $t2, 88($sp)
  div $t1, $t2
  mflo $t3
  sw $t3, 92($sp)
  lw $t1, 72($sp)
  lw $t2, 92($sp)
  add $t3,$t1,$t2
  sw $t3, 96($sp)
  lw $t3, 96($sp)
  lw $t1, 96($sp)
  lw $t2, 60($sp)
  add $t2, $t2, $sp
  sw $t3, ($t2)
  li $t3, 0
  sw $t3, 44($sp)
  li $t3, 1
  sw $t3, 48($sp)
  li $t3, 4
  sw $t3, 52($sp)
  lw $t1, 52($sp)
  lw $t2, 48($sp)
  mul $t3,$t1,$t2
  sw $t3, 56($sp)
  lw $t1, 56($sp)
  lw $t2, 44($sp)
  add $t3,$t1,$t2
  sw $t3, 44($sp)
  li $t1, 16
  lw $t2, 44($sp)
  add $t2, $t2, $t1
  sw $t2, 60($sp)
  li $t3, 15
  sw $t3, 64($sp)
  lw $t3, 64($sp)
  lw $t1, 64($sp)
  lw $t2, 60($sp)
  add $t2, $t2, $sp
  sw $t3, ($t2)
  li $t3, 0
  sw $t3, 44($sp)
  li $t3, 1
  sw $t3, 48($sp)
  li $t3, 4
  sw $t3, 52($sp)
  lw $t1, 52($sp)
  lw $t2, 48($sp)
  mul $t3,$t1,$t2
  sw $t3, 56($sp)
  lw $t1, 56($sp)
  lw $t2, 44($sp)
  add $t3,$t1,$t2
  sw $t3, 44($sp)
  li $t1, 16
  lw $t2, 44($sp)
  add $t2, $t2, $t1
  sw $t2, 60($sp)
  lw $t4, 60($sp)
  add $t4, $t4, $sp
  lw $a0, ($t4)
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal write
  lw $ra,0($sp)
  addi $sp, $sp, 4
  li $t3, 0
  sw $t3, 44($sp)
  li $t3, 1
  sw $t3, 48($sp)
  li $t3, 4
  sw $t3, 52($sp)
  lw $t1, 52($sp)
  lw $t2, 48($sp)
  mul $t3,$t1,$t2
  sw $t3, 56($sp)
  lw $t1, 56($sp)
  lw $t2, 44($sp)
  add $t3,$t1,$t2
  sw $t3, 44($sp)
  li $t1, 16
  lw $t2, 44($sp)
  add $t2, $t2, $t1
  sw $t2, 60($sp)
  li $t3, 0
  sw $t3, 64($sp)
  li $t3, 1
  sw $t3, 68($sp)
  li $t3, 4
  sw $t3, 72($sp)
  lw $t1, 72($sp)
  lw $t2, 68($sp)
  mul $t3,$t1,$t2
  sw $t3, 76($sp)
  lw $t1, 76($sp)
  lw $t2, 64($sp)
  add $t3,$t1,$t2
  sw $t3, 64($sp)
  li $t1, 16
  lw $t2, 64($sp)
  add $t2, $t2, $t1
  sw $t2, 80($sp)
  lw $t4, 80($sp)
  addu $t4, $t4, $sp
  lw $t1, ($t4)
  lw $t2, 4($sp)
  neg $t3, $t1
  sw $t3, 84($sp)
  lw $t3, 84($sp)
  lw $t1, 84($sp)
  lw $t2, 60($sp)
  add $t2, $t2, $sp
  sw $t3, ($t2)
  li $t3, 0
  sw $t3, 44($sp)
  li $t3, 1
  sw $t3, 48($sp)
  li $t3, 4
  sw $t3, 52($sp)
  lw $t1, 52($sp)
  lw $t2, 48($sp)
  mul $t3,$t1,$t2
  sw $t3, 56($sp)
  lw $t1, 56($sp)
  lw $t2, 44($sp)
  add $t3,$t1,$t2
  sw $t3, 44($sp)
  li $t1, 16
  lw $t2, 44($sp)
  add $t2, $t2, $t1
  sw $t2, 60($sp)
  lw $t4, 60($sp)
  add $t4, $t4, $sp
  lw $a0, ($t4)
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal write
  lw $ra,0($sp)
  addi $sp, $sp, 4
  li $t3, 0
  sw $t3, 44($sp)
  lw $v0,44($sp)
  jr $ra
label1:
