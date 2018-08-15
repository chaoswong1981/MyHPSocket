package com.example.tony.myhpsocket;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        int version = 0;
        version = MyHPSocket.version();
        tv.setText(Integer.toHexString(version));

        MyHPSocket.connect("192.168.232.182", 5555);
        MyHPSocket.send("helloworld".getBytes());
    }
}
