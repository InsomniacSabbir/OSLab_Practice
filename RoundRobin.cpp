#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

typedef struct process
{
    int serial;
    int first_arrival;
    int arrival;
    int finish;
    int burst;
    int waiting;
    int execution_start;
    int turn_around;
}process;

int main()
{
    printf("How many process: ");
    int pro;
    scanf("%d",&pro);
    process ob[pro];
    int i;
    int quantum;
    printf("Set the time quantum: ");
    scanf("%d",&quantum);
    printf("Give the process description: \n");
    int maximum=0;
    int minimum=9999999;
    for(i=0;i<pro;i++)
    {
        ob[i].serial=i;
        printf("Give the arrival time of process %d: ",i);
        scanf("%d",&ob[i].arrival);
        ob[i].first_arrival=ob[i].arrival;
        printf("Give the burst time of process %d: ",i);
        scanf("%d",&ob[i].burst);
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
        ob[i].waiting=0;
        V[ob[i].arrival].push_back(ob[i]);
    }
    queue<process>ready_queue;

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
    int time=0;
    while(!ready_queue.empty())
    {
        process temp = ready_queue.front();
        ready_queue.pop();
        temp.execution_start=time;
        ob[temp.serial].execution_start=time;
        for(j=1;j<=temp.burst;j++)
        {
            time++;
            printf("Processing process %d\ttime %d\n",temp.serial,time);
            if(j==quantum && j!=temp.burst)
            {
                ob[temp.serial].burst-=quantum;
                ob[temp.serial].waiting+=(ob[temp.serial].execution_start - ob[temp.serial].arrival);
                ob[temp.serial].arrival=time;
                j+=temp.burst;
            }
            else if(j==quantum && j==temp.burst)
            {
                ob[temp.serial].burst=0;
                ob[temp.serial].waiting+=(ob[temp.serial].execution_start - ob[temp.serial].arrival);
                ob[temp.serial].arrival=time;
                j+=temp.burst+5;
                ob[temp.serial].finish=time;
            }
            else if(j!=quantum && j==temp.burst)
            {
                ob[temp.serial].waiting=(ob[temp.serial].execution_start - ob[temp.serial].arrival);
                ob[temp.serial].burst=0;
                ob[temp.serial].finish=time;
                ob[temp.serial].arrival=time;
                j+=temp.burst+5;
            }
        }
        for(i=i+1;i<=time;i++)
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

        if(ob[temp.serial].burst!=0)
        {
                ready_queue.push(ob[temp.serial]);

        }
    }
    maximum_time=time;
    double total_turn_around=0;
    double total_waiting=0;
    double pro_double = pro;
    double total_time = maximum_time;
    for(i=0;i<pro;i++)
    {
        //cout<<"waiting time for process "<<i<<" is "<<ob[i].waiting<<endl;
        ob[i].turn_around = ob[i].finish - ob[i].first_arrival;
        total_turn_around += ob[i].turn_around;
        total_waiting += ob[i].waiting;
    }

    printf("Average turn around time: %lf\n",total_turn_around / pro_double);
    printf("Average waiting time: %lf\n",total_waiting / pro_double);
    printf("Throughput: %lf\n",pro_double / total_time);
    return 0;
}


