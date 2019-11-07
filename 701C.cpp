
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



typedef long num_chars;
typedef long label;
#define REPEAT(token, num) for (token = 0; token < num; token++)

/**
 * NOTE:
 * string holds the input string found with scanf()
 *
 * numTypes is the number of distinct letters found in string.
 * Each letter is marked with its own label within 0 and numTypes-1.
 * This way, the label can be used in an array of numTypes elements.
 * A letter is converted to its label with convertToLabel[].
 * flats[i] == convertToLabel[string[i]]
 *
 * countTypes[i][convertToLabel[letter]] is the number of occurrences of letter in string within indicies 0 and i.
*/

num_chars length, numTypes, countTypes[100000][52], answer;
label convertToLabel[256], flats[100000];
char string[100001];

int main() {
    num_chars i, beg, mid, end, j;
    bool valid;
    scanf("%li %s", &length, string);
    //The answer is at least length, so that's our initial guess:
    answer = length;

    //Mark all 256 characters as "not yet found in string":
    REPEAT(i, 256) convertToLabel[i] = -1;

    REPEAT(i, length) {
        //If string[i] is a new letter, give it a new label and increment numTypes:
        if (convertToLabel[string[i]] == -1) convertToLabel[string[i]] = numTypes++;
        //Set flats[i]:
        flats[i] = convertToLabel[string[i]];

        //If there is a previous letter, copy the previous countTypes[] over to the new countTypes[]
        if (i) memcpy(countTypes+i, countTypes+(i-1), 52*sizeof(label));
        //Increment countTypes[i][flats[i]] to mark another occurrence of string[i]:
        /*if(i)
            countTypes[i][flats[i]] = countTypes[i-1][flats[i]]+1;

        else*/
            countTypes[i][flats[i]]++;
    }

    //for(int i=0;i<length;i++)
    //    printf("%d\n",flats[i]);

    //Loop through each letter:
    REPEAT(i, length) {
        /*
            We want to find the least index beg such that string[i] through string[beg] contains all types of letters.
            We do this using binary search knowing that i <= beg <= length-1.
        */
        beg = i, end = length-1;
        while (beg <= end) {
            //Here, we are testing mid to see if string[i] through string[mid] has all of the letters.
            mid = (beg+end)/2;
            //We assume that this is true until we can prove it is false.
            valid = true;

            //Loop through each type of letter:
            REPEAT(j, numTypes) {
                //If the number of occurences of j from i to mid is 0, then string[i] through string[mid] is missing j and it is thus not valid:
                if ((countTypes[mid][j]-(i ? countTypes[i-1][j] : 0)) == 0) valid = false;
            }

            //If, by the end, mid has passed all tests, then it is valid and beg <= mid, so we lower end:
            if (valid) end = mid-1;
            //Otherwise, beg > mid and we heighten beg:
            else beg = mid+1;
        }
        //Finally, if beg exists (beg < length) and the number of letters between i and beg is less than the current answer, we update answer:
        if (beg < length && answer > beg-i+1) answer = beg-i+1;
    }
    printf("%li\n", answer);

    exit(0);
}
