#include<stdio.h>
#include "stdafx.h"
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int main()
{
	FILE *fr=fopen("b-large.in","r");
	FILE *fw=fopen("outl.txt","w");
	int data;
	fscanf(fr,"%d",&data);
	for(int p=0;p<data;p++)
	{
		int num;
		fscanf(fr,"%d",&num);
		vector<int>vec;
		for(int i=0;i<num;i++)
		{
			int zan;
			fscanf(fr,"%d",&zan);
			vec.push_back(zan);
		}
		int mini=1000000000;
		for(int i=1;i<=1000;i++)
		{
			int cnt=0;
			for(int j=0;j<vec.size();j++)
			{
				cnt+=(vec[j]-1)/i;
			}
			mini=min(mini,i+cnt);
		}
		fprintf(fw,"Case #%d: %d\n",p+1,mini);
	}
}