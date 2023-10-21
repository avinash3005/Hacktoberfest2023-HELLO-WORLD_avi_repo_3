/* A FUNCTION (ARITHMATIC_CALCULATIONS) IN C SYNTAX 
THAT TAKES AN INT ARRAY AS INPUT AND IT WILL PRINTS 
THE MEAN, MEDIAN AND MODE OF NUMBERS WHICH ARE IN THE ARRAY. */
#include<stdio.h>
#include<math.h>
// FUNCTION DEFINITION AND DECLARATION
int arithmetic_calculations(int array[],int number)
{
  float mean, median, total;
  int charli, delta, second_array[] = {0};
  int stand_in, count = 1, max = 0, mode;

  //SORTING ARRAY IN ASCENDING ORDER
  for(charli = 0; charli < number; charli++)
  {
    for (delta = charli + 1; delta < number; delta++) 
    {
      if(array[charli] > array[delta])
      { 
        stand_in = array[charli];
        array[charli] = array[delta];
        array[delta] = stand_in;
      }
    }
  }
  
  // TOTAL OF ELEMENTS OF ARRAY
  for(charli = 0; charli < number; charli++)
  {
    total = (float)(total + array[charli]);
  }
  // TAKING MEAN OF ARRAY
  mean = total/number;
  //PRINTING MEAN
  printf("The value of Mean = %.2f \n", mean);
  //IF ARRAY HAS EVEN NUMBER OF ELEMENTS
  if(number % 2 == 0)
  {
   median = (float)(array[(number - 1) / 2] + array[number / 2]) / 2.0;
  } 
  //IF ARRAY HAS ODD NUMBER OF ELEMENTS
  else
  {
    median = (float)array[number / 2];
  }
  // PRINTING MEDIAN ACCORDING TO CONDITION
  printf("The value of Median = %.2f \n", median);
  // CODE FOR CALCULATING MODE
  for (charli = 0; charli < number - 1; charli++)
  {
    mode = 0;
    //A COUPLE OF LOOPS WILL BE USED FOR COMPARISON
    for (delta = charli + 1; delta < number; delta++)
    {
      /*IF SAME ELEMENTS ARE PRESENT IN FIRST ARRAY,
       IT WILL CAUSE INCREMENT IN MODE */
      if (array[charli] == array[delta])
      {
        mode++;
      }
    }
    // END 0F SECOND LOOP
    //IF MODE HAS INCREASED, THIS CONDITION WILL EXECUTE
    if ((mode > max) && (mode != 0))
    {
      stand_in = 0;
      //VALUE OF MODE IS COPIED IN MAX
      max = mode;
      //THE REPEATED VALUE IS SENT IN SECOND ARRAY
      second_array[stand_in] = array[charli];
      stand_in++;
    }
    else if (mode == max) 
    // IF MODE IS NOT INCRESED, THIS CONDITION WILL BE EXECUTED
    {
      second_array[stand_in] = array[charli];
      stand_in++;
    }
  }
  for (charli = 0; charli < number; charli++)
  {
    if (array[charli] == second_array[charli])
    { // CHECK POINT FOR BOTH ARRAYS
      count++;
    }
  }
  //IF COUNT IS ZERO, MODE IS ZERO
  if (count == number)
  {
    printf("There is no mode \n");
  }
  else
  {
    for (charli = 0; charli < stand_in; charli++)
    // NUMBER OF MODE ELEMENTS ARE STORED IN SECOND ARRAY 
    {
      printf("The value of Mode = %d \n",second_array[charli]);
    }
  }
}

// MAIN FUNCTION
int main()
{
  int number, array[10], charli;

  // TAKING THE SIZE OF ARRAY, FROM USER
  printf("enter size of array: \n");
  scanf("%d", &number);
  //CONDITION FOR TAKING ELEMENTS OF ARRAY
  printf("enter elements of array: ");
  for(charli = 0; charli < number; charli++)
  {
    scanf("%d", &array[charli]);
  }
  //FUNCTION CALL
  arithmetic_calculations(array,number);
  return 0;
}
