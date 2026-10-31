#include <cs50.h>
#include <stdio.h>

// func prototype
float average(int len, int numbers[]);

int main(void) {
  // creates constant of how many number
  const int N = 3;

  // use that constant to determine the num of chunk for the array
  int scores[N];

  // i is zero; if i is less than the number of chunk, adds one
  // inside the loop, cs50 get_int will take interger, and assign it to the
  // scores array index, hence why it starts with zero
  for (int i = 0; i < N; i++) {
    scores[i] = get_int("Score: ");
  }

  printf("Average: %f\n", average(N, scores));
}

// define func
//  set func type to average, requires explicit input 1. len, which will be N
//  from above, ie the length of the array and 2. the value/data in each index
float average(int len, int numbers[]) {
  // total sum of all numbers
  int sum = 0;

  //
  for (int i = 0; i < len; i++) {
    // assign first number to sum, then use i which is placeholder for index to
    // add the initial sum with the second, then loop until the it reaches the
    // max num of chunk in the array, as defined above. make it compact by using
    // += instead oof sum = sum + numbers[i];

    sum += numbers[i];
  }

  // sum is established outside of the for looop, the loop only update the value
  // during each iteration. To calculate the average, use the updated sum from
  // the loop and divide by the num of chunk in array

  return sum / (float)len;
}

// fixes made:
// 1. main's for loop: added missing `int` so `i` is declared (was undeclared)
// 2. average's for loop: changed `,` to `;` between condition and increment
// 3. printf format string: fixed `'n` typo to the real newline escape `\n`
// 4. average: added `return` so the computed value leaves the function
//    instead of being discarded (was always coming back as garbage/0)
// 5. average: cast `len` to (float) before dividing, so the division is
//    float division and keeps the decimal instead of truncatin