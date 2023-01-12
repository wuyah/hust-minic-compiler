parser: 
	flex lex.l
	bison -d parser.y 
	gcc -o parser.out array_exp.c stringSet.c vector.c ast.c utility.c exp.c semantic.c objectCode.c lex.yy.c parser.tab.c  -lfl

clean:
	rm 