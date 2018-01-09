//
// Created by zhaobq on 2017-4-25.
//

#ifndef MPI_CONNECT_MPI_CLIENT_H
#define MPI_CONNECT_MPI_CLIENT_H

#include "MPI_Base.h"
#include "ErrorHandler.h"
#include "MPI_Util.h"

class MPI_Client : public MPI_Base{
public:
    MPI_Client(IRecv_buffer* mh, char* svc_name, char* uuid);
    MPI_Client(IRecv_buffer* mh, char* svc_name, char* uuid, char* port);
    ~MPI_Client();

    int initialize();
    //void run();
    int stop(bool flag);
    int finalize();
    int exit();

    bool new_msg_come(ARGS *args);
//    void send(void *buf, int msgsize, int dest, MPI_Datatype datatype, int tag, MPI_Comm comm);
//    int send_int(int buf, int msgsize, int dest, int tag);
    int send_string(char* buf, int msgsize, int dest, int tag);
    void recv_handle(ARGS args,void* buf);
    void errhandler(MPI_Comm *comm, int* errcode,...);

private:
    char* svc_name_;
    char portname[MPI_MAX_PORT_NAME] = "\0";

	MPI_Errhandler eh;

    MPI_Comm sc_comm_;
    string uuid_= "";

    bool port_f = false;
};

#endif //MPI_CONNECT_MPI_CLIENT_H
