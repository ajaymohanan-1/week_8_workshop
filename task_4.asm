# ****************************************************************************************************
                                        Task_4_description
# ****************************************************************************************************
# The following MIPS assembly program calls a function test_sequence that tests the sequence 
# of bits in a word (of which the address is loaded into register $a0) for a particular condition 
# and then accordingly returns an integer in register $v0. If the condition is met, the function 
# returns 1. Else, the function returns 0.
#   1. Describe the condition check performed by the test_condition function in the code?
#   2. Are the saved temporary registers correctly handled in the function test_sequence? If no, edit 
#      the function to fix this.
# ****************************************************************************************************

.text                     # start generating instructions 
.globl test_sequence      # this label should be globally known

main:

li $a0, 0x10010000 # load argument register $a0 with the address of input sequence
jal test_sequence
                     
infinite: j infinite # wait here when the calculation has finished

#-------------------------------------------------------------------------
# test_sequence - $a0 contains address of input sequence to test
#               - result returned in register $v0
#-------------------------------------------------------------------------
test_sequence: lw $s0, 0($a0) # $s0 contains the input sequence
li $s1, 0 
li $s2, 16 
li $s3, 1 
li $s7, 0

# shift the input sequence
srl $s4, $s0, 16
sll $s5, $s0, 16
srl $s5, $s5, 16

loop: beq $s1, $s2, exit # check whether loop limit has been reached
sll $s7, $s7, 1 
and $s6, $s5, $s3 
beq $s6, $zero, skip 
add_one: addi $s7, $s7, 1 
skip: addi $s1, $s1, 1 # increment loop counter
srl $s5, $s5, 1 
j loop # repeat loop

exit: li $v0, 0 # initialize return value to 0
bne $s7, $s4, skip_1 # check whether the input sequence passes the test
addi $v0, $v0, 1 # set return value to 1
skip_1: jr $ra # jump to contents of return address register $ra