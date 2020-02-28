#include<iostream>
#include<math.h>
#include<string.h>
#include<ctype.h>
using namespace std;

template <class T>
class MySet
{
	private:
    T *set;
    int card;
    
    public:
    MySet(int n)
    {
        card=n;
        set=new T[card];
    }
	
    void feed(T t)
    {
        for(int k=0;k<card;k++)
        {
            	cin>>set[k];
        }
      Remove();
    }
     void show()
    {
    	cout<<"{ ";
        for(int i=0;i<card;i++)
        {
        	if(i==card-1)
        	{
        		cout<<set[i];
			}
        	else
            {
            	cout<<set[i]<<", ";
			}
        }
        cout<<"\b}"<<endl;
        showcard();
    }

    void Remove()
    {
        for(int i=0;i<card;i++)
        {
            for(int j=i+1;j<card;)
            {
                if(set[i]==set[j])
                {
                    set[i]=set[j];
                    for(int k=j;k<card-1;k++)
                    {
                        set[k]=set[k+1];
                    }
                    --card;
                }
                else
                {
                    j++;
                }
            }
        }
    }
    MySet operator + (const MySet& M)
    {
        MySet<T>temp(card+M.card);
        for(int i=0,j=0;i<(card+M.card);i++)
        {
            if (i<card)
            {
                temp.set[i]=set[i];
            }
            else
            {
                temp.set[i]=M.set[j];
                j++;
            }
            
        }
        temp.Remove();
        return temp;
        
    }
    MySet operator * (const MySet& ob)
    {
      
        int k=0;
        for(int i=0;i<card;i++)
        {
        	for(int j=0;j<ob.card;j++)
        	{
        		if(set[i]==ob.set[j])
        		{
        			k++;
				}
			}
		}
		int p=0;
		MySet<T> temp1(k);
		 for(int i=0;i<card;i++)
        {
        	for(int j=0;j<ob.card;j++)
        	{
        		if(set[i]==ob.set[j])
        		{
        			temp1.set[p]=set[i];
        			p++;
				}
			}
		}
		temp1.Remove();
		return temp1;
    }
    MySet operator - (const MySet& ob1)
    {
        MySet<T> temp2(card);
        for(int i=0;i<card;i++)
        {
            temp2.set[i]=set[i];
        }
        MySet<T> Sub=temp2*ob1;
        for(int i=0;i<temp2.card;i++)
        {
            for(int j=0;j<Sub.card;j++)
            {
                if(temp2.set[i]==Sub.set[j])
                {
                    for(int k=i;k<temp2.card-1;k++)
                    {
                        temp2.set[k]=temp2.set[k+1];
                    }
                    temp2.card--;
                }
            }
        }
        temp2.Remove();
        return temp2;
    }
     MySet operator ^ (MySet ob2)
    {
        MySet<T> temp3(card);
        for(int i=0;i<card;i++)
        {
            temp3.set[i]=set[i];
        }
        MySet<T> Sub1=temp3*ob2;
        MySet<T> Union=temp3+ob2;
        for(int i=0;i<Union.card;i++)
        {
            for(int j=0;j<Sub1.card;j++)
            {
                if(Union.set[i]==Sub1.set[j])
                {
                    for(int k=i;k<Union.card-1;k++)
                    {
                        Union.set[k]=Union.set[k+1];
                    }
                    Union.card--;
                }
            }
        }
        Union.Remove();
        return Union;
    }
    
    bool operator == (const MySet<T>& ob4)
    {
    	int flag=0;
    	if(card>=ob4.card)
    	{
    	    for(int i=0;i<card;i++)
        	{
        		for(int j=0;j<card;j++)
                {
                	if(set[i]==ob4.set[j])
            		{
             		   	flag =1;
             		   	break;
            		}
				}
            		
        	}
		}
		else
		{
		    for(int i=0;i<ob4.card;i++)
        	{
        		for(int i=0;i<ob4.card;i++)
          	    	if(set[i]!=ob4.set[i])
          	   		{
            	   		 flag=1;
            	   		 break;
            		}
      		}
		}
      if(flag)
      {
      	 return true;
	  }
	  else{
	  	 return false;
	  }
       
    }
    MySet<T>& operator =(const MySet<T>& ob3)
    {
        for(int i=0;i<card;i++)
        {
            set[i]=ob3.set[i];
        }
        return *this;
    }
    void showcard()
    {
        cout<<"\nCardinality :"<<card << "\n";
    }
    void PowerSet()
    {
    	int len=pow(2,card);
    	cout<<"{ ";
    	for(int i=0;i<len;i++)
    	{
    		cout<<"{ ";
    		for(int t=i,j=0;j<card;j++)
    		{
    			if(t&1)
    			{
    				cout << set[j];
				}
				t>>=1;
			}
			if(i==len-1)
			{
				cout<<"\b\b },"; 
		    }   
			else
			{
				cout<<"\b\b }, "; 
			}    
        }
		cout<<"\b }"; 
	}
};

template<typename T>
void Set(T t)
{
	char choice;
	int ch;
	int card1,card2;
	
	cout << "Enter cardinality of first set:";
	cin >> card1;
	MySet<T> Set1(card1);
	cout << "\nEnter cardinality of second set:";
	cin >> card2;
	MySet<T> Set2(card2);
	cout << "\nEnter the elements of first set:";
	Set1.feed(t);
	cout << "\nEnter the elements of second set:";
	Set2.feed(t);
	cout << "\n\nMENU FOR SET:\n";
	cout << "1. Union\n";
    cout << "2. Intersection\n";
    cout << "3. Difference(Enter the biggest set first)\n";
    cout << "4. Symmetric Difference\n";
    cout << "5. Equality of sets\n";
    cout << "6. Power sets for both sets\n";
    cout << "7. Implementation of assignment operator\n";
    do
    {
    	cout << "Enter your choice: ";
    	cin >> ch;
    	switch(ch)
    	{
    		case 1:
            {
            	MySet<T> Set3=Set1+Set2;
            	Set3.show();
                break;
            }
            case 2:
            {
            	MySet<T> Set3(Set1*Set2);
            	Set3.show();
                break;
            }
            case 3:
            {
            	MySet<T> Set3=Set2-Set1;
            	MySet<T> Set4=Set1-Set2;
            	cout<<"\nDifference Set2-Set1 is: ";
            	Set3.show();
            	cout<<"\nDifference Set1-Set2 is: ";
            	Set4.show();
                break;
            }
            case 4:
            {
            	MySet<T> Set3=Set1^Set2;
            	Set3.show();
                break;
            }
            case 5:
            {
            	if(Set1==Set2)
            	{
            		cout<<"\nSets are equal.";
				}
				else
				{
					cout<<"\nSets aren't equal.";
				}
                break;
            }
            case 6:
           	{  cout<<"\nPower Set of Set1:";
			   Set1.PowerSet();
			   cout<<"\nPower Set of Set2:";
			   Set2.PowerSet(); 	
			   break;	
			}
            case 7:
            {
            	cout<<"\nImplementing assignment operator:"<<endl;
            	MySet<T> Set3(card2);
            	Set3=Set2;
            	Set3.show();
                break;
            }
            default:
            {
            	cout<<"\nInvalid choice!!!";
            	break;
            }
        }
        cout<<"Do you want to continue?(Y/N):";
        cin>>choice;
    }while(choice=='Y'||choice=='y');
}

int main()
{
   int ch;
   string str="xyz";
   cout << "MENU:";
	cout << "\n1.char";
	cout << "\n2.int";
	cout << "\n3.double";
	cout << "\n4.String";
	cout << "\n\nEnter your choice:";
	cin>>ch;
   switch (ch)
   {
        case 1:
        {
            Set('a');
            break;
        }
        case 2:
        {
            Set(1);
            break;
        }
        case 3:
        {
            Set(1.0);
            break;
        }
        case 4:
        {
            Set(str);
            break;
        }
        default:
        {
            cout<<"\nInvalid choice\n";
            break;
        }
   }
    return 0;
}

template class MySet<char>;
template class MySet<int>;
template class MySet<double>;
template class MySet<string>;
