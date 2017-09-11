#include <cstdio>
#include <cmath>
#define MAX 102
double real[MAX];
using namespace std;
double gongshi(double num);
void erfen(double real, double head, double end);
double a[2] = {0, gongshi(100)};
int main(){
    int num;
    #ifdef TEST
    FILE *fp = fopen("D:\\1.txt","r");
    fscanf(fp, "%d", &num);
    for(int n = 0; n < num; n++){
        fscanf(fp, "%lf", &real[n]);
    }
    #else
    scanf("%d", &num);
    for(int n = 0; n < num; n++){
        scanf("%lf", &real[n]);
    }
    #endif // TEST
    for(int n = 0; n < num; n++){
        if(real[n] < 6.0){
            printf("No solution!\n");
        }
        else if(real[n] == 6.0){
            printf("%.4lf\n", 0.0);
        }
        else if(real[n] > gongshi(100)){
            printf("No solution!\n");
        }
        else if(real[n] == gongshi(100)){
            printf("%.4lf\n", 100.0);
        }
        else{
            /*erfen(real[n], 0.0, 100.0);*/
            double head = 0.0, end = 100.0;
            while(1){
                double temp = (head + end) / 2;
                double test = gongshi(temp) - real[n];
                if(end - head < 1e-5){
                    if((int)floor(head*1e5) % 10 != (int)floor(end*1e5) % 10)
                        if(gongshi(floor(end*1e5) / 1e5) < real[n])
                           head = end;
                    break;
                }
                else if(gongshi(temp) > real[n])
                    end = temp;
                else
                    head = temp;
            }
            printf("%.4lf\n", head);
        }
    }
    #ifdef TEST
    fclose(fp);
    system("pause");
    #endif // TEST
}
double gongshi(double x){
    double temp = 8*pow(x,4) + 7*pow(x,3) + 2*pow(x,2) + 3*x + 6;
    return temp;
}
void erfen(double real,double head, double end){
    double temp = (head + end) / 2;
    double test4 = gongshi(temp);
    if(end - head < 1e-5){
        if((int)floor(head*1e5) % 10 != (int)floor(end*1e5) % 10){
            double test3 = floor(end * 1e5) / 1e5;
            double test2 = gongshi(floor(end * 1e5) / 1e5);
            if(gongshi(floor(end*1e5) / 1e5) < real)
                printf("%.4lf\n", end);
            else
                printf("%.4lf\n", head);
        }


    }
    else if(gongshi(temp) > real)
        erfen(real, head, temp);
    else
        erfen(real, temp, end);
}
