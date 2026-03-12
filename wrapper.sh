../run.sh ./src "*" ./out/bank.o "-I../lib/strlib/include \
		     	   	-I../lib/sqlitelib/include \
			    		       -I ./include \
		  			 -L../lib/strlib/out \
				                 -l:libstr.a  \
				        -L../lib/sqlitelib/out \
						      -lsqlite  \
						      -lsqlite3" \
