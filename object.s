.data
_Prompt: .asciiz "Enter an integer:  "
_ret: .asciiz "\n"
.globl main0
.text
main0:
  addi $sp,$sp,-666
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

main:
  addi $sp, $sp, -56
  li.s $f3, 0.000000
  s.s $f3, 20($sp)
  li $t1, 20
  addu $t1, $t1, $sp
  lw $t3, ($t1)
  sw $t3, 12($sp)
  li $t3, 2
  sw $t3, 20($sp)
  lw $t1, 20($sp)
  sw $t1, 16($sp)
  l.s $f1, 12($sp)
  li.s $f2, 0.0
  c.eq.s $f1, $f2
  cfc1 $t0, $31
  sne $t3, $t0, $zero
  sw $t3, 20($sp)
  l.s $f1, 20($sp)
  li.s $f2, 0.0
  c.eq.s $f1, $f2
  cfc1 $t0, $31
  sne $t3, $t0, $zero
  sw $t3, 24($sp)
  li $t1, 24
  addu $t1, $t1, $sp
  lw $t3, ($t1)
  sw $t3, 16($sp)
  li $t3, 2
  sw $t3, 20($sp)
  li $t3, 3
  sw $t3, 40($sp)
  lw $t1, 20($sp)
  lw $t2, 40($sp)
  lw $t1, 20($sp)
  lw $t2, 40($sp)
  add $t3,$t1,$t2
  sw $t3, 28($sp)
  li $t3, 4
  sw $t3, 40($sp)
  li $t3, 5
  sw $t3, 80($sp)
  lw $t1, 40($sp)
  lw $t2, 80($sp)
  lw $t1, 40($sp)
  lw $t2, 80($sp)
  mul $t3,$t1,$t2
  sw $t3, 48($sp)
  li $t3, 2
  sw $t3, 80($sp)
  lw $t1, 48($sp)
  lw $t2, 80($sp)
  lw $t1, 48($sp)
  lw $t2, 80($sp)
  div $t1, $t2
  mflo $t3
  sw $t3, 56($sp)
  lw $t1, 28($sp)
  lw $t2, 56($sp)
  lw $t1, 28($sp)
  lw $t2, 56($sp)
  add $t3,$t1,$t2
  sw $t3, 52($sp)
  li $t1, 52
  addu $t1, $t1, $sp
  lw $t3, ($t1)
  sw $t3, 16($sp)
  lw $a0, 16($sp)
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal write
  lw $ra,0($sp)
  addi $sp, $sp, 4
  li $t3, 0
  sw $t3, 20($sp)
  lw $v0,20($sp)
  jr $ra
label1:
