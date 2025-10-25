class Solution {
public:
    /**
     * Calculates the total money in the Leetcode bank after n days.
     * This solution uses a brute-force simulation approach.
     *
     * @param n The total number of days.
     * @return The total amount of money saved.
     */
    int totalMoney(int n) {
        int totalMoney = 0;
        int currentMondayAmount = 1; // Tracks the amount to be deposited on Monday

        // Loop as long as there are days left to deposit
        while (n > 0) {
            
            // Inner loop simulates one week (Monday to Sunday)
            for (int dayOfWeek = 0; dayOfWeek < 7; ++dayOfWeek) {
                
                // If we have no more days left, break out of both loops
                if (n == 0) {
                    break;
                }

                // The deposit for the current day is the Monday amount + day offset
                int dailyDeposit = currentMondayAmount + dayOfWeek;
                
                // Add the deposit to the total
                totalMoney += dailyDeposit;

                // We have processed one day
                n--;
            }
            
            // After a full or partial week, increment the amount for the *next* Monday
            currentMondayAmount++;
        }

        return totalMoney;
    }
};
