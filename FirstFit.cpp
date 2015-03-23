#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
    int req,hole,i;
    vector<int>Vhole,Vreq;
    Vhole.clear();
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
        Vhole.push_back(temp);
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
    for(i=0;i<Vreq.size();i++)
    {
        ok=0;
        for(j=0;j<Vhole.size();j++)
        {
            if(Vreq[i]<=Vhole[j])
            {
                printf("Req number %d is allocated in hole number %d\n",i+1,j+1);
                Vhole[j]-=Vreq[i];
                ok=1;
                j+=Vhole.size();
            }
        }
        if(!ok)
        {
            printf("Couldn't allocate request number %d\n",i+1);
        }
    }
    return 0;
}
