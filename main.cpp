#include <iostream>

int arVisit[50][50]{};
int arMap[50][50];

int nDirectX[4]={0,1,0,-1};
int nDirectY[4]={-1,0,1,0};

int nDirection{};
void turnLeft()
{
    nDirection=(nDirection+3)%4;
}

int main()
{
    int nHeight{};
    int nWidth{};
    int nStartX{};
    int nStartY{};
    scanf("%d %d",&nHeight, &nWidth);
    scanf("%d %d %d", &nStartX,&nStartY,&nDirection);

    arMap[nStartX][nStartY]=1;
    for(int i=0;i<nHeight;i++)
    {
        for(int j=0;j<nWidth;j++)
        {
            scanf("%d",&arMap[i][j]);
        }
    }

    int nCount{};
    int nTurnCount{};
    while(1)
    {
        turnLeft();
        int nX = nStartX + nDirectX[nDirection];
        int nY = nStartY + nDirectY[nDirection];
        if(arVisit[nX][nY]==0 && arMap[nX][nY]==0)
        {
            arVisit[nX][nY]=1;
            nStartX=nX;
            nStartY=nY;
            nCount++;
            nTurnCount=0;
        }
        // 회전한 이후 정면에 가보지 않은 칸이 없거나 바다인 경우
        else
        {
            nTurnCount++;
        }
        // 네 방향 모두 갈 수 없는 경우
        if(nTurnCount==4)
        {
            nX = nStartX - nDirectX[nDirection];
            nY = nStartY - nDirectY[nDirection];
            // 뒤로 갈 수 있다면 이동하기
            if (arMap[nX][nY] == 0)
            {
                nStartX = nX;
                nStartY = nY;
            }
            // 뒤가 바다로 막혀있는 경우
            else break;
            nTurnCount = 0;
        }
    }
    printf("%d\n",nCount);
}
