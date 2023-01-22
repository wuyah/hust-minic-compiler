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

func:
  lw $t1, 12($sp)
  lw $t2, 20($sp)
  mtc1 $t1, $f1
  mtc1 $t2, $f2
  add.s $f3,$f1,$f2
  s.s $f3, 28($sp)
  lw $v0,28($sp)
  jr $ra
label1:

main:
  addi $sp, $sp, -100
  li.s $f3, 1.100000
  s.s $f3, 16($sp)
  lw $t3, 16($sp)
  sw $t3, 12($sp)
  li.s $f3, 2.100000
  s.s $f3, 24($sp)
  lw $t3, 24($sp)
  sw $t3, 20($sp)
  li $t3, 0
  sw $t3, 48($sp)
  li $t3, 0
  sw $t3, 52($sp)
  li $t3, 4
  sw $t3, 56($sp)
  lw $t1, 56($sp)
  lw $t2, 52($sp)
  mul $t3,$t1,$t2
  sw $t3, 60($sp)
  lw $t1, 60($sp)
  lw $t2, 48($sp)
  add $t3,$t1,$t2
  sw $t3, 48($sp)
  li $t1, 32
  lw $t2, 48($sp)
  add $t2, $t2, $t1
  sw $t2, 64($sp)
  lw $t3, 12($sp)
  lw $t1, 12($sp)
  lw $t2, 64($sp)
  add $t2, $t2, $sp
  sw $t3, ($t2)
  li $t3, 0
  sw $t3, 48($sp)
  li $t3, 1
  sw $t3, 52($sp)
  li $t3, 4
  sw $t3, 56($sp)
  lw $t1, 56($sp)
  lw $t2, 52($sp)
  mul $t3,$t1,$t2
  sw $t3, 60($sp)
  lw $t1, 60($sp)
  lw $t2, 48($sp)
  add $t3,$t1,$t2
  sw $t3, 48($sp)
  li $t1, 32
  lw $t2, 48($sp)
  add $t2, $t2, $t1
  sw $t2, 64($sp)
  lw $t3, 20($sp)
  lw $t1, 20($sp)
  lw $t2, 64($sp)
  add $t2, $t2, $sp
  sw $t3, ($t2)
  li $t3, 0
  sw $t3, 48($sp)
  li $t3, 0
  sw $t3, 52($sp)
  li $t3, 4
  sw $t3, 56($sp)
  lw $t1, 56($sp)
  lw $t2, 52($sp)
  mul $t3,$t1,$t2
  sw $t3, 60($sp)
  lw $t1, 60($sp)
  lw $t2, 48($sp)
  add $t3,$t1,$t2
  sw $t3, 48($sp)
  li $t1, 32
  lw $t2, 48($sp)
  add $t2, $t2, $t1
  sw $t2, 64($sp)
  li $t3, 0
  sw $t3, 68($sp)
  li $t3, 1
  sw $t3, 72($sp)
  li $t3, 4
  sw $t3, 76($sp)
  lw $t1, 76($sp)
  lw $t2, 72($sp)
  mul $t3,$t1,$t2
  sw $t3, 80($sp)
  lw $t1, 80($sp)
  lw $t2, 68($sp)
  add $t3,$t1,$t2
  sw $t3, 68($sp)
  li $t1, 32
  lw $t2, 68($sp)
  add $t2, $t2, $t1
  sw $t2, 84($sp)
  lw $t4, 64($sp)
  addu $t4, $t4, $sp
  lw $t1, ($t4)
  lw $t4, 84($sp)
  addu $t4, $t4, $sp
  lw $t2, ($t4)
  mtc1 $t1, $f1
  mtc1 $t2, $f2
  sub.s $f3,$f1,$f2
  s.s $f3, 88($sp)
  li $t3, 1
  sw $t3, 92($sp)
  lw $t1, 88($sp)
  lw $t2, 92($sp)
  mtc1 $t1, $f1
  mtc1 $t2, $f2
  cvt.s.w $f2, $f2
  sub.s $f3,$f1,$f2
  s.s $f3, 96($sp)
  lw $t3, 96($sp)
  s.s $f3, 28($sp)
  lw $a0, 28($sp)
  mtc1 $a0, $f12
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal writef
  lw $ra,0($sp)
  addi $sp, $sp, 4
  lw $t1, 12($sp)
  lw $t2, 20($sp)
  mtc1 $t1, $f1
  mtc1 $t2, $f2
  add.s $f3,$f1,$f2
  s.s $f3, 48($sp)
  lw $t3, 48($sp)
  s.s $f3, 28($sp)
  lw $a0, 28($sp)
  mtc1 $a0, $f12
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal writef
  lw $ra,0($sp)
  addi $sp, $sp, 4
  move $t0,$sp
  addi $sp, $sp, -32
  sw $ra,0($sp)
  lw $t1, 12($t0)
  move $t3,$t1
  sw $t3,12($sp)
  lw $t1, 20($t0)
  move $t3,$t1
  sw $t3,20($sp)
  jal func
  lw $ra,0($sp)
  addi $sp,$sp,32
  sw $v0,48($sp)
  lw $t3, 48($sp)
  s.s $f3, 28($sp)
  lw $a0, 28($sp)
  mtc1 $a0, $f12
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal writef
  lw $ra,0($sp)
  addi $sp, $sp, 4
  lw $t1, 12($sp)
  lw $t2, 20($sp)
  mtc1 $t1, $f1
  mtc1 $t2, $f2
  mfc1 $t1, $f1
  mfc1 $t2, $f2
  slt $t3, $t1, $t2
  sw $t3, 48($sp)
  lw $t3, 48($sp)
  sw $t3, 44($sp)
  lw $a0, 44($sp)
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal write
  lw $ra,0($sp)
  addi $sp, $sp, 4
  lw $t1, 12($sp)
  lw $t2, 20($sp)
  mtc1 $t1, $f1
  mtc1 $t2, $f2
  mfc1 $t1, $f1
  mfc1 $t2, $f2
  sgt $t3, $t1, $t2
  sw $t3, 48($sp)
  lw $t3, 48($sp)
  sw $t3, 44($sp)
  lw $a0, 44($sp)
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal write
  lw $ra,0($sp)
  addi $sp, $sp, 4
  lw $t1, 12($sp)
  lw $t2, 20($sp)
  mtc1 $t1, $f1
  mtc1 $t2, $f2
  mul.s $f3,$f1,$f2
  s.s $f3, 48($sp)
  lw $t3, 48($sp)
  s.s $f3, 28($sp)
  lw $a0, 28($sp)
  mtc1 $a0, $f12
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal writef
  lw $ra,0($sp)
  addi $sp, $sp, 4
  lw $t1, 44($sp)
  lw $t2, 20($sp)
  mtc1 $t1, $f1
  mtc1 $t2, $f2
  cvt.s.w $f1, $f1
  add.s $f3,$f1,$f2
  s.s $f3, 48($sp)
  li $t3, 1
  sw $t3, 52($sp)
  lw $t1, 48($sp)
  lw $t2, 52($sp)
  mtc1 $t1, $f1
  mtc1 $t2, $f2
  cvt.s.w $f2, $f2
  add.s $f3,$f1,$f2
  s.s $f3, 56($sp)
  lw $t1, 56($sp)
  lw $t2, 12($sp)
  mtc1 $t1, $f1
  mtc1 $t2, $f2
  div.s $f3, $f1, $f2
  s.s $f3, 60($sp)
  lw $t3, 60($sp)
  s.s $f3, 28($sp)
  lw $a0, 28($sp)
  mtc1 $a0, $f12
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal writef
  lw $ra,0($sp)
  addi $sp, $sp, 4
  li $t3, 0
  sw $t3, 48($sp)
  lw $v0,48($sp)
  jr $ra
label2:
