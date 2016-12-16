#!/bin/bash

sed 's/[\n\r]+/\n/g'\
| sed 's/[A-Z][ \n\r\t]/A /g'\
| sed "s/[A-Z]$/A\'/g"\
| sed 's/[A-Z][A-Z][ \n\r\t]/AB /g'\
| sed "s/[A-Z][A-Z]$/AB\'/g"\
| sed 's/[A-Z][A-Z][A-Z][ \n\r\t]/ABC /g'\
| sed "s/[A-Z][A-Z][A-Z]$/ABC\'/g"\
| sed 's/ +/ /g'\
| sed 's/ $//g'
#| sed 's/[0-9]\+\(\.[0-9]\+\)\?/1.1/g'
