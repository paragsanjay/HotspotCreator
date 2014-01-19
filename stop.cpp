#include <string>
#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
std::string exec(char* cmd) {
    FILE* pipe = _popen(cmd, "r");
    if (!pipe) return "ERROR";
    char buffer[128];
    std::string result = "";
    while(!feof(pipe)) {
    	if(fgets(buffer, 128, pipe) != NULL)
    		result += buffer;
    }
    _pclose(pipe);
    return result;
}
int main()
{
    string cho;
    char cmd[10000]="netsh wlan set hostednetwork mode=allow ssid=";

    cout<<"Welcome to HotSpot Creator       -developed by Parag Mhatre"<<endl;
    cout<<"==========================================================="<<endl;
    cout<<"do you want to stop[y/n]";
    cin>>cho;
    string s1;
    if(cho.find("y"))
{s1=exec("netsh wlan stop hostednetwork");
}
else
{
    return 0;
}

if(s1.find("stoped"))
{
    cout<<s1;
}
else
{
    cout<<"Plz run it as administrator previlages"<<endl;
}


    return 0;
}

