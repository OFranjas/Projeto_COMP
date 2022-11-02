lex ../Meta1/jucompiler.l
yacc -d ./jucompiler.y
cc -o jucompiler y.tab.c lex.yy.c


lex ../Meta1/jucompiler.l
yacc -d -v juccompiler.y		
cc -o jucompiler y.tab.c lex.yy.c functions.c
./juccompiler
./juccompiler -t