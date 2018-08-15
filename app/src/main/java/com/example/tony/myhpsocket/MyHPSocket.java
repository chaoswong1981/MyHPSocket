package com.example.tony.myhpsocket;

/**
 * Created by tony on 2018/8/14.
 */

public class MyHPSocket {
    static {
        System.loadLibrary("myhpsocket");
    }

    public static native int version();
    public static native int connect(String ip, int port);
    public static native int send(byte[] buff);
    public static native int recv(byte[] buff);
    public static native void close();
}
