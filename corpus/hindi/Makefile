all hindi: source.txt target.txt

source.txt target.txt: ncert.06.14.hindi.corp ncert.07.10.hindi.corp ncert.08.04.hindi.corp ncert.09.11.hindi.corp
	rm -f source.txt
	touch source.txt
	../get0mod3Lines.out < ncert.06.14.hindi.corp > temp
	../filter.out temp | ../filter.sh | perl -ne 'print if /\S/' > temp1
	../get0mod3Lines.out < ncert.07.10.hindi.corp > temp
	../filter.out temp | ../filter.sh | perl -ne 'print if /\S/' > temp2
	../get0mod3Lines.out < ncert.08.04.hindi.corp > temp
	../filter.out temp | ../filter.sh | perl -ne 'print if /\S/' > temp3
	../get0mod3Lines.out < ncert.09.11.hindi.corp > temp
	../filter.out temp | ../filter.sh | perl -ne 'print if /\S/' > temp4
	cat temp1 >> source.txt
	cat temp2 >> source.txt
	cat temp3 >> source.txt
	cat temp4 >> source.txt
	#../filter ncert.06.14.hindi.corp | ../filter.sh | ../get0mod3Lines >> source.txt
	#../filter ncert.07.10.hindi.corp | ../filter.sh | ../get0mod3Lines >> source.txt
	#../filter ncert.08.04.hindi.corp | ../filter.sh | ../get0mod3Lines >> source.txt
	#../filter ncert.09.11.hindi.corp | ../filter.sh | ../get0mod3Lines >> source.txt
	rm -f target.txt
	touch target.txt
	../get1mod3Lines.out < ncert.06.14.hindi.corp > temp
	../filter.out temp | ../filter.sh | perl -ne 'print if /\S/' > temp1
	../get1mod3Lines.out < ncert.07.10.hindi.corp > temp
	../filter.out temp | ../filter.sh | perl -ne 'print if /\S/' > temp2
	../get1mod3Lines.out < ncert.08.04.hindi.corp > temp
	../filter.out temp | ../filter.sh | perl -ne 'print if /\S/' > temp3
	../get1mod3Lines.out < ncert.09.11.hindi.corp > temp
	../filter.out temp | ../filter.sh | perl -ne 'print if /\S/' > temp4
	cat temp1 >> target.txt
	cat temp2 >> target.txt
	cat temp3 >> target.txt
	cat temp4 >> target.txt
	#../filter ncert.06.14.hindi.corp | ../filter.sh | ../get1mod3Lines >> target.txt
	#../filter ncert.07.10.hindi.corp | ../filter.sh | ../get1mod3Lines >> target.txt
	#../filter ncert.08.04.hindi.corp | ../filter.sh | ../get1mod3Lines >> target.txt
	#../filter ncert.09.11.hindi.corp | ../filter.sh | ../get1mod3Lines >> target.txt
	rm temp*

clean:
	rm -f source.txt
	rm -f target.txt
