all: numcheckseq numcheckdatapar 
#all: numcheckseq numcheckdatapar numcheckfuncpar 

clean: 
	/bin/rm -f *.o numcheckseq numcheckdatapar

# vcoê deve criar as regras para gerar os dois outros programas.
numcheckdatapar: conditions.o numchecks.o timediff.o numcheckdatapar.o
	gcc -pthread -Wall conditions.o numchecks.o timediff.o numcheckdatapar.o -o numcheckdatapar

numcheckseq: conditions.o numchecks.o timediff.o numcheckseq.o
	gcc -Wall conditions.o numchecks.o timediff.o numcheckseq.o -o numcheckseq

numcheckdatapar.o: numcheckdatapar.c conditions.h numchecks.h timediff.h
	gcc -pthread -Wall -c  numcheckdatapar.c

numcheckseq.o: numcheckseq.c conditions.h numchecks.h timediff.h
	gcc -Wall -c numcheckseq.c

conditions.o: conditions.c conditions.h
	gcc -Wall -c conditions.c

numchecks.o: numchecks.c numchecks.h
	gcc -Wall -c numchecks.c

timediff.o: timediff.c timediff.h
	gcc -Wall -c timediff.c
