#include <cstdio>
#include <algorithm>
#include <cstring>
using std::sort;

struct student
{
	char reg_num[14];
	int loc_num;
	int loc_rank;
	int score; 
};

student arr[30000];

bool cmp(const student& a, const student& b)
{
	if(a.score != b.score)
		return a.score > b.score;
	return  strcmp(a.reg_num, b.reg_num)<0;
}

int main()
{
	int n, k, cnt=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		for(int j=0;j<k;j++)
		{
			scanf("%s %d", arr[cnt].reg_num, &arr[cnt].score);
			arr[cnt].loc_num = i;
			cnt++;
		}
		sort(arr+cnt-k, arr+cnt, cmp);
		int r=1;
		for(int j=0;j<k;j++)
		{
			if(j!=0 && arr[j+cnt-k].score!=arr[j+cnt-k-1].score)
				r = j+1;
			arr[j+cnt-k].loc_rank = r;
		}
	}
	sort(arr, arr+cnt, cmp);
	printf("%d\n", cnt);
	int r=1; 
	for(int i=0;i<cnt;i++)
	{
		if(i!=0 && arr[i].score!=arr[i-1].score)
			r = i+1;
		printf("%s %d %d %d\n", arr[i].reg_num, r, arr[i].loc_num, arr[i].loc_rank);
	}
	return 0;
}
