/**********************************************
* Name: Ashley Morton*
* Date: Due September 12, 2017*
* Assignment: Project 1 -Sequence and Order validation
************************************************* 
Program reads n a file with math equations
************************************************/
#include <stdio.h>
#include <stdlib.h>

//•Your program should read from afile where the math expressions are.The file should be in the "Resource" folder in your solution.

//Declare character stack
char stack[30], top;

int isOpen(char a);
int isClosing(char a);
char firstLine(int a);
int Matches(char a, char b);
void Push(char a);
void Pop();


int count = 0;
char lines[30];
/*******************************************************************
* Description: Main function calls others                          *
* Input:   None                                                    *
* Output:  Hopefully the correct answers                           *
* Precondition:  File read must not be null                        *
* Post condition:  Prints string and if it's correct/incorrrect    *
*******************************************************************/
void main()
{
	FILE * fp;
	fopen_s(&fp, "math.txt", "r");
	

	//if file's not empty
	if (fp != NULL)
	{
		//get first line for length
		fgets(lines, 30, fp);
		int firstNum = atoi(lines);
		
		
		while (fscanf_s(fp, "%s", lines, sizeof(lines))!=EOF)
		{
			int stringLength = strlen(lines);
			int symbol;
			int error = 0;
			count = 0;
			//Embedded for
			for (int j = 0; j < stringLength && error==0; j++)
			{
				
				symbol = lines[j];
				if (isOpen(symbol))
				{
						Push(symbol);
				}//end if
				else if (isClosing(symbol))
				{

					if (strlen(stack)!=  0 && Matches(stack[count-1], symbol))
					{
						Pop();
						
					}
					else 
					{
						error++;
					}
				}//end else if

			}//End for

			if (error == 0 && count == 0)
			{
				printf_s("%s -> Correct\n", lines);
			}
			else
			{
				printf_s("%s -> Incorrect\n", lines);
			}
			
			}//End while
		
		}//End if
		 //Close file
	fclose(fp);
	return 0;
}//End main


 /****************************************************************************
 * Description: Reads first line to see how many equations are in the file   *
 * Input:   given first line in the file to verify it's a valid number       *
 * Output:  returns number in first line                                     *
 * Precondition:  Take in character                                          *
 * Post condition:  returns valid int                                        *
 ****************************************************************************/
//The text file includes one math expression per line,
//the number of lines in the file are specified in the very first lineof the file.
	//** Finished example file math.txt
char firstLine(int a)
{
	if (a < 0 || a>30)
	{
		return a;
	}
	else
	{
		return printf_s("Error: First line of file must be a number.");

	}
}



/*******************************************************************
* Description: Checks if its an opening parenthesis                *
* Input:   Takes in a char                                         *
* Output:  return 1 or 0 stating if true/false respectively        *
* Precondition:  Must see if it's a valid opening perenth          *
* Post condition:  returns 1 or 0 stating if true/false            *
*******************************************************************/
//Your program should contain a separate functionfor validating the proper sequence and order of the '{}', '[]', and '()', that is, the correctness of themath expression.Extra points(5)
int isOpen(char a)
{
	return (a == '(' || a == '[' || a == '{');
}

/*******************************************************************
* Description: Checks if its an closeing parenthesis               *
* Input:   Takes in a char                                         *
* Output:  return 1 or 0 stating if true/false respectively        *
* Precondition:  Must see if it's a valid closeing perenth         *
* Post condition:  returns 1 or 0 stating if true/false            *
*******************************************************************/
int isClosing(char a)
{
	return (a == ')' || a == ']' || a == '}');
}

/*******************************************************************
* Description: Checks if perenthesis match                         *
* Input:   Takes in two chars to compare/see if they match         *
* Output:  return 1 or 0 stating if true/false respectively        *
* Precondition:  Must see if it's a valid match                    *
* Post condition:  returns 1 or 0 stating if true/false            *
*******************************************************************/
int Matches(char a, char b)
{
	return (a == '(' && b == ')' || a == '[' && b == ']' || a == '{' && b == '}');

}

/*******************************************************************
* Description: pop from the 'stack' array                          *
* Input:  None                                                     *
* Output:  None                                                    *
* Precondition:  decriments count                                  *
* Post condition:  decriment and update count                      *
*******************************************************************/
void Pop()
{
	count--;
}//End Pop

 /***************************************************************************
 * Description: push a character into the 'stack'                           *
 * Input:  Takes in a character to push onto the 'stack'                    *
 * Output:  None                                                            *
 * Precondition:  Increment count after adding open parenth to the 'stack'  *
 * Post condition:  Decrement count                                         *
 ***************************************************************************/
void Push(char a)
{
	stack[count] = a;
	count++;
}//End Push

//******EXTRA CREDIT*******
//Your program should indicate the location of the error in the expression(e.g.print charsin bold).In the example above : [{()]}àincorrect. (notice the{ and the ]in bold)