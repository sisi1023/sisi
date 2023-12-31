/*
 $$$$$$\   $$$$$$\  $$\   $$\ $$$$$$$$\ 
$$  __$$\ $$  __$$\ $$ |  $$ |\__$$  __|
$$ /  \__|$$ /  $$ |$$ |  $$ |   $$ |   
$$ |      $$ |  $$ |$$ |  $$ |   $$ |   
$$ |      $$ |  $$ |$$ |  $$ |   $$ |   
$$ |  $$\ $$ $$\$$ |$$ |  $$ |   $$ |   
\$$$$$$  |\$$$$$$ / \$$$$$$  |   $$ |   
 \______/  \___$$$\  \______/    \__|   
               \___|                    
                                        
   电子信息四班 姚鑫   Using gbk encoding                             
*/
#include<stdio.h>
#define TRUE 1
#define FALSE 0
#define N 21
int AdjMatrix[N][N]=
{{0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,1,1,0,0},
    {0,0,0,1,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,1,0,0},
    {0,0,0,0,1,0,1,1,0,0,1,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,1,1,0,0,0,0,1,0,0,1,0,0,0,1,0,0,0},
    {0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0},
    {0,1,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,0,0,1},
    {0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,0,1,0,0,0,0},
    {1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,1,0,0,0},
    {0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,1,0,0,1,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,1,1},
    {0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0},
    {1,0,0,0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1},
    {0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,1,0}};

int degree[N]={0};   //记录顶点的degree数目
char *order[N]={"红色","蓝色","黄色","绿色"};
char *name[N]={"成都市","自贡市","攀枝花市","泸州市","德阳市","绵阳市","广元市","遂宁市","内江市","乐山市",
"南充市","眉山市","宜宾市","广安市","达州市","雅安市","巴中市","资阳市","阿坝藏族羌族自治州","甘孜藏族自治州","凉山彝族自治州"};
int Max(int *a);//找度最大的结点下标
int judge(int i,int k);//判断k点是否能加入颜色集中第i中颜色顶点集
void Welsh_Powell();//韦尔奇 鲍威尔图结点染色法
struct OrderNode
{
	int used;     //标记次序是否被用，0代表未用
	int rear;     //顶点集合尾指针
	int node[N];  //同次序顶点集合
}OrderSet[N]={{0,0,0,0}};  //顶点集
int main()
{
	Welsh_Powell();
	return 0;
}
int Max(int *a)
{
	int i,value,index;
	value=-1;
	index=0;
	for(i=0;i<N;i++)
	{
		if(value<a[i])
		{
			value=a[i];
			index=i;
		}
	}
	a[index]=-1;
	return index;
}                     
int judge(int i,int k)
{
	int p,q,m;

	p=0;
	q=OrderSet[i].rear;
	while(AdjMatrix[k][OrderSet[i].node[p]]==0&&p!=OrderSet[i].rear)
		p++;
	if(p==q)return 1;
	return 0;
}                  
void Welsh_Powell()
{
	int i,k,j;
	int orderPtr;
	for(i=0;i<N;++i)
	{
		for(j=0;j<N;++j)
		{
			if(i!=j&&AdjMatrix[i][j])
				degree[i]++;
		}
	}

	for(j=0;j<N;++j)
	{
		k=Max(degree);
		orderPtr=0;
		if(OrderSet[orderPtr].used==1)
		{
			while(!judge(orderPtr,k))
				orderPtr++;
		}
		OrderSet[orderPtr].node[OrderSet[orderPtr].rear++]=k;
		if(OrderSet[orderPtr].used==0) OrderSet[orderPtr].used=1;
	}
	for(j=0;j<N;++j)
	{
		if(OrderSet[j].used==1)
		{
			printf("%s:",order[j]);
			for(i=0;i<OrderSet[j].rear;++i)
				printf("%s ",name[OrderSet[j].node[i]]);
			printf("\n");
		}
	}
}                        
