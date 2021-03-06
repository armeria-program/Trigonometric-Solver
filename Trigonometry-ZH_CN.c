#include <stdio.h>
#include <math.h>
#include <string.h>


int main(int argc, const char * argv[]) {
    double e=pow(3,0.5)/2;
    double m=0;
    double n=4*M_PI;
    double a=1;
    double b=1;
    double c=0;
    double d=0;
    char x[3];
    int num=0;
    int type;
    double convert;

    printf("三角方程计算器，可以解出：\na*sin/cos/tan/cot(bx+c)+d=e\n请输入三角函数类型：");
    scanf("%s",x);
    printf("请输入a，b，c，d，e：\n");
    scanf("%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e);
    printf("请输入范围的最小值和最大值：\n");
    scanf("%lf%lf",&m,&n);
    printf("弧度请输入0，角度请输入1:\n");
    scanf("%d",&type);

    if(type==0) convert=1;
    else if(type==1){
    	convert=180/M_PI;
    	m=m/convert;
    	n=n/convert;
    }else{
        printf("错误！\n");
        return -1;
    }
    
    //a*sin(bx+c)+d=e,x属于[m,n]
    if(strcmp(x,"sin")==0){
        printf("%.2fsin(%.2fx+%.2f)+%.2f=%.2f,x∈[%.2f,%.2f]\n\n",a,b,c,d,e,m,n);
        
        double begin=(m*b+c-asin((e-d)/a))/(2*M_PI);
        double end=(n*b+c-asin((e-d)/a))/(2*M_PI);
        
        for(int k=ceil(begin);k<=floor(end);k++){
            printf("%.3f\n",((2*k*M_PI+asin((e-d)/a)-c)/b)*convert);
            num++;
        }
        
        begin=(m*b+c+asin((e-d)/a)-M_PI)/(2*M_PI);
        end=(n*b+c+asin((e-d)/a)-M_PI)/(2*M_PI);
        
        for(int k=ceil(begin);k<=floor(end);k++){
            printf("%.3f\n",(((2*k+1)*M_PI-asin((e-d)/a)-c)/b)*convert);
            num++;
        }
    }
    
    //a*cos(bx+c)+d=e,x属于[m,n]
    if(strcmp(x,"cos")==0){
        printf("%.2fcos(%.2fx+%.2f)+%.2f=%.2f,x∈[%.2f,%.2f]\n\n",a,b,c,d,e,m,n);
        double begin=(m*b+c-acos((e-d)/a))/(2*M_PI);
        double end=(n*b+c-acos((e-d)/a))/(2*M_PI);
        
        for(int k=ceil(begin);k<=floor(end);k++){
            printf("%.3f\n",((2*k*M_PI+acos((e-d)/a)-c)/b)*convert);
            num++;
        }
        
        begin=(m*b+c+acos((e-d)/a))/(2*M_PI);
        end=(n*b+c+acos((e-d)/a))/(2*M_PI);
        
        for(int k=ceil(begin);k<=floor(end);k++){
            printf("%.3f\n",((2*k*M_PI-acos((e-d)/a)-c)/b)*convert);
            num++;
        }
    }
    
    //a*tan(bx+c)+d=e,x属于[m,n]
    if(strcmp(x,"tan")==0){
        printf("%.2ftan(%.2fx+%.2f)+%.2f=%.2f,x∈[%.2f,%.2f]\n\n",a,b,c,d,e,m,n);
        double begin=((m*b+c-atan((e-d)/a))/M_PI);
        double end=((n*b+c-atan((e-d)/a))/M_PI);
        
        for(int k=ceil(begin);k<=floor(end);k++){
            printf("%.3f\n",((k*M_PI+atan((e-d)/a)-c)/b)*convert);
            num++;
        }
    }
    
    //a*cot(bx+c)+d=e,x属于[m,n]
    if(strcmp(x,"cot")==0){
        printf("%.2fcot(%.2fx+%.2f)+%.2f=%.2f,x∈[%.2f,%.2f]\n\n",a,b,c,d,e,m,n);
        double begin=((m*b+c-atan(a/(e-d)))/M_PI);
        double end=((n*b+c-atan(a/(e-d)))/M_PI);
        
        for(int k=ceil(begin);k<=floor(end);k++){
            printf("%.3f\n",((k*M_PI+atan(a/(e-d))-c)/b)*convert);
            num++;
        }
    }
    printf("共%d个解。\n",num);
    return 0;
}
