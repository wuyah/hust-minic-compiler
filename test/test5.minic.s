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
  addi $sp, $sp, -56
  li $t3, 1
  sw $t3, 16($sp)
  lw $t3, 16($sp)
  sw $t3, 12($sp)
  li $t3, 0
  sw $t3, 32($sp)
  li $t3, 1
  sw $t3, 36($sp)
  li $t3, 4
  sw $t3, 40($sp)
  lw $t1, 40($sp)
  lw $t2, 36($sp)
  mul $t3,$t1,$t2
  sw $t3, 44($sp)
  lw $t1, 44($sp)
  lw $t2, 32($sp)
  add $t3,$t1,$t2
  sw $t3, 32($sp)
  li $t1, 20
  lw $t2, 32($sp)
  add $t2, $t2, $t1
  sw $t2, 48($sp)
  li $t3, 3
  sw $t3, 52($sp)
  lw $t3, 52($sp)
  lw $t1, 52($sp)
  lw $t2, 48($sp)
  add $t2, $t2, $sp
  sw $t3, ($t2)
  li $t3, 0
  sw $t3, 32($sp)
  li $t3, 1
  sw $t3, 36($sp)
  li $t3, 4
  sw $t3, 40($sp)
  lw $t1, 40($sp)
  lw $t2, 36($sp)
  mul $t3,$t1,$t2
  sw $t3, 44($sp)
  lw $t1, 44($sp)
  lw $t2, 32($sp)
  add $t3,$t1,$t2
  sw $t3, 32($sp)
  li $t1, 20
  lw $t2, 32($sp)
  add $t2, $t2, $t1
  sw $t2, 48($sp)
  lw $t1, 48($sp)
  addu $t1, $t1, $sp
  lw $t3, ($t1)
  sw $t3, 52($sp)
  lw $t4, 48($sp)
  addu $t4, $t4, $sp
  lw $t1, ($t4)
  addi $t1, $t1, 1
  lw $t2, 48($sp)
  add $t2, $t2, $sp
  sw $t1, ($t2)
  li $t3, 0
  sw $t3, 32($sp)
  li $t3, 1
  sw $t3, 36($sp)
  li $t3, 4
  sw $t3, 40($sp)
  lw $t1, 40($sp)
  lw $t2, 36($sp)
  mul $t3,$t1,$t2
  sw $t3, 44($sp)
  lw $t1, 44($sp)
  lw $t2, 32($sp)
  add $t3,$t1,$t2
  sw $t3, 32($sp)
  li $t1, 20
  lw $t2, 32($sp)
  add $t2, $t2, $t1
  sw $t2, 48($sp)
  lw $t4, 48($sp)
  add $t4, $t4, $sp
  lw $a0, ($t4)
  addi $sp, $sp, -4
  sw $ra,0($sp)
  jal write
  lw $ra,0($sp)
  addi $sp, $sp, 4
  li $t3, 0
  sw $t3, 32($sp)
  lw $v0,32($sp)
  jr $ra
label1:
