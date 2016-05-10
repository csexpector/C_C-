/* 
 * File:   fcfs.cpp
 * Author: dttung
 *
 * Created on October 4, 2015, 10:57 AM
 */

#include <cstdlib>
#include <iostream>
#include <deque>
#include <queue>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    int ps[10][19] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {7,19,8,13,17,13,19,19,44,15,29,51,14,68,15,49,14, 0, 0},     // p1
                      {9,52,12,42,24,31,24,21,26,43,14,31,23,32,15, 0, 0, 0, 0},    // p2
                      {25,51,43,53,44,21,15,31,24,29,31,34,12, 0, 0, 0, 0, 0, 0},   // p3
                      {6,29,5,22,6,24,8,27,5,25,6,24,8,26,9, 22, 8, 0, 0},          // p4
                      {5,66,6,82,5,71,6,43,4,26,6,51,3,77,4,61,3,42,5},             // p5
                      {9,35,8,41,11,33,13,32,8,41,16,29,11,0, 0, 0, 0, 0, 0},       // p6
                      {5,28,6,21,5,39,8,16,7,29,5,31,4,22,6,24,5, 0, 0},            // p7
                      {20,26,19,23,18,42,27,43,19,37,26,43,35,55,21, 0, 0, 0, 0},   // p8
                      {6,35,5,41,6,33,4,32,8,31,4,29,5,16,3,32,4, 0, 0}};           // p9
    
    
    deque<int> burst[10], iotime[10], remainio[10];
    
    // init burst and iotime
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 19; j = j+2)
        {
            if (ps[i][j] != 0)
            {
                burst[i].push_back(ps[i][j]);
                iotime[i].push_back(ps[i][j+1]);
                remainio[i].push_back(ps[i][j+1]);
            }
        }
    }

    
    // process in ready queue and io queue
    deque<int> ready, io;
    for (int i = 1; i < 10; i++)
    {
        ready.push_back(i);
    }
    int currTime = 0;
    int currBurst = 0;
    int passTime = 0;
    int running; // running process
    int runningBurst = 0; // burst of running process
    int runningIO;    // iotime of runnign process

    int count = 0;
    while (ready.size() != 0 || io.size() != 0)
    {
        //if (count++ == 12) exit(9); 
        cout << "Current Time: " << currTime << endl;
        // Get a running process from ready queue
        running = ready.front(); ready.pop_front();
        // Get burstime
        runningBurst = burst[running].front(); burst[running].pop_front();
        // Get iotime
        runningIO    = iotime[running].front(); iotime[running].pop_front(); 

        // Shown running process
        cout << "Now running: P" << running << endl;
        cout << ".................................................." << endl;
        // Show the other queue in ready with burst time
        cout << "Ready Queue:  Process    Burst" << endl;
        
        for (int i = 0; i < ready.size(); i++)
        {
            int rp = ready.at(i); //cout << "Debug:" << rp << endl;
            int burstTime = burst[rp].front();
            cout << "              P" << rp << "         " << burstTime << endl;
        }
        
        // Show IO queue
        cout << "Now in I/O:   Process    Remaining I/O time" << endl;
        if (io.size() == 0)
            cout << "              [empty]" << endl;
        else
        {
            for (int i = 0; i < io.size(); i++)
            {
                int iop = io.at(i);
                int remainTime = remainio[iop].front(); // 
                cout << "              P" << iop << "         " << remainTime << endl;
            }
        }
        
        // update ready queue, io queue
        // for each process in io queue, update remain time
        // if remain time is < 0, push new process in ready

        int size = io.size();
        for (int i = 0; i < size; i++)
        {
            int iop = io.front(); io.pop_front();
            int remainTime = remainio[iop].front(); remainio[iop].pop_front();// 
            cout << "Debug: " << iop << "Before: " << remainTime << " After: ";
            remainTime -= runningBurst; cout <<  remainTime << endl;
            if (remainTime > 0) // still in io queue
            {
                io.push_back(iop);
                remainio[iop].push_front(remainTime);
            }
            else // push new process in ready
            {
                ready.push_back(iop);
            }
        }
        cout << "REMAIN: ";
        for (int i = 0; i < remainio[1].size(); i++)
        {
            cout << remainio[1].at(i) << " -- ";
        }
        cout << endl;
        // push running process to ioque
        io.push_back(running);

        // update current time
        currTime += runningBurst;
    }
    return 0;
}

