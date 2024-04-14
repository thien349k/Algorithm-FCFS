#include<bits/stdc++.h>
using namespace std;

class Process
{
    public:
        int arrivalTime, burstTime, waitingTime, turnaroundTime, cpTime;
        int ten;
        Process(){
            arrivalTime = burstTime = waitingTime = turnaroundTime = cpTime = ten = 0;
        }
        ~Process(){}
};

// tinh thoi gian cho cua moi tien trinh va thoi gian tien trinh ket thuc thuc thi
void calculateWating_CPTime(vector<Process> &p){ 
    int n = p.size();
    int currenttime = 0;
    for(int i = 0; i < n; i++){
        if(currenttime < p[i].arrivalTime){
            currenttime = p[i].arrivalTime;
        }
        p[i].waitingTime = currenttime - p[i].arrivalTime;
        currenttime += p[i].burstTime;
        p[i].cpTime = currenttime;
    }
}

// tinh thoi gian quay vong cua moi tien trinh
// thoi gian qua vong la thoi gian tinh tu thoi diem xuat hien den khi tien trinh ket thuc
void calculateTurnarounddTime(vector<Process> &p){
    int n = p.size();
    for(int i = 0; i < n; i++){
        p[i].turnaroundTime = p[i].waitingTime + p[i].burstTime;
    }
}

// tinh trung binh thoi gian cho va thoi gian quay vong
void calculateAverageTime(vector<Process> &p){
    int n = p.size();
    double totalTurnaroundTime = 0, totalWaitingTime = 0;
    for(int i = 0; i < n; i++){
        totalTurnaroundTime += p[i].turnaroundTime;
        totalWaitingTime += p[i].waitingTime;
    }
    double avgTurnaroundTime = totalTurnaroundTime / n;
    double avgWaitingTime = totalWaitingTime / n;
    cout << "Thoi gian cho doi trung binh = " << avgWaitingTime << endl;
    cout << "Thoi gian quay vong trung binh = " << avgTurnaroundTime << endl;
    cout << "_________________________________________\n";
}

bool cmp(Process p1, Process p2){
    return p1.arrivalTime < p2.arrivalTime;
}
void fcfs(){
    cout << "Nhap so tien trinh: " ;
    int n; cin >> n;
    vector<Process> p(n);
    for(int i = 0; i < n; i++){
        cout << '\n';
        cout << "Nhap gia tri arrival " << i + 1 << ": ";
        cin >> p[i].arrivalTime;
        cout << "Nhap gia tri burst " << i + 1 << ": ";
        cin >> p[i].burstTime;
        p[i].ten = i + 1;
    }
    // sap xep theo thu tu den truoc phuc vu truoc
    sort(p.begin(), p.end(), cmp);
    cout << "_________________________________________\n";

    cout << "Thoi gian tien trinh ket thuc thuc thi\n";
    calculateWating_CPTime(p);
    for (int i = 0; i < n; ++i)
        cout << "Tien trinh " << p[i].ten << " = " << p[i].cpTime << '\n';
    cout << "_________________________________________\n";

    calculateTurnarounddTime(p);
    cout << "Thoi gian quay vong va cho doi\n";
    for (int i = 0; i < n; ++i)
        cout << "Tien trinh " << p[i].ten << " = (" << p[i].turnaroundTime << ", " << p[i].waitingTime << ")" << '\n';
    cout << "_________________________________________\n";

    calculateAverageTime(p);

    cout << "Bieu do grantt\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "|     P" << p[i].ten;
    }
cout << "|\n" << p[0].arrivalTime;
    for (int i = 0; i < n; ++i)
    {
        cout << "       " << p[i].cpTime;
    }
    cout << "\n_________________________________________\n";

}
int main()
{
    cout << "_________________________________________\n";
    cout << "LAP LICH CPU BANG FCFS\n";
    cout << "_________________________________________\n";
    fcfs();
    return 0;
}