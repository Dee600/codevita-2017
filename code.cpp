#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

using namespace std;
void expand(int);
bool IsPrime(int);


int temp_ones,temp_tens,int_hund=7,int_thous=8,int_and=3;
int flag_ones = 0,flag_tens = 0,flag_hund = 0,flag_thous = 0,flag_and = 0;



int main()
{
    int num,low, high, i, flag, final_res=0;
   
    //cout<<"Input:"<<endl;
	cin>>low>>high;
	if(low==1)
	{
		low++;
    }
	if(low==0)
	{
		low=low+2;
    }
	if(low<0)
	{
	
		low=2;
    }
    if(low>99999)
    {
    	low=99999;
	}
    if(high>99999)
    {
    	high=99999;
	}
    //cout<<"Output:"<<endl;
    
    while (low <= high)
    {
    	 
        flag_ones = 0;
		flag_tens = 0;
		flag_hund = 0;
		flag_thous = 0;
		flag_and = 0;
        flag = 0;
        temp_ones = 0;
        temp_tens = 0;

        for(i = 2; i <= low/2; ++i)
        {
            if(low % i == 0)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            cout<<"prime numbers:"<<low<<endl;
            expand(low);
            
            int res = temp_ones + temp_tens + (int_hund*flag_hund) + (int_thous*flag_thous) + (int_and*flag_and);
            
			cout<<"add res"<<res<<endl;
		
  		
  			(IsPrime(res)==true)? final_res++:final_res;

  		
  		
		}
        ++low;
       
    }
    cout<<final_res;
    return 0;
}





bool IsPrime (int n1)
{
  if((n1==2)||(n1==3)) return true;

  int iResidum = n1 % 6;
  if(!((iResidum == 5) || ( iResidum == 1))) return false;

  if(n1 %3 == 0) return false;
  for(int i=1; 
      6*i <= (int)sqrt(double(n1))+6; 
      i++)
  {
      if( n1 % 6*i-1==0) return false;
                if( n1 % 6*i+1==0) return false;
  }

  return true;
}











void expand(int value)
{
    const char * const ones[20] = {"zero", "one", "two", "three","four","five","six","seven",
    "eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen",
    "eighteen","nineteen"};
    const char * const tens[10] = {"", "ten", "twenty", "thirty","forty","fifty","sixty","seventy",
    "eighty","ninety"};

    if(value<0)
    {
        //cout<<"minus ";
        expand(-value);
    }
    else if(value>=1000)
    {
        expand(value/1000);
        //cout<<" thousand";
        flag_thous++;
        
        if(value % 1000)
        {
            if(value % 1000 < 100)
            {
                //cout << " and";
                flag_and++;
                
            }
            //cout << " " ;
            expand(value % 1000);
        }
    }
    else if(value >= 100)
    {
        expand(value / 100);
        //cout<<" hundred";
        flag_hund++;
        
        if(value % 100)
        {
            //cout << " and ";
            flag_and++;
            expand (value % 100);
        }
    }
    else if(value >= 20)
    {
        //cout << tens[value / 10];
        temp_tens = temp_tens + strlen(tens[value/10]);
        flag_tens++;
        if(value % 10)
        {
            //cout << " ";
            expand(value % 10);
        }
    }
    else
    {
        //cout<<ones[value];
        temp_ones =temp_ones + strlen(ones[value]);
        //cout<<strlen(ones[value])<<endl;
        flag_ones++;
    }
    return;
}
