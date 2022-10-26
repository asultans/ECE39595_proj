# suffix rules don't allow pre-requisites to be used and are deprecated for
# this reason.  The right way to do this is to use patterns.  The "%" pattern
# allows any file to be matched.
OBJS = main.o Symtbl.o buffers.o ops.o Data.o Stmt.o
CC = g++ -std=c++11
INCLUDE = 
LIBS = 
CFLAGS = -Wall -g
EXECUTABLE = Proj_stp1
COMMANDLINE =

.PHONY : run
run : $(EXECUTABLE)
	./$(EXECUTABLE) $(COMMANDLINE)

cleanmake : clean Proj_stp1

.PHONY : $(EXECUTABLE)
$(EXECUTABLE) :  $(OBJS)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJS) $(INCLUDE) $(LIBS)

%.o : %.c 
	$(CC) $(CFLAGS) -c $@ $(INCLUDE) $(LIBS)

test0 : Proj_stp1
	./Proj_stp1 ProjectAssigned/OutputAndTestCases/TestCases10_08_22/0StartExit 0StartExit_output

test1_10: Proj_stp1
	./Proj_stp1 ProjectAssigned/OutputAndTestCases/TestCases10_08_22/1PushI 1PushI_output
	./Proj_stp1 ProjectAssigned/OutputAndTestCases/TestCases10_08_22/2PrintTOS 2PrintTOS_output
	./Proj_stp1 ProjectAssigned/OutputAndTestCases/TestCases10_08_22/3Add 3Add_output
	./Proj_stp1 ProjectAssigned/OutputAndTestCases/TestCases10_08_22/4Prints 4Prints_output
	./Proj_stp1 ProjectAssigned/OutputAndTestCases/TestCases10_08_22/5Div 5Div_output
	./Proj_stp1 ProjectAssigned/OutputAndTestCases/TestCases10_08_22/6Dup 6Dup_output
	./Proj_stp1 ProjectAssigned/OutputAndTestCases/TestCases10_08_22/7Mul 7Mul_output
	./Proj_stp1 ProjectAssigned/OutputAndTestCases/TestCases10_08_22/8Negate 8Negate_output
	./Proj_stp1 ProjectAssigned/OutputAndTestCases/TestCases10_08_22/9Pop 9Pop_output
	./Proj_stp1 ProjectAssigned/OutputAndTestCases/TestCases10_08_22/10Swap 10Swap_output

testLabel: Proj_stp1
	./Proj_stp1 ProjectAssigned/OutputAndTestCases/TestCases10_08_22/11Label 11Label_output

testJump: Proj_stp1
	./Proj_stp1 ProjectAssigned/OutputAndTestCases/TestCases10_08_22/12Jump 12Jump_output
	./Proj_stp1 ProjectAssigned/OutputAndTestCases/TestCases10_08_22/24JumpZero 24JumpZero_output
	./Proj_stp1 ProjectAssigned/OutputAndTestCases/TestCases10_08_22/25JumpNZero 25JumpNZero_output

testGoSub: Proj_stp1
	./Proj_stp1 ProjectAssigned/OutputAndTestCases/TestCases10_08_22/13SimpleGoSub_GoSubLabel_Return 13SimpleGoSub_GoSubLabel_Return_output

testScalarEasy: Proj_stp1
	./Proj_stp1 ProjectAssigned/OutputAndTestCases/TestCases10_08_22/14ScalarEasy 14ScalarEasy_output
	./Proj_stp1 ProjectAssigned/OutputAndTestCases/TestCases10_08_22/16ScalarEasy 16ScalarEasy_output


testScalerHard: Proj_stp1
	./Proj_stp1 ProjectAssigned/OutputAndTestCases/TestCases10_08_22/15ScalarHard 15ScalarHard_output
	./Proj_stp1 ProjectAssigned/OutputAndTestCases/TestCases10_08_22/17ScalarHard 17ScalarHard_output
	./Proj_stp1 ProjectAssigned/OutputAndTestCases/TestCases10_08_22/18ScalarHardest 18ScalarHardest_output

testArray: Proj_stp1
	./Proj_stp1 ProjectAssigned/OutputAndTestCases/TestCases10_08_22/19ArrayEasy 19ArrayEasy_output
	./Proj_stp1 ProjectAssigned/OutputAndTestCases/TestCases10_08_22/20ArrayHard 20ArrayHard_output
	./Proj_stp1 ProjectAssigned/OutputAndTestCases/TestCases10_08_22/21ArrayEasy 21ArrayEasy_output
	./Proj_stp1 ProjectAssigned/OutputAndTestCases/TestCases10_08_22/22ArrayHard 22ArrayHard_output
	./Proj_stp1 ProjectAssigned/OutputAndTestCases/TestCases10_08_22/23ArrayHardest 23ArrayHardest_output

TestRecurse: Proj_stp1
	./Proj_stp1 ProjectAssigned/OutputAndTestCases/TestCases10_08_22/26Recurse 26Recurse_output

testDot: Proj_stp1
	./Proj_stp1 ProjectAssigned/OutputAndTestCases/TestCases10_08_22/27DotProd 27DotProd_output

testSample: Proj_stp1
	./Proj_stp1 ProjectAssigned/OutputAndTestCases/TestCases10_08_22/99Sample 99Sample_output




clean :
	rm $(EXECUTABLE) ${OBJS} 