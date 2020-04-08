package com.shreyas.robofeveriotv1;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.webkit.WebChromeClient;
import android.webkit.WebView;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {
    private WebView Wv;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Wv = findViewById(R.id.webView);
        Wv.setWebChromeClient(new WebChromeClient());
        Wv.loadUrl("http://192.168.4.1/");
        Button powerOn = findViewById(R.id.button2);
        Button powerOff = findViewById(R.id.button);

        powerOn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Wv.loadUrl("http://192.168.4.1/power/on");
            }
        });

        powerOff.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Wv.loadUrl("http://192.168.4.1/power/off");
            }
        });


    }
}
