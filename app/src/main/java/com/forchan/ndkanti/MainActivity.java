package com.forchan.ndkanti;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import com.forchan.ndkanti.databinding.ActivityMainBinding;
import com.forchan.ndkanti.tools.java2ndk;

public class MainActivity extends AppCompatActivity {
    private Button btnenterndk;

    // Used to load the 'ndkanti' library on application startup.


    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());
        btnenterndk = findViewById(R.id.btnenterndk);
        java2ndk.init();

        btnenterndk.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Toast.makeText(getApplicationContext(), "进入加密", Toast.LENGTH_SHORT).show();
            }
        });


        // Example of a call to a native method
        TextView tv = binding.sampleText;
//        tv.setText(stringFromJNI());
    }

    /**
     * A native method that is implemented by the 'ndkanti' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}