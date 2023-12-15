#include <iostream>

#include "Thread_Controler"

using namespace std;

using namespace susu_tools;

int wdnmd(char str)
{
    int i=0;
    while(true)
    {
    	//cout<<(int)str<<" ";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        i++;
        if(i >= 100)
        {
            break;
        }
    }
    cout<<endl;
    return 0;
}

int main()
{
    Thread_Controler* p = Thread_Controler::get_Thread_Controler();
    
    int i = 'a';
    for(i='A';i<='z';i++)
    {
        p->add_tesk(wdnmd,i);
        std::this_thread::sleep_for(std::chrono::milliseconds(125));
    }

    cout<<"hellp world"<<endl;

    getchar();
    for(i='A';i<='z';i++)
    {
        p->add_tesk(wdnmd,i);
        std::this_thread::sleep_for(std::chrono::milliseconds(125));
    }
    getchar();
    return 0;
}
