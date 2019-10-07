//This program calculates the average amount of rainfall over a certain number of years.
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
  //Validates that number of years is greater than or equal to one.
  bool done = false;
  while (!done)
  {
    cout << "Enter the number of years: ";
    int number_years;
    cin >> number_years;

    if (number_years < 1)
    {
      cout << "Please enter a number greater than or equal to one." << endl;
    }
    else
    {
      done = true;
    }

    //for loops prompt user to enter inches of rainfall for every month
    int total_rainfall = 0;
    int total_months = 0;
    for (int counts = 0; counts < number_years; counts++)
    {
      for (int month_number = 1; month_number <= 12; month_number++)
      {
        //While loop to validate inches of rainfall is not negative
        bool quit = false;
        while (!quit)
        {
          cout << "Enter rainfall for each month in inches: ";
          int inches_rainfall;
          cin >> inches_rainfall;

          if (inches_rainfall < 0)
          {
            cout << "Please enter a positive number." << endl;
          }
          else
          {
            quit = true;
          }
          //accumulator to sum all inches of rainfall
          total_rainfall += inches_rainfall;
        }
        total_months = month_number * number_years;
      }
    }
    cout << "The total inches of rainfall were: " << total_rainfall
         << " inches." << endl;
    cout << "The total number of months were: " << total_months
         << " months." << endl;

    double average_rainfall = static_cast<double>(total_rainfall) /
                              total_months;
    cout << fixed << setprecision(2) << endl;
    cout << "The average rainfall was " << average_rainfall
         << " inch(s) per month." << endl;
  }
  return 0;
}
