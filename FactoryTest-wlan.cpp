#include <stdio.h>
#include <memory.h>
#include <unistd.h>
#include "common.h"

int WlanTest()
{
    int retValue = 0;

    FILE *fp;
    char tmp[1024];
    memset(tmp, 0, sizeof(tmp));

    //wpa_supplicant
    fp = popen("ps|grep wpa_supplicant|grep -v grep", "r");
    if(fp == NULL)
    {
        FormatPrint("Failed to run command\n");
        retValue = 1;
        return retValue;
    }

    fgets(tmp, sizeof(tmp), fp);
    if(strlen(tmp) == 0)
    {
        FormatPrint("no wpa_supplicant running\n");
        retValue = 1;
    }
    else
    {
        FormatPrint("RESULT | %s", tmp);
        while(fgets(tmp, sizeof(tmp), fp) != NULL)
        {
            FormatPrint("RESULT | %s", tmp);
        }
    }
    pclose(fp);


    // //扫描无线网络
    // FormatPrint("扫描无线网络\n");
    // fp = popen("wpa_cli scan 'wlan0'", "r");
    // sleep(3);
    // if (fp == NULL)
    // {
    //     FormatPrint("Failed to run command\n" );
    //     retValue = 1;
    //     return retValue;
    // }

    // fgets(tmp, sizeof(tmp), fp);
    // if(strlen(tmp)==0)
    // {
    //     FormatPrint("no scan wlan0 result\n");
    //     retValue = 1;
    // }
    // else
    // {
    //     FormatPrint("RESULT | %s", tmp);
    //     while (fgets(tmp, sizeof(tmp), fp) != NULL)
    //     {
    //         FormatPrint("RESULT | %s", tmp);
    //     }
    // }
    // pclose(fp);

    return retValue;
}

int main(int argc, char *argv[])
{
    int retValue = 0;
    retValue = WlanTest();
    if(retValue == 0)
    {
        FormatPrint("WLanTest=[OK]\n");
    }
    else
    {
        FormatPrint("WLanTest=[NG]\n");
    }

    return retValue;
}
