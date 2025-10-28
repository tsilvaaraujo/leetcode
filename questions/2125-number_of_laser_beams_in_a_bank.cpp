class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int current = -1, previous = -1,total = 0;
        for(int i = 0; i < bank.size(); i++) {
            current = 0;
            for(int j = 0; j < bank[i].size(); j++) {
                if(bank[i][j] == '1')
                    current++;
            }
            if(current != -1 and previous != -1) {
                total += previous * current;
            }
            if(current != 0)
                previous = current;
        }
        return total;
    }
};
