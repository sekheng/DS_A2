#include "DetectMemoryLeak.h"
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
void QueryMachine(vector<int>& data, vector<int>& queries, vector<unsigned int>& results);

double timeTaken(clock_t startTime);

// this ensures that _CrtDumpMemoryLeaks() is called after main() and right before program terminates
struct AtExit
{
    ~AtExit() { _CrtDumpMemoryLeaks(); }
} doAtExit;

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
    for (int push = 10, lol = 8; push <= 1000000; push *= 10, --lol)
    {
        ll.insert_at(lol, push);
    }
    cout << ll.size() << endl;
    ll.insert_at(10, 70);
    cout << ll.size() << endl;
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
    cout << q.size() << endl;
    q.enqueue(20);
    q.enqueue(42);
    cout << q.dequeue() << endl;
    cout << q.size() << endl;
    for (int num = 10; num <= 1000000; num *= 10)
    {
        q.enqueue(num);
    }
    cout << q.size() << endl;
    for (int num = 10; num > 0; --num)
    {
        cout << q.dequeue() << endl;
    }
    cout << q.size() << endl;
    cout << endl;

    // Part 3
    cout << "Part 3" << endl;
    Stack s;
    cout << s.size() << endl;
    s.push(46);
    s.push(8);
    cout << s.pop() << endl;
    cout << s.size() << endl;
    cout << s.pop() << endl;
    cout << s.size() << endl;
    for (int num = 10; num <= 1000000; num *= 10)
    {
        s.push(num);
    }
    cout << s.size() << endl;
    for (int num = 10; num > 0; --num)
    {
        cout << s.pop() << endl;
    }
    cout << s.size() << endl;
    cout << endl;

    // part 4
    cout << "Part 4" << endl;
    const char* input = "<>";
    cout << Brackets(input) << endl;
    cout << Brackets("()") << endl;
    cout << Brackets("(<)>") << endl;
    cout << Brackets(")<)>") << endl;
    cout << Brackets("()((<>)())") << endl;
    cout << Brackets("()((<>()))") << endl;
    cout << Brackets("{<[()]>}") << endl;
    cout << Brackets("()()[]<>{{[{}]}}") << endl;
    cout << endl;


    // part 5
    cout << "Part 5" << endl;
    int dataArray[] = {1, 4, 5, 6, 9, 1, 1, 4};
    int queryArray[] = {1, 2, 3};

    vector<int> data(dataArray, dataArray + sizeof(dataArray) / sizeof(dataArray[0]));
    vector<int> queries(queryArray, queryArray + sizeof(queryArray) / sizeof(queryArray[0]));
    vector<unsigned int> results;
    QueryMachine(data, queries, results);
    for (size_t i = 0; i < results.size(); ++i)
    {
        cout << queries[i] << " occurred " << results[i] << " times" << endl;
    }
    cout << endl;
    results.empty();
    //vector<int> data2 = { 1, 2, 3, 4, 3, 2, 2, 6 };
    //vector<int> query2 = { 1, 2, 3 };
    //vector<unsigned int> results2;
    //QueryMachine(data2, query2, results2);
    //for (size_t i = 0; i < results2.size(); ++i)
    //{
    //    cout << results2[i] << " ";
    //}
    //cout << endl;
    //vector<int> query3 = { 3, 4, 5 };
    //vector<unsigned int> results3;
    //QueryMachine(data2, query3, results3);
    //for (size_t i = 0; i < results3.size(); ++i)
    //{
    //    cout << results3[i] << " ";
    //}
    //cout << endl;
    //vector<int> query4 = { 6, 5, 7 };
    //vector<unsigned int> results4;
    //QueryMachine(data2, query4, results4);
    //for (size_t i = 0; i < results4.size(); ++i)
    //{
    //    cout << results4[i] << " ";
    //}
    //cout << endl;
    cout << "Time taken to run the above code is " << timeTaken(start) << "ms" << endl;

    return 0;
}

// If you are curious, this calculates the time taken between the start time and the time that this function is called.
// The return value is in milliseconds (ms)
double timeTaken(clock_t startTime)
{
    return (clock() - startTime) / (double)(CLOCKS_PER_SEC/1000);
}

