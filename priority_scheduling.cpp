#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

typedef struct process
{
    int serial;
    int arrival;
    int finish;
    int burst;
    int priority;
    int waiting;
    int execution_start;
    int turn_around;
    bool operator < (const process& p) const {
        return priority>p.priority;
    }
}process;

int main()
{
    printf("How many process: ");
    int pro;
    scanf("%d",&pro);
    process ob[pro];

    int i;
    printf("Give the process description: \n");
    int maximum=0;
    int minimum=9999999;
    for(i=0;i<pro;i++)
    {
        ob[i].serial=i;
        printf("Give the arrival time of process %d: ",i);
        scanf("%d",&ob[i].arrival);

        printf("Give the burst time of process %d: ",i);
        scanf("%d",&ob[i].burst);

        printf("Give the priority of process %d: ",i);
        scanf("%d",&ob[i].priority);

        if(ob[i].arrival>maximum)
        {
            maximum=ob[i].arrival;
        }
        if(ob[i].arrival<minimum)
        {
            minimum=ob[i].arrival;
        }
    }

    vector<process>V[maximum+1];
    for(i=0;i<=maximum;i++)
    {
        V[i].clear();
    }

    for(i=0;i<pro;i++)
    {
        V[ob[i].arrival].push_back(ob[i]);
    }

    priority_queue<process>ready_queue;

    /*for(i=0;i<pro;i++)
    {
        ready_queue.push(ob[i]);
    }

    for(i=0;i<V[minimum].size();i++)
    {
        process temp = V[minimum][i];
        //ready_queue.pop();
        cout<<"serial: "<<temp.serial<<" burst time: "<<temp.burst<<endl;
    }*/

    for(i=0;i<V[minimum].size();i++)
    {
        ready_queue.push(V[minimum][i]);
    }

    int j,k;
    i=minimum;
    int maximum_time;
    while(!ready_queue.empty())
    {
        process temp = ready_queue.top();
        ready_queue.pop();
        temp.execution_start=i;
        ob[temp.serial].execution_start=i;
        for(j=1;j<=temp.burst;j++)
        {
            printf("Processing process %d\ttime %d\n",temp.serial,i+j-1);
        }

        if(i!=minimum)
        {
            i--;
        }

        for(i=i+1;i<(temp.execution_start+temp.burst);i++)
        {
            if(i<=maximum)
            {
                for(k=0;k<V[i].size();k++)
                {
                    //cout<<"serial: "<<V[i][k].serial<<" arrival time: "<<V[i][k].arrival<<endl;
                    ready_queue.push(V[i][k]);
                }
            }
        }
    }
    maximum_time=i;
    double total_turn_around=0;
    double total_waiting=0;
    double pro_double = pro;
    double total_time = maximum_time;
    for(i=0;i<pro;i++)
    {
        ob[i].waiting = ob[i].execution_start - ob[i].arrival;
        ob[i].finish = ob[i].execution_start + ob[i].burst;
        ob[i].turn_around = ob[i].finish - ob[i].arrival;
        total_turn_around += ob[i].turn_around;
        total_waiting += ob[i].waiting;
    }

    printf("Average turn around time: %lf\n",total_turn_around / pro_double);
    printf("Average waiting time: %lf\n",total_waiting / pro_double);
    printf("Throughput: %lf\n",pro_double / total_time);
    return 0;
}

