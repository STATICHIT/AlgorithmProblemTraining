//比较复杂的方法
#include<stdio.h>
#include<string.h>
void main()
{
    char a[40];                      //假设输入  1    2    3    -    2    3    +    1    0    0  （得200）
    int i,j,alen,n=0,z=0,m;          //a数组   a[0] a[1] a[2] a[3] a[4] a[5] a[6] a[7] a[8] a[9]
    //b数组   b[0] b[1] b[2] b[3] b[4] b[5] b[6] b[7] b[8] b[9]
    int b[40],c[40],s[40]= {0};      //
    gets(a);                         //s数组   |<---s[1]---->|  |  |<-s[2]->|  |  |<---s[3]--->|   s[n]来记录各项式
    alen=strlen(a);                  //c数组                   c[1]           c[2]
    for(i=0; i<alen; i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            b[i]=a[i]-'0';
            //printf("b[%d]=%d ",i,b[i]);//检查数组b赋值的情况
        }
        if(a[i]=='+'||a[i]=='-')//此时i为符号这一位
        {

            c[n+1]=a[i];//用c[n+1]记录第n个加减号
            for(j=z; j<=i-1; j++)//初始化了z=0，循环到符号前一位
            {
                //	printf("%d \n",b[j]);检查当前b数组赋值情况
                for(m=j; m<i-1; m++) //距离符号一位就是个位数，z=i-1不进入循环即本身，
                                      //距离符号两位就是十位数，循环一次乘一个10，距离符
                                      //号三位就是百位，循环两次乘两个10。。
                {
                    b[j]=b[j]*10;
                }
                s[n]+=b[j];//因为这里还要用到n，所以不在c[n+1]=a[i]下面就n++
            }              //得出一位数就加到数1中
            n++;//下一次循环结果记入s[n+1]中，下一个符号标志就储存在k[n+1+1]中了
            z=i+1;//i+1为符号的后一位，下一轮循环就合成下一个整体数！！
        }
        if(i==alen-1)//由题目可知最后一个字符一定是数字，所以到最后一个数时，上面的
                     //“遇加减号则将加减号前的数字进位后组合成一个项式”命令无法执
                     //行，则需一个新的指令使代码再次执行
        {
            for(j=z; j<=i; j++) //从最后一个数的起始数字a[z]开始，循环到最后一个数字a[i]
            {
                for(m=j; m<i; m++)

                {
                    b[j]=b[j]*10;
                }
                //	printf("%d \n",b[j]);检查当前位数命令完成情况

                s[n]+=b[j];
                //printf("  s[n]=%d ,n=%d\n",s[n],n);
            }
        }
    }
    int ans=s[0];
    for(i=1; i<=n; i++) //第一个元素一定是数字且第一个数由s[1]记录，
                        //第二个数由s[2]记录。。所以从i=1开始
    {
        if(c[i]=='+')
        {
            ans=s[i]+ans;
        }
        if(c[i]=='-')
        {
            ans=ans-s[i];
        }
    }
    printf("%d\n",ans);
}

//学长说其实一个i就能实现，

/*
#include<stdio.h>
#include<string.h>
void main()
{
    char a[40];
    int i,j,len,temp=0,ans;
    scanf("%s",a);
    len=strlen(a);
    for(i=0;i<len;i++)
    {
        for(j=0;j<len;j++)
        {
             if(a[i]=='+'||a[i]=='-')
        {break;}
            temp*=10;
        }
    }
}



*/























