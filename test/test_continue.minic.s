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
  addi $sp, $sp, -32
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
  li $t3, 4
  sw $t3, 24($sp)
  lw $t1, 12($sp)
  lw $t2, 24($sp)
  beq $t1,$t2,label7
  j label6
label7:
  lw $t1, 12($sp)
  sw $t1, 24($sp)
  lw $t1, 12($sp)
  addi $t1, $t1, 1
  sw $t1, 12($sp)
  li $t3, 4
  sw $t3, 24($sp)
  lw $t1, 24($sp)
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
  j label5
label6:
  li $t3, 3
  sw $t3, 24($sp)
  lw $t1, 24($sp)
  sw $t1, 16($sp)
  lw $a0, 12($sp)
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal write
  lw $ra,0($sp)
  addi $sp, $sp, 4
  lw $t1, 12($sp)
  sw $t1, 24($sp)
  lw $t1, 12($sp)
  addi $t1, $t1, 1
  sw $t1, 12($sp)
  j label5
label3:
  lw $a0, 16($sp)
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal write
  lw $ra,0($sp)
  addi $sp, $sp, 4
  li $t3, 0
  sw $t3, 36($sp)
  lw $t1, 12($sp)
  lw $t2, 36($sp)
  sub $t3,$t1,$t2
  sw $t3, 28($sp)
label18:
  li $t3, 5
  sw $t3, 24($sp)
  lw $t1, 12($sp)
  lw $t2, 24($sp)
  blt $t1,$t2,label16
  j label15
label16:
  li $t3, 4
  sw $t3, 32($sp)
  lw $t1, 12($sp)
  lw $t2, 32($sp)
  beq $t1,$t2,label20
  j label19
label20:
  lw $t1, 12($sp)
  sw $t1, 32($sp)
  lw $t1, 12($sp)
  addi $t1, $t1, 1
  sw $t1, 12($sp)
  li $t3, 4
  sw $t3, 32($sp)
  lw $t1, 32($sp)
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
  j label17
label19:
  li $t3, 3
  sw $t3, 32($sp)
  lw $t1, 32($sp)
  sw $t1, 16($sp)
  lw $a0, 12($sp)
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal write
  lw $ra,0($sp)
  addi $sp, $sp, 4
label17:
  lw $t1, 12($sp)
  sw $t1, 36($sp)
  lw $t1, 12($sp)
  addi $t1, $t1, 1
  sw $t1, 12($sp)
  j label18
label15:
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
  li $t3, 0
  sw $t3, 24($sp)
  lw $v0,24($sp)
  jr $ra
label1:
