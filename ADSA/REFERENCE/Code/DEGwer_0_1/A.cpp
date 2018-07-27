#include<stdio.h>
#include "stdafx.h"
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	FILE *fr=fopen("a-large.in","r");
	FILE *fw=fopen("outl.txt","w");
	int num;
	fscanf(fr,"%d",&num);
	for(int p=0;p<num;p++)
	{
		int num;
		fscanf(fr,"%d",&num);
		vector<int>vec;
		for(int i=0;i<num+1;i++)
		{
			char zan;
			fscanf(fr," %c",&zan);
			vec.push_back(zan-'0');
		}
		for(int i=0;;i++)
		{
			bool f=true;
			int cnt=0;
			for(int j=0;j<=num;j++)
			{
				if(cnt>=j)cnt+=vec[j];
				else if(vec[j]!=0)f=false;
			}
			if(f)
			{
				fprintf(fw,"Case #%d: %d\n",p+1,i);
				break;
			}
			vec[0]++;
		}
	}
}