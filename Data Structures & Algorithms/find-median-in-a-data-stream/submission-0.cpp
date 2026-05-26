class MedianFinder {
private:
    priority_queue<int> botHalf;
    priority_queue<int, vector<int>, greater<int>> topHalf;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        botHalf.push(num);
        topHalf.push(botHalf.top());
        botHalf.pop();

        if(botHalf.size() < topHalf.size()){
            botHalf.push(topHalf.top());
            topHalf.pop();
        }

        return;
    }
    
    double findMedian() {
        if(botHalf.size() != topHalf.size()){
            return botHalf.top();
        }
        return (botHalf.top() + topHalf.top()) / 2.0;
    }
};
