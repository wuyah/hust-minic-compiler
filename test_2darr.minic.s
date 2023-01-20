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
  addi $sp, $sp, -108
  li $t3, 0
  sw $t3, 60($sp)
  lw $t3, 60($sp)
  sw $t3, 44($sp)
label5:
  li $t3, 2
  sw $t3, 60($sp)
  lw $t1, 44($sp)
  lw $t2, 60($sp)
  blt $t1,$t2,label3
  j label2
label3:
  li $t3, 0
  sw $t3, 64($sp)
  lw $t3, 64($sp)
  sw $t3, 48($sp)
label8:
  li $t3, 2
  sw $t3, 64($sp)
  lw $t1, 48($sp)
  lw $t2, 64($sp)
  blt $t1,$t2,label6
  j label4
label6:
  li $t3, 0
  sw $t3, 68($sp)
  lw $t3, 68($sp)
  sw $t3, 52($sp)
label11:
  li $t3, 2
  sw $t3, 68($sp)
  lw $t1, 52($sp)
  lw $t2, 68($sp)
  blt $t1,$t2,label9
  j label7
label9:
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal read
  lw $ra,0($sp)
  addi $sp, $sp, 4
  sw $v0, 72($sp)
  lw $t3, 72($sp)
  sw $t3, 56($sp)
  li $t3, 0
  sw $t3, 72($sp)
  li $t3, 4
  sw $t3, 76($sp)
  lw $t1, 76($sp)
  lw $t2, 52($sp)
  mul $t3,$t1,$t2
  sw $t3, 80($sp)
  lw $t1, 80($sp)
  lw $t2, 72($sp)
  add $t3,$t1,$t2
  sw $t3, 72($sp)
  li $t3, 8
  sw $t3, 84($sp)
  lw $t1, 84($sp)
  lw $t2, 48($sp)
  mul $t3,$t1,$t2
  sw $t3, 88($sp)
  lw $t1, 88($sp)
  lw $t2, 72($sp)
  add $t3,$t1,$t2
  sw $t3, 72($sp)
  li $t3, 16
  sw $t3, 92($sp)
  lw $t1, 92($sp)
  lw $t2, 44($sp)
  mul $t3,$t1,$t2
  sw $t3, 96($sp)
  lw $t1, 96($sp)
  lw $t2, 72($sp)
  add $t3,$t1,$t2
  sw $t3, 72($sp)
  li $t1, 12
  lw $t2, 72($sp)
  add $t2, $t2, $t1
  sw $t2, 100($sp)
  lw $t3, 56($sp)
  lw $t1, 56($sp)
  lw $t2, 100($sp)
  add $t2, $t2, $sp
  sw $t3, ($t2)
label10:
  lw $t3, 52($sp)
  sw $t3, 104($sp)
  lw $t1, 52($sp)
  addi $t1, $t1, 1
  sw $t1, 52($sp)
  j label11
label7:
  lw $t3, 48($sp)
  sw $t3, 104($sp)
  lw $t1, 48($sp)
  addi $t1, $t1, 1
  sw $t1, 48($sp)
  j label8
label4:
  lw $t3, 44($sp)
  sw $t3, 104($sp)
  lw $t1, 44($sp)
  addi $t1, $t1, 1
  sw $t1, 44($sp)
  j label5
label2:
  li $t3, 0
  sw $t3, 60($sp)
  lw $t3, 60($sp)
  sw $t3, 44($sp)
label16:
  li $t3, 2
  sw $t3, 60($sp)
  lw $t1, 44($sp)
  lw $t2, 60($sp)
  blt $t1,$t2,label14
  j label13
label14:
  li $t3, 0
  sw $t3, 64($sp)
  lw $t3, 64($sp)
  sw $t3, 48($sp)
label19:
  li $t3, 2
  sw $t3, 64($sp)
  lw $t1, 48($sp)
  lw $t2, 64($sp)
  blt $t1,$t2,label17
  j label15
label17:
  li $t3, 0
  sw $t3, 68($sp)
  lw $t3, 68($sp)
  sw $t3, 52($sp)
label22:
  li $t3, 2
  sw $t3, 68($sp)
  lw $t1, 52($sp)
  lw $t2, 68($sp)
  blt $t1,$t2,label20
  j label18
label20:
  li $t3, 0
  sw $t3, 72($sp)
  li $t3, 4
  sw $t3, 76($sp)
  lw $t1, 76($sp)
  lw $t2, 52($sp)
  mul $t3,$t1,$t2
  sw $t3, 80($sp)
  lw $t1, 80($sp)
  lw $t2, 72($sp)
  add $t3,$t1,$t2
  sw $t3, 72($sp)
  li $t3, 8
  sw $t3, 84($sp)
  lw $t1, 84($sp)
  lw $t2, 48($sp)
  mul $t3,$t1,$t2
  sw $t3, 88($sp)
  lw $t1, 88($sp)
  lw $t2, 72($sp)
  add $t3,$t1,$t2
  sw $t3, 72($sp)
  li $t3, 16
  sw $t3, 92($sp)
  lw $t1, 92($sp)
  lw $t2, 44($sp)
  mul $t3,$t1,$t2
  sw $t3, 96($sp)
  lw $t1, 96($sp)
  lw $t2, 72($sp)
  add $t3,$t1,$t2
  sw $t3, 72($sp)
  li $t1, 12
  lw $t2, 72($sp)
  add $t2, $t2, $t1
  sw $t2, 100($sp)
  lw $t4, 100($sp)
  add $t4, $t4, $sp
  lw $a0, ($t4)
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal write
  lw $ra,0($sp)
  addi $sp, $sp, 4
label21:
  lw $t3, 52($sp)
  sw $t3, 108($sp)
  lw $t1, 52($sp)
  addi $t1, $t1, 1
  sw $t1, 52($sp)
  j label22
label18:
  lw $t3, 48($sp)
  sw $t3, 108($sp)
  lw $t1, 48($sp)
  addi $t1, $t1, 1
  sw $t1, 48($sp)
  j label19
label15:
  lw $t3, 44($sp)
  sw $t3, 108($sp)
  lw $t1, 44($sp)
  addi $t1, $t1, 1
  sw $t1, 44($sp)
  j label16
label13:
  li $t3, 0
  sw $t3, 60($sp)
  lw $v0,60($sp)
  jr $ra
label1:
