#include<stdio.h>

#define MAXCOST 0x7fff
#define MAXVALUE 100

int graph[MAXVALUE][MAXVALUE];
int lowcost[MAXVALUE];

void Prime(int graph[][MAXVALUE], int n)
{
	int sum = 0;
	int i, j, min, minid, mst[MAXVALUE];
	for (i = 2; i <= n; i++)
	{
		lowcost[i] = graph[1][i];
		mst[i] = 1;
	}
	mst[1] = 0;
	for (i = 2; i <= n; i++)
	{
		min = MAXCOST;
		minid = 0;
		for (j = 2; j <= n; j++)
		{
			if (lowcost[j] < min && lowcost[j] != 0)
			{
				min = lowcost[j];
				minid = j;
			}
		}
		lowcost[minid] = 0;
		printf("V%d->V%d: %d\n", mst[minid], minid, min);
		sum += min;
		for (j = 2; j <= n; j++)
		{
			if (graph[minid][j] < lowcost[j])
			{
				lowcost[j] = graph[minid][j];
				mst[j] = minid;
			}
		}
	}
	printf("minimum path = %d\n", sum);
}

int main()
{
	int i, j;
	int vertex, edge;
	int x, y, cost;
	printf("enter number of vertex and edge:\n");
	scanf_s("%d %d", &vertex, &edge);
	for (i = 1; i <= vertex; i++)
		for (j = 1; j <= vertex; j++)
			graph[i][j] = MAXCOST; 

	printf("enter graph info:\n");
	for (i = 1; i <= edge; i++)
	{
		scanf_s("%d %d %d", &x, &y, &cost);
		graph[x][y] = cost;
		graph[y][x] = cost;
	}

	Prime(graph, vertex);
	return 0;
}