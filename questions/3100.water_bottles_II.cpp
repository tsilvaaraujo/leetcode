class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int bottlesDrunk = 0;
        int emptyBottles = 0;
        while(true) {
            if(numBottles != 0) {
                bottlesDrunk += numBottles;
                emptyBottles += numBottles;
                numBottles = 0;
                while(emptyBottles >= numExchange) {
                    emptyBottles -= numExchange;
                    numExchange++;
                    numBottles++;
                }
            }
            else if(numExchange > emptyBottles) {
                return bottlesDrunk;
            }
        }
    }
};
