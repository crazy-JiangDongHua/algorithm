#include <cstdio>
#include <algorithm>
using std::sort;

struct node{
	int key;
	int next;
	int id;
	int isvalid=1;
}list[100010];

class comp{
public:
	bool operator()(const node& a, const node& b)const
	{
		if(a.isvalid < b.isvalid)
			return true;
		else if(a.isvalid > b.isvalid)
			return false;
		else
		{
			return a.key<b.key;
		}
	}
};

int main()
{
	int head, n;
	scanf("%d %d", &n, &head);
	while(n--)
	{
		int id, next, key;
		scanf("%d %d %d", &id, &key, &next);
		list[id].id = id;
		list[id].key = key;
		list[id].next = next;
	}
	int cnt = 0;
	// 遍历链表 因为有些读取的节点不再链表上
	while(head != -1)
	{
		list[head].isvalid = 0;
		head = list[head].next;
		cnt++;
	} 
	sort(list, list+100010, comp());
	if(cnt==0)
		printf("0 -1\n");
	else
	{
		printf("%d %05d\n",cnt, list[0].id);
		for(int i=0;i<cnt;i++)
		{
			printf("%05d %d ", list[i].id, list[i].key);
			if(i!=cnt-1)
				printf("%05d\n",list[i+1].id);
			else
				printf("-1\n");
		}
	}
	return 0;
}
