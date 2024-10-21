#include <iostream>
#include <vector>

class NumberIterator {
public:
    virtual ~NumberIterator() {};
    virtual int next() = 0;  // pure virtual function
    virtual bool isFinished() = 0;  // pure virtual function
};

class ForwardsIterator : public NumberIterator {
    int currentPosition;
    std::vector<int> &numbers;
public:
    ForwardsIterator(std::vector<int> &numbers) : currentPosition(0), numbers(numbers) {};
    int next() override {
        int current = numbers.at(currentPosition);
        currentPosition += 1;
        return current;
    }
    bool isFinished() override {
        return currentPosition >= numbers.size();
    }
};

class BackwardIterator : public NumberIterator {
    int currentPosition;
    std::vector<int> &numbers;
public:
    BackwardIterator(std::vector<int> &numbers) : currentPosition(0), numbers(numbers) {};
    int next() override {
        int current = numbers.at(numbers.size() - currentPosition - 1);
        currentPosition += 1;
        return current;
    }
    bool isFinished() override {
        return currentPosition >= numbers.size();
    }
};

class NumberCollection {
    std::vector<int> numbers;
public:
    NumberCollection(const std::vector<int>& numbers) : numbers(numbers) {};
    NumberIterator* getForwardsIterator() {
        return new ForwardsIterator(numbers);
    }
    NumberIterator* getBackwardIterator() {
        return new BackwardIterator(numbers);
    }
};

int main() {
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7 };
    NumberCollection nc(numbers);

    NumberIterator* fi = nc.getForwardsIterator();
    NumberIterator* bi = nc.getBackwardIterator();

    while (!fi->isFinished()) {
        std::cout << fi->next() << " ";
    }
    std::cout << std::endl;

    while (!bi->isFinished()) {
        std::cout << bi->next() << " ";
    }
    std::cout << std::endl;

    delete fi;
    delete bi;
    return 0;
}
