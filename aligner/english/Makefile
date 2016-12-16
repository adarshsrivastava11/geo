.PHONY: all

all: clean
	../../giza-pp/GIZAppv2/plain2snt.out english-source.txt english-target.txt
	../../giza-pp/GIZAppv2/snt2cooc.out english-source.vcb english-target.vcb english-source_english-target.snt > coocurrenceFile.cooc
	../../giza-pp/GIZAppv2/GIZA++ -s english-source.vcb -t english-target.vcb -c english-source_english-target.snt -CoocurrenceFile coocurrenceFile.cooc

clean:
	rm -f *.$(USER).*
