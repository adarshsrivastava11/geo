.PHONY: install
install:
	make install --directory=./giza-pp
	make install --directory=./corpus
	make english
	make hindi
	make install --directory=./interpreter

english: english-align english-interpret

english-align:
	make english --directory=./corpus
	cp ./corpus/english-source.txt ./aligner/english/
	cp ./corpus/english-target.txt ./aligner/english/
	make english --directory=./aligner
	mkdir -p ./interpreter/english/
	cp ./aligner/english/*.t3.* ./interpreter/english/alignment.txt
	cp ./aligner/english/english-source.vcb ./interpreter/english/
	cp ./aligner/english/english-target.vcb ./interpreter/english/

english-interpret:
	make english --directory=./interpreter

hindi: hindi-align hindi-interpret

hindi-align:
	make hindi --directory=./corpus
	cp ./corpus/hindi-source.txt ./aligner/hindi
	cp ./corpus/hindi-target.txt ./aligner/hindi
	make hindi --directory=./aligner
	mkdir -p ./interpreter/hindi/
	cp ./aligner/hindi/*.t3.* ./interpreter/hindi/alignment.txt
	cp ./aligner/hindi/hindi-source.vcb ./interpreter/hindi/
	cp ./aligner/hindi/hindi-target.vcb ./interpreter/hindi/	

hindi-interpret:
	make hindi --directory=./interpreter

clean:
	make clean --directory=./corpus
	make clean --directory=./aligner
	# make clean --directory=./interpreter
	rm -rf *.o *~
