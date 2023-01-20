src = $(wildcard *.c)

parser:$(src)
	flex lex.l
	bison -d parser.y 
	gcc -o parser.out $^ -lfl
clean:
	rm parser.out