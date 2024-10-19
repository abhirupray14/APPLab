#include<stdio.h>
#include<stdlib.h>
struct DisjointSet{
	int n;
	int *par;
	int *size;
	//int *rank;
};
struct DisjointSet* createDisjointSet(int n)
{
	struct DisjointSet *ds = (struct DisjointSet*)malloc(sizeof(struct DisjointSet));
	ds->n = n;
	ds->par = (int*)malloc((n+1)*sizeof(int));
	ds->size = (int*)malloc((n+1)*sizeof(int));
	for(int i=0;i<=n;i++)
	{
		ds->par[i] = i;
		ds->size[i] = 1;
	}
	return ds;
}
int findPar(struct DisjointSet *ds, int u)
{
	if(u == ds->par[u])
		return u;
	else
		return ds->par[u] = findPar(ds,ds->par[u]);
}
void unionBySize(struct DisjointSet *ds,int u,int v)
{
	int u_par = findPar(ds,u);
	int v_par = findPar(ds,v);
	if(u_par == v_par) return;
	else if(ds->size[u_par] >= ds->size[v_par])
	{
		ds->size[u_par] += ds->size[v_par];
		ds->par[v_par] = u_par;
	}
	else
	{
		ds->size[v_par] += ds->size[u_par];
		ds->par[u_par] = v_par;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int nodes;
		scanf("%d",&nodes);
		int arr[nodes][nodes];
		for(int i=0;i<nodes;i++)
		{
			for(int j=0;j<nodes;j++)
			{
				scanf("%d",&arr[i][j]);
			}
		}
		struct DisjointSet *ds = createDisjointSet(nodes);
		for(int i=0;i<nodes;i++)
		{
			int u = i+1;
			for(int j=0;j<nodes;j++)
			{
				if(arr[i][j] == 1)
				{
					unionBySize(ds,u,j+1);
				}
			}
		}

		int arr1[nodes+1];
		for(int i=0;i<=nodes;i++)
			arr1[i] = 0;
		int count = 0;
		for(int i=1;i<=nodes;i++)
		{
			int x = ds->par[i];
			if(arr1[x] != 1)
			{
				count += 1;
				arr1[x] = 1;
			}
		}
		printf("%d\n",count);
		for(int i=1;i<=nodes;i++)
		{
			if(arr1[i] == 1)
				printf("%d ",i);
		}
		printf("\n");
	}
	return 0;
}
