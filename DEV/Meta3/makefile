chmall: jucompiler.l expr.y Tree.c Tree.h analise_semantica.c analise_semantica.h 
	flex jucompiler.l
	yacc -d -v expr.y		
	cc -o expr y.tab.c lex.yy.c Tree.c analise_semantica.c 