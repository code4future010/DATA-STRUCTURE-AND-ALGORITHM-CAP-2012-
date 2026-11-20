// LeetCode 232 - Implement Queue using Stacks
// Amortized time: O(1) per operation; Space: O(n)
class MyQueue {
private:
    stack<int> inputStack, outputStack;

    void moveIfNeeded() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        inputStack.push(x);
    }

    int pop() {
        moveIfNeeded();
        int value = outputStack.top();
        outputStack.pop();
        return value;
    }

    int peek() {
        moveIfNeeded();
        return outputStack.top();
    }

    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};
