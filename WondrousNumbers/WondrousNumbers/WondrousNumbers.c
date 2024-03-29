//x=value of x
//&x=adress of x
//*x=value at adress x

/*which, given a starting number, prints the wondrous sequence starting with that number, (separate numbers with a single space) stopping only when the sequence reaches 1.   Your function is to print a single new line character '\n' after printing the 1, and nothing else.

NOTE: For the purposes of this exercise a sequence starting with 1 will immediately terminate.

You can assume that the starting number is an integer and that it is greater than zero.

As well as having the side-effect of printing out the sequence, your function is to return the number of terms in the printed sequence.

Recall that the wondrous sequence is generated by the simple rule:
if the current term is even: the next term is half the current term.
if the current term is odd: the next term is three times the current term, plus 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

unsigned long long wondrous(unsigned long long start);
void testwondrous(void);
unsigned long long doTheCounting(unsigned long long start);

int main(int argc, char *argv[])
{
	testwondrous();

	unsigned long long start;
	int counter;

	start = 1674652200;
			
	counter = 1;
		
	while (counter < 1000)
	{
		start++;
		counter = 1;

		doTheCounting(start);
		counter = doTheCounting(start);

	}
	
	printf("%d is ze number\n", start);
	printf("%d time to go to 1\n", counter);

	return counter;
}

void testwondrous(void)
{

	assert(wondrous(3) == 10);
	assert(wondrous(4) == 2);
	assert(doTheCounting(1341234558) == 988);
	assert(doTheCounting(670617279) == 987);
	//ah!
	//http://www.ericr.nl/wondrous/delrecs.html
	assert(doTheCounting(1412987847) == 1001);
		
}

unsigned long long wondrous(unsigned long long start)
{

	unsigned long long wonderfullNum;

	//check pair/impair
	if (start%2 == 0)
	{
		wonderfullNum = start / 2;
	}
	else
	{
		wonderfullNum = (start*3)+1;
	}
	
	return wonderfullNum;

}

unsigned long long doTheCounting(unsigned long long start)
{

	int counter = 1;

	//loop til 1
	while (start != 1)
	{
		wondrous(start);
		start = wondrous(start);
		counter++;
	}
	return counter;
}