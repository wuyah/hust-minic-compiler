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
  addi $sp, $sp, -40
  li.s $f3, 1.100000
  s.s $f3, 16($sp)
  lw $t1, 16($sp)
  sw $t1, 12($sp)
  li.s $f3, 2.100000
  s.s $f3, 24($sp)
  lw $t1, 24($sp)
  sw $t1, 20($sp)
  lw $t1, 12($sp)
  lw $t2, 20($sp)
  mtc1 $t1, $f1
  mtc1 $t2, $f2
  add.s $f3,$f1,$f2
  s.s $f3, 32($sp)
  lw $t1, 32($sp)
  sw $t1, 28($sp)
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
  sw $v0,32($sp)
  lw $t1, 32($sp)
  sw $t1, 28($sp)
  lw $a0, 28($sp)
  mtc1 $a0, $f12
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal writef
  lw $ra,0($sp)
  addi $sp, $sp, 4
  li $t3, 0
  sw $t3, 32($sp)
  lw $v0,32($sp)
  jr $ra
label2:
