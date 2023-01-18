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
  addi $sp, $sp, -20
  li $t3, 1
  sw $t3, 16($sp)
  lw $t1, 16($sp)
  sw $t1, 12($sp)
  lw $t1, 12($sp)
  lw $t2, 4($sp)
  neg $t3, $t1
  sw $t3, 16($sp)
  lw $t1, 16($sp)
  sw $t1, 12($sp)
  lw $a0, 12($sp)
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal write
  lw $ra,0($sp)
  addi $sp, $sp, 4
label1:
