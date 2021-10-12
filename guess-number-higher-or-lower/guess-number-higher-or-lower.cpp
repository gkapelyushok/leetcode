/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = (right - left) / 2 + left;
            int guesss = guess(mid);
            if (guesss == 1) {
                left = mid + 1;
            } else if (guesss == -1) {
                right = mid - 1;
            } else {
                return mid;
            }         
        }
        return right;
    }
    
};