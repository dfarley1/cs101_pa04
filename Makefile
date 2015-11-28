# Makefile starter for pa01.

# See Cmake/Makefile for a complete commented sample Makefile,
# illustrating separate compilation and dependencies.

# Running "make" can generate many error messages.  Do
#	make intList.o >& make.log
# to compile intList.c and cause the errors to go into the file make.log.
# When "make" finishes you can read the file with "view", "more", or "less".
#
# Many later error messages can be meaningless because they were caused
# by an earlier error.  Always try to correct errors in order.
#
# Do 
#       make graph01 >& make.log
# or 
#       make >& make.log
# to create the executable file graph01.
#
# ===================================================================

CC     = gcc
CFLAGS = -g -Wall -O0 -std=c99 -D_SVID_SOURCE

greedy04:	greedy04.o edgeList.o loadWgtGraph.o
	${CC}  -o  greedy04 greedy04.o edgeList.o loadWgtGraph.o

#intList.o:	intList.c  intList.h
#	${CC}  -c  ${CFLAGS}  intList.c

edgeList.o:	edgeList.c  edgeList.h
	${CC}  -c  ${CFLAGS}  edgeList.c

loadWgtGraph.o:	loadWgtGraph.c  loadWgtGraph.h
	${CC}  -c  ${CFLAGS}  loadWgtGraph.c

#dfsTrace.o:	dfsTrace.c  dfsTrace.h
#	${CC}  -c  ${CFLAGS}  dfsTrace.c

greedy04.o:	greedy04.c
	${CC}  -c  ${CFLAGS}  greedy04.c

clean:
	rm *.o

