.data
_Prompt: .asciiz "Enter an integer:  "
_ret: .asciiz "\n"
.globl main0
.text
main0:
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
  sw $t3, 56($sp)
  lw $t1, 56($sp)
  sw $t1, 44($sp)
  li $t3, 0
  sw $t3, 56($sp)
  lw $v0,56($sp)
  jr $ra
label1:
