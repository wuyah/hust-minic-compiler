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
  addi $sp, $sp, -28
  li $t3, 0
  sw $t3, 24($sp)
  lw $t1, 24($sp)
  sw $t1, 12($sp)
label5:
  li $t3, 5
  sw $t3, 24($sp)
  lw $t1, 12($sp)
  lw $t2, 24($sp)
  blt $t1,$t2,label4
  j label3
label4:
  lw $t1, 12($sp)
  sw $t1, 24($sp)
  lw $t1, 12($sp)
  addi $t1, $t1, 1
  sw $t1, 12($sp)
  li $t3, 0
  sw $t3, 24($sp)
  lw $t1, 24($sp)
  sw $t1, 16($sp)
label10:
  li $t3, 3
  sw $t3, 24($sp)
  lw $t1, 16($sp)
  lw $t2, 24($sp)
  blt $t1,$t2,label9
  j label8
label9:
  lw $t1, 16($sp)
  sw $t1, 24($sp)
  lw $t1, 16($sp)
  addi $t1, $t1, 1
  sw $t1, 16($sp)
  li $t3, 1
  sw $t3, 24($sp)
  lw $t1, 16($sp)
  lw $t2, 24($sp)
  beq $t1,$t2,label12
  j label10
label12:
  j label8
  j label10
label8:
  lw $a0, 16($sp)
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal write
  lw $ra,0($sp)
  addi $sp, $sp, 4
  li $t3, 3
  sw $t3, 24($sp)
  lw $t1, 12($sp)
  lw $t2, 24($sp)
  beq $t1,$t2,label14
  j label5
label14:
  j label3
  j label5
label3:
  lw $a0, 12($sp)
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal write
  lw $ra,0($sp)
  addi $sp, $sp, 4
  li $t3, 0
  sw $t3, 24($sp)
  lw $t1, 24($sp)
  sw $t1, 12($sp)
label19:
  li $t3, 5
  sw $t3, 24($sp)
  lw $t1, 12($sp)
  lw $t2, 24($sp)
  blt $t1,$t2,label17
  j label16
label17:
  lw $t1, 12($sp)
  sw $t1, 28($sp)
  lw $t1, 12($sp)
  addi $t1, $t1, 1
  sw $t1, 12($sp)
  li $t3, 0
  sw $t3, 28($sp)
  lw $t1, 28($sp)
  sw $t1, 16($sp)
label24:
  li $t3, 3
  sw $t3, 28($sp)
  lw $t1, 16($sp)
  lw $t2, 28($sp)
  blt $t1,$t2,label23
  j label22
label23:
  lw $t1, 16($sp)
  sw $t1, 28($sp)
  lw $t1, 16($sp)
  addi $t1, $t1, 1
  sw $t1, 16($sp)
  li $t3, 2
  sw $t3, 28($sp)
  lw $t1, 16($sp)
  lw $t2, 28($sp)
  beq $t1,$t2,label26
  j label24
label26:
  j label22
  j label24
label22:
  lw $a0, 16($sp)
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal write
  lw $ra,0($sp)
  addi $sp, $sp, 4
  li $t3, 3
  sw $t3, 28($sp)
  lw $t1, 12($sp)
  lw $t2, 28($sp)
  beq $t1,$t2,label28
  j label18
label28:
  j label16
label18:
  lw $t1, 12($sp)
  sw $t1, 12($sp)
  j label19
label16:
  lw $a0, 12($sp)
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal write
  lw $ra,0($sp)
  addi $sp, $sp, 4
  li $t3, 0
  sw $t3, 24($sp)
  lw $v0,24($sp)
  jr $ra
label1:
