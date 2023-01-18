.data
_Prompt: .asciiz "Enter an integer:  "
_ret: .asciiz "\n"
.globl main0
.text
main0:
  addi $sp,$sp,-888
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
  addi $sp, $sp, -60
  li $t3, 1
  sw $t3, 16($sp)
  lw $t1, 16($sp)
  sw $t1, 12($sp)
  li $t3, 1
  sw $t3, 24($sp)
  lw $t1, 24($sp)
  sw $t1, 20($sp)
  li $t3, 0
  sw $t3, 36($sp)
  li $t3, 0
  sw $t3, 40($sp)
  li $t3, 4
  sw $t3, 44($sp)
  lw $t1, 44($sp)
  lw $t2, 40($sp)
  mul $t3,$t1,$t2
  sw $t3, 48($sp)
  lw $t1, 48($sp)
  lw $t2, 36($sp)
  add $t3,$t1,$t2
  sw $t3, 36($sp)
  li $t1, 28
  lw $t2, 36($sp)
  add $t2, $t2, $t1
  sw $t2, 52($sp)
  li $t3, 1
  sw $t3, 56($sp)
  lw $t1, 56($sp)
  lw $t2, 52($sp)
  add $t2, $t2, $sp
  sw $t1, ($t2)
  li $t3, 0
  sw $t3, 36($sp)
  li $t3, 0
  sw $t3, 40($sp)
  li $t3, 4
  sw $t3, 44($sp)
  lw $t1, 44($sp)
  lw $t2, 40($sp)
  mul $t3,$t1,$t2
  sw $t3, 48($sp)
  lw $t1, 48($sp)
  lw $t2, 36($sp)
  add $t3,$t1,$t2
  sw $t3, 36($sp)
  li $t1, 28
  lw $t2, 36($sp)
  add $t2, $t2, $t1
  sw $t2, 52($sp)
  lw $t1, 12($sp)
  lw $t2, 52($sp)
  sne $t1, $t1, $zero
  sne $t2, $t2, $zero
  or $t3,$t1,$t2
  sw $t3, 56($sp)
  lw $t1, 56($sp)
  sw $t1, 12($sp)
  lw $a0, 12($sp)
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal write
  lw $ra,0($sp)
  addi $sp, $sp, 4
  li $t3, 0
  sw $t3, 36($sp)
  lw $v0,36($sp)
  jr $ra
label1:
