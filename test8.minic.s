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
  addi $sp, $sp, -24
  li $t3, 0
  sw $t3, 20($sp)
  lw $t1, 20($sp)
  sw $t1, 12($sp)
  lw $t1, 12($sp)
  sw $t1, 20($sp)
  lw $t1, 12($sp)
  addi $t1, $t1, 1
  sw $t1, 12($sp)
  lw $t1, 20($sp)
  sw $t1, 16($sp)
  lw $a0, 12($sp)
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal write
  lw $ra,0($sp)
  addi $sp, $sp, 4
  lw $a0, 16($sp)
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal write
  lw $ra,0($sp)
  addi $sp, $sp, 4
  lw $t1, 12($sp)
  addi $t1, $t1, 1
  sw $t1, 12($sp)
  lw $t1, 12($sp)
  sw $t1, 20($sp)
  lw $t1, 20($sp)
  sw $t1, 16($sp)
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
