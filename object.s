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
  addi $sp, $sp, -44
  li.s $f3, 1.100000
  s.s $f3, 20($sp)
  li $t3, 2
  sw $t3, 28($sp)
  l.s $f1, 20($sp)
  lw $t2, 28($sp)
  mtc1 $t2, $f2
  cvt.s.w $f2, $f2
  add.s $f3,$f1,$f2
  s.s $f3, 32($sp)
  lw $t1, 32($sp)
  sw $t1, 12($sp)
  li $t3, 2
  sw $t3, 40($sp)
  lw $t1, 40($sp)
  sw $t1, 36($sp)
  l.s $f1, 12($sp)
  lw $t2, 36($sp)
  mtc1 $t2, $f2
  cvt.s.w $f2, $f2
  mfc1 $t1, $f1
  mfc1 $t2, $f2
  sgt $t3, $t1, $t2
  sw $t3, 40($sp)
  lw $t1, 40($sp)
  sw $t1, 36($sp)
  li $t3, 0
  sw $t3, 40($sp)
  lw $v0,40($sp)
  jr $ra
label1:
