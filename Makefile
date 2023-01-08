parser: 
	flex lex.l
	bison -d parser.y 
	gcc -o parser.out vector.c ast.c utility.c exp.c semantic.c objectCode.c lex.yy.c parser.tab.c  -lfl


clean:
	rm 