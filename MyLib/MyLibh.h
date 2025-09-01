#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <limits> // for numeric_limits
#include <fstream> 

using namespace std;

namespace MyLib
{
	namespace Input
	{
		int ReadNumber()
		{
			int Number = 0;
			cout << "Please enter a number ? \n";
			cin >> Number;
		
			while (cin.fail())
			{
				//user didn't input a number 
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Invalid Number, Enter a valid one : " << endl;
		
				cin >> Number;
			}
		
			return Number;
		}

		int ReadPositiveNumber(string message)
		{
			int Number = 0;

			do
			{
				cout << message << endl;
				cin >> Number;

			} while (Number < 0);

			return Number;
		}

		short ReadShortNumber()
		{
			short Number = 0;

			cout << "Please Enter a number : \n";
			cin >> Number;

			return Number;
		}

		int ReadIntNumber()
		{
			int Number = 0;

			cout << "Please Enter a number : \n";
			cin >> Number;

			return Number;
		}

		float ReadFloatNumber()
		{
			float Number = 0;

			cout << "Please Enter a float number : \n";
			cin >> Number;

			return Number;
		}

		int ReadNumberInRange(int From, int To)
		{
			int Number = 0;

			do
			{
				cout << "Please Enter a Number between " << From << " and " << To << endl;
				cin >> Number;

			} while (Number <= From || Number >= To);


			return Number;
		}

	}

	namespace Array
	{
		void ReadArray(int arr[100], int& arrLength)
		{
			cout << "\nPlease enter number of elements : \n";
			cin >> arrLength;

			cout << "\nEnter Array Elements : \n";

			for (int i = 0; i < arrLength; i++)
			{
				cout << "Element [" << (i + 1) << "] : ";
				cin >> arr[i];
			}
			cout << endl;
		}

		void PrintArray(int arr[100], int arrLength)
		{
			for (int i = 0; i < arrLength; i++)
			{
				cout << arr[i] << " ";
			}

			cout << "\n";
		}

		int CountOccurrences(int NumberToCheck, int arr[100], int arrLength)
		{
			int Count = 0;

			for (int i = 0; i < arrLength; i++)
			{
				if (arr[i] == NumberToCheck)
				{
					Count++;
				}
			}

			return Count;
		}

		int RandomNumber(int From, int To)
		{
			int randomNumber = rand() % (To - From + 1) + From;
			return randomNumber;
		}

		void FillArrayWithRandomNumbers(int arr[100], int& arrayLength)
		{
			cout << "\nEnter number of elements : \n";
			cin >> arrayLength;

			for (int i = 0; i < arrayLength; i++)
			{
				arr[i] = RandomNumber(1, 100);
			}
		}

		int MaxNumberInArray(int arr[100], int arrayLength)
		{
			int MaxNumber = arr[0];

			for (short i = 1; i < arrayLength; i++)
			{
				if (arr[i] > MaxNumber)
				{
					MaxNumber = arr[i];
				}
			}

			return MaxNumber;
		}

		int MinNumberInArray(int arr[100], int arrayLength)
		{
			int MinNumber = arr[0];

			for (short i = 1; i < arrayLength; i++)
			{
				if (arr[i] < MinNumber)
				{
					MinNumber = arr[i];
				}
			}

			return MinNumber;
		}

		int SumOfAllNumbersInArray(int arr[100], int arrayLength)
		{
			int Summation = 0;

			for (int i = 0; i < arrayLength; i++)
			{
				Summation += arr[i];
			}

			return Summation;
		}

		float ArrayAverage(int arr[100], int arrayLength)
		{
			int Summation = SumOfAllNumbersInArray(arr, arrayLength);

			return (float)Summation / arrayLength;
		}

		void SummationOf2Arrays(int arraysLength, int arr[100], int arr2[100], int arrSum[100])
		{
			for (int i = 0; i < arraysLength; i++)
			{
				arrSum[i] = arr[i] + arr2[i];
			}
		}

		void Swap(int& A, int& B)
		{
			int Temp = A;
			A = B;
			B = Temp;
		}

		void ShuffleArray(int arr[100], int arrayLength)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				int index1 = RandomNumber(1, arrayLength) - 1;
				int index2 = RandomNumber(1, arrayLength) - 1;

				Swap(arr[index1], arr[index2]);
			}
		}

		void CopyArrayInReverseOrder(int arrSource[100], int arrDestination[100], int arrayLength)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				arrDestination[i] = arrSource[arrayLength - 1 - i];
			}
		}

		short FindNumberPositionInArray(int arr[100], int arrayLength, int Number)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				if (arr[i] == Number)
				{
					return i;
				}
			}
			// if your reached here , this means the number isn't found  
			return -1;
		}

		bool IsNumberInArray(int arr[100], int arrayLength, int Number)
		{
			return FindNumberPositionInArray(arr, arrayLength, Number) != -1;
		}

		int ReadNumber()
		{
			int Number = 0;

			cout << "\nPlease enter a number :";
			cin >> Number;

			return Number;
		}

		void AddArrayElement(int Number, int arr[100], int& arrayLength)
		{
			//it's a new element so we want to add the length by 1
			arrayLength++;
			arr[arrayLength - 1] = Number;
		}

		void InputUserNumbersInArray(int arr[100], int& arrayLength)
		{
			bool AddMore = true;

			do
			{
				AddArrayElement(ReadNumber(), arr, arrayLength);

				cout << "\nDo you want to add more numbers? [0]:No , [1]:Yes ? ";
				cin >> AddMore;

			} while (AddMore);
		}

		void CopyArrayUsingAddArrayElement(int arrSource[100], int arrDestination[100], int arrayLength, int& arrLengthDestination)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				AddArrayElement(arrSource[i], arrDestination, arrLengthDestination);
			}
		}

		void CopyOddNumbers(int arrSource[100], int arrDestination[100], int arrayLength, int& arrDestinationLength)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				if (arrSource[i] % 2 != 0)
				{
					// If odd, add it to the destination array using the AddArrayElement function.
					AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
				}
			}
		}

		void CopyDistinctNumbersToArray(int arrSource[100], int arrDestination[100], int SourceLength, int& DestinationLength)
		{
			for (int i = 0; i < SourceLength; i++)
			{
				if (!IsNumberInArray(arrDestination, DestinationLength, arrSource[i]))
				{
					AddArrayElement(arrSource[i], arrDestination, DestinationLength);
				}
			}
		}

		bool IsPalindromeArray(int arrSource[100], int arrDestination[100], int arrayLength)
		{
			CopyArrayInReverseOrder(arrSource, arrDestination, arrayLength);

			for (int i = 0; i < arrayLength; i++)
			{
				if (arrSource[i] != arrDestination[i])
				{
					return false;
				}
			}

			return true;
		}

		short OddCount(int arr[100], int arrayLength)
		{
			short Counter = 0;

			for (int i = 0; i < arrayLength; i++)
			{
				if (arr[i] % 2 != 0)
				{
					Counter++;
				}
			}

			return Counter;
		}

		short EvenCount(int arr[100], int arrayLength)
		{
			short Counter = 0;

			for (int i = 0; i < arrayLength; i++)
			{
				if (arr[i] % 2 == 0)
				{
					Counter++;
				}
			}

			return Counter;
		}

		short PositiveNumbersCount(int arr[100], int arrayLength)
		{
			short Counter = 0;

			for (int i = 0; i < arrayLength; i++)
			{
				if (arr[i] >= 0)
				{
					Counter++;
				}
			}

			return Counter;
		}

		short NegativeNumbersCount(int arr[100], int arrayLength)
		{
			short Counter = 0;

			for (int i = 0; i < arrayLength; i++)
			{
				if (arr[i] < 0)
				{
					Counter++;
				}
			}

			return Counter;
		}
	}

	namespace DigitUtils
	{
		int ReverseNumber(int Number)
		{
			int Remainder = 0, Number2 = 0;

			while (Number > 0)
			{
				Remainder = Number % 10;
				Number /= 10;
				Number2 = Number2 * 10 + Remainder; // Shift left :)
			}
			return Number2;
		}

		bool IsPalindrome(int Number)
		{
			return Number == ReverseNumber(Number);
		}

		int CountDigitFrequency(int Number, short DigitToCheck)
		{

			if (Number == 0 && DigitToCheck == 0)
			{
				return 1;
			}

			int Remainder = 0, FreqCount = 0;

			while (Number > 0)
			{
				Remainder = Number % 10;
				Number /= 10;

				if (Remainder == DigitToCheck)
				{
					FreqCount++;
				}
			}

			return FreqCount;
		}

		void PrintAllDigitsFrequency(int Number)
		{
			cout << endl;


			for (int i = 0; i < 10; i++)
			{
				short DigitFrequency = 0;
				DigitFrequency = CountDigitFrequency(Number, i);

				if (DigitFrequency > 0)
				{
					cout << "Digit " << i << " Frequency is "
						<< DigitFrequency << " Time(s).\n";
				}
			}
		}

		int SumOfDigits(int Number)
		{
			int Summation = 0, Remainder = 0;

			while (Number > 0)
			{
				Remainder = Number % 10;
				Number /= 10;
				Summation += Remainder;
			}

			return Summation;
		}

	}

	namespace Math
	{
		int MaxOf2Numbers(int Number1, int Number2)
		{
			if (Number1 > Number2)
			{
				return Number1;
			}
			else
			{
				return Number2;
			}
		}

		int MaxOf3Numbers(int A, int B, int C)
		{
			if (A > B)
			{
				if (A > C)
					return A;
				else
					return C;
			}
			else
			{
				if (B > C)
					return B;
				else
					return C;
			}
		}

		void Swap(int& A, int& B)
		{
			int Temp;

			Temp = A;
			A = B;
			B = Temp;
		}

		int FactorialOfN(int Number)
		{
			int F = 1;

			for (int Counter = Number; Counter >= 1; Counter--)
			{
				F *= Counter;
			}

			return F;
		}

		int SumNumbers()
		{
			int Summation = 0;
			int Number = 0;
			int Counter = 1;

			cout << "Please enter number " << to_string(Counter) << " : " << endl;
			cin >> Number;

			while (Number != -99)
			{
				Summation += Number;
				Counter++;

				cout << "Please enter number " << to_string(Counter) << " : " << endl;
				cin >> Number;
			}

			return Summation;
		}

		bool IsPerfectNumber(int Number)
		{
			int Sum = 0;

			for (int i = 1; i < Number; i++)
			{
				if (Number % i == 0)
				{
					Sum += i;
				}
			}

			return Sum == Number;
		}

		float MyABS(float Number)
		{
			if (Number >= 0)
			{
				return Number;
			}
			else
			{
				// return -Number or 0 - Number ;
				return Number * -1;
			}
		}

		float GetFractionPart(float Number)
		{
			return Number - (int)Number;
		}

		int MyRound(float Number)
		{
			int IntPart = int(Number);

			float FractionsPart = GetFractionPart(Number);

			// If the absolute value of the fractional part is 0.5 or more, round the number accordingly.
			if (abs(FractionsPart) >= 0.5f)
			{
				// If the number is positive, round up.
				if (Number > 0)
				{
					return ++IntPart;
				}
				// If the number is negative, round down.
				else
				{
					return --IntPart;
				}
			}
			// If the fractional part is less than 0.5, keep the integer part as it is.
			else
			{
				return IntPart;
			}
		}

		int MyFloor(float Number)
		{
			int IntPart = int(Number);

			if (Number >= 0)
			{
				return IntPart;
			}
			else
			{
				// If there's a fraction in the number 
				if (GetFractionPart(Number) != 0.0f)
				{
					return --IntPart;
				}
				else
				{
					return IntPart;
				}

			}
		}

		int MyCeil(float Number)
		{
			int IntPart = int(Number);

			if (Number == IntPart)
			{
				return IntPart;
			}
			else
			{
				if (Number >= 0)
				{
					return ++IntPart;
				}
				else
				{
					return IntPart;
				}
			}
		}

		float MySqrt(float Number)
		{
			return pow(Number, 0.5);
		}
	}

	namespace CheckNumbers
	{
		bool ValidateNumberInRange(int Number, int From, int To)
		{
			return (Number >= From && Number <= To);
		}

	}

	namespace Print
	{
		void PrintRangeFrom1ToNumber(int Number)
		{
			for (int Counter = 1; Counter <= Number; Counter++)
			{
				cout << Counter << endl;
			}
		}

		void PrintRangeFromNumberto1(int Number)
		{
			for (int Counter = Number; Counter >= 1; Counter--)
			{
				cout << Counter << endl;
			}
		}

	}

	namespace Conversions
	{
		float HoursToDays(float NumberOfHours)
		{
			return NumberOfHours / 24;
		}

		float HoursToWeeks(float NumberOfHours)
		{
			return NumberOfHours / 24 / 7;
		}

		float DaysToWeeks(float NumberOfDays)
		{
			return  NumberOfDays / 7;
		}
	}

	namespace Random
	{
		int RandomNumber(int From, int To)
		{
			int RandNum = rand() % (To - From + 1) + From;
			return RandNum;
		}
	}

	namespace Console
	{
		void ResetScreen()
		{
			system("cls");
			system("color 0F");
		}
	}

	namespace Vector
	{
		int ReadNumber()
		{
			int Number = 0;
			cout << "Please enter a number ? \n";
			cin >> Number;
				
			while (cin.fail())
			{
				//user didn't input a number 
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Invalid Number, Enter a valid one : " << endl;
				
				cin >> Number;
			}
				
			return Number;
		}
		
		void ReadNumbers(vector<int>& vNumbers)
		{
			char ReadMore = 'Y';
			int Number;
		
			while (ReadMore == 'Y' || ReadMore == 'y')
			{
				Number = ReadNumber();
				vNumbers.push_back(Number);
		
				cout << "\nDo you want to add more numbers ? Y/N: \n";
				cin >> ReadMore;
			}
		}
		
		void PrintVectorNumbers(const vector<int>& vNumbers)
		{
			cout << "\n";
			cout << "Numbers vector : \n";
		
			for (int& Number : vNumbers)
			{
				cout << Number << endl;
			}
			cout << endl;
		}

	}

	namespace Files
	{
		void PrintFileContent(const string FilePath)
			{
				fstream MyFile(FilePath, ios::in);
			
				if (MyFile.is_open())
				{
					string currentLine = "";
			
					while (getline(MyFile, currentLine))
					{
						cout << currentLine << '\n';
					}
			
					MyFile.close();
				}
		}
		
		void CopyFile(const string sourcePath, const string destinationPath, const bool override)
			{
				fstream srcFile;
				srcFile.open(sourcePath, ios::in);
			
				fstream destinationFile;
				destinationFile.open(destinationPath, override ? ios::out : ios::app);
			
				if (srcFile.is_open() && destinationFile.is_open())
				{
					string currentLine = "";
					while (getline(srcFile, currentLine))
					{
						destinationFile << currentLine << '\n';
					}
			
					srcFile.close();
					destinationFile.close();
				}
		}
		
		void ClearFile(const string FilePath)
			{
				fstream MyFile(FilePath, ios::out);
			
				if (MyFile.is_open())
				{
					MyFile.close();
				}
		}
		
		void CutFile(const string sourcePath, const string destinationPath, const bool override)
		{
			CopyFile(sourcePath, destinationPath, override);
			ClearFile(sourcePath);
		}

	}



}
