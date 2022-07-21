#include <iostream>
#include <math.h>

int GetDigitSum(int number)
{
	// print out intro statement
	std::cout << "Get the sum of all the digits of " << number << ".\n";

	// initialize total to 0 before we start looping
	int total = 0;

	// initialize digits var using the formula to find the
	// number of digits in number, rounding down get the
	// total number of digits
	int digits = log10(number) + 1;

	// while digits is greater than 0 keep looping
	while (digits > 0)
	{
		// check if this is not the first iteratoin
		if (total != 0)
		{
			// not the first iteration, so print out
			// a plus to show adding
			std::cout << " + ";
		}

		// First, get the value of the leftmost digit of number
		// divide number by 10 to the digits minus 1 power, then
		int digitNum = number / pow(10, digits - 1);

		// print that digit out
		std::cout << digitNum;

		// add this digit to the total
		total = total + digitNum;

		// Next, “remove” the leftmost digit from number by:
		// getting the value of the leftmost digit of number, as above
		// multiply that value by 10 to the power of digits minus 1 to 
		// get the “positional value” of the leftmost digit of number, 
		// then subtract that from number
		number = number - ((int)(number / pow(10, digits - 1)) * pow(10, digits - 1));

		// decrement b to analyze the next digit of a during
		// the next iteration
		digits--;
	}

	// print out and return the calculated sum of all number’s digits
	std::cout << " = " << total << "\n";
	return total;
}

int GetLastDigits(int number, int digit)
{
	// print out the intro statement
	// changing the grammer if we are only getting one digit
	std::cout << "Get the last ";
	if (digit > 1)
		std::cout << digit << " digits";
	else
		std::cout << "digit";

	// print out the rest of the intro statement
	std::cout << " of " << number << ":\n";

	// initialize total and place to 0 before we start looping
	int total = 0;
	int place = 0;

	// while place is less than the passed digit
	while (place < digit)
	{
		// First, get the value of the place digit from the end
		// of number and add it to total
		// to get the value of the pth digit of number:
		// use modulo of number by 10 and multiply that by 10 to
		// the place power then round that value down
		total += (number % 10) * pow(10, place);

		// divide number by 10 to trim off this leftmost digit,
		// this will allow the next digit to
		// be analyzed by modulo if needed
		number = number / 10;

		// increment place, this allows for the next digit to be
		// added properly to total if needed.
		place++;
	}

	// print out and return the retrieved digits of number
	std::cout << total << "\n";
	return total;
}

int CheckNeg(int number)
{
	// check if the number is negative
	if (number < 0)
	{
		// print out to ignore the sign
		std::cout << "Ignore the negative sign.\n\n";
		number = abs(number);
	}
	return number;
}

bool DivideBy1(int number)
{
	// print out that 1 is divisible by everything
	std::cout << "1 is divisible by everything. Thus, " << number << " is divisible by 1.\n";
	return true;
}

bool DivideBy2(int number)
{
	// print out intro statement
	std::cout << "To check if " << number << " is equally divisible by 2:\n";

	// initialize divisible as false before we start
	bool divisible = false;

	// initialize digits using the usual formula to find the
	// number of digits in number
	int digits = log10(number) + 1;
	
	// check if the number is negative
	number = CheckNeg(number);

	// print out 2 divisor trick prefix
	std::cout << "\nCheck if ";

	if (digits > 2)
	{
		std::cout << "the last digit of " << number;
	}
	else
	{
		std::cout << number;
	}

	// print out 2 divisor trick
	std::cout << " is a 0, 2, 4, 6 or 8.\n\n";

	// check if the last digit is a 0, 2, 4, 6 or 8
	int LastDigits = 0;
	LastDigits = GetLastDigits(number, 1);
	divisible = (LastDigits == 0 || LastDigits == 2 || LastDigits == 4 || LastDigits == 6 || LastDigits == 8);

	// print result
	std::cout << "\n" << LastDigits << (divisible ? " is" : " is not") << " 0, 2, 4, 6 or 8. Thus, the original number " << (divisible ? "is" : "is not") << " divisible by 2.\n";

	return divisible;
}

bool DivideBy3(int number)
{
	// print out intro statement
	std::cout << "To check if " << number << " is equally divisible by 3:\n\n";

	// initialize divisible as false before we start
	bool divisible = false;

	// check if the number is negative
	number = CheckNeg(number);

	// if number is big, get the sum of all digits of number
	while (number > 60)
	{
		number = GetDigitSum(number);

		// if number is still too big
		if (number > 60)
		{
			// print get digit sum step
			std::cout << "\n" << number << " is rather big.\n";
		}
	}

	// number is small enough just use modulo
	divisible = number % 3 == 0;

	// print result
	std::cout << "\n" << number << (divisible ? " is" : " is not") << " a multiple of 3. Thus, the orginal number" << (divisible ? " is" : " is not") << " divisible by 3.\n";

	return divisible;
}

bool DivideBy4(int number)
{
	// print out intro statement
	std::cout << "To check if " << number << " is equally divisible by 4:\n";

	// initialize divisible as false before we start
	bool divisible = false;

	// initialize digits using the usual formula to find the
	// number of digits in number
	int digits = log10(number) + 1;

	// check if the number is negative
	number = CheckNeg(number);

	// if number is big, get the last 2 digits of number
	if (digits > 2)
	{
		// print out get last digits step
		std::cout << "\n" << number << " is rather big.\n";
		number = GetLastDigits(number, 2);
	}

	if (number > 40)
	{
		// check if the second digit is even
		int digit2 = (number / 100) % 10;
		int LastDigits = 0;
		if (digit2 % 2 == 0)
		{
			// print out even digit trick
			std::cout << "\nThe leftmost digit of " << number << " is even.\nTherefore, the original number is divisible by 4 if the last digit is a 0, 4 or 8.\n\n";

			// last digit is a 0, 4 or 8
			LastDigits = GetLastDigits(number, 1);
			divisible = (LastDigits == 2 || LastDigits == 4 || LastDigits == 8);

			// print result
			std::cout << "\n" << LastDigits << (divisible ? " is" : " is not") << " a 0, 4 or 8. Thus, the original number " << (divisible ? "is" : "is not") << " divisible by 4.\n";
		}
		else
		{
			// print out odd digit trick
			std::cout << "\nThe leftmost digit of " << number << " is odd.\nTherefore, the original number is divisible by 4 if the last digit - 2 is a 2 or 6.\n\n";

			// last 2 digits - 2 is a multiple of 8
			LastDigits = GetLastDigits(number - 2, 1);
			divisible = (LastDigits == 2 || LastDigits == 6);

			// print result
			std::cout << "\n" << LastDigits << (divisible ? " is" : " is not") << " a 2 or 6. Thus, the original number " << (divisible ? "is" : "is not") << " divisible by 4.\n";
		}

		
	}
	else
	{
		std::cout << "\n" << number << " is small enough to check the multiples of 4 to see if it is divisible by 4.\n";
		// number is small enough just use modulo
		divisible = number % 4 == 0;

		// print result
		std::cout << "\n" << number << (divisible ? " is" : " is not") << " a multiple of 4. Thus, " << number << (divisible ? " is" : " is not") << " divisible by 4.\n";
	}

	return divisible;
}

bool DivideBy5(int number)
{
	// print out intro statement
	std::cout << "To check if " << number << " is equally divisible by 5:\n";

	// initialize divisible as false before we start
	bool divisible = false;

	// initialize digits using the usual formula to find the
	// number of digits in number
	int digits = log10(number) + 1;

	// check if the number is negative
	number = CheckNeg(number);

	// print out 5 divisor trick prefix
	std::cout << "\nCheck if ";

	if (digits > 2)
	{
		std::cout << "the last digit of " << number;
	}
	else
	{
		std::cout << number;
	}

	// print out 5 divisor trick
	std::cout << " is a 0 or 5.\n\n";

	// check if the last digit is a 0 or 5
	int LastDigits = 0;
	LastDigits = GetLastDigits(number, 1);
	divisible = (LastDigits == 0 || LastDigits == 5);

	// print result
	std::cout << "\n" << LastDigits << (divisible ? " is" : " is not") << " 0 or 5. Thus, the original number " << (divisible ? "is" : "is not") << " divisible by 5.\n";

	return divisible;
}

bool DivideBy6(int number)
{
	// print out intro statement
	std::cout << "To check if " << number << " is equally divisible by 6:\n\nAs 6 is a product of 2 and 3...\n";

	// initialize divisible as false before we start
	bool divisible = false;

	// check if the number is negative
	number = CheckNeg(number);

	// print out 6 divisor trick prefix
	std::cout << "\nCheck if " << number << " is divisible by 2:\n\n";

	// check 2
	divisible = DivideBy2(number);

	// print out result
	if (divisible)
	{
		std::cout << "\n" << number << " is divisible by 2, next check if it is divisible by 3:\n\n";

		// check 3
		divisible = DivideBy3(number);

		// print out result
		if (divisible)
		{
			std::cout << "\n" << number << " is divisible by 3 and by 2, Thus, " << number << " is divisible by 6.\n";
		}
		else
		{
			std::cout << "\n" << number << " is not divisible by 3, Thus, " << number << " is not divisible by 6.\n";
		}
	}
	else
	{
		std::cout << "\n" << number << " is not divisible by 2, Thus, " << number << " is not divisible by 6.\n";
	}

	return divisible;
}

bool DivideBy7(int number)
{
	// print out intro statement
	std::cout << "To check if " << number << " is equally divisible by 7:\n";

	// initialize divisible as false before we start looping
	bool divisible = false;

	// initialize digits using the usual formula to find the
	// number of digits in number
	int digits = log10(number) + 1;

	// check if the number is negative
	number = CheckNeg(number);

	// while we have more than 1 digit, keep looping
	while (digits > 1)
	{
		// print out a prefix
		std::cout << "\n1. ";
		// get the leftmost digit of number
		int lastDigit = GetLastDigits(number, 1);

		// print doubling step
		std::cout << "\n2. Double " << lastDigit << ".\n";
		// double lastDigit
		lastDigit *= 2;
		// print result of doubling
		std::cout << lastDigit << "\n";

		// print strip step
		std::cout << "\n3. Remove the last digit from " << number << ".\n";
		// strip of the leftmost digit of number
		number = number / 10;

		// print subtraction step
		std::cout << "\n4. Subract " << number << " from " << lastDigit
			<< ", ignore the sign of the difference.\n";
		std::cout << number << " - " << lastDigit;
		// set number equal to the absolute difference
		// between number and lastDigit
		number = abs(number - lastDigit);

		// print result of subracting
		std::cout << " = " << number << "\n";

		// recalculate the new number of digits of number to
		// see if we need to loop again
		digits = log10(number) + 1;

		// print if we have to loop again
		if (digits > 1)
		{
			std::cout << "\n" << number << " is still not one digit, repeat steps 1 - 4.\n";
		}
	}

	// print final check step
	// now that we only have 1 digit left, check if it is 0 or 7
	if (number == 0 || number == 7)
	{
		std::cout << "\n" << number << " is a 7 or a 0. Thus, the orginal number is divisible by 7.\n";
		// if it is, then the original number is divisible by 7
		divisible = true;
	}
	else
	{
		std::cout << "\n" << number << " is not a 7 or a 0. Thus, the orginal number is not divisible by 7.\n";
	}
		
	// return if number is divisible by 7
	return divisible;
}

bool DivideBy8(int number)
{
	// print out intro statement
	std::cout << "To check if " << number << " is equally divisible by 8:\n";

	// initialize divisible as false before we start
	bool divisible = false;

	// initialize digits using the usual formula to find the
	// number of digits in number
	int digits = log10(number) + 1;

	// check if the number is negative
	number = CheckNeg(number);

	// if number is big, get the last 3 digits of number
	if (digits > 3)
	{
		// print out get last digits step
		std::cout << "\n" << number << " is rather big.\n";
		number = GetLastDigits(number, 3);
	}

	if (digits > 2)
	{
		// check if the third digit is even
		int digit3 = (number / 100) % 10;
		int LastDigits = 0;
		if (digit3 % 2 == 0)
		{
			// print out even digit trick
			std::cout << "\nThe leftmost digit of " << number << " is even.\nTherefore, the original number is divisible by 8 if the last 2 digits are a multiple if 8.\n\n";
			
			// last 2 digits are a multiple of 8
			LastDigits = GetLastDigits(number, 2);
			divisible = LastDigits % 8 == 0;			
		}
		else
		{
			// print out odd digit trick
			std::cout << "\nThe leftmost digit of " << number << " is odd.\nTherefore, the original number is divisible by 8 if the last 2 digits - 4 is a multiple if 8.\n\n";

			// last 2 digits - 4 is a multiple of 8
			LastDigits = GetLastDigits(number - 4, 2);
			divisible = LastDigits % 8 == 0;
		}

		// print result
		std::cout << "\n" << LastDigits << (divisible ? " is" : " is not") << " a multiple of 8. Thus, the original number " << (divisible ? "is" : "is not") << " divisible by 8.\n";
	}
	else
	{
		std::cout << "\n" << number << " is small enough to check the multiples of 8 to see if it is divisible by 8.\n";
		// number is small enough just use modulo
		divisible = number % 8 == 0;

		// print result
		std::cout << "\n" << number << (divisible ? " is" : " is not") << " a multiple of 8. Thus, " << number <<(divisible ? " is" : " is not") << " divisible by 8.\n";
	}

	return divisible;
}

bool DivideBy9(int number)
{
	// print out intro statement
	std::cout << "To check if " << number << " is equally divisible by 9:\n\n";

	// initialize divisible as false before we start
	bool divisible = false;

	// check if the number is negative
	number = CheckNeg(number);

	// if number is big, get the sum of all digits of number
	while (number > 100)
	{
		number = GetDigitSum(number);

		// if number is still too big
		if (number > 100)
		{	
			// print get digit sum step
			std::cout << "\n" << number << " is rather big.\n";
		}
	}
	
	// number is small enough just use modulo
	divisible = number % 9 == 0;

	// print result
	std::cout << "\n" << number << (divisible ? " is" : " is not") << " a multiple of 9. Thus, the orginal number" << (divisible ? " is" : " is not") << " divisible by 9.\n";

	return divisible;
}

bool DivideBy10(int number)
{
	// print out intro statement
	std::cout << "To check if " << number << " is equally divisible by 10:\n";

	// initialize divisible as false before we start
	bool divisible = false;

	// initialize digits using the usual formula to find the
	// number of digits in number
	int digits = log10(number) + 1;

	// check if the number is negative
	number = CheckNeg(number);

	// print out 5 divisor trick prefix
	std::cout << "\nCheck if ";

	if (digits > 2)
	{
		std::cout << "the last digit of " << number;
	}
	else
	{
		std::cout << number;
	}

	// print out 10 divisor trick
	std::cout << " is a 0.\n\n";

	// check if the last digit is a 0
	int LastDigits = 0;
	LastDigits = GetLastDigits(number, 1);
	divisible = (LastDigits == 0);

	// print result
	std::cout << "\n" << LastDigits << (divisible ? " is" : " is not") << " 0. Thus, the original number " << (divisible ? "is" : "is not") << " divisible by 10.\n";

	return divisible;
}

bool GetDivAlg(int number, int divisor)
{
	// initialize divisible as false before we start
	bool divisible = false;
	// select an algorithm based on the divisor given
	switch(divisor)
	{
	case 1:
		divisible = DivideBy1(number);
		break;
	case 2:
		divisible = DivideBy2(number);
		break;
	case 3:
		divisible = DivideBy3(number);
		break;
	case 4:
		divisible = DivideBy4(number);
		break;
	case 5:
		divisible = DivideBy5(number);
		break;
	case 6:
		divisible = DivideBy6(number);
		break;
	case 7:
		divisible = DivideBy7(number);
		break;
	case 8:
		divisible = DivideBy8(number);
		break;
	case 9:
		divisible = DivideBy9(number);
		break;
	case 10:
		divisible = DivideBy10(number);
		break;
	}

	return divisible;
}

void GetInput(int& number, int& divisor)
{
	// initialize reference variables, just in case
	number = 0;
	divisor = 0;

	// print out prompt to ask the user for a number
	std::cout << "Input a number you wish to check, integers only: ";
	std::cin >> number;

	// keep looping until validation is correct
	while (std::cin.fail())
	{
		// clear cin buffer to accept new input
		std::cin.clear();
		std::cin.ignore(256, '\n');
		// print out error to the user
		std::cout << "Please input an integer only.\n";

		// print out prompt to ask the user for a new number
		std::cout << "Input a number you wish to check, integers only: ";
		std::cin >> number;
	}

	// clear cin buffer to accept new input
	std::cin.clear();
	std::cin.ignore(256, '\n');

	// print out prompt to ask the user for a divisor
	std::cout << "Input a divisor you wish to divide by, integers only (1 - 10): ";
	std::cin >> divisor;

	// keep looping until validation is correct
	while (divisor < 1 || divisor > 10 || std::cin.fail())
	{
		// clear cin buffer to accept new input
		std::cin.clear();
		std::cin.ignore(256, '\n');

		// check if number input is not an integer
		if (std::cin.fail()) {
			// print out error to the user
			std::cout << "Please input an integer only.\n";
		}
		// check if divisor input is out of range
		if (divisor < 1 || divisor > 10)
		{
			// print out error to the user
			std::cout << "Divisor out of range.\n";
		}

		// print out prompt to ask the user for a new divisor
		std::cout << "Input a divisor you wish to divide by, integers only (1 - 10): ";
		std::cin >> divisor;
	
	}
}

int main()
{
	// initialize main variables
	int number, divisor;
	char input;
	
	// print out welcome message
	std::cout << "Welcome to Division Tricks:\n\n";

	do
	{
		// get input and show the math trick steps
		GetInput(number, divisor);
		GetDivAlg(number, divisor);

		// print out prompt to ask user if they want to quit
		// or try another set
		std::cout << "\nCheck another number and divisor?\nInput y for yes or n to quit.\n";
		std::cin >> input;

		// keep looping until validation is correct
		while (input != 'y' && input != 'n')
		{
			// print out error to the user
			std::cout << "Please input y or n.\n";

			// clear cin buffer to accept new input
			std::cin.clear();
			std::cin.ignore(256, '\n');

			// print out prompt to ask user again if they 
			// want to quit or try another set
			std::cout << "\nCheck another number and divisor?\nInput y for yes or n to quit.\n";
			std::cin >> input;
		}
	} while (input == 'y');
}