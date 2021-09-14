#include <iostream>
using namespace std;

int hextode(char* hexstr)
{
    if(hexstr ==NULL)
        return 0;
    char binary[17]={0};//放二进制字符串
    //Convert strings to a long-integer value.
    long i32=strtol(hexstr,NULL,16);//读取16进制的值
    int toint = 0;
    int ratio = 1;
    if(hexstr[0]>'8')
    {
        //Converts an integer to a string
        itoa(i32,binary,2);/*输出为二进制*/
        for(int i=1;i<16;i++) //除第一位外取反
        {
            binary[i] ='0'+!(binary[i]-'0');
        }
        cout<<endl;
        int nTakeover = 0;
        bool isoverflow = false;
        for(int i=15;i>=0;i--) //二进制加1
        {
            int nsum = binary[i]-'0'+nTakeover; //每位加上进位
            if(i==15)
                nsum++;
            if(nsum==2)
            {
                if(i == 0)
                    isoverflow = true;
                else
                {
                    nsum-=2;
                    nTakeover = 1;
                    binary[i] = '0'+nsum;
                }
            }
            else
            {
                binary[i] = '0'+nsum;
                break;
            }
        }
        for(int j=15;j>0;--j)
        {
            toint = toint+ (binary[j]-'0')*ratio;
            ratio=ratio*2;
        }
        toint = toint*(-1);
        return toint;
    }
    else
    {
        toint= i32;
        return toint;
    }
}

int main(){
    char * strhex = "ffd9";
    int result = hextode(strhex);
    cout<< result<<endl;
}
