lex ../Meta1/jucompiler.l
yacc -d -v jucompiler.y		
cc -o jucompiler y.tab.c lex.yy.c Tree.c
./jucompiler
./jucompiler -t