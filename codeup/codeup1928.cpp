// 日期差值 
#include <cstdio>
struct date
{
	int y;
	int m;
	int d;
};

int days[2][13] = {
	{0,31,28,31,30,31,30,31,31,30,31,30,31}, //平年
	{0,31,29,31,30,31,30,31,31,30,31,30,31}//闰年
};

bool isLeap(int year)
{
	return year%400==0 || (year%4==0 && year%100!=0);
}

int main()
{
	date m, n;
	while(scanf("%4d%2d%2d",&m.y,&m.m,&m.d)!=-1)
	{
		scanf("%4d%2d%2d",&n.y,&n.m,&n.d);
		//保证m<n
		if (m.y>n.y || (m.y==n.y && m.m>n.m) || (m.y==n.y && m.m==n.m && m.d>n.d))
		{
			date temp = m;
			m = n;
			n = temp;
		}
		
		int res = 1;
		// 直接加一年的量，加速 
		if(m.y != n.y)
		{
			while(m.y != n.y-1)
			{
				if(m.m>2)
				{
					m.y++;
					res+=isLeap(m.y)?366:365;
				}
				else
				{
					if(isLeap(m.y))
					{
						res+=366;
						if(m.m==2 && m.d==29)
							m.d=28;
					}
					else
					{
						res+=365;
					}
					m.y++;
				}
			}
		}
		// 两年以内，一天一天加 
		while(m.y!=n.y || m.m!=n.m || m.d!=n.d)
		{
			res++;
			m.d++;
			if(m.d == days[isLeap(m.y)][m.m] + 1)
			{
				m.d = 1;
				m.m++;
			}
			if(m.m == 13)
			{
				m.m = 1;
				m.y++;
			}
		}
		printf("%d\n", res); 
	}
}
