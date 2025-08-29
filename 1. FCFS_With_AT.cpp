//FCFS with Arival Time 


#include <iostream>
#include <iomanip> // for setw, formatting
using namespace std;

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    // Declare arrays
    int at[n], bt[n], ct[n], wt[n], tat[n], rt[n], start[n];

    // Input Arrival Time
    cout << endl << "Enter Arrival Time of all processes:\n";
    for (int i = 0; i < n; i++) {
        cout << "AT of P[" << i + 1 << "]: ";
        cin >> at[i];
    }

    // Input Burst Time
    cout << "\nEnter Burst Time of all processes:\n";
    for (int i = 0; i < n; i++) {
        cout << "BT of P[" << i + 1 << "]: ";
        cin >> bt[i];
    }

    // First Process Calculation
    start[0] = at[0];                
    ct[0] = start[0] + bt[0];       

  
    for (int i = 1; i < n; i++) {
        if (at[i] > ct[i - 1])        // CPU idle
            start[i] = at[i];
        else
            start[i] = ct[i - 1];
        ct[i] = start[i] + bt[i];
    }

    
    float totalWT = 0, totalTAT = 0, totalRT = 0;

    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];       // Turn Around Time
        wt[i]  = tat[i] - bt[i];      // Waiting Time
        rt[i]  = start[i] - at[i];    // Response Time

        totalWT  += wt[i];
        totalTAT += tat[i];
        totalRT  += rt[i];
    }

    // Print Table 
    cout << "\n\n---------------------------------------------\n";
    cout << left << setw(6) << "PNO" 
         << setw(6) << "AT" 
         << setw(6) << "BT" 
         << setw(6) << "ST" 
         << setw(6) << "CT" 
         << setw(6) << "TAT" 
         << setw(6) << "WT" 
         << setw(6) << "RT" << endl;
    cout << "---------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << left << setw(6) << ("P" + to_string(i + 1))
             << setw(6) << at[i]
             << setw(6) << bt[i]
             << setw(6) << start[i]
             << setw(6) << ct[i]
             << setw(6) << tat[i]
             << setw(6) << wt[i]
             << setw(6) << rt[i] << endl;
    }
    cout << "---------------------------------------------\n";

    // Print averages
    cout << fixed;
    cout.precision(2);
    cout << endl << "Average Waiting Time     = " << (totalWT / n) << endl;
    cout << "Average Turnaround Time  = " << (totalTAT / n) << endl;
    cout << "Average Response Time    = " << (totalRT / n) << endl;

    return 0;
}

// <<<<Input>>>>
// Enter the number of processes: 4

// Enter Arrival Time of all processes:
// AT of P[1]: 0
// AT of P[2]: 1
// AT of P[3]: 5
// AT of P[4]: 6

// Enter Burst Time of all processes:
// BT of P[1]: 2
// BT of P[2]: 2
// BT of P[3]: 3
// BT of P[4]: 4


// <<<<Output>>>>
// ---------------------------------------------
// PNO   AT    BT    ST    CT    TAT   WT    RT    
// ---------------------------------------------
// P1    0     2     0     2     2     0     0     
// P2    1     2     2     4     3     1     1     
// P3    5     3     5     8     3     0     0     
// P4    6     4     8     12    6     2     2     
// ---------------------------------------------

// Average Waiting Time     = 0.75
// Average Turnaround Time  = 3.50
// Average Response Time    = 0.75