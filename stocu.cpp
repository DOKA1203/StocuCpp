#include <iostream>

using namespace std;

int n[9][9];

bool canplaceInSq(int y,int x ,int su)
{
    y/=3;
    x/=3;

    y*=3;
    x*=3;

    for(int i=y;i<y+3;i++){
        for(int j=x;j<x+3;j++){
            if(n[i][j]==su)return false;
        }
    }
    return true;
}

bool canplace(int y,int x , int su)
{
    for(int i=0;i<9;i++)
    {
        if(n[y][i] == su)return false;
    }

    for(int i=0;i<9;i++)
    {
        if(n[i][x] == su)return false;
    }
    if(!canplaceInSq(y,x,su))return false;
    return true;
}
bool Dfs(int y,int x)
{
    if(x==9)
    {
        x=0;
        y++;
    }
    if(y==9)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                cout << n[i][j] << " ";
            }cout << endl;
        }
        return true;
    }

    if(n[y][x] == 0)
    {
        for(int i=1;i<=9;i++)
        {
            if(canplace(y,x,i))
            {
                n[y][x] = i;
                if(Dfs(y,x+1)) return true;
                n[y][x] = 0;
            }
        }
    }
    else{
        return Dfs(y,x+1);
    }
    return false;
}
int main()
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin >> n[i][j];
        }
    }
    Dfs(0,0);

    return 0;
}
