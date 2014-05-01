#include<stdio.h>
#include<string.h>
#define r 19
#define c 19
int traverse(int ur,int uc,int r1,int c1,int r2,int c2,char ch,char ar[][c]);
int find(int x,int y,char ch);
char ar1[r][c];
char ar2[r][c];
char myColor[5],opponentColor[5];        // myColor stores your player's color and opponentColor stores your player's opponent color
char board[19][19];                     //input Board, board[i][j]= 'X' or 'R' or 'B'
void setColor(char *color)                      //to set your player's color
{
    strcpy(myColor,color);
    if(!strcmp(color,"Red"))
        strcpy(opponentColor,"Blue");
    else
        strcpy(opponentColor,"Red");

}

void inputBoard()
{
    int i;
    for(i=0;i<19;i++)
        scanf("%s",board[i]);
}

//prints board
void printBoard()
{
    int i;
    printf("\n");
    for(i=0;i<19;i++)
        printf("%2d : %s\n",i+1,board[i]);
    printf("\n");
}

// This is the function which you have to implement. You have to write your strategy in this function.
// outputRow and outputCol holds your final answer and outputs them to screen.

void strategy(char *outputRow,char *outputCol)
{
    //your final answer will be store in outputRow and outputCol
     // example : *outputRow='A'; *outputCol='S';
     int i,j,wr=0,wc=0,lr=0,lc=0,flagw=0,flagl=0,flag;
     for(i=0;i<19;i++)
                      for(j=0;j<19;j++)
                      {
                                       if(ar1[i][j]=='X')
                                       {
                                                 if(find(i,j,myColor[0]))
                                                 {
                                                                      wr=i;
                                                                      wc=j;
                                                                      flagw=1;
                                                 }
                                                 if(find(i,j,opponentColor[0]))
                                                 {
                                                                      lr=i;
                                                                      lc=j;
                                                                      flagl=1;
                                                 }
                                       }
                      }
     if(flagw&&flagl)
     {
                     i=lr;
                     j=lc;
     }
     else if(flagl)
     {
          i=lr;
          j=lc;
     }
     else if(flagw)
     {
          i=wr;
          j=wc;
     }
     else
     {
     	 flag=1;
         for(i=0;i<19&&flag;i++)
         {
         	for(j=0;j<19&&flag;j++)
         		if(ar1[i][j]=='X')
         		 	flag=0;
         }
         i--;
         j--;
     }
     *outputRow=65+i;
     *outputCol=65+j;                                         
}
void ini(char ar2[r][c])
{
	int i,j;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			ar2[i][j]=' ';
}
int find(int x,int y,char ch)
{
     int i,j,i1,j1,flag=0;
     char ar3[r][c];
     for(i=-1;i<2;i++)
                      for(j=-1;j<2;j++)
                      {
                                       if(ar1[x+i][y+j]==ch&&x+i>=0&&x+i<r&&y+j>=0&&y+j<c)
                                           ar3[i+1][j+1]='1';
                                       else
                                           ar3[i+1][j+1]='0';//it j=1 earlier instead of j+1due to silly typing mistake
                      }
     for(i=-1;i<2&&!flag;i++)
                     for(j=-1;j<2&&!flag;j++)
                                     if(ar3[i+1][j+1]=='1'&&i!=0&&j!=0)
                                                   for(i1=-1;i1<2&&!flag;i1++)
                                                                      for(j1=-1;j1<2&&!flag;j1++)
                                                                                                if(ar3[i1+1][j1+1]=='1'&&i1!=0&&j1!=0)
                                                                                                {
                                            														ini(ar2);
                                                                                                    if(!traverse(3,3,i+1,j+1,i1+1,j+1,'1',ar3))
                                                                                                    {
																		ini(ar2);   
                                                                                               flag=traverse(r,c,x+i,y+j,x+i1,y+j1,ch,ar1);
                                                                                                    }
                                                                                                }
     return flag;
}
     
                                     
     
int traverse(int ur,int uc,int r1,int c1,int r2,int c2,char ch,char ar[r][c])
{
     int flag=0;
     ar2[r1][c1]='X';
     if(r1!=r2||c1!=c2)
     {
				if(!flag&&r1-1>=0&&ar[r1-1][c1]==ch&&ar2[r1-1][c1]!='X')
					flag=traverse(ur,uc,r1-1,c1,r2,c2,ch,ar);
				if(!flag&&c1-1>=0&&ar[r1][c1-1]==ch&&ar2[r1][c1-1]!='X')
					flag=traverse(ur,uc,r1,c1-1,r2,c2,ch,ar);
				if(!flag&&r1+1<ur&&ar[r1+1][c1]==ch&&ar2[r1+1][c1]!='X')
					flag=traverse(ur,uc,r1+1,c1,r2,c2,ch,ar);
				if(!flag&&c1+1<uc&&ar[r1][c1+1]==ch&&ar2[r1][c1+1]!='X')
					flag=traverse(ur,uc,r1,c1+1,r2,c2,ch,ar);
				if(!flag&&r1-1>=0&&c1-1>=0&&ar[r1-1][c1-1]==ch&&ar2[r1-1][c1-1]!='X')
					flag=traverse(ur,uc,r1-1,c1-1,r2,c2,ch,ar);
				if(!flag&&r1-1>=0&&c1+1<uc&&ar[r1-1][c1+1]==ch&&ar2[r1-1][c1+1]!='X')
					flag=traverse(ur,uc,r1-1,c1+1,r2,c2,ch,ar);
				if(!flag&&r1+1<ur&&c1-1>=0&&ar[r1+1][c1-1]==ch&&ar2[r1+1][c1-1]!='X')
					flag=traverse(ur,uc,r1+1,c1-1,r2,c2,ch,ar);
				if(!flag&&r1+1<ur&&c1+1<uc&&ar[r1+1][c1+1]==ch&&ar2[r1+1][c1+1]!='X')
					flag=traverse(ur,uc,r1+1,c1+1,r2,c2,ch,ar);
     }
     else if(r1==r2&&c1==c2)
	 flag=1;
	 if(!flag)
	 	ar2[r1][c1]=' ';
     return flag;
}

int main()
{
    int i ,j;
    char color[5];
    scanf("%s",color);

    setColor(color);

    inputBoard();   
    for(i=0;i<19;i++)
                     for(j=0;j<19;j++)
                                      ar1[i][j]=board[i][j];                   //read board from input console

    char outputRow,outputCol;
    strategy(&outputRow,&outputCol);  // calling your strategy function

    printf("%c%c",outputRow,outputCol);     // your output
    return 0;
    
}
