#include<stdio.h>
#include<stdlib.h>

int q[100], size = 100, front = -1, rear = -1;

void enque(int value)
{
	if(rear == size-1)
	{
		printf("Queue Overflow\n");
	}
	else if(front == -1)
	{
		front = rear = 0;
		q[rear] = value;
	}
	else
	{
		rear++;
		q[rear] = value;
	}
}

int deque()
{
	int value;

	if(front == -1)
	{
		printf("Queue Underflow\n");
	}
	else if(front == rear)
	{
		value = q[front];
		front = rear = -1;
	}
	else
	{
		value = q[front];
		front++;
	}

	return value;
}

int isEmpty()
{
	if(front == -1)
		return 1;
	else
		return 0;
}


void dfsTraversal(int **edges, int n, int sv, int *visited)
{
	printf("%d\t", sv);

	*(visited + sv) = 1;

	for(int i = 0; i < n; ++i)
	{
		if(i == sv)
		{
			continue;
		}

		if(*(*(edges + sv) + i) == 1)
		{
			if(*(visited + i))
			{
				continue;
			}

			dfsTraversal(edges, n, i, visited);
		}
	}
}

void bfsTraversal(int **edges, int n, int sv)
{
	int *visited, vertex;

	visited = (int *) malloc(n * sizeof(int));
	for(int i = 0; i < n; ++i)
	{
		*(visited + 1) = 0;
	}

	enque(sv);

	while(!isEmpty())
	{
		vertex = deque();

		if(!(*(visited + vertex)))
		{
			printf("%d\t", vertex);
			*(visited + vertex) = 1;

			for(int i = 0; i < n; i++)
			{
				if(*(*(edges + vertex) + i) && !(*(visited + i)))
				{
					enque(i);
				}
			}
		}
	}

	free(visited);

}

void main()
{
	int n, e, **edges, f, s, *visited, a = 1, choice;

	printf("Enter the number of vertices :");
	scanf(" %d", &n);

	printf("Enter the number of edges : ");
	scanf("%d", &e);

	edges = (int **) malloc(n * sizeof(int*));

	for(int i = 0; i < n; ++i)
	{
		*(edges + i) = (int *) malloc(n * sizeof(int));
		for(int j = 0; j < n; ++j)
		{
			*(*(edges + i) + j) = 0;
		}
	}

	printf("Enter the edges : \n");

	for(int i = 0; i < e; ++i)
	{
		scanf("%d %d", &f, &s);

		*(*(edges+f)+s) = 1;
		*(*(edges+s)+f) = 1;
	}

	visited = (int *) malloc(n * sizeof(int));

	while(a)
	{

		printf("\n1.BFS\n2.DFS\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);

		for(int i = 0; i < n; ++i)
		{
			*(visited + i) = 0;
		}

		switch(choice)
		{
			case 1 : if(n == 0)
						printf("Graph is empty!!\n");
					 else
					 {
					 	printf("BFS Traversal :\n");

						bfsTraversal(edges, n, 0);
						printf("\n");
					 }

					 break;

			case 2 : if(n == 0)
						printf("Graph is empty!!\n");
					 else
					 {
						printf("DFS Traversal is :\n");
						dfsTraversal(edges, n, 0, visited);
					 }

					 break;

			case 3 : a = 0;
					 break;

			default : printf("Invalid Entry!!\n");
		}
		
	}

	

	for(int i = 0; i < n; i++)
	{
		free(*(edges + i));
	}

	free(edges);	 	 
}
