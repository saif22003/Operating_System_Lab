#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    // Declare arrays
    int bt[n], ct[n], wt[n], tat[n], rt[n], start[n];

    // Input Burst Time only
    cout << "\nEnter Burst Time of all processes:\n";
    for (int i = 0; i < n; i++) {
        cout << "BT of P[" << i + 1 << "]: ";
        cin >> bt[i];
    }


    start[0] = 0;                     
    ct[0] = bt[0];                    


    for (int i = 1; i < n; i++) {
        start[i] = ct[i - 1];         // Next process starts after previous completion
        ct[i] = start[i] + bt[i];     // Completion time
    }

   
    float totalWT = 0, totalTAT = 0, totalRT = 0;

    for (int i = 0; i < n; i++) {
        tat[i] = ct[i];               // TAT = CT - AT, but AT = 0
        wt[i]  = tat[i] - bt[i];      // Waiting Time
        rt[i]  = wt[i];               // RT = same as WT in FCFS (non-preemptive)

        totalWT  += wt[i];
        totalTAT += tat[i];
        totalRT  += rt[i];
    }

    // Print Table 
    cout << "\n\n----------------------------------------\n";
    cout << left << setw(6) << "PID" 
         << setw(6) << "BT" 
         << setw(6) << "ST" 
         << setw(6) << "CT" 
         << setw(6) << "TAT" 
         << setw(6) << "WT" 
         << setw(6) << "RT" << endl;
    cout << "----------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << left << setw(6) << ("P" + to_string(i + 1))
             << setw(6) << bt[i]
             << setw(6) << start[i]
             << setw(6) << ct[i]
             << setw(6) << tat[i]
             << setw(6) << wt[i]
             << setw(6) << rt[i] << endl;
    }
    cout << "----------------------------------------\n";

    // Print averages
    cout << fixed;
    cout.precision(2);
    cout << endl << "Average Waiting Time     = " << (totalWT / n) << endl;
    cout << "Average Turnaround Time  = " << (totalTAT / n) << endl;
    cout << "Average Response Time    = " << (totalRT / n) << endl;

    return 0;
}


// <<<<Input>>>>

// Enter the number of processes: 5

// Enter Burst Time of all processes:
// BT of P[1]: 8
// BT of P[2]: 3
// BT of P[3]: 2
// BT of P[4]: 1
// BT of P[5]: 4

// <<<<Output>>>>

// ----------------------------------------
// PNO   BT    ST    CT    TAT   WT    RT    
// ----------------------------------------
// P1    8     0     8     8     0     0     
// P2    3     8     11    11    8     8     
// P3    2     11    13    13    11    11    
// P4    1     13    14    14    13    13    
// P5    4     14    18    18    14    14    
// ----------------------------------------

// Average Waiting Time     = 9.20
// Average Turnaround Time  = 12.80
// Average Response Time    = 9.20
