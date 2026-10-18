# Filter (Less) - Babystep Debugging Guide

Welcome to your debugging roadmap! I've broken down the issues you are facing into small, conceptual babysteps so you can work through them later. 

## Part 1: The Case of the Unchanged Pixels

**The Symptom:** 
When running `check50`, your `grayscale` and `sepia` functions failed because the output exactly matched the *original* colors (e.g., actual: `20 40 90`). 

**The Good News:**
Your logic and math for `grayscale`, `sepia`, and `reflect` are completely, 100% correct!

**Babystep 1:**
If your math is perfect, why would the computer test a version of your code that does nothing? 
* *Hint:* Did you save your `helpers.c` file before running the tests? 
* *Hint:* Did you run `make filter` to recompile your C code so `check50` uses the newest version? 
**Action:** Save your file, re-run `make filter`, and re-run `check50`. You should see a lot of green!

---

## Part 2: The Blur Bug

**The Symptom:**
Once you recompile, your `blur` function will still have a structural logic flaw.

**The Setup:**
Inside your `blur` function, you are currently looping over every pixel `[i][j]`. 
For each pixel, you are doing two things simultaneously in the exact same loop:
1. Copying the current pixel to your `copy` array.
2. Looking at neighboring pixels in the `copy` array to calculate the average.

**Babystep 2:**
Think about this chronologically. Look at your code starting on **line 102** and **line 104**. You have a single set of loops encompassing both your copying logic (**lines 106-108**) and your math (**lines 109-136**).

When you are on **line 119**, calculating the average for the very first pixel `[0][0]`, you are asking your code to look at its neighbor to the right `[0][1]`. 
* *Question:* Have you copied the pixel at `[0][1]` into your `copy` array yet? 
* *Answer:* No! You won't copy that pixel until the *next* iteration of your `j` loop on line 104. Because of this, your math is pulling empty/garbage memory for any neighbors you haven't visited yet.

**Babystep 3:**
How can you completely separate the copying process from the math process?
* *Action:* Instead of trying to copy and calculate at the exact same time, try making a dedicated set of loops *first* whose only job is to completely fill up the `copy` array. 
* Once the `copy` array is a 100% complete replica of the image, *then* you can start your second set of loops to do the blurring math!

---

## Part 3: The Blur Blueprint

Just to make sure you have everything you need, here is the conceptual blueprint for what your `blur` function should look like once you split those loops apart:

1. **Create the blank copy array** (You already did this!)
2. **Loop 1: The Copier**
   * Loop through every row `i`
   * Loop through every column `j`
   * Copy `image[i][j]` into `copy[i][j]` for Red, Green, and Blue.
3. **Loop 2: The Math**
   * Loop through every row `i` again
   * Loop through every column `j` again
   * Set your `totes` variables to 0
   * Loop through `r` and `s` to find the neighbors in your fully-populated `copy` array
   * Do the math
   * Assign the final values back to `image[i][j]`

Your math inside the loop is already 100% perfect, and your `cap_hue` helper function is a great safety net. Once you re-arrange those loops into this blueprint, you will have completed the entire problem set!
