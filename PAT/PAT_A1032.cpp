#include <cstdio>

struct node
{
	char data;
	int next;
}list[100010];

int main()
{
	int head1, head2, n;
	scanf("%d %d %d", &head1, &head2, &n);
	while(n--)
	{
		int id, next;
		char c;
		scanf("%d %c %d", &id, &c, &next); 
		list[id].data = c;
		list[id].next = next;
	}
	while(head1 != -1)
	{
		list[head1].data = ' ';
		head1 = list[head1].next; 
	}
	while(head2!=-1 && list[head2].data!=' ')
	{
		head2 = list[head2].next;
	}
	if(head2!=-1)
		printf("%05d\n",head2);
	else
		printf("-1\n");
	return 0;
}
