package com.example.flaunch

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.layout.*
import androidx.compose.material3.Button
import androidx.compose.material3.ExperimentalMaterial3Api
import androidx.compose.material3.RadioButton
import androidx.compose.material3.Text
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.unit.dp


class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            QuizApp()
        }
    }
}

@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun QuizApp() {
    var selectedDifficulty by remember { mutableStateOf(0) }

    Column(
        modifier = Modifier
            .fillMaxSize()
            .padding(16.dp),
        verticalArrangement = Arrangement.Center,
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        Button(onClick = { selectedDifficulty = 1 }) {
            Text(text = "Легкий")
        }
        Spacer(modifier = Modifier.height(8.dp))
        Button(onClick = { selectedDifficulty = 2 }) {
            Text(text = "Тяжелый")
        }
            Questions(selectedDifficulty)
    }
}

@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun Questions(difficulty: Int) {
    val questions = when (difficulty) {
        1 -> listOf(
            Question("Какая страна самая крупная?", listOf("Китай", "Россия", "США"), "Россия"),
            Question("Какой сейчас год?", listOf("2025", "2000", "2008"), "2025"),
            Question("Какая медаль за первое место?", listOf("Бронзовая", "Серебряная", "Золотая"), "Золотая")
        )
        2 -> listOf(
            Question("Сколько человек проживает в России?", listOf("143млн", "200млн", "167млн"), "143млн"),
            Question("В каком году распался СССР?", listOf("1989", "1991", "1995"), "1991"),
            Question("Сколько стоит доллар?", listOf("98", "95", "89"), "89"),
            Question("Какой самый большой орган у человека?", listOf("Печень", "Легкие", "Кожа"), "Кожа")
        )
        else -> emptyList()
    }

    var currentQuestion by remember {mutableIntStateOf(0)}
    var selectedAnswer by remember {mutableStateOf("")}
    var score by remember {mutableIntStateOf(0)}
    var quizFinished by remember {mutableStateOf(false)}
    var enabledButton by remember {mutableStateOf(false)}

    Column(modifier = Modifier.fillMaxSize().padding(16.dp), verticalArrangement = Arrangement.Center, horizontalAlignment = Alignment.CenterHorizontally){
        if (quizFinished == false){
            Text(text = "Вопрос: ${questions[currentQuestion].text}")
            Spacer(modifier = Modifier.height(12.dp))

            questions[currentQuestion].options.forEach {
                    option ->
                Row(modifier = Modifier.fillMaxWidth(), verticalAlignment = Alignment.CenterVertically){
                    RadioButton(
                        selected = selectedAnswer == option,
                        onClick = {
                            selectedAnswer = option
                            questions[currentQuestion].options.forEach{option ->
                                if (selectedAnswer == option)
                                    enabledButton = true
                            }
                        }
                    )
                    Text(text = option)
                }
            }


            Button(onClick ={
                if (selectedAnswer == questions[currentQuestion].correctAnswer){
                    score++
                }
                if (currentQuestion < questions.size - 1)
                    currentQuestion++
                else
                    quizFinished = true;
                selectedAnswer = ""
                enabledButton = false
            }, enabled = enabledButton){
                Text(text = if (currentQuestion < questions.size -1) "Следующий вопрос" else "Закончить")
            }
        }
        else{
            Text(text = "Ваш результат: $score/${questions.size}")
            Button(onClick = {
                quizFinished = false
                currentQuestion = 0
                score = 0
                selectedAnswer = ""
            }){
                Text(text = "Перезапустить квиз")
            }
        }
    }
}

data class Question(val text: String, val options: List<String>, val correctAnswer: String)
