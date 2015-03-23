#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
    int req,hole,i;
    vector<int>Vhole[2],Vreq;
    Vhole[0].clear();
    Vhole[1].clear();
    Vreq.clear();
    printf("How many requests: ");
    scanf("%d",&req);
    printf("How many holes: ");
    scanf("%d",&hole);
    printf("Give the hole description: ");
    for(i=0;i<hole;i++)
    {
        int temp;
        printf("Give the size of hole no. %d\n",i+1);
        scanf("%d",&temp);
        Vhole[0].push_back(i+1);
        Vhole[1].push_back(temp);
    }

    printf("Give the request description: ");
    for(i=0;i<req;i++)
    {
        int temp;
        printf("Give the size of request no. %d\n",i+1);
        scanf("%d",&temp);
        Vreq.push_back(temp);
    }

    int ok;
    int j;

    for(i=0;i<Vhole[1].size()-1;i++)
    {
        for(j=i+1;j<Vhole[1].size();j++)
        {
            if(Vhole[1][i]<Vhole[1][j])
            {
                int temp=Vhole[1][i];
                Vhole[1][i]=Vhole[1][j];
                Vhole[1][j]=temp;

                temp=Vhole[0][i];
                Vhole[0][i]=Vhole[0][j];
                Vhole[0][j]=temp;
            }
        }
    }
    int k,l;
    for(i=0;i<Vreq.size();i++)
    {
        ok=0;
        for(j=0;j<Vhole[0].size();j++)
        {
            if(Vreq[i]<=Vhole[1][j])
            {
                printf("Req number %d is allocated in hole number %d\n",i+1,Vhole[0][j]);
                Vhole[1][j]-=Vreq[i];
                ok=1;
                j+=Vhole[0].size();

                for(k=0;k<Vhole[1].size()-1;k++)
                {
                    for(l=k+1;l<Vhole[1].size();l++)
                    {
                        if(Vhole[1][k]<Vhole[1][l])
                        {
                            int temp=Vhole[1][k];
                            Vhole[1][k]=Vhole[1][l];
                            Vhole[1][l]=temp;

                            temp=Vhole[0][k];
                            Vhole[0][k]=Vhole[0][l];
                            Vhole[0][l]=temp;
                        }
                    }
                }
            }
        }
        if(!ok)
        {
            printf("Couldn't allocate request number %d\n",i+1);
        }
    }
    return 0;
}


