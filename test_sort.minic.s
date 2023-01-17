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
  addi $sp, $sp, -88
  li $t3, 0
  sw $t3, 0($sp)
  lw $t1, 0($sp)
  sw $t1, 36($sp)
label4:
  li $t3, 6
  sw $t3, 48($sp)
  lw $t1, 36($sp)
  lw $t2, 48($sp)
  blt $t1,$t2,label3
  j label2
label3:
  li $t3, 0
  sw $t3, 48($sp)
  li $t3, 4
  sw $t3, 48($sp)
  lw $t1, 48($sp)
  lw $t2, 36($sp)
  lw $t1, 48($sp)
  lw $t2, 36($sp)
  mul $t3,$t1,$t2
  sw $t3, 52($sp)
  lw $t1, 52($sp)
  lw $t2, 48($sp)
  lw $t1, 52($sp)
  lw $t2, 48($sp)
  add $t3,$t1,$t2
  sw $t3, 48($sp)
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal read
  lw $ra,0($sp)
  addi $sp, $sp, 4
  sw $v0, 60($sp)
  li $t1, 60
  addu $t1, $t1, $sp
  lw $t3, ($t1)
  sw $t3, 56($sp)
  j label4
label2:
  li $t3, 1
  sw $t3, 0($sp)
  lw $t1, 0($sp)
  sw $t1, 36($sp)
label7:
  li $t3, 5
  sw $t3, 48($sp)
  lw $t1, 36($sp)
  lw $t2, 48($sp)
  blt $t1,$t2,label6
  j label5
label6:
  j label7
label5:
  li $t3, 0
  sw $t3, 0($sp)
  lw $t1, 0($sp)
  sw $t1, 40($sp)
label10:
  li $t3, 6
  sw $t3, 48($sp)
  lw $t1, 48($sp)
  lw $t2, 36($sp)
  lw $t1, 48($sp)
  lw $t2, 36($sp)
  sub $t3,$t1,$t2
  sw $t3, 52($sp)
  lw $t1, 40($sp)
  lw $t2, 52($sp)
  blt $t1,$t2,label9
  j label8
label9:
  li $t3, 0
  sw $t3, 48($sp)
  li $t3, 4
  sw $t3, 48($sp)
  lw $t1, 48($sp)
  lw $t2, 40($sp)
  lw $t1, 48($sp)
  lw $t2, 40($sp)
  mul $t3,$t1,$t2
  sw $t3, 52($sp)
  lw $t1, 52($sp)
  lw $t2, 48($sp)
  lw $t1, 52($sp)
  lw $t2, 48($sp)
  add $t3,$t1,$t2
  sw $t3, 48($sp)
  li $t3, 0
  sw $t3, 48($sp)
  li $t3, 1
  sw $t3, 92($sp)
  lw $t1, 40($sp)
  lw $t2, 92($sp)
  lw $t1, 40($sp)
  lw $t2, 92($sp)
  add $t3,$t1,$t2
  sw $t3, 56($sp)
  li $t3, 4
  sw $t3, 64($sp)
  lw $t1, 64($sp)
  lw $t2, 56($sp)
  lw $t1, 64($sp)
  lw $t2, 56($sp)
  mul $t3,$t1,$t2
  sw $t3, 68($sp)
  lw $t1, 68($sp)
  lw $t2, 48($sp)
  lw $t1, 68($sp)
  lw $t2, 48($sp)
  add $t3,$t1,$t2
  sw $t3, 48($sp)
  lw $t1, 56($sp)
  lw $t2, 72($sp)
  bgt $t1,$t2,label11
  j 
label11:
  li $t3, 0
  sw $t3, 48($sp)
  li $t3, 4
  sw $t3, 48($sp)
  lw $t1, 48($sp)
  lw $t2, 40($sp)
  lw $t1, 48($sp)
  lw $t2, 40($sp)
  mul $t3,$t1,$t2
  sw $t3, 52($sp)
  lw $t1, 52($sp)
  lw $t2, 48($sp)
  lw $t1, 52($sp)
  lw $t2, 48($sp)
  add $t3,$t1,$t2
  sw $t3, 48($sp)
  li $t1, 56
  addu $t1, $t1, $sp
  lw $t3, ($t1)
  sw $t3, 44($sp)
  li $t3, 0
  sw $t3, 48($sp)
  li $t3, 4
  sw $t3, 48($sp)
  lw $t1, 48($sp)
  lw $t2, 40($sp)
  lw $t1, 48($sp)
  lw $t2, 40($sp)
  mul $t3,$t1,$t2
  sw $t3, 52($sp)
  lw $t1, 52($sp)
  lw $t2, 48($sp)
  lw $t1, 52($sp)
  lw $t2, 48($sp)
  add $t3,$t1,$t2
  sw $t3, 48($sp)
  li $t3, 0
  sw $t3, 60($sp)
  li $t3, 1
  sw $t3, 104($sp)
  lw $t1, 40($sp)
  lw $t2, 104($sp)
  lw $t1, 40($sp)
  lw $t2, 104($sp)
  add $t3,$t1,$t2
  sw $t3, 68($sp)
  li $t3, 4
  sw $t3, 76($sp)
  lw $t1, 76($sp)
  lw $t2, 68($sp)
  lw $t1, 76($sp)
  lw $t2, 68($sp)
  mul $t3,$t1,$t2
  sw $t3, 80($sp)
  lw $t1, 80($sp)
  lw $t2, 60($sp)
  lw $t1, 80($sp)
  lw $t2, 60($sp)
  add $t3,$t1,$t2
  sw $t3, 60($sp)
  li $t1, 84
  addu $t1, $t1, $sp
  lw $t3, ($t1)
  sw $t3, 56($sp)
  li $t3, 0
  sw $t3, 48($sp)
  li $t3, 1
  sw $t3, 92($sp)
  lw $t1, 40($sp)
  lw $t2, 92($sp)
  lw $t1, 40($sp)
  lw $t2, 92($sp)
  add $t3,$t1,$t2
  sw $t3, 56($sp)
  li $t3, 4
  sw $t3, 64($sp)
  lw $t1, 64($sp)
  lw $t2, 56($sp)
  lw $t1, 64($sp)
  lw $t2, 56($sp)
  mul $t3,$t1,$t2
  sw $t3, 68($sp)
  lw $t1, 68($sp)
  lw $t2, 48($sp)
  lw $t1, 68($sp)
  lw $t2, 48($sp)
  add $t3,$t1,$t2
  sw $t3, 48($sp)
  lw $t1, 44($sp)
  sw $t1, 72($sp)
  j label10
label8:
  li $t3, 0
  sw $t3, 0($sp)
  lw $t1, 0($sp)
  sw $t1, 36($sp)
label16:
  li $t3, 6
  sw $t3, 48($sp)
  lw $t1, 36($sp)
  lw $t2, 48($sp)
  blt $t1,$t2,label15
  j label14
label15:
  j label16
label14:
  li $t3, 0
  sw $t3, 48($sp)
  li $t3, 4
  sw $t3, 48($sp)
  lw $t1, 48($sp)
  lw $t2, 36($sp)
  lw $t1, 48($sp)
  lw $t2, 36($sp)
  mul $t3,$t1,$t2
  sw $t3, 52($sp)
  lw $t1, 52($sp)
  lw $t2, 48($sp)
  lw $t1, 52($sp)
  lw $t2, 48($sp)
  add $t3,$t1,$t2
  sw $t3, 48($sp)
  lw $a0, 56($sp)
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal write
  lw $ra,0($sp)
  addi $sp, $sp, 4
  li $t3, 1
  sw $t3, 48($sp)
  lw $v0,48($sp)
  jr $ra
label1:
