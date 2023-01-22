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
  addi $sp, $sp, -104
  li $t3, 0
  sw $t3, 56($sp)
  lw $t3, 56($sp)
  sw $t3, 36($sp)
label5:
  li $t3, 6
  sw $t3, 56($sp)
  lw $t1, 36($sp)
  lw $t2, 56($sp)
  blt $t1,$t2,label3
  j label2
label3:
  li $t3, 0
  sw $t3, 60($sp)
  li $t3, 4
  sw $t3, 64($sp)
  lw $t1, 64($sp)
  lw $t2, 36($sp)
  mul $t3,$t1,$t2
  sw $t3, 68($sp)
  lw $t1, 68($sp)
  lw $t2, 60($sp)
  add $t3,$t1,$t2
  sw $t3, 60($sp)
  li $t1, 12
  lw $t2, 60($sp)
  add $t2, $t2, $t1
  sw $t2, 72($sp)
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal read
  lw $ra,0($sp)
  addi $sp, $sp, 4
  sw $v0, 76($sp)
  lw $t3, 76($sp)
  lw $t1, 76($sp)
  lw $t2, 72($sp)
  add $t2, $t2, $sp
  sw $t3, ($t2)
label4:
  lw $t3, 36($sp)
  sw $t3, 80($sp)
  lw $t1, 36($sp)
  addi $t1, $t1, 1
  sw $t1, 36($sp)
  j label5
label2:
  li $t3, 1
  sw $t3, 56($sp)
  lw $t3, 56($sp)
  sw $t3, 36($sp)
label9:
  li $t3, 5
  sw $t3, 56($sp)
  lw $t1, 36($sp)
  lw $t2, 56($sp)
  blt $t1,$t2,label7
  j label6
label7:
  li $t3, 0
  sw $t3, 60($sp)
  lw $t3, 60($sp)
  sw $t3, 40($sp)
label12:
  li $t3, 6
  sw $t3, 60($sp)
  lw $t1, 60($sp)
  lw $t2, 36($sp)
  sub $t3,$t1,$t2
  sw $t3, 64($sp)
  lw $t1, 40($sp)
  lw $t2, 64($sp)
  blt $t1,$t2,label10
  j label8
label10:
  li $t3, 0
  sw $t3, 64($sp)
  li $t3, 4
  sw $t3, 68($sp)
  lw $t1, 68($sp)
  lw $t2, 40($sp)
  mul $t3,$t1,$t2
  sw $t3, 72($sp)
  lw $t1, 72($sp)
  lw $t2, 64($sp)
  add $t3,$t1,$t2
  sw $t3, 64($sp)
  li $t1, 12
  lw $t2, 64($sp)
  add $t2, $t2, $t1
  sw $t2, 76($sp)
  li $t3, 0
  sw $t3, 80($sp)
  li $t3, 1
  sw $t3, 84($sp)
  lw $t1, 40($sp)
  lw $t2, 84($sp)
  add $t3,$t1,$t2
  sw $t3, 88($sp)
  li $t3, 4
  sw $t3, 92($sp)
  lw $t1, 92($sp)
  lw $t2, 88($sp)
  mul $t3,$t1,$t2
  sw $t3, 96($sp)
  lw $t1, 96($sp)
  lw $t2, 80($sp)
  add $t3,$t1,$t2
  sw $t3, 80($sp)
  li $t1, 12
  lw $t2, 80($sp)
  add $t2, $t2, $t1
  sw $t2, 100($sp)
  lw $t4, 76($sp)
  addu $t4, $t4, $sp
  lw $t1, ($t4)
  lw $t4, 100($sp)
  addu $t4, $t4, $sp
  lw $t2, ($t4)
  bgt $t1,$t2,label13
  j label11
label13:
  li $t3, 0
  sw $t3, 64($sp)
  li $t3, 4
  sw $t3, 68($sp)
  lw $t1, 68($sp)
  lw $t2, 40($sp)
  mul $t3,$t1,$t2
  sw $t3, 72($sp)
  lw $t1, 72($sp)
  lw $t2, 64($sp)
  add $t3,$t1,$t2
  sw $t3, 64($sp)
  li $t1, 12
  lw $t2, 64($sp)
  add $t2, $t2, $t1
  sw $t2, 76($sp)
  lw $t1, 76($sp)
  addu $t1, $t1, $sp
  lw $t3, ($t1)
  sw $t3, 44($sp)
  li $t3, 0
  sw $t3, 64($sp)
  li $t3, 4
  sw $t3, 68($sp)
  lw $t1, 68($sp)
  lw $t2, 40($sp)
  mul $t3,$t1,$t2
  sw $t3, 72($sp)
  lw $t1, 72($sp)
  lw $t2, 64($sp)
  add $t3,$t1,$t2
  sw $t3, 64($sp)
  li $t1, 12
  lw $t2, 64($sp)
  add $t2, $t2, $t1
  sw $t2, 76($sp)
  li $t3, 0
  sw $t3, 80($sp)
  li $t3, 1
  sw $t3, 84($sp)
  lw $t1, 40($sp)
  lw $t2, 84($sp)
  add $t3,$t1,$t2
  sw $t3, 88($sp)
  li $t3, 4
  sw $t3, 92($sp)
  lw $t1, 92($sp)
  lw $t2, 88($sp)
  mul $t3,$t1,$t2
  sw $t3, 96($sp)
  lw $t1, 96($sp)
  lw $t2, 80($sp)
  add $t3,$t1,$t2
  sw $t3, 80($sp)
  li $t1, 12
  lw $t2, 80($sp)
  add $t2, $t2, $t1
  sw $t2, 100($sp)
  lw $t1, 100($sp)
  addu $t1, $t1, $sp
  lw $t3, ($t1)
  lw $t1, 100($sp)
  lw $t2, 76($sp)
  add $t2, $t2, $sp
  sw $t3, ($t2)
  li $t3, 0
  sw $t3, 64($sp)
  li $t3, 1
  sw $t3, 68($sp)
  lw $t1, 40($sp)
  lw $t2, 68($sp)
  add $t3,$t1,$t2
  sw $t3, 72($sp)
  li $t3, 4
  sw $t3, 76($sp)
  lw $t1, 76($sp)
  lw $t2, 72($sp)
  mul $t3,$t1,$t2
  sw $t3, 80($sp)
  lw $t1, 80($sp)
  lw $t2, 64($sp)
  add $t3,$t1,$t2
  sw $t3, 64($sp)
  li $t1, 12
  lw $t2, 64($sp)
  add $t2, $t2, $t1
  sw $t2, 84($sp)
  lw $t3, 44($sp)
  lw $t1, 44($sp)
  lw $t2, 84($sp)
  add $t2, $t2, $sp
  sw $t3, ($t2)
label11:
  lw $t3, 40($sp)
  sw $t3, 104($sp)
  lw $t1, 40($sp)
  addi $t1, $t1, 1
  sw $t1, 40($sp)
  j label12
label8:
  lw $t3, 36($sp)
  sw $t3, 104($sp)
  lw $t1, 36($sp)
  addi $t1, $t1, 1
  sw $t1, 36($sp)
  j label9
label6:
  li $t3, 0
  sw $t3, 56($sp)
  lw $t3, 56($sp)
  sw $t3, 36($sp)
label19:
  li $t3, 6
  sw $t3, 56($sp)
  lw $t1, 36($sp)
  lw $t2, 56($sp)
  blt $t1,$t2,label17
  j label16
label17:
  li $t3, 0
  sw $t3, 60($sp)
  li $t3, 4
  sw $t3, 64($sp)
  lw $t1, 64($sp)
  lw $t2, 36($sp)
  mul $t3,$t1,$t2
  sw $t3, 68($sp)
  lw $t1, 68($sp)
  lw $t2, 60($sp)
  add $t3,$t1,$t2
  sw $t3, 60($sp)
  li $t1, 12
  lw $t2, 60($sp)
  add $t2, $t2, $t1
  sw $t2, 72($sp)
  lw $t4, 72($sp)
  add $t4, $t4, $sp
  lw $a0, ($t4)
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal write
  lw $ra,0($sp)
  addi $sp, $sp, 4
label18:
  lw $t3, 36($sp)
  sw $t3, 80($sp)
  lw $t1, 36($sp)
  addi $t1, $t1, 1
  sw $t1, 36($sp)
  j label19
label16:
  li $t3, 1
  sw $t3, 56($sp)
  lw $v0,56($sp)
  jr $ra
label1:
