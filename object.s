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
  addi $sp, $sp, -140
  li $t3, 1
  sw $t3, 68($sp)
  lw $t1, 68($sp)
  sw $t1, 64($sp)
  li $t3, 0
  sw $t3, 72($sp)
  li $t3, 1
  sw $t3, 140($sp)
  lw $t1, 64($sp)
  lw $t2, 140($sp)
  sub $t3,$t1,$t2
  sw $t3, 80($sp)
  li $t3, 1
  sw $t3, 152($sp)
  lw $t1, 80($sp)
  lw $t2, 152($sp)
  add $t3,$t1,$t2
  sw $t3, 88($sp)
  li $t3, 4
  sw $t3, 108($sp)
  lw $t1, 108($sp)
  lw $t2, 88($sp)
  mul $t3,$t1,$t2
  sw $t3, 112($sp)
  lw $t1, 112($sp)
  lw $t2, 72($sp)
  add $t3,$t1,$t2
  sw $t3, 72($sp)
  li $t3, 12
  sw $t3, 116($sp)
  lw $t1, 116($sp)
  lw $t2, 104($sp)
  mul $t3,$t1,$t2
  sw $t3, 120($sp)
  lw $t1, 120($sp)
  lw $t2, 72($sp)
  add $t3,$t1,$t2
  sw $t3, 72($sp)
  li $t3, 24
  sw $t3, 124($sp)
  lw $t1, 124($sp)
  lw $t2, 64($sp)
  mul $t3,$t1,$t2
  sw $t3, 128($sp)
  lw $t1, 128($sp)
  lw $t2, 72($sp)
  add $t3,$t1,$t2
  sw $t3, 72($sp)
  li $t3, 20
  sw $t3, 136($sp)
  lw $t1, 136($sp)
  sw $t1, 132($sp)
  li $t3, 0
  sw $t3, 72($sp)
  li $t3, 1
  sw $t3, 140($sp)
  lw $t1, 64($sp)
  lw $t2, 140($sp)
  sub $t3,$t1,$t2
  sw $t3, 80($sp)
  li $t3, 1
  sw $t3, 152($sp)
  lw $t1, 80($sp)
  lw $t2, 152($sp)
  add $t3,$t1,$t2
  sw $t3, 88($sp)
  li $t3, 4
  sw $t3, 108($sp)
  lw $t1, 108($sp)
  lw $t2, 88($sp)
  mul $t3,$t1,$t2
  sw $t3, 112($sp)
  lw $t1, 112($sp)
  lw $t2, 72($sp)
  add $t3,$t1,$t2
  sw $t3, 72($sp)
  li $t3, 12
  sw $t3, 116($sp)
  lw $t1, 116($sp)
  lw $t2, 104($sp)
  mul $t3,$t1,$t2
  sw $t3, 120($sp)
  lw $t1, 120($sp)
  lw $t2, 72($sp)
  add $t3,$t1,$t2
  sw $t3, 72($sp)
  li $t3, 24
  sw $t3, 124($sp)
  lw $t1, 124($sp)
  lw $t2, 64($sp)
  mul $t3,$t1,$t2
  sw $t3, 128($sp)
  lw $t1, 128($sp)
  lw $t2, 72($sp)
  add $t3,$t1,$t2
  sw $t3, 72($sp)
  li $t1, 132
  addu $t1, $t1, $sp
  lw $t3, ($t1)
  sw $t3, 60($sp)
  lw $a0, 60($sp)
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal write
  lw $ra,0($sp)
  addi $sp, $sp, 4
  li $t3, 0
  sw $t3, 72($sp)
  lw $v0,72($sp)
  jr $ra
label1:
