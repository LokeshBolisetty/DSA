/*

Question:
The school cafeteria offers circular and square sandwiches at lunch break, referred to by numbers 0 and 1 respectively. All students stand in a queue. Each student either prefers square or circular sandwiches.

The number of sandwiches in the cafeteria is equal to the number of students. The sandwiches are placed in a stack. At each step:

    If the student at the front of the queue prefers the sandwich on the top of the stack, they will take it and leave the queue.
    Otherwise, they will leave it and go to the queue's end.

This continues until none of the queue students want to take the top sandwich and are thus unable to eat.

You are given two integer arrays students and sandwiches where sandwiches[i] is the type of the i​​​​​​th sandwich in the stack (i = 0 is the top of the stack) and students[j] is the preference of the j​​​​​​th student in the initial queue (j = 0 is the front of the queue). Return the number of students that are unable to eat.

*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int leetCodeOptimal(vector<int>& students, vector<int>& sandwiches) {
    //Copy pasted from leetcode as is
    int hungry = 0;
    while(students.size() and sandwiches.size()){
        
        if (students[0] == sandwiches[0]){
            hungry = 0;
            students.erase(students.begin());
            sandwiches.erase(sandwiches.begin());
        } else {
            hungry++;
            int student = students[0];
            students.erase(students.begin());
            students.push_back(student);
        }
        if (hungry == students.size()){
            return hungry;
        }
    
    }
    return hungry;
}

int countStudents(vector<int> &students, vector<int> &sandwiches)
{
    // Students cant eat lunch when all the students want the same thing and the top of the stack is different
    int n = students.size();
    int count = 0;
    queue<int> stud;
    int sandwichCount = 0;
    for (int i = 0; i < n; i++)
    {
        count += students[i];
        stud.push(students[i]);
        sandwichCount += sandwiches[i];
    }

    //If there are equal number of square and circular sandwiches, then no one will stay hungry
    if (sandwichCount == count)
        return 0;
    for (int i = 0; i < n; i++)
    {
        //If all the remaining students want either square or rectangle, then they can't have it
        if (count == n - i && sandwiches[i] != stud.front())
            return count;
        else if (count == 0 && sandwiches[i] != stud.front())
            return n - i;
        while (sandwiches[i] != stud.front())
        {
            stud.push(stud.front());
            stud.pop();
        }
        stud.pop();
        count -= sandwiches[i];
    }
    return -1;
}

int main()
{
    vector<int> students = {0, 0, 0};
    vector<int> sandwiches = {1, 1, 1};
    cout << countStudents(students, sandwiches) << endl;
    return 0;
}