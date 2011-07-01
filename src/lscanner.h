/* File: scanner.h
 * ---------------
 * You should not need to modify this file. It declare a few constants,
 * types, variables,and functions that are used and/or exported by
 * the lex-generated scanner.
 */

#ifndef _H_scanner
#define _H_scanner

#include <stdio.h>

#define MaxIdentLen 31    // Maximum length for identifiers

  
/* Typedef: TokenType enum
 * -----------------------
 * This enumeration defines the constants for the different token types.
 * The scanner should return these values for the associated key words
 * and token types.  The numbers start at 256 because 0-255 are reserved
 * for single character token values. After pp1, we will rely on
 * y.tab.h generated by yacc for these constants.
 */
typedef enum { 
    T_Void = 256,		// void
    T_Int, 			// int
    T_Double, 			// double
    T_Bool, 			// bool
    T_String, 			// string
    T_Class, 			// class
    T_Null, 			// null
    T_Dims,			// []
    T_LessEqual, 		// <=
    T_GreaterEqual, 		// >=
    T_Equal, 			// ==
    T_NotEqual, 		// !=
    T_And, 			// &&
    T_Or,			// ||
    T_While, 			// while
    T_For, 			// for
    T_If, 			// if
    T_Else, 			// else
    T_Return, 			// return
    T_Break,			// break
    T_Extends, 			// extends
    T_This, 			// this
    T_Implements, 		// implements
    T_Interface, 		// interface
    T_New, 			// new
    T_NewArray,			// NewArray
    T_Identifier, 		// <identifier>
    T_StringConstant, 		// <string-constant>
    T_IntConstant, 		// <int-constant>
    T_DoubleConstant,		// <double-constant>
    T_BoolConstant, 		// <bool-constant>
    T_Print, 			// Print
    T_ReadInteger, 		// ReadInteger
    T_ReadLine,			// ReadLine
    T_Unsigned,			// unsigned
    T_Continue,			// continue
    T_LeftShift,		// <<
    T_RightShift,		// >>
    T_Increment,		// ++
    T_Decrement,		// --
    T_Sizeof,			// sizeof
    T_Typeof,			// typeof
    T_NumTokenTypes		// const: Number of tokens
} TokenType;

 
/* These are a list of printable names for each token value defined
 * above.  The strings should match in position to the types. They
 * are used in our main program to verify output from your scanner.
 */
static const char *gTokenNames[T_NumTokenTypes] = {
  "T_Void", "T_Int", "T_Double", "T_Bool", "T_String", "T_Class", "T_Null", 
  "T_Dims", "T_LessEqual", "T_GreaterEqual", "T_Equal", "T_NotEqual",
  "T_And", "T_Or", "T_While", "T_For", "T_If", "T_Else", "T_Return",
  "T_Break", "T_Extends", "T_This", "T_Implements", "T_Interface",
  "T_New", "T_NewArray","T_Identifier", "T_StringConstant",
  "T_IntConstant", "T_DoubleConstant", "T_BoolConstant", "T_Print",
  "T_ReadInteger", "T_ReadLine"
};

 
/* Typedef: YYSTYPE
 * ----------------
 * Defines the union type that is used by the scanner to store
 * attibute information about tokens as they are scanned. This
 * type definition will be generated by Yacc in the later assignments.
 */
typedef union {
    int integerConstant;
    bool boolConstant;
    char *stringConstant;
    double doubleConstant;
    char identifier[MaxIdentLen+1]; // +1 for terminating null
} YYSTYPE;

 
/* Global variable: yylval
 * -----------------------
 * Strange name, but by convention, this is the name of union that
 * is written to by scanner and read by parser containing information
 * about the lexeme just scanned.
 */

extern YYSTYPE yylval;
extern char *yytext;		// Text of lexeme just scanned
int yylex();			// Defined in the generated lex.yy.c file
void InitScanner();		// Defined in scanner.l user subroutines
 
#endif
