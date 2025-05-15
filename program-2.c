#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[]) {

    //returns shell
    char *shell=getenv("SHELL");
    printf("%s\n",shell);

    //retuns path
    char *mypath=getenv("PATH");
    printf("%s\n",mypath);

    //returns name
    char username[100];
    getlogin_r(username, 100);
    printf("%s\n",username);

    //the 3rd argument is just a pointer that can be used to get info about anything relating to the system

    return 0;

}
