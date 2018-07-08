//***************************************************************************************************************************************************
//
// File Name: Main.cpp
//
// Description:
//  TODO: Add file description.
//
// Change History:
//  Author               Date           Description
//  Matthew D. Yorke     07/08/2018     Completed problem 1 of Project Euler with expanded capabilities to allow other maximum values to test.
//
//***************************************************************************************************************************************************

#include <iostream>
#include <sstream>

//***************************************************************************************************************************************************
//
// Method Name: GetUserInputInteger
//
// Description:
//  Returns an integer value a use inputs into the command line. If the value is not an integer type, then an error is produced asking for a valid
//  integer to be entered. Once a valid integer is input by the user, the value is returned.
//
//***************************************************************************************************************************************************
int GetUserInputInteger()
{
   std::string integerString = "";
   int returnInteger = 0;
   bool isValidInteger = false;

   while (isValidInteger == false)
   {
		std::getline(std::cin, integerString);
		std::stringstream stringToIntgerConversion(integerString);

		// Checks for complete conversion to integer and checks for minimum value
		if(stringToIntgerConversion >> returnInteger &&
         !(stringToIntgerConversion >> integerString))
      {
         isValidInteger = true;
      }
      else
      {
         std::cerr << "Invalid type, please enter an integer value: ";
      }
   }

   return returnInteger;
}

//***************************************************************************************************************************************************
//
// Method Name: GetSumofMultiples
//
// Description:
//  Cycles through each value from 0 to the maximum value (not including) and any value a multiple of 3 or 5 is added to the total sum of values.
//  Once the values are all checked, the sum total of values that are multiples of 3 or 5 are returned.
//
//***************************************************************************************************************************************************
int GetSumofMultiples(int maxValue)
{
   int sum = 0;

   for (int count = 0; count < maxValue; count++)
   {
      if (count % 3 == 0 ||
          count % 5 == 0)
      {
         sum += count;
      }
   }

   return sum;
}

//***************************************************************************************************************************************************
//
// Method Name: main
//
// Description:
//  The entrance of the program for this project. This method handles the prompt of the problem and calls methods to retrieve the user input and
//  computational outputs.
//
//***************************************************************************************************************************************************
int main()
{
   int sum = 0;
   int maxValue = 0;

   std::cout << "Enter an integer value for the maximum check for multiples of 3 and 5: ";

   maxValue = GetUserInputInteger();

   sum  = GetSumofMultiples(maxValue);

   std::cout << "The sum of all values that multiples of 3 and 5 below " << maxValue << " is: " << sum << "\n";

   system("pause");
}