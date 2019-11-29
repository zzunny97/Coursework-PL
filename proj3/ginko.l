%{
#include <stdio.h>
#include <stdlib.h>
#include "ginko.tab.h"
extern int cur_line;
%}

number (([0-9]+(\.[0-9]*)?)|([0-9]*\.[0-9]+))
variable [a-zA-Z]+

%%
"SET"		{ 
	//printf("LEX SET\n"); 
	return SET; 
}
"to"		{ return to; }
"IF"		{ return IF;}
"THEN"		{ return THEN; }
"ENDIF"		{ return ENDIF; }
"ELSE"		{ return ELSE;}
"FUNC"		{ 
	//printf("LEX FUNC\n");
	return FUNC;
}
"RETURN"	{ 
	//printf("LEX RETURN\n");
	return RETURN;
}
"ENDWHILE"	{ return ENDWHILE; } 
"PRINT"		{ 
	//printf("LEX PRINT\n"); 
	return PRINT;
}
"WHILE"		{ 
	//printf("LEX WHILE\n"); 
	return WHILE; 
}
"DO"		{ 
	//printf("LEX DO\n");
	return DO;
}
">="		{
	//printf("LEX >=\n");
	return GREQ_SYM;
}

"<=" {
	//printf("LEX <=\n");
	return LESQ_SYM;
}
"==" {
	//printf("LEX ==\n");
	return EQ_SYM;
}
"!=" {
	//printf("LEX !=\n");
	return NEQ_SYM;
}

{number}	{ 
	//printf("LEX number: %lf\n", atof(yytext)); 
	yylval.dval = atof(yytext); 
	return NUMBER; 
}
{variable}	{ 
	yylval.idx = findindex(yytext);
	//printf("LEX var: %s var idx: %d\n", yytext, yylval.idx); 
	return ID; 
}
[ \t]+	;
[\n]	{ cur_line++;  }
[-+*/!<>(),{}]		{ 
	//printf("LEX symbol: %s\n", yytext); 
	return *yytext; 
}
[;]			{ return *yytext; } 	
.			{ 
	printf("unknown variable %s\n", yytext); 
}		
%%
