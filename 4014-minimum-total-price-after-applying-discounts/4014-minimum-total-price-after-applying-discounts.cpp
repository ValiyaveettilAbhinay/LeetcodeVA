class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        
        sort(prices.rbegin(),prices.rend());
        sort(discounts.rbegin(),discounts.rend());

        int n = discounts.size();
        double sum = 0;
        int ind = 0;

        for(int price : prices){
            
            int disc = 0;
            if(ind < n){
                disc = discounts[ind];
                ind++;
            }

            double addPrice = 0;
            if(disc != 0){
                addPrice = (price * (100 - disc))/100.0;
            }
            else{
                addPrice = price;
            }
            sum += addPrice;

        }
        return sum;

    }
};