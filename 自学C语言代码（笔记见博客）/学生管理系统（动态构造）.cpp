# include <stdio.h>
# include <malloc.h>

struct Student
{
	int age;
	float score;
	char name[100];
};
int main(void)
{
	int len;
	struct Student * pArr;
	int i, j;
	struct Student t;

	//动态的构造一维数组
	printf("请输入学生的个数：\n");
	printf("len = ");
	scanf("%d", &len);
	pArr = (struct Student *)malloc(len * sizeof(struct Student));

	//输入
	for(i=0; i<len; ++i)
	{
		printf("请输入第%d个学生的信息：\n", i+1);
		printf("age = ");
		scanf("%d", &pArr[i].age);

		printf("name = ");
		scanf("%s", pArr[i].name); //name是数组名，本身就已经是数组首元素的地址，所以不能改成&pArr[i].name

		printf("score = ");
		scanf("%f", &pArr[i].score);
	}

	//排序
	for(i=0; i<len-1; ++i)
	{
		for(j=0; j<len-1-i; ++j)
		{
			if(pArr[j].score > pArr[i].score)
			{
				t = pArr[j];
				pArr[j] = pArr[j+1];
				pArr[j+1] = t;
			}
		}
	}

	printf("\n\n学生的信息是：\n");
	//输出
	for(i=0; i<len; ++i)
	{
		printf("第%d个学生的信息：\n", i+1);
		printf("age = %d\n", pArr[i].age);
		printf("name = %s\n", pArr[i].name);
		printf("score = %f\n", pArr[i].score);
	}
	return 0;
}
