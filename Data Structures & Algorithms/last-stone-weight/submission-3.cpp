class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for(int x : stones){
            maxHeap.push(x);
        }

        while(maxHeap.size() >= 2){
            int num1 = maxHeap.top();
            maxHeap.pop();
            int num2 = maxHeap.top();
            maxHeap.pop();
            if(num1 > num2){
                maxHeap.push(num1 - num2);
            }
        }
        maxHeap.push(0);
        return maxHeap.top();

    }
};
