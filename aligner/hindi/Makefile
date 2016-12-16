.PHONY: all

all: clean
	../../giza-pp/GIZAppv2/plain2snt.out hindi-source.txt hindi-target.txt
	../../giza-pp/GIZAppv2/snt2cooc.out hindi-source.vcb hindi-target.vcb hindi-source_hindi-target.snt > coocurrenceFile.cooc
	../../giza-pp/GIZAppv2/GIZA++ -s hindi-source.vcb -t hindi-target.vcb -c hindi-source_hindi-target.snt -CoocurrenceFile coocurrenceFile.cooc

clean:
	rm -f *.$(USER).*	
