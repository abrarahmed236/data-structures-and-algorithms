# Find Median from Data Stream (Problem 295)

Use a vector to remember the previously seen elements.  
Inefficient since we need to sort each time we call `findMedian`

```cpp
class MedianFinder {
    vector<int> data_stream;

   public:
    MedianFinder() {}

    void addNum(int num) { data_stream.push_back(num); }

    double findMedian() {
        sort(data_stream.begin(), data_stream.end());
        int N = data_stream.size();
        if (N & 1)
            return data_stream[N / 2];
        else
            return (data_stream[(N - 1) / 2] + data_stream[N / 2]) / 2.0;
    }
};
```

Version with two priority queues

```cpp
class MedianFinder {
    priority_queue<int, vector<int>, less<int>> less;    // maxHeap
    priority_queue<int, vector<int>, greater<int>> more; // minHeap

   public:
    MedianFinder() {}

    void addNum(int num) {
        less.push(num);
        more.push(less.top());
        less.pop();
        if (more.size() > less.size()) {
            less.push(more.top());
            more.pop();
        }
    }

    double findMedian() {
        if (less.size() > more.size())
            return less.top();
        else
            return (less.top() + more.top()) / 2.0;
    }
};
```

Additional follow-up questions exist. `//later`. Can be done.

### Follow up 1

What if all numbers are in the range 100. how would you solve this problem ?

- Yes, with buckets.

What if 99% of all problems are in 0 to 100 range but 1% are outside ?

- Yes, in this case the median is definitely between 0 100 so maintain buckets
  and remember how many numbers are before and after.
