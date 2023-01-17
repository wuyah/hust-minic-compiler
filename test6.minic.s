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
  addi $sp, $sp, -60
  li $t3, 1
  sw $t3, 28($sp)
  lw $t1, 28($sp)
  sw $t1, 24($sp)
  li $t3, 0
  sw $t3, 32($sp)
  li $t3, 0
  sw $t3, 36($sp)
  li $t3, 4
  sw $t3, 40($sp)
  lw $t1, 40($sp)
  lw $t2, 36($sp)
  lw $t1, 40($sp)
  lw $t2, 36($sp)
  mul $t3,$t1,$t2
  sw $t3, 44($sp)
  lw $t1, 44($sp)
  lw $t2, 32($sp)
  lw $t1, 44($sp)
  lw $t2, 32($sp)
  add $t3,$t1,$t2
  sw $t3, 32($sp)
  li $t3, 1
  sw $t3, 52($sp)
  lw $t1, 52($sp)
  sw $t1, 48($sp)
  li $t3, 0
  sw $t3, 32($sp)
  li $t3, 0
  sw $t3, 36($sp)
  li $t3, 4
  sw $t3, 40($sp)
  lw $t1, 40($sp)
  lw $t2, 36($sp)
  lw $t1, 40($sp)
  lw $t2, 36($sp)
  mul $t3,$t1,$t2
  sw $t3, 44($sp)
  lw $t1, 44($sp)
  lw $t2, 32($sp)
  lw $t1, 44($sp)
  lw $t2, 32($sp)
  add $t3,$t1,$t2
  sw $t3, 32($sp)
  li $t3, 1
  sw $t3, 64($sp)
  lw $t1, 48($sp)
  lw $t2, 64($sp)
  lw $t1, 48($sp)
  lw $t2, 64($sp)
  add $t3,$t1,$t2
  sw $t3, 56($sp)
  li $t1, 56
  addu $t1, $t1, $sp
  lw $t3, ($t1)
  sw $t3, 20($sp)
  lw $a0, 20($sp)
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal write
  lw $ra,0($sp)
  addi $sp, $sp, 4
  li $t3, 1
  sw $t3, 52($sp)
  lw $t1, 20($sp)
  lw $t2, 52($sp)
  lw $t1, 20($sp)
  lw $t2, 52($sp)
  add $t3,$t1,$t2
  sw $t3, 36($sp)
  li $t1, 36
  addu $t1, $t1, $sp
  lw $t3, ($t1)
  sw $t3, 20($sp)
  lw $a0, 20($sp)
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal write
  lw $ra,0($sp)
  addi $sp, $sp, 4
  li $t3, 0
  sw $t3, 32($sp)
  li $t3, 0
  sw $t3, 36($sp)
  li $t3, 4
  sw $t3, 40($sp)
  lw $t1, 40($sp)
  lw $t2, 36($sp)
  lw $t1, 40($sp)
  lw $t2, 36($sp)
  mul $t3,$t1,$t2
  sw $t3, 44($sp)
  lw $t1, 44($sp)
  lw $t2, 32($sp)
  lw $t1, 44($sp)
  lw $t2, 32($sp)
  add $t3,$t1,$t2
  sw $t3, 32($sp)
  lw $a0, 48($sp)
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal write
  lw $ra,0($sp)
  addi $sp, $sp, 4
  li $t3, 0
  sw $t3, 32($sp)
  lw $v0,32($sp)
  jr $ra
label1:
