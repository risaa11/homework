package com.example.flaunch

import android.os.Bundle
import android.util.Log
import android.widget.Toast
import android.widget.Toast.LENGTH_SHORT
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.text.KeyboardOptions
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Text
import androidx.compose.material3.TextField
import androidx.compose.runtime.Composable
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateMapOf
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.platform.LocalContext
import androidx.compose.ui.text.input.KeyboardType
import androidx.compose.ui.tooling.preview.Preview
import com.example.flaunch.ui.theme.FlaunchTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            Test()
        }
    }
}

@Composable
fun Test() {
    FlaunchTheme {
        val context = LocalContext.current
        var inputString by remember { mutableStateOf("")}


        Scaffold(modifier = Modifier.fillMaxSize()) {  innerPadding ->
            Column(modifier = Modifier
                    .padding(innerPadding)
                    .fillMaxSize(),
                    horizontalAlignment = Alignment.CenterHorizontally,
                verticalArrangement = Arrangement.Center)
            {
                TextField(
                    value = inputString,
                    keyboardOptions = KeyboardOptions(keyboardType = KeyboardType.Number),
                    onValueChange = {
                            newText ->
                        if (newText.length <= 1){
                            inputString = newText
                            Log.d("test", inputString);

                            if (inputString != ""){
                                val toast = Toast.makeText(context, getSeason(inputString), LENGTH_SHORT)
                                toast.show()
                            }
                        }
                    }
                )
            }

        }
    }
}

fun getSeason(num: String): String {
    return when (num){
        "1" -> "Это цифра!"
        "2" -> "Это цифра!"
        "3" -> "Это цифра!"
        "4" -> "Это цифра!"
        "5" -> "Это цифра!"
        "6" -> "Это цифра!"
        "7" -> "Это цифра!"
        "8" -> "Это цифра!"
        "9" -> "Это цифра!"
        "0" -> "Это цифра!"
        "&" -> "Это спец символ!"
        "#" -> "Это спец символ!"
        "<" -> "Это спец символ!"
        else -> "Непредусмотренный вариант!"
    }
}
