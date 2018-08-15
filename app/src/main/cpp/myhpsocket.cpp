//
// Created by tony on 2018/8/14.
//

#include "com_example_tony_myhpsocket_MyHPSocket.h"
#include <hpsocket/HPSocket.h>
#include <string>

jint JNICALL Java_com_example_tony_myhpsocket_MyHPSocket_version
(JNIEnv *, jclass)
{
    return HP_GetHPSocketVersion();
}

/*******************************
 *
 */

class MyTcpClientListener : public CTcpClientListener
{
public:
    MyTcpClientListener() {}
    ~MyTcpClientListener() {}

private:
    virtual EnHandleResult OnSend(ITcpClient* pSender, CONNID dwConnID, const BYTE* pData, int iLength)
    {
        return HR_OK;
    }
    virtual EnHandleResult OnReceive(ITcpClient* pSender, CONNID dwConnID, const BYTE* pData, int iLength)
    {
        return HR_OK;
    }
    virtual EnHandleResult OnClose(ITcpClient* pSender, CONNID dwConnID, EnSocketOperation enOperation, int iErrorCode)
    {
        return HR_OK;
    }
    virtual EnHandleResult OnConnect(ITcpClient* pSender, CONNID dwConnID)
    {
        return HR_OK;
    }
};


/*******************************
 *
 */


static MyTcpClientListener s_listener;
static CTcpPackClientPtr s_client(&s_listener);

jint JNICALL Java_com_example_tony_myhpsocket_MyHPSocket_connect
        (JNIEnv *, jclass, jstring ip, jint port)
{
    s_client->SetMaxPackSize(0x01FFF);
    s_client->SetPackHeaderFlag(0x169);

    LPCTSTR address = "192.168.232.182";
    int portt = 5555;
    bool r = s_client->Start(address, portt, false);
    LPCTSTR desp = s_client->GetLastErrorDesc();

    return 0;
}

JNIEXPORT jint JNICALL Java_com_example_tony_myhpsocket_MyHPSocket_send
        (JNIEnv *, jclass, jbyteArray)
{
    std::string t = "helloworld";
    const char* buff = t.c_str();
    s_client->Send((const BYTE*)buff, 10);
    return 0;
}

JNIEXPORT jint JNICALL Java_com_example_tony_myhpsocket_MyHPSocket_recv
        (JNIEnv *, jclass, jbyteArray buf)
{
    //s_client->Rec
    return 0;
}

JNIEXPORT void JNICALL Java_com_example_tony_myhpsocket_MyHPSocket_close
        (JNIEnv *, jclass)
{
    s_client->Stop();
}