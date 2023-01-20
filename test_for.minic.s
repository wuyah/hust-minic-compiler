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
  addi $sp, $sp, -36
  li $t3, 1
  sw $t3, 24($sp)
  lw $t3, 24($sp)
  sw $t3, 20($sp)
  li $t3, 0
  sw $t3, 24($sp)
  lw $t3, 24($sp)
  sw $t3, 12($sp)
label6:
  li $t3, 3
  sw $t3, 24($sp)
  lw $t1, 12($sp)
  lw $t2, 24($sp)
  blt $t1,$t2,label4
  j label3
label4:
  li $t3, 0
  sw $t3, 28($sp)
  lw $t3, 28($sp)
  sw $t3, 16($sp)
label9:
  li $t3, 4
  sw $t3, 28($sp)
  lw $t1, 16($sp)
  lw $t2, 28($sp)
  blt $t1,$t2,label7
  j label5
label7:
  lw $a0, 20($sp)
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal write
  lw $ra,0($sp)
  addi $sp, $sp, 4
label8:
  lw $t3, 16($sp)
  sw $t3, 36($sp)
  lw $t1, 16($sp)
  addi $t1, $t1, 1
  sw $t1, 16($sp)
  j label9
label5:
  lw $t3, 12($sp)
  sw $t3, 36($sp)
  lw $t1, 12($sp)
  addi $t1, $t1, 1
  sw $t1, 12($sp)
  j label6
label3:
  li $t3, 0
  sw $t3, 24($sp)
  lw $v0,24($sp)
  jr $ra
label1:
