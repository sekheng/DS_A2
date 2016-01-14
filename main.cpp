#include <string>
#include <vector>
#include "Node.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include <iostream>
#include <ctime>

using std::cout;
using std::endl;
using std::string;
using std::vector;


bool Brackets(const string& input);
void QueryMachine(vector<int>& data, vector<int>& queries, vector<int>& results);

double timeTaken(clock_t startTime);

int main()
{
    // This sets the boolean values to be represented in a textual format.
    cout << std::boolalpha;

    // Start the clock
    clock_t start = clock();

    // part 1
    cout << "Part 1" << endl;
    LinkedList ll;
    cout << ll.size() << endl;
    ll.insert_at(99999, 8);
    ll.push_back(69);
    ll.push_front(999);
    ll.push_back(99);
    cout << ll.size() << endl;
    cout << ll.pop_back() << endl;
    cout << ll.size() << endl;
    cout << ll.pop_front() << endl;
    cout << ll.size() << endl;
    cout << ll.pop_back() << endl;
    cout << ll.size() << endl;
    ll.insert_at(2, 10);
    cout << ll.size() << endl;
    cout << ll.pop_at(0) << endl;
    cout << ll.size() << endl;
    cout << ll.pop_front() << endl;
    cout << ll.size() << endl;
    for (int push = 10, lol = 8; push <= 1000000; push *= 10, lol--)
    {
        ll.insert_at(lol, push);
    }
    cout << ll.size() << endl;
    ll.insert_at(5, 70);
    cout << ll.size() << endl;
    cout << ll.pop_at(3) << endl;
    cout << ll.size() << endl;
    for (int need_delete = 10; need_delete > 0; --need_delete)
    {
        cout << ll.pop_front() << endl;
    }
    cout << endl;

    // part 2
    cout << "Part 2" << endl;
    Queue q;
    q.enqueue(20);
    q.enqueue(42);
    cout << q.dequeue() << endl;
    cout << q.size() << endl;
    for (int num = 10; num <= 1000000; num *= 10)
    {
        q.enqueue(num);
    }
    cout << q.size() << endl;
    cout << endl;

    // part 3
    cout << "Part 3" << endl;
    Stack s;
    s.push(46);
    s.push(8);
    cout << s.pop() << endl;
    cout << s.size() << endl;
    cout << endl;

    // part 4
    cout << "Part 4" << endl;
    const char* input = "<>";
    cout << Brackets(input) << endl;
    cout << endl;


    // part 5
    cout << "Part 5" << endl;
    int dataArray[] = {1, 4, 5, 6, 9, 1, 1, 4};
    int queryArray[] = {1, 2, 3};

    vector<int> data(dataArray, dataArray + sizeof(dataArray) / sizeof(dataArray[0]));
    vector<int> queries(queryArray, queryArray + sizeof(queryArray) / sizeof(dataArray[0]));
    vector<int> results;
    QueryMachine(data, queries, results);
    for (size_t i = 0; i < results.size(); ++i)
    {
        cout << results[i] << " ";
    }
    cout << endl;

    cout << "Time taken to run the above code is " << timeTaken(start) << "ms" << endl;
}

// If you are curious, this calculates the time taken between the start time and the time that this function is called.
// The return value is in milliseconds (ms)
double timeTaken(clock_t startTime)
{
    return (clock() - startTime) / (double)(CLOCKS_PER_SEC/1000);
}

