#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)


void maxV(int W, int wt[], int val[], int n);
void minW(int W, int wt[], int val[], int n);
void maxW(int W, int wt[], int val[], int n);
void maxR(int W, int wt[], int val[], int n);

int main(int argc, char *argv[])
{
	char line1[128]; int A[100];
	int tempW=0; int bestV=0, bestW=0;
	int tempV=0;
	char line2[128];
	char line3[128];
	char line4[128]; 
	char *pt;
	int max1;
	int i=0;
	int tot_wt;
	int a;
	int v[10];	
	int w[10];	
	char const* const fileName = argv[1]; 
	FILE* f = fopen(fileName, "r"); 
	if (!f) 
	{
		printf("ERROR");
	} 
	else 
	{
		fscanf(f, "%127[^\n]\n%127[^\n]\n%127[^\n]\n%127[^\n] ", line1, line2,line3, line4);
		
		max1=atoi(line1);		
		printf("NUMBER OF OBJECTS:%d\n",max1);	//line1

		
		do 
		{
			pt = strtok (line2,",");
			while (pt != NULL) 
			{
				w[i] = atoi(pt);		
				//printf("%d\n", w[i]);
				i++;
				pt = strtok (NULL, ",");
			}
		}while(i<max1);
	
		
		i=0;
		
		do 
		{
			pt = strtok (line3,",");
			while (pt != NULL) 
			{
				v[i] = atoi(pt);		
				i++;
				pt = strtok (NULL, ",");
			}
		}while(i<max1);
	
		printf("WEIGHT:");
		for(i=0;i<max1;i++)
		printf("%d\n", w[i]);

		printf("PROFIT:");
		for(i=0;i<max1;i++)
		printf("%d\n", v[i]);
		
		tot_wt=atoi(line4);
		printf("CAPACITY:%d",tot_wt);
		

		
		maxV(tot_wt, w, v,max1);
		maxW(tot_wt, w, v,max1);
		minW(tot_wt, w, v,max1);		
		maxR(tot_wt, w, v,max1);



		fclose(f);
	}
	return 0;
}
	


void maxV(int W, int wt[], int val[], int n)
{
	printf("\n----------------------------------------");
	printf("\nmaximum profit first\n");

	int i, w, g=0; int a; int j;
	int Wt1[n+1][W+1]; int x,y; int value[n]; int max_prof=0;


	for (i = 0; i <= n; i++)
	{	
		
		for (w = 0; w <= W; w++)
		{
			if (i==0 || w==0)
			{			
				Wt1[i][w] = 0; value[i]=0;
			}			
			else if (wt[i-1] <= w)
			{		

				for (x = 0; x < n; ++x)
				{
					for (y = x + 1; y < n; ++y)
					{
						if (val[x] < val[y])
						{
							a = val[x];
							val[x] = val[y];
							val[y] = a;
						}
					}
				}


				
				if((val[i-1] +Wt1[i-1][w-wt[i-1]])>(Wt1[i-1][w]))
				{
					
					value[i]=max(val[i],val[i-1]);
					Wt1[i][w] =val[i-1] +Wt1[i-1][w-wt[i-1]];
				}
				}
				else
				{ 
					Wt1[i][w] = Wt1[i-1][w]; value[i]=val[i];
				
				} 

			
		}
	}
	
	
	printf("VALUES\t WEIGHTS\n");
	for (g = 0; g<count; g++) 
	{
	if(v1[g]!=0)
	{
	printf("\n%d\t%d\n", v1[g],w1[g]); 
	//printf("%d\n", w1[g]); 

	max_prof=max_prof+v1[g];
	}
	}
	printf("\nMAXIMUM PROFIT ACHIEVED:%d\n", max_prof);


}
//-------------------------------------------------------------------------------------------------------------------------------------------




void maxW(int W, int wt[], int val[], int n)
{
	
	printf("\n----------------------------------------\n");
	printf("maximum weight first\n");

	int w1[n],v1[n];


	int i, w, g=0; int a; int j;
	 int x,y; int value[n]; int max_prof=0;


	int tempsum=0; int count=0;
i=0;j=0;
	do
	{
	 count++;
		
	w1[j]=max(wt[i],wt[i+1]);
	if(w1[j]==(wt[i])) v1[j]=val[i]; else v1[j]=val[i+1];
	tempsum=tempsum+w1[j];i++; j++; 
	
}while(tempsum<W);


	g=0;  max_prof=0;
	printf("VALUES\t WEIGHTS\n");
	for (g = 0; g<count; g++) 
	{
	if(v1[g]!=0)
	{
	printf("\n%d\t%d\n", v1[g],w1[g]); 
}
}
	printf("\nMAXIMUM PROFIT ACHIEVED:%d\n", max_prof);


}

//--------------------------------------------------------------------------------------------------------------------------


void minW(int W, int wt[], int val[], int n)
{


	printf("\n----------------------------------------\n");
	printf("minimum weight first\n");
	int w1[n],v1[n];
	int i, w, g=0; int a; int j;
	int x,y; int value[n]; int max_prof=0;

	//printf("VALUES USED:\n");
	int tempsum=0; int count=0; int tempdif=1;
	i=0;j=0; //printf("fffffffffffffffffffffffffffffffffff");
	//while(tempdif>=0)
	
	do
	{
	 
	w1[j]=min(wt[i],wt[i-1]);
	if(w1[j]==(wt[i])) v1[j]=val[i]; else v1[j]=val[i-1];
	tempsum=tempsum+w1[j];
	
	tempdif=W-tempsum-wt[i+1];
	i++; j++; count++;
	
	
}while(tempdif>=0);
	
	




	g=0;  max_prof=0;
	printf("VALUES\t WEIGHTS\n");
	for (g = 0; g<count; g++) 
	{
	if(v1[g]!=0)
	{
	printf("\n%d\t%d\n", v1[g],w1[g]); 
	}
	}
	printf("\nMAXIMUM PROFIT ACHIEVED:%d\n", max_prof);
	









}
void maxR(int W, int wt[], int val[], int n)


{


	printf("\n----------------------------------------\n");
	printf("maximum profit per unit first\n");
	int w1[n],v1[n]; int rate[n];
	int i, w, g=0; int a; int j;
	int x,y; int value[n]; int max_prof=0;
	for(i=0;i<n;i++)
	{
		rate[i]=val[i]/wt[i];
	}
	int rate1[n];
	//printf("VALUES USED:\n");
	int tempsum=0; int count=0; int tempdif=1; 
	i=0;j=0; //printf("fffffffffffffffffffffffffffffffffff");
	//while(tempdif>=0)
	
	for(i=0;i<n;i++)
	{
		rate1[j]=max(rate[i-1],rate[i]); if (rate1[j]==rate[i-1]) 
		{
			tempsum=tempsum+wt[i-1]; v1[j]=wt[i]-1;
		}
		else
		{
		 tempsum=tempsum+wt[i]; v1[j]=wt[i];
		}
		j++; 
		if(W-tempsum>0) count++;

	}

g=0;  max_prof=0;
	printf("VALUES\t WEIGHTS\n");
	for (g = 0; g<count; g++) 
	{
	if(v1[g]!=0)
	{
	printf("\n%d\t%d\n", v1[g],w1[g]); 
	//printf("%d\n", w1[g]); 

	max_prof=max_prof+v1[g];
	}
	}
	printf("\nMAXIMUM PROFIT ACHIEVED:%d\n", max_prof);



}


