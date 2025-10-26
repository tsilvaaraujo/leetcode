class Solution {
public:
    int totalMoney(int n) {
        int current = 1, previous = 1;
        for(int i = 1; i < n; i++) {
            if(i % 7 == 0) { 
                current = current + (previous - 5);
                previous -= 5;
            } else {
                current = current + (previous + 1);
                previous++;
            }
        }
        return current;
    }
};
