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
  addi $sp, $sp, -36
  li $t3, 1
  sw $t3, 16($sp)
  lw $t1, 16($sp)
  sw $t1, 12($sp)
  li $t3, 2
  sw $t3, 24($sp)
  lw $t1, 24($sp)
  sw $t1, 20($sp)
  li $t3, 1
  sw $t3, 32($sp)
  lw $t1, 12($sp)
  lw $t2, 32($sp)
  beq $t1,$t2,label5
  j label4
label5:
  li $t3, 2
  sw $t3, 32($sp)
  lw $t1, 20($sp)
  lw $t2, 32($sp)
  beq $t1,$t2,label3
  j label4
label3:
  li $t3, 1
  sw $t3, 32($sp)
  lw $t1, 32($sp)
  sw $t1, 28($sp)
  j label2
label4:
  li $t3, 2
  sw $t3, 32($sp)
  lw $t1, 32($sp)
  sw $t1, 28($sp)
label2:
  li $t3, 0
  sw $t3, 32($sp)
  lw $v0,32($sp)
  jr $ra
label1:
