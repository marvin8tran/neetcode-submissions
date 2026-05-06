class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for(int x : stones){
            maxHeap.push(x);
        }

        while(maxHeap.size() > 1){
            int a = maxHeap.top();
            maxHeap.pop();
            a -= maxHeap.top();
            maxHeap.pop();
            maxHeap.push(a);
        }

        return maxHeap.top();

    }
};
