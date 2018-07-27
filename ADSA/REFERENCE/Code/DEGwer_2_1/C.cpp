#include<stdio.h>
#include "stdafx.h"
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
int dat[5][5]=
{
	{0,0,0,0,0},
	{0,1,2,3,4},
	{0,2,-1,4,-3},
	{0,3,-4,-1,2},
	{0,4,3,-2,-1}
};
int tim(int a,int b)
{
	int t=0;
	if(a<0)t^=1;
	if(b<0)t^=1;
	if(t==0)return dat[abs(a)][abs(b)];
	else return -dat[abs(a)][abs(b)];
}
int main()
{
	FILE *fr=fopen("c-large.in","r");
	FILE *fw=fopen("outl.txt","w");
	int data;
	//scanf("%d",&data);
	fscanf(fr,"%d",&data);
	for(int p=0;p<data;p++)
	{
		int num;
		long long kai;
		//scanf("%d%lld",&num,&kai);
		fscanf(fr,"%d%lld",&num,&kai);
		if(kai>20)
		{
			kai=(kai-20)%4+20;
		}
		vector<int>vec;
		for(int i=0;i<num;i++)
		{
			char zan;
			fscanf(fr," %c",&zan);
			//scanf(" %c",&zan);
			if(zan=='i')vec.push_back(2);
			if(zan=='j')vec.push_back(3);
			if(zan=='k')vec.push_back(4);
		}
		printf("Case #%d: ",p+1);
		fprintf(fw,"Case #%d: ",p+1);
		for(int i=1;i<kai;i++)
		{
			for(int j=0;j<num;j++)vec.push_back(vec[j]);
		}
		int st=1000000000,go=-1;
		int now=1;
		for(int i=0;i<vec.size();i++)
		{
			now=tim(now,vec[i]);
		}
		if(now!=-1)
		{
			printf("NO\n");
			fprintf(fw,"NO\n");
			continue;
		}
		now=1;
		for(int i=0;i<vec.size();i++)
		{
			now=tim(now,vec[i]);
			if(now==2)
			{
				st=i;
				break;
			}
		}
		now=1;
		for(int i=vec.size()-1;i>=0;i--)
		{
			now=tim(vec[i],now);
			if(now==4)
			{
				go=i;
				break;
			}
		}
		if(st<go)fprintf(fw,"YES\n");
		else fprintf(fw,"NO\n");
		if(st<go)printf("YES\n");
		else printf("NO\n");
	}
}