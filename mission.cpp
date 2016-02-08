#include "DetectMemoryLeak.h"
#include <string>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <queue>

using std::string;
using std::vector;
using std::list;
using std::map;
using std::stack;
using std::queue;

// DO NOT MODIFY ANY LINE ABOVE OR ADD EXTRA INCLUDES

/*! 
 *  \brief     DM2126 Assignment 2
 *  \details   Submit the whole solution, but only this file will be used to grade
 *  \author    Lee Sek Heng
 *  \date      2015 
 *  \note      150629Z
 */


// Balanced parenthesis
 bool Brackets(const string& input)
{
    const char *charstring = input.c_str();
    stack<char> brackets;
    for (int num = 0; charstring[num] != '\0'; ++num) {
        switch (charstring[num]) {
        case ')':  if (brackets.size() <= 0 || brackets.top() != '(') { return false; }
                   else {
                       brackets.pop();
                   } break;
        case '}': if (brackets.size() <= 0 || brackets.top() != '{') { return false; }
                  else {
                      brackets.pop();
                  } break;
        case ']': if (brackets.size() <= 0 || brackets.top() != '[') { return false; }
                  else {
                      brackets.pop();
                  } break;
        case '>': if (brackets.size() <= 0 || brackets.top() != '<') { return false; }
                  else {
                      brackets.pop();
                  } break;
        default:        
            brackets.push(charstring[num]);
        }
    }
    if (brackets.size() <= 0) {
        return true;
    }
    else {
        return false;
    }
 }

// Query machine, hits
void QueryMachine(vector<int>& data, vector<int>& queries, vector<unsigned int>& results)
{
    map<int, size_t> isize_tmap;
    for (auto it : queries) {
        isize_tmap.insert(std::pair<int, size_t>(it, 0));
    }
    for (auto it : data) {
        if (isize_tmap.count(it) == 1) {
            map<int, size_t>::iterator it2 = isize_tmap.find(it);
            it2->second += 1;
        }
    }
    for (map<int, size_t>::iterator it = isize_tmap.begin(); it != isize_tmap.end(); ++it) {
        results.push_back(it->second);
    }
}