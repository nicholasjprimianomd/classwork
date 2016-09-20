/**
 * @file proj3.cpp
 * \mainpage
 *
 * CISC 2200, Data Structures<br>
 * Project 3: Recognizing Infix Arithmetic Expressions<p>
 *
 * A stack-based program that repeatedly
 * <ul>
 *     <li>reads an expression from standard input.</li>
 *     <li>computes the value of that expression, and</li>
 *     <li>prints the expression's value.</li>
 * </ul>
 *
 * @author Nicholas Primiano
 * @date   3 March 2014 
 * @file proj3.cc
 */

/*
 * includes
 */
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

/**
 * We will be doing integer arithmetic.
 * Use a <code>typedef</code> in case we want to geralize this.
 */
typedef int ValueType;

/** @class IllegalExprException
 *  Exception class thrown by illegal postfix expression
 */
class IllegalExprException : public exception { }; 

/** @class ZeroDivideException
 *  Exception class thrown by attempt to divide by zero.
 */
class ZeroDivideException : public exception { }; 

/*
 * function prototypes, with doxygen docs
 */

/**
 * Determine the value of an postfix expression
 *
 * @param expr a string, supposedly representing an infix expression
 * @return the value of <code>expr</code>
 * @throw IllegalExprException if <code>expr</code> is not a legal postfix
 * expression 
 * @throw ZeroDivideException if <code>expr</code> involves a division
 * by zero
 */
ValueType processExpression(const string& expr) 
    throw (IllegalExprException, ZeroDivideException);

/**
 * Determine the precedence of an operator.
 *
 * @param op the operator in question
 * @pre <code>op</code> is one of the '+','-','*','/'
 * @return the precedence of an operation
 * 2 for multiplicative operations, 1 for additive, or
 * 0 for illegal operations.
 */
int precedence(char op);

/**
 * Print a help message if the user wants one.
 */
void provideHelpIfNecessary(void);

/**
 * Do the binary operation using a vector of a postfix expression.
 *
 * @param postfix postfix expression converted from infix
 * @param post stack to use while evaluating the postfix expression
 * @post all binary operations are applied to <code>postfix</code>
 */
void evaluate(vector<char> postfix, stack<int> &post);

/**
 * Do a binary operation.
 * 
 * @param left the left operand
 * @param operation the operation to be preformed
 * @param right the right operand 
 * @throw IllegalExprException if <code>expr</code> is not a legal postfix
 * expression 
 * @throw ZeroDivideException if <code>expr</code> involves a division
 * by zero 
 *@return the result of the operation
 */
ValueType doOperation(ValueType left, char operation, ValueType right)
    throw (IllegalExprException, ZeroDivideException);

/**
 * The usual main function
 */
int main(void)
{
    provideHelpIfNecessary();
    while (true) {
	cout << "Expression? " ;
	string expr;                    // holds the supposed expression
	getline(cin, expr);
	if (expr.length() == 0){
	    break;
	}
	try {
	    ValueType result = processExpression(expr);
	    cout << "Answer : " << result << endl;
	} catch (ZeroDivideException ex) {
	    cerr << "Attempt to divide by zero!\n";
	} catch (IllegalExprException ex) {
	    cerr << "Illegal infix expression!\n";
	}
    } // end while
    cout << endl;
} // end main

void provideHelpIfNecessary(void)
{
    cout << "Do you need help (Y/N)? ";
    string help;
    cin >> help;
    if (help == "Y" || help == "y") {
	cout << "Enter an infix expression at the prompt. " << endl
	     << "The program will tell you its value. " << endl
	     << "To stop the program, just hit \"return\" " 
	     << "at the prompt." << endl;
        cin.ignore();
    }
    else if (help == "N" || help == "n") {
        cin.ignore();
	return;   
    }
    else {
	cout << "Response must be either either \"Y\" or \"N\"." << endl;
	provideHelpIfNecessary();
    } 
} // end provideHelpIfNecessary

ValueType processExpression(const string& expr) 
    throw (IllegalExprException, ZeroDivideException)
{
    vector<char> postfix;
    stack<char> aStack;
    char ch;
    int braceCount = 0;
    int operandCount = 0;
    int operatorCount = 0;
    for(unsigned int i = 0; i < expr.length(); i++) {
	ch = expr[i];
	switch(ch)
	    {
	    case '0':
	    case '1':
	    case '2':
	    case '3':
	    case '4':
	    case '5':
	    case '6':
	    case '7':
	    case '8':
	    case '9':
		operatorCount++;
		postfix.push_back(ch);
		break;
	    case '(':
		braceCount++;
		aStack.push(ch);
		break;
	    case '+':
	    case '-':
	    case '*':
	    case '/':
		if (i == expr.length()-1)
		    throw IllegalExprException();
		while((!aStack.empty()) && (aStack.top() != '(') && 
		      (precedence(ch) <= precedence(aStack.top()))){
		    postfix.push_back(aStack.top());
		    aStack.pop();
		}
		operandCount++;
		aStack.push(ch);
		break;
	    case ')':
		if (braceCount < 1)
		    throw IllegalExprException();
		while(aStack.top() != '('){
		    postfix.push_back(aStack.top());
    		    aStack.pop();
		}
		braceCount--;
		aStack.pop();
		break;
	    default:
		throw IllegalExprException();
	    } 
    }
    if (braceCount != 0 || operandCount == 0)
	throw IllegalExprException();
    if (operatorCount <= operandCount)
	throw IllegalExprException();
    while(!aStack.empty()){
	postfix.push_back(aStack.top());
	aStack.pop();
    }
    stack<int> post;
    evaluate(postfix, post);
    return post.top();
} // end processExpression

int precedence(char op)
{
    int prec = 0;
    switch (op){
    case '+':
	prec = 1;
	break;
    case '-':
	prec = 1;
	break;
    case '*':
	prec = 2;
	break;
    case '/':
	prec = 2;
	break;
    }
    return prec;
} // end precedence

void evaluate(vector<char> postfix, stack<int> &post)
{    
    for(unsigned int i = 0; i < postfix.size(); i++) {
	if ('0' <= postfix[i] && postfix[i] <= '9') {
	    post.push(postfix[i] - '0');   
	}
	else {
            // pop right then left as a result of stack direction
	    int right = post.top();
	    post.pop();
	    int left = post.top();
	    post.pop();
	    post.push(doOperation(left, postfix[i], right));
	}
    }
} //end evaluate

ValueType doOperation(ValueType left, char operation, ValueType right)
    throw (IllegalExprException, ZeroDivideException)
{
    switch (operation){
    case '+':
	return left + right;	
    case '-':
	return left - right;
    case '*':
	return left * right;
    case '/':
	if(right == 0)
	    throw ZeroDivideException();
	return left / right;
    default:
	throw IllegalExprException();
    }
    return 0;
} // end doOperation
