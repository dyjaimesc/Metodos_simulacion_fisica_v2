all:  ejecutar 

ejecutar: run.sh
	./run.sh

.PHONY: clean
clean:
	rm -f *~ *# a.out *.x *.pdf *.gp *.txt
