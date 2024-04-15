# include <stdio.h>
# include <iostream>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>

const int MAXSTR = 2048;
const char ULE_MESSAGE[] = "Max User Limit Exceed. See You~";
const int JOBS = 2; // one for recv all others message, the other for sending message

// define Argument struct passing to pthread
typedef struct _argument
{
    int clientSockfd;
    struct sockaddr_in serverInfo;
    bool* connectPtr;
} Argument;


class ClientDuan
{
private:
    int clientSockfd;
    struct sockaddr_in serverInfo;
public:
    ClientDuan();
    void connectToServer();
    static void* othersMessage(void* argsVoid);
    static void* myMessage(void* argsVoid);
};

//void  connectToServer();
//void* othersMessage(void* argsVoid);
//void* myMessage(void* argsVoid);
