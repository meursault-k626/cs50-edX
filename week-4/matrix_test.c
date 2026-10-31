#include <stdio.h>

int main(void)
{
    int seating_chart[3][4];
    int student_id = 1;

    // 1. The outer loop controls the ROW
    for (int row = 0; row < 3; row++)
    {
        // 2. The inner loop controls the COLUMN (the desk in that row)
        for (int col = 0; col < 4; col++)
        {
            // Assign the student ID to this specific seat
            seating_chart[row][col] = student_id;
            
            // Increment the ID for the next student
            student_id++;
        }
    }
}