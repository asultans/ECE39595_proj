# suffix rules don't allow pre-requisites to be used and are deprecated for
# this reason.  The right way to do this is to use patterns.  The "%" pattern
# allows any file to be matched.
OBJS = main.o Symtbl.o buffers.o Stmt.o ops.o Data.o
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

test1 : Proj_stp1
	./Proj_stp1 ProjectAssigned/OutputAndTestCases/TestCases10_08_22/0StartExit 0StartExit_output

test2: Proj_stp1
	./Proj_stp1 ProjectAssigned/OutputAndTestCases/TestCases10_08_22/1PushI 1PushI_output
	./Proj_stp1 ProjectAssigned/OutputAndTestCases/TestCases10_08_22/2PrintTOS 2PrintTOS_output
  
testReg: Proj_stp1
	./Proj_stp1 ProjectAssigned/OutputAndTestCases/TestCases10_08_22/15ScalarHard 15ScalarHard_output

testLabel: Proj_stp1
	./Proj_stp1 ProjectAssigned/OutputAndTestCases/TestCases10_08_22/11Label 11Label_output

clean :
	rm $(EXECUTABLE) ${OBJS} 