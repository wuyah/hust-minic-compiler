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
  addi $sp, $sp, -444
  li $t3, 2
  sw $t3, 376($sp)
  lw $t1, 376($sp)
  sw $t1, 372($sp)
  li $t3, 4
  sw $t3, 384($sp)
  lw $t1, 384($sp)
  sw $t1, 380($sp)
  li $t3, 1
  sw $t3, 392($sp)
  lw $t1, 392($sp)
  sw $t1, 388($sp)
  li $t3, 0
  sw $t3, 12($sp)
  lw $t1, 388($sp)
  lw $t2, 380($sp)
  add $t3,$t1,$t2
  sw $t3, 400($sp)
  li $t3, 4
  sw $t3, 408($sp)
  lw $t1, 408($sp)
  lw $t2, 400($sp)
  mul $t3,$t1,$t2
  sw $t3, 412($sp)
  lw $t1, 412($sp)
  lw $t2, 12($sp)
  add $t3,$t1,$t2
  sw $t3, 12($sp)
  li $t3, 24
  sw $t3, 416($sp)
  lw $t1, 416($sp)
  lw $t2, 380($sp)
  mul $t3,$t1,$t2
  sw $t3, 420($sp)
  lw $t1, 420($sp)
  lw $t2, 12($sp)
  add $t3,$t1,$t2
  sw $t3, 12($sp)
  li $t3, 120
  sw $t3, 424($sp)
  lw $t1, 424($sp)
  lw $t2, 372($sp)
  mul $t3,$t1,$t2
  sw $t3, 428($sp)
  lw $t1, 428($sp)
  lw $t2, 12($sp)
  add $t3,$t1,$t2
  sw $t3, 12($sp)
  li $t3, 1
  sw $t3, 436($sp)
  lw $t1, 436($sp)
  sw $t1, 400($sp)
  li $t3, 0
  sw $t3, 22($sp)
  li $t3, 5
  sw $t3, 400($sp)
  li $t3, 4
  sw $t3, 416($sp)
  lw $t1, 416($sp)
  lw $t2, 400($sp)
  mul $t3,$t1,$t2
  sw $t3, 420($sp)
  lw $t1, 420($sp)
  lw $t2, 22($sp)
  add $t3,$t1,$t2
  sw $t3, 22($sp)
  li $t3, 24
  sw $t3, 424($sp)
  lw $t1, 424($sp)
  lw $t2, 0($sp)
  mul $t3,$t1,$t2
  sw $t3, 428($sp)
  lw $t1, 428($sp)
  lw $t2, 22($sp)
  add $t3,$t1,$t2
  sw $t3, 22($sp)
  li $t3, 120
  sw $t3, 432($sp)
  lw $t1, 432($sp)
  lw $t2, 0($sp)
  mul $t3,$t1,$t2
  sw $t3, 436($sp)
  lw $t1, 436($sp)
  lw $t2, 22($sp)
  add $t3,$t1,$t2
  sw $t3, 22($sp)
  lw $t1, 400($sp)
  sw $t1, 396($sp)
  li $t3, 0
  sw $t3, 400($sp)
  lw $v0,400($sp)
  jr $ra
label1:
