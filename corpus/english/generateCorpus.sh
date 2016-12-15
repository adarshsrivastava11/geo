#!/bin/bash

rm -f source.txt
rm -f target.txt

touch source.txt
touch target.txt

for file in $@
do
	echo "Generating corpus from $file"
	./get0mod3Lines < $file >> source.txt
	./get1mod3Lines < $file >> target.txt
done
